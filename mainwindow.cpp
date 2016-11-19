#include "mainwindow.h"
#include "build/ui_mainwindow.h"

void SourceImageMouseCallback(int e, int x, int y, int d, void *ptr);
void TargetImageMouseCallback(int e, int x, int y, int d, void *ptr);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	connect(ui->btn_src_open, SIGNAL(clicked()), this, SLOT(ButtonOpenSourceImagePressed()));
	connect(ui->btn_src_del, SIGNAL(clicked()), this, SLOT(ButtonDeleteSourcePointPressed()));
	connect(ui->btn_src_clear, SIGNAL(clicked()), this, SLOT(ButtonClearSourcePointPressed()));
	
	connect(ui->btn_tar_open, SIGNAL(clicked()), this, SLOT(ButtonOpenTargetImagePressed()));
	connect(ui->btn_tar_del, SIGNAL(clicked()), this, SLOT(ButtonDeleteTargetPointCloudPressed()));
	connect(ui->btn_tar_clear, SIGNAL(clicked()), this, SLOT(ButtonClearTargetPointPressed()));

	connect(ui->btn_perspective, SIGNAL(clicked()), this, SLOT(ButtonPerspectiveTransformPressed()));
	connect(ui->btn_undo, SIGNAL(clicked()), this, SLOT(ButtonUndoTransformPressed()));
	
	connect(ui->tree_src_point, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(TreeSourcePointClicked(QTreeWidgetItem *)));
	connect(ui->tree_tar_point, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(TreeTargetPointClicked(QTreeWidgetItem *)));

	namedWindow("Source Image", WINDOW_AUTOSIZE);
	namedWindow("Target Image", WINDOW_AUTOSIZE);

	//determine source area need more code at wrap perspective
	//setMouseCallback("Source Image", SourceImageMouseCallback, this);
	
	setMouseCallback("Target Image", TargetImageMouseCallback, this);




	//source_img_points.push_back(Point2f(float(0), float(0)));
	//source_img_points.push_back(Point2f(float(0), float(source_img.rows)));
	//source_img_points.push_back(Point2f(float(source_img.cols), float(source_img.rows)));
	//source_img_points.push_back(Point2f(float(source_img.cols), float(0)));

}

MainWindow::~MainWindow()
{
    delete ui;
}



QString MainWindow::GetOpenImageFilename()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Open source image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

	return filename;
}

void MainWindow::ButtonOpenSourceImagePressed()
{
	
	QString filename = GetOpenImageFilename();
	if (filename.trimmed().isEmpty()) return;

	source_img = imread(filename.toStdString(), CV_LOAD_IMAGE_COLOR);
	imshow("Source Image", source_img);

	AddPointsToSourceTree(0, 0);
	AddPointsToSourceTree(0, source_img.rows);
	AddPointsToSourceTree(source_img.cols, source_img.rows);
	AddPointsToSourceTree(source_img.cols, 0);

}

void MainWindow::ButtonOpenTargetImagePressed()
{
	QString filename = GetOpenImageFilename();
	if (filename.trimmed().isEmpty()) return;

	target_img = imread(filename.toStdString(), CV_LOAD_IMAGE_COLOR);
	imshow("Target Image", target_img);
}

/////////////////////////////////////////////

void MainWindow::ButtonDeleteSourcePointPressed()
{
	if (source_img_points.size() <= 0) return;

	QTreeWidgetItem *current_item = ui->tree_src_point->currentItem();
	int current_index = ui->tree_src_point->currentIndex().row();
	delete current_item;
	
	source_img_points.erase(source_img_points.begin() + current_index);

	//cout << "cleare clicked point" << endl;
	//cout << source_img_points << endl;

	
}
void MainWindow::ButtonClearSourcePointPressed()
{
	if (source_img_points.size() <= 0) return;

	for (int i = 0; i < source_img_points.size(); i++)
	{
		QTreeWidgetItem *current_item = ui->tree_src_point->topLevelItem(0);
		delete current_item;
	}
	
	source_img_points.clear();
	source_img_points.shrink_to_fit();
	
	//cout << "cleare clicked point" << endl;
	//cout << source_img_points << endl;

}

