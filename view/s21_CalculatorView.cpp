#include "s21_CalculatorView.h"

#include "ui_s21_CalculatorView.h"

s21_CalculatorView::s21_CalculatorView(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::s21_CalculatorView) {
  ui->setupUi(this);
  setInitialSettings();
  setConnections();
  setGraphVisual();
  setCreditValidators();
  setXValidator();
  on_menuCalculator_clicked(true);
  ui->calcInputExpr->setFocus();
}

s21_CalculatorView::~s21_CalculatorView() { delete ui; }

void s21_CalculatorView::setXValidator() {
  QRegularExpressionValidator* validatorXValue =
      new QRegularExpressionValidator(
          QRegularExpression("[0-9]+(\\,[0-9]{1,2})?"), this);
  ui->xValue->setValidator(validatorXValue);
}

void s21_CalculatorView::onButtonClicked(QPushButton* button,
                                         const QString& text) {
  closeMenu();
  if (button == ui->pi || button == ui->div) {
    ui->calcInputExpr->setText(ui->calcInputExpr->text() + text);
  } else {
    if (!ui->xEq->isChecked()) {
      ui->calcInputExpr->setText(ui->calcInputExpr->text() + button->text());
    }

    if (ui->xEq->isChecked()) {
      ui->xValue->setText(ui->xValue->text() + button->text());
    }

    if (!text.isEmpty()) {
      ui->calcInputExpr->setText(ui->calcInputExpr->text() + text);
    }
  }
}

void s21_CalculatorView::on_AC_clicked() {
  ui->inputWidget->setVisible(true);
  ui->outputWidget->setVisible(false);
  ui->calcInputExpr->setText("");
  ui->xValue->setText("");
  ui->xValue->setVisible(false);
  ui->xEq->setChecked(false);
  ui->xEq->setCheckable(true);
  ui->calcInputExpr->setFocus();
}

void s21_CalculatorView::on_rem_clicked() {
  if (!ui->xEq->isChecked()) {
    ui->calcInputExpr->setText(ui->calcInputExpr->text().chopped(1));
  }

  if (ui->xEq->isChecked() && !ui->xValue->text().isEmpty()) {
    ui->xValue->setText(ui->xValue->text().chopped(1));
  }

  if (ui->xEq->isChecked() && ui->xValue->text().isEmpty()) {
    ui->xValue->setVisible(false);
    ui->calcInputExpr->setFocus();
    ui->xEq->setChecked(false);
  }
}

void s21_CalculatorView::on_xEq_clicked(bool checked) {
  closeMenu();

  if (checked) {
    ui->xValue->setVisible(true);
    ui->xValue->setFocus();
  }

  if (!checked && ui->xValue->text().isEmpty()) {
    ui->xValue->setVisible(false);
    ui->calcInputExpr->setFocus();
  }

  if (!checked) {
    ui->calcInputExpr->setFocus();
  }
}

void s21_CalculatorView::on_sign_clicked() {
  if (ui->xEq->isChecked()) {
    if (ui->xValue->text().isEmpty()) {
      ui->xValue->setText("-");
    } else if (ui->xValue->text() == "-") {
      ui->xValue->clear();
    } else {
      ui->xValue->setText(QString::number(-1 * ui->xValue->text().toDouble()));
    }
  }
}

void s21_CalculatorView::on_equal_clicked() {
  ui->inputWidget->setVisible(false);
  ui->outputWidget->setVisible(true);
  ui->expAfterCalcLabel->setText(ui->calcInputExpr->text());
  ui->xEq->setChecked(false);
  ui->xEq->setCheckable(false);
  ui->calcResult->setStyleSheet("color: rgb(0, 0, 0);");

  std::string expression = ui->calcInputExpr->text().toStdString();
  s21::CalculatorController calculator;
  calculator.setX(ui->xValue->text().toDouble());
  std::string result = calculator.calculate(expression);

  if (calculator.checkErrors()) {
    ui->calcResult->setStyleSheet("color: #FD72B5;");
  }

  ui->calcResult->setText(QString::fromStdString(result));
  ui->calcInputExpr->setFocus();
}
