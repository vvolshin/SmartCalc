#ifndef S21_CALCULATORVIEW_H
#define S21_CALCULATORVIEW_H

#include <QColor>
#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QRegularExpressionValidator>
#include <QVector>

#include "controller/s21_CalculatorController.h"
#include "controller/s21_CreditsController.h"
#include "view/qcustomplot/qcustomplot.h"

namespace Ui {
class s21_CalculatorView;
}

class s21_CalculatorView : public QMainWindow {
  Q_OBJECT

 public:
  explicit s21_CalculatorView(QWidget* parent = nullptr);
  ~s21_CalculatorView();

 private:
  Ui::s21_CalculatorView* ui;
  void setInitialSettings();
  void setConnections();
  void setGraphVisual();
  void setXValidator();
  void setCreditValidators();
  void buttons();
  void connectUniqueButtons();
  void closeMenu();
  void onButtonClicked(QPushButton* button, const QString& text = "");
  void on_menuIconClosed_clicked();
  void on_menuIconOpen_clicked();
  void on_menuRightButtonIconClosed_clicked();
  void on_menuRightButtonOpenLogo_clicked();
  void on_menuRightButtonClose_clicked();
  void on_menuRightButtonOpen_clicked();
  void on_menuCalculator_clicked(bool checked);
  void on_menuCredit_clicked(bool checked);
  void on_menuDeposit_clicked(bool checked);
  void on_redrawButton_clicked();
  void on_creditCalculateButton_clicked();
  void on_AC_clicked();
  void on_rem_clicked();
  void on_xEq_clicked(bool checked);
  void on_equal_clicked();
  void on_sign_clicked();
  void on_creditTextExpr_textChanged(const QString& arg1);
  void on_menuCreditCalendarButtonOpen_clicked();
  void on_menuRightButtonCreditClose_clicked();
  void on_menuCreditCalendarButtonClosed_clicked();
  void on_menuRightButtonCreditOpenLogo_clicked();
  void drawGraph();
  void updateLineEditSize(QLineEdit* lineEdit);
  void createCreditTable(s21::CreditsController& credits);

  double xBegin, xEnd, h, X;
  double yBegin, yEnd;
  QVector<double> x, y;
};

#endif  // S21_CALCULATORVIEW_H
