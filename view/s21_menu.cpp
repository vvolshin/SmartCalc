#include "s21_CalculatorView.h"
#include "ui_s21_CalculatorView.h"

void s21_CalculatorView::setInitialSettings() {
  ui->menuLeftBoxClosed->setVisible(true);
  ui->menuLeftBoxOpen->setVisible(false);
  ui->menuRightBoxClosed->setVisible(false);
  ui->menuRightBoxOpen->setVisible(true);
  ui->menuCreditCalendarOpen->setVisible(false);
  ui->menuCreditCalendarClosed->setVisible(false);
  ui->menuBackToCreditOpen->setVisible(false);
  ui->menuBackToCreditClosed->setVisible(false);
  ui->menuBackToCalculatorOpen->setVisible(false);
  ui->menuBackToCalculatorClosed->setVisible(false);
  ui->calcAreaWidget->setVisible(true);
  ui->xValue->setVisible(false);
  ui->inputWidget->setVisible(true);
  ui->outputWidget->setVisible(false);
  ui->graphAreaWidget->setVisible(false);
  ui->interestTextExpr->setVisible(false);
  ui->creditCalendarTable->setVisible(false);
  ui->depositFiller->setVisible(false);
}

void s21_CalculatorView::closeMenu() {
  ui->menuLeftBoxClosed->setVisible(true);
  ui->menuLeftBoxOpen->setVisible(false);
  ui->menuRightBoxClosed->setVisible(false);
  ui->menuRightBoxOpen->setVisible(true);
}

void s21_CalculatorView::on_menuIconClosed_clicked() {
  ui->menuLeftBoxClosed->setVisible(false);
  ui->menuLeftBoxOpen->setVisible(true);
  ui->menuRightBoxOpen->setVisible(false);
  ui->menuRightBoxClosed->setVisible(true);

  if (ui->menuBackToCalculatorOpen->isVisible()) {
    ui->menuBackToCalculatorOpen->setVisible(false);
    ui->menuRightBoxOpen->setVisible(false);
    ui->menuRightBoxClosed->setVisible(false);
    ui->menuBackToCalculatorClosed->setVisible(true);

    ui->menuCreditCalendarOpen->setVisible(false);
    ui->menuCreditCalendarClosed->setVisible(false);
    ui->menuBackToCreditOpen->setVisible(false);
    ui->menuBackToCreditClosed->setVisible(false);
  }

  if (ui->menuCreditCalendarOpen->isVisible()) {
    ui->menuBackToCalculatorOpen->setVisible(false);
    ui->menuRightBoxOpen->setVisible(false);
    ui->menuRightBoxClosed->setVisible(false);
    ui->menuBackToCalculatorClosed->setVisible(false);

    ui->menuCreditCalendarOpen->setVisible(false);
    ui->menuCreditCalendarClosed->setVisible(true);
    ui->menuBackToCreditOpen->setVisible(false);
    ui->menuBackToCreditClosed->setVisible(false);
  }

  if (ui->menuBackToCreditOpen->isVisible()) {
    ui->menuBackToCreditOpen->setVisible(false);
    ui->menuBackToCreditClosed->setVisible(true);
  }

  if (ui->menuDeposit->isChecked()) {
    ui->menuCalculator->setChecked(false);
    ui->menuCredit->setChecked(false);
    ui->calcAreaWidget->setVisible(false);
    ui->graphAreaWidget->setVisible(false);
    ui->menuBackToCalculatorOpen->setVisible(false);
    ui->menuBackToCalculatorClosed->setVisible(false);
    ui->menuRightBoxClosed->setVisible(false);
    ui->menuRightBoxOpen->setVisible(false);
    ui->menuLeftBoxClosed->setVisible(false);
    ui->menuLeftBoxOpen->setVisible(true);
    ui->creditAreaWidget->setVisible(false);
    ui->menuCreditCalendarOpen->setVisible(false);
    ui->menuCreditCalendarClosed->setVisible(false);
    ui->menuBackToCreditOpen->setVisible(false);
    ui->menuBackToCreditClosed->setVisible(false);
    ui->depositFiller->setVisible(true);
  }
}

