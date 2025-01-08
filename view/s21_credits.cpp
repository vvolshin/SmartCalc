#include "s21_CalculatorView.h"
#include "ui_s21_CalculatorView.h"

void s21_CalculatorView::setCreditValidators() {
  QRegularExpressionValidator* validatorLoanTermLine =
      new QRegularExpressionValidator(QRegularExpression("[0-9]+"), this);
  ui->loanTermLine->setValidator(validatorLoanTermLine);

  QRegularExpressionValidator* validatorInterestRateLine =
      new QRegularExpressionValidator(
          QRegularExpression("[0-9]{1,2}(\\,[0-9]{1,2})?"), this);
  ui->interestRateLine->setValidator(validatorInterestRateLine);

  QRegularExpressionValidator* validatorCreditInputExpr =
      new QRegularExpressionValidator(
          QRegularExpression("[0-9]+(\\,[0-9]{1,2})?"), this);
  ui->creditTextExpr->setValidator(validatorCreditInputExpr);
}

void s21_CalculatorView::on_creditCalculateButton_clicked() {
  if (ui->creditTextExpr->text() == "" || ui->loanTermLine->text() == "" ||
      ui->interestRateLine->text() == "") {
    return;
  }

  s21::CreditsController credits;
  double loan = ui->creditTextExpr->text().toDouble();
  int period = ui->loanTermLine->text().toInt();
  double interest = ui->interestRateLine->text().toDouble();

  try {
    credits.setParams(loan, period, interest);
  } catch (std::exception& e) {
    ui->creditTextExpr->setStyleSheet("color: #FD72B5;");
    ui->creditTextExpr->setText("Error");
    return;
  }

  if (ui->annuityButton->isChecked()) {
    credits.calculateAnnuityPayment();
  }

  if (ui->differentialButton->isChecked()) {
    credits.calculateDifferentialPayment();
  }

  double totalInterest = credits.getTotalInterest();
  totalInterest = std::round(totalInterest * 100) / 100;

  ui->interestTextExpr->setVisible(true);
  ui->interestTextExpr->setText(" +" + QString::number(totalInterest));
  createCreditTable(credits);
}

void s21_CalculatorView::createCreditTable(s21::CreditsController& credits) {
  std::vector<s21::MonthInfo> monthInfoList = credits.getSummaryData();
  ui->paymentCalendar->setRowCount(monthInfoList.size());
  ui->paymentCalendar->setColumnCount(5);
  ui->paymentCalendar->setColumnWidth(0, 52);
  ui->paymentCalendar->setColumnWidth(1, 124);
  ui->paymentCalendar->setColumnWidth(2, 124);
  ui->paymentCalendar->setColumnWidth(3, 124);
  ui->paymentCalendar->setColumnWidth(4, 124);
  ui->paymentCalendar->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->paymentCalendar->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  QHeaderView* header = ui->paymentCalendar->horizontalHeader();
  header->setSectionResizeMode(QHeaderView::Fixed);

  for (int row = 0; row < monthInfoList.size(); ++row) {
    s21::MonthInfo info = monthInfoList[row];

    QTableWidgetItem* itemMonth =
        new QTableWidgetItem(QString::number(info.month));
    QTableWidgetItem* itemPrincipalPayment =
        new QTableWidgetItem(QString::number(info.principalPayment));
    QTableWidgetItem* itemInterestPayment =
        new QTableWidgetItem(QString::number(info.interestPayment));
    QTableWidgetItem* itemBalanceOwed =
        new QTableWidgetItem(QString::number(info.balanceOwed));
    QTableWidgetItem* itemMonthPayment =
        new QTableWidgetItem(QString::number(info.monthPayment));

    ui->paymentCalendar->setItem(row, 0, itemMonth);
    ui->paymentCalendar->setItem(row, 1, itemPrincipalPayment);
    ui->paymentCalendar->setItem(row, 2, itemInterestPayment);
    ui->paymentCalendar->setItem(row, 3, itemBalanceOwed);
    ui->paymentCalendar->setItem(row, 4, itemMonthPayment);

    itemMonth->setTextAlignment(Qt::AlignCenter);
    itemPrincipalPayment->setTextAlignment(Qt::AlignCenter);
    itemInterestPayment->setTextAlignment(Qt::AlignCenter);
    itemBalanceOwed->setTextAlignment(Qt::AlignCenter);
    itemMonthPayment->setTextAlignment(Qt::AlignCenter);
  }
}

void s21_CalculatorView::updateLineEditSize(QLineEdit* lineEdit) {
  QFont font = lineEdit->font();
  font.setPixelSize(32);
  QFontMetrics metrics(font);
  int characterWidth = metrics.horizontalAdvance('A');
  int textWidth = characterWidth * lineEdit->text().size();
  lineEdit->setFixedWidth(textWidth + 20);

  int labelXPos = lineEdit->x() + textWidth;
  ui->interestTextExpr->move(labelXPos, ui->interestTextExpr->y());
}

void s21_CalculatorView::on_creditTextExpr_textChanged(const QString& arg1) {
  if (ui->creditTextExpr->text() == "") {
    ui->creditTextExpr->setStyleSheet(
        "background-color: #F5F5F5;\ncolor: #0E0E0E;");
  }
  updateLineEditSize(ui->creditTextExpr);
  ui->interestTextExpr->setText("");
}
