#include <QApplication>
#include <QIcon>

#include "s21_CalculatorView.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

#ifdef __linux__
  QIcon icon(":/icon/MainIcon256.ico");
  a.setWindowIcon(icon);
#else
  QIcon icon(":/icon/MainIcon256.icns");
  a.setWindowIcon(icon);
#endif

  int id = QFontDatabase::addApplicationFont(":/roboto/RobotoFlex-Regular.ttf");
  QString family = QFontDatabase::applicationFontFamilies(id).at(0);

  s21_CalculatorView w;

  QMainWindow mainWindow;
  mainWindow.setMinimumSize(QSize(600, 450));
  mainWindow.setMaximumSize(QSize(800, 600));

  QWidget centralWidget;
  centralWidget.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  mainWindow.setCentralWidget(&centralWidget);

  w.show();
  return a.exec();
}