///////////////////////////////////////////////

void MainWindow::ButtonDeleteTargetPointCloudPressed()
{
	if (target_img_points.size() <= 0) return;

	QTreeWidgetItem *current_item = ui->tree_tar_point->currentItem();

	cout << "current item "<< current_item << endl;

	if (current_item == NULL) return;

	int current_index = ui->tree_tar_point->currentIndex().row();
	delete current_item;

	target_img_points.erase(target_img_points.begin() + current_index);

	//cout << "cleare clicked point" << endl;
	//cout << target_img_points << endl;
}
void MainWindow::ButtonClearTargetPointPressed()
{
	if (target_img_points.size() <= 0) return;

	for (int i = 0; i < target_img_points.size(); i++)
	{
		QTreeWidgetItem *current_item = ui->tree_tar_point->topLevelItem(0);
		delete current_item;
	}

	target_img_points.clear();
	target_img_points.shrink_to_fit();

	//cout << "cleare clicked point" << endl;
	//cout << target_img_points << endl;
}

void MainWindow::ButtonPerspectiveTransformPressed()
{
	cout << " Calculating Homography " << endl;
	Mat H = findHomography(source_img_points, target_img_points, 0);
	Mat source_transform;
	warpPerspective(source_img, source_transform, H, target_img.size());


	Mat transformed_gray, transformed_gray_inv;
	Mat src_final, tar_final;

	cvtColor(source_transform, transformed_gray, CV_BGR2GRAY);
	threshold(transformed_gray, transformed_gray, 0, 255, CV_THRESH_BINARY);
	bitwise_not(transformed_gray, transformed_gray_inv);


	target_img.copyTo(tar_final, transformed_gray_inv);
	//source_transform.copyTo(src_final, transformed_gray);


	target_img = source_transform + tar_final;
	imshow("Target Image", target_img);

}
void MainWindow::ButtonUndoTransformPressed()
{

}

void MainWindow::TreeSourcePointClicked(QTreeWidgetItem *current_select_item)
{

}
void MainWindow::TreeTargetPointClicked(QTreeWidgetItem *current_select_item)
{

}

////////////////SOURCE IMAGE//////////////////////

void SourceImageMouseCallback(int e, int x, int y, int d, void *ptr)
{
	MainWindow *mainWindow = (MainWindow *)(ptr);
	if (e == EVENT_LBUTTONDOWN)
	{
		cout << x << " " << y << endl;
		mainWindow->AddPointsToSourceTree(x, y);
	}
}

void MainWindow::AddPointsToSourceTree(int x, int y)
{
	if (source_img_points.size() >= 4)
	{
		cout << "source img : reach 4 selected points" << endl;
		return;
	}

	source_img_points.push_back(Point2f(float(x), float(y)));

	QTreeWidgetItem *new_item = new QTreeWidgetItem(ui->tree_src_point);
	new_item->setText(0, QString::number(x) + "," + QString::number(y));
	ui->tree_src_point->addTopLevelItem(new_item);

	circle(source_img, Point(x, y), 2, Scalar(0, 0, 255), 4);
	imshow("Source Image", source_img);
}

////////////////TARGET IMAGE/////////////////////////////////////////////

void TargetImageMouseCallback(int e, int x, int y, int d, void *ptr)
{
	MainWindow *mainWindow = (MainWindow *)(ptr);
	if (e == EVENT_LBUTTONDOWN)
	{
		cout << x << " " << y << endl;
		mainWindow->AddPointsToTargetTree(x, y);
	}
}

void MainWindow::AddPointsToTargetTree(int x, int y)
{
	if (target_img_points.size() >= 4)
	{
		cout << "target image : reach 4 selected points" << endl;
		return;
	}

	target_img_points.push_back(Point2f(float(x), float(y)));

	QTreeWidgetItem *new_item = new QTreeWidgetItem(ui->tree_tar_point);
	new_item->setText(0, QString::number(x) + "," + QString::number(y));
	ui->tree_tar_point->addTopLevelItem(new_item);

	circle(target_img, Point(x, y), 2, Scalar(0, 0, 255), 4);
	imshow("Target Image", target_img);
}

