#include "s21_CalculatorView.h"
#include "ui_s21_CalculatorView.h"

void s21_CalculatorView::setGraphVisual() {
  QLinearGradient plotGradient;
  plotGradient.setColorAt(1, QColor(0, 0, 0));
  ui->graphArea->setBackground(plotGradient);

  QLinearGradient axisRectGradient;
  axisRectGradient.setColorAt(1, QColor(0, 0, 0));
  ui->graphArea->axisRect()->setBackground(axisRectGradient);

  ui->graphArea->xAxis->setTickLabels(false);
  ui->graphArea->xAxis->setTickPen(Qt::NoPen);
  ui->graphArea->yAxis->setTickLabels(false);
  ui->graphArea->yAxis->setTickPen(Qt::NoPen);

  ui->graphArea->xAxis->grid()->setPen(QPen(Qt::transparent));
  ui->graphArea->yAxis->grid()->setPen(QPen(Qt::transparent));

  ui->graphArea->xAxis->grid()->setZeroLinePen(QPen(Qt::white));
  ui->graphArea->yAxis->grid()->setZeroLinePen(QPen(Qt::white));
}

void s21_CalculatorView::drawGraph() {
  x.clear();
  y.clear();
  ui->graphArea->clearGraphs();

  ui->exprForDrawLable->setStyleSheet(
      "background-color: #535353; border-radius: 12px; color: #F5F5F5;");
  ui->exprForDrawLable->setText(ui->calcInputExpr->text());

  h = 0.1;
  xBegin = -10.00;
  xEnd = 10.00;
  yBegin = -10.00;
  yEnd = 10.00;

  ui->xMinSpin->setValue(xBegin);
  ui->xMaxSpin->setValue(xEnd);
  ui->yMinSpin->setValue(yBegin);
  ui->xMaxSpin->setValue(yEnd);

  if (xBegin > xEnd || yBegin > yEnd) {
    ui->exprForDrawLable->setStyleSheet(
        "background-color: #535353; border-radius: 12px; color: #FD72B5;");
    ui->exprForDrawLable->setText("Error");
  }

  ui->graphArea->xAxis->setRange(xBegin, xEnd);
  ui->graphArea->yAxis->setRange(yBegin, yEnd);

  std::string expression = ui->calcInputExpr->text().toStdString();
  s21::Validator validator;
  validator.checkExpression(expression);

  if (!validator.hasError()) {
    for (X = xBegin; X <= xEnd; X += h) {
      x.push_back(X);
      s21::Calculator calculator;
      calculator.setX(X);
      double result = std::stod(calculator.calculate(expression));
      y.push_back(result);
    }

    QPen pen(QColor(0xFD, 0x72, 0xB5));
    pen.setWidth(3);
    ui->graphArea->addGraph();
    ui->graphArea->graph(0)->setPen(pen);
    ui->graphArea->graph(0)->addData(x, y);
  }
  ui->graphArea->replot();
}

void s21_CalculatorView::on_redrawButton_clicked() {
  x.clear();
  y.clear();
  ui->graphArea->clearGraphs();

  ui->exprForDrawLable->setStyleSheet(
      "background-color: #535353; border-radius: 12px; color: #F5F5F5;");
  ui->exprForDrawLable->setText(ui->calcInputExpr->text());

  h = 0.1;
  xBegin = ui->xMinSpin->value();
  xEnd = ui->xMaxSpin->value();
  yBegin = ui->yMinSpin->value();
  yEnd = ui->yMaxSpin->value();

  if (xBegin > xEnd || yBegin > yEnd) {
    ui->exprForDrawLable->setStyleSheet(
        "background-color: #535353; border-radius: 12px; color: #FD72B5;");
    ui->exprForDrawLable->setText("Error");
  }

  ui->graphArea->xAxis->setRange(xBegin, xEnd);
  ui->graphArea->yAxis->setRange(yBegin, yEnd);

  std::string expression = ui->calcInputExpr->text().toStdString();
  s21::Validator validator;
  validator.checkExpression(expression);

  if (!validator.hasError()) {
    for (X = xBegin; X <= xEnd; X += h) {
      x.push_back(X);
      s21::Calculator calculator;
      calculator.setX(X);
      double result = std::stod(calculator.calculate(expression));
      y.push_back(result);
    }

    QPen pen(QColor(0xFD, 0x72, 0xB5));
    pen.setWidth(3);
    ui->graphArea->addGraph();
    ui->graphArea->graph(0)->setPen(pen);
    ui->graphArea->graph(0)->addData(x, y);
  }
  ui->graphArea->replot();
}
