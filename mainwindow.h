#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	void AddPointsToSourceTree(int x, int y);
	void AddPointsToTargetTree(int x, int y);

private:
    Ui::MainWindow *ui;
	Mat source_img, target_img;
	vector<Mat> history_img;
	vector<Point2f> source_img_points, target_img_points;
	
	QString GetOpenImageFilename();
	//void SourceImageMouseCallback(int e, int x, int y, int d, void *ptr);
	


private slots:
	void ButtonOpenSourceImagePressed();
	void ButtonDeleteSourcePointPressed();
	void ButtonClearSourcePointPressed();

	void ButtonOpenTargetImagePressed();
	void ButtonDeleteTargetPointCloudPressed();
	void ButtonClearTargetPointPressed();

	void ButtonPerspectiveTransformPressed();
	void ButtonUndoTransformPressed();

	void TreeSourcePointClicked(QTreeWidgetItem *current_select_item);
	void TreeTargetPointClicked(QTreeWidgetItem *current_select_item);

};

#endif // MAINWINDOW_H