void s21_CalculatorView::on_menuIconOpen_clicked() {
  ui->menuLeftBoxClosed->setVisible(true);
  ui->menuLeftBoxOpen->setVisible(false);
  ui->menuRightBoxOpen->setVisible(true);
  ui->menuRightBoxClosed->setVisible(false);

  if (ui->menuBackToCalculatorClosed->isVisible()) {
    ui->menuBackToCalculatorOpen->setVisible(true);
    ui->menuRightBoxOpen->setVisible(false);
    ui->menuRightBoxClosed->setVisible(false);
    ui->menuBackToCalculatorClosed->setVisible(false);
  }

  if (ui->menuCreditCalendarClosed->isVisible()) {
    ui->menuBackToCalculatorOpen->setVisible(false);
    ui->menuRightBoxOpen->setVisible(false);
    ui->menuRightBoxClosed->setVisible(false);
    ui->menuBackToCalculatorClosed->setVisible(false);

    ui->menuCreditCalendarOpen->setVisible(true);
    ui->menuCreditCalendarClosed->setVisible(false);
    ui->menuBackToCreditOpen->setVisible(false);
    ui->menuBackToCreditClosed->setVisible(false);
  }

  if (ui->menuBackToCreditClosed->isVisible()) {
    ui->menuBackToCreditOpen->setVisible(true);
    ui->menuBackToCreditClosed->setVisible(false);
  }

  if (ui->menuDeposit->isChecked()) {
    ui->menuCalculator->setChecked(false);
    ui->menuCredit->setChecked(false);
    ui->calcAreaWidget->setVisible(false);
    ui->graphAreaWidget->setVisible(false);
    ui->menuBackToCalculatorOpen->setVisible(false);
    ui->menuBackToCalculatorClosed->setVisible(false);
    ui->menuRightBoxClosed->setVisible(false);
    ui->menuRightBoxOpen->setVisible(false);
    ui->menuLeftBoxClosed->setVisible(true);
    ui->menuLeftBoxOpen->setVisible(false);
    ui->creditAreaWidget->setVisible(false);
    ui->menuCreditCalendarOpen->setVisible(false);
    ui->menuCreditCalendarClosed->setVisible(false);
    ui->menuBackToCreditOpen->setVisible(false);
    ui->menuBackToCreditClosed->setVisible(false);
    ui->depositFiller->setVisible(true);
  }
}

void s21_CalculatorView::on_menuCalculator_clicked(bool checked) {
  ui->menuCalculator->setChecked(true);

  if (checked) {
    ui->menuCredit->setChecked(false);
    ui->menuDeposit->setChecked(false);
    ui->menuCreditCalendarOpen->setVisible(false);
    ui->menuCreditCalendarClosed->setVisible(false);
    ui->menuBackToCreditOpen->setVisible(false);
    ui->menuBackToCreditClosed->setVisible(false);

    ui->calcAreaWidget->setVisible(true);
    ui->creditAreaWidget->setVisible(false);
    ui->creditCalendarTable->setVisible(false);
    ui->depositFiller->setVisible(false);

    closeMenu();
    ui->menuInfo->setText("Calculator");
    ui->calcInputExpr->setFocus();
  }
}

void s21_CalculatorView::on_menuCredit_clicked(bool checked) {
  ui->menuCredit->setChecked(true);

  if (checked) {
    ui->menuCalculator->setChecked(false);
    ui->menuDeposit->setChecked(false);
    ui->calcAreaWidget->setVisible(false);
    ui->graphAreaWidget->setVisible(false);
    ui->menuBackToCalculatorOpen->setVisible(false);
    ui->menuBackToCalculatorClosed->setVisible(false);
    ui->menuRightBoxClosed->setVisible(false);
    ui->menuRightBoxOpen->setVisible(false);
    ui->menuLeftBoxClosed->setVisible(true);
    ui->menuLeftBoxOpen->setVisible(false);
    ui->menuCreditCalendarClosed->setVisible(false);
    ui->menuBackToCreditOpen->setVisible(false);
    ui->menuBackToCreditClosed->setVisible(false);
    ui->menuInfo->setText("Credit");
    ui->creditAreaWidget->setVisible(true);
    ui->annuityButton->setChecked(true);
    ui->differentialButton->setChecked(false);
    ui->menuCreditCalendarOpen->setVisible(true);
    ui->depositFiller->setVisible(false);
    ui->creditTextExpr->setFocus();
  }
}

