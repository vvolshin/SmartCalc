#include "s21_CalculatorController.h"

namespace s21 {
void CalculatorController::setX(double number) noexcept {
  calculator_.setX(number);
}

bool CalculatorController::checkErrors() const noexcept {
  return calculator_.checkErrors();
}

std::string CalculatorController::calculate(std::string expression) noexcept {
  return calculator_.calculate(expression);
}
}  // namespace s21
