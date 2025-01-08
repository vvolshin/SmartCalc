#include "s21_CalculatorView.h"
#include "ui_s21_CalculatorView.h"

void s21_CalculatorView::setConnections() {
  buttons();
  connectUniqueButtons();
  connect(ui->menuIconClosed, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuIconClosed_clicked);
  connect(ui->menuIconOpen, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuIconOpen_clicked);
  connect(ui->menuRightButtonIconClosed, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuRightButtonIconClosed_clicked);
  connect(ui->menuRightButtonOpenLogo, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuRightButtonOpenLogo_clicked);
  connect(ui->menuRightButtonClose, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuRightButtonClose_clicked);
  connect(ui->menuRightButtonOpen, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuRightButtonOpen_clicked);
  connect(ui->menuCalculator, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuCalculator_clicked);
  connect(ui->menuCredit, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuCredit_clicked);
  connect(ui->menuDeposit, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuDeposit_clicked);
  connect(ui->AC, &QPushButton::clicked, this,
          &s21_CalculatorView::on_AC_clicked);
  connect(ui->rem, &QPushButton::clicked, this,
          &s21_CalculatorView::on_rem_clicked);
  connect(ui->xEq, &QPushButton::clicked, this,
          &s21_CalculatorView::on_xEq_clicked);
  connect(ui->equal, &QPushButton::clicked, this,
          &s21_CalculatorView::on_equal_clicked);
  connect(ui->sign, &QPushButton::clicked, this,
          &s21_CalculatorView::on_sign_clicked);
  connect(ui->redrawButton, &QPushButton::clicked, this,
          &s21_CalculatorView::on_redrawButton_clicked);
  connect(ui->creditCalculateButton, &QPushButton::clicked, this,
          &s21_CalculatorView::on_creditCalculateButton_clicked);
  connect(ui->creditTextExpr, &QLineEdit::textChanged, this,
          &s21_CalculatorView::on_creditTextExpr_textChanged);
  connect(ui->menuCreditCalendarButtonOpen, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuCreditCalendarButtonOpen_clicked);
  connect(ui->menuRightButtonCreditClose, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuRightButtonCreditClose_clicked);
  connect(ui->menuCreditCalendarButtonClosed, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuCreditCalendarButtonClosed_clicked);
  connect(ui->menuRightButtonCreditOpenLogo, &QPushButton::clicked, this,
          &s21_CalculatorView::on_menuRightButtonCreditOpenLogo_clicked);
}

void s21_CalculatorView::buttons() {
  QList<QPushButton*> buttonList = {
      ui->n_0,      ui->n_1,  ui->n_2,      ui->n_3,   ui->n_4,     ui->n_5,
      ui->n_6,      ui->n_7,  ui->n_8,      ui->n_9,   ui->xSymbol, ui->brOpen,
      ui->brClosed, ui->sqrt, ui->plus,     ui->minus, ui->log,     ui->ln,
      ui->sin,      ui->cos,  ui->tan,      ui->asin,  ui->acos,    ui->atan,
      ui->mod,      ui->exp,  ui->eMantisa, ui->coma,  ui->pow};

  for (QPushButton* button : buttonList) {
    connect(button, &QPushButton::clicked, this,
            [=]() { onButtonClicked(button); });
  }
}

void s21_CalculatorView::connectUniqueButtons() {
  connect(ui->pi, &QPushButton::clicked, this,
          [this]() { onButtonClicked(ui->pi, "pi"); });

  connect(ui->div, &QPushButton::clicked, this,
          [this]() { onButtonClicked(ui->div, "/"); });

  connect(ui->mult, &QPushButton::clicked, this,
          [this]() { onButtonClicked(ui->div, "*"); });

  connect(ui->xSquare, &QPushButton::clicked, this,
          [this]() { onButtonClicked(ui->div, "^2"); });
}