void s21_CalculatorView::on_menuDeposit_clicked(bool checked) {
  ui->menuDeposit->setChecked(true);

  if (checked) {
    ui->menuCalculator->setChecked(false);
    ui->menuCredit->setChecked(false);
    ui->calcAreaWidget->setVisible(false);
    ui->graphAreaWidget->setVisible(false);
    ui->menuBackToCalculatorOpen->setVisible(false);
    ui->menuBackToCalculatorClosed->setVisible(false);
    ui->menuRightBoxClosed->setVisible(false);
    ui->menuRightBoxOpen->setVisible(false);
    ui->menuLeftBoxClosed->setVisible(true);
    ui->menuLeftBoxOpen->setVisible(false);
    ui->creditAreaWidget->setVisible(false);
    ui->menuCreditCalendarOpen->setVisible(false);
    ui->menuCreditCalendarClosed->setVisible(false);
    ui->menuBackToCreditOpen->setVisible(false);
    ui->menuBackToCreditClosed->setVisible(false);
    ui->depositFiller->setVisible(true);

    ui->menuInfo->setText("Deposit");
  }
}

void s21_CalculatorView::on_menuRightButtonIconClosed_clicked() {
  ui->menuBackToCalculatorOpen->setVisible(true);
  ui->menuLeftBoxClosed->setVisible(true);
  ui->menuLeftBoxOpen->setVisible(false);
  ui->calcAreaWidget->setVisible(false);
  ui->graphAreaWidget->setVisible(true);
  drawGraph();
  ui->exprForDrawLable->setText(ui->calcInputExpr->text());
}

void s21_CalculatorView::on_menuRightButtonOpenLogo_clicked() {
  ui->calcAreaWidget->setVisible(true);
  setInitialSettings();
}

void s21_CalculatorView::on_menuRightButtonClose_clicked() {
  ui->calcAreaWidget->setVisible(true);
  setInitialSettings();
}

void s21_CalculatorView::on_menuRightButtonOpen_clicked() {
  ui->menuBackToCalculatorOpen->setVisible(true);
  ui->menuLeftBoxClosed->setVisible(true);
  ui->menuLeftBoxOpen->setVisible(false);
  ui->calcAreaWidget->setVisible(false);
  ui->graphAreaWidget->setVisible(true);
  drawGraph();
  ui->exprForDrawLable->setText(ui->calcInputExpr->text());
}

void s21_CalculatorView::on_menuCreditCalendarButtonOpen_clicked() {
  ui->creditAreaWidget->setVisible(false);
  ui->creditCalendarTable->setVisible(true);
  ui->menuCreditCalendarOpen->setVisible(false);
  ui->menuBackToCreditOpen->setVisible(true);
  ui->paymentCalendar->clearContents();
  on_creditCalculateButton_clicked();
}

void s21_CalculatorView::on_menuRightButtonCreditClose_clicked() {
  ui->creditAreaWidget->setVisible(true);
  ui->creditCalendarTable->setVisible(false);
  ui->menuCreditCalendarOpen->setVisible(true);
  ui->menuBackToCreditOpen->setVisible(false);
  on_creditCalculateButton_clicked();
}

void s21_CalculatorView::on_menuCreditCalendarButtonClosed_clicked() {
  ui->menuLeftBoxClosed->setVisible(true);
  ui->menuLeftBoxOpen->setVisible(false);
  ui->creditAreaWidget->setVisible(false);
  ui->creditCalendarTable->setVisible(true);
  ui->menuCreditCalendarOpen->setVisible(false);
  ui->menuBackToCreditOpen->setVisible(true);
  ui->menuCreditCalendarClosed->setVisible(false);
  ui->paymentCalendar->clearContents();
  on_creditCalculateButton_clicked();
}

void s21_CalculatorView::on_menuRightButtonCreditOpenLogo_clicked() {
  ui->menuLeftBoxClosed->setVisible(true);
  ui->menuLeftBoxOpen->setVisible(false);
  ui->menuBackToCreditClosed->setVisible(false);
  ui->creditAreaWidget->setVisible(true);
  ui->creditCalendarTable->setVisible(false);
  ui->menuCreditCalendarOpen->setVisible(true);
  ui->menuBackToCreditOpen->setVisible(false);
  on_creditCalculateButton_clicked();
}
