cmake_minimum_required(VERSION 2.8)
project(MultiHomography)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "My multi config types" FORCE)

SET("OpenCV_DIR" "C:/opencv3.1.0/build")
find_package(OpenCV REQUIRED)
find_package(VTK REQUIRED) #QT5_WRAP_CPP

file(GLOB project_cpp *.cpp)
file(GLOB project_h *.h)

QT5_WRAP_CPP (project_HEADERS_MOC mainwindow.h)
QT5_WRAP_UI (project_FORMS_HEADER mainwindow.ui)

ADD_DEFINITIONS (${QT_DEFINITIONS})

ADD_EXECUTABLE (MultiHomography 
${project_cpp} ${project_h} ${project_HEADERS_MOC} ${project_FORMS_HEADER}
)

target_link_libraries(MultiHomography ${OpenCV_LIBS})
qt5_use_modules (MultiHomography Widgets)