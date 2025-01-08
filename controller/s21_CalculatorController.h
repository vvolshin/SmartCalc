#ifndef CPP3_SMARTCALC_SRC_CONTROLLER_S21_CALCULATORCONTROLLER_H
#define CPP3_SMARTCALC_SRC_CONTROLLER_S21_CALCULATORCONTROLLER_H

#include "model/s21_Calculator.h"
namespace s21 {
class CalculatorController {
 public:
  CalculatorController() = default;
  ~CalculatorController() = default;

  void setX(double number) noexcept;
  bool checkErrors() const noexcept;
  std::string calculate(std::string expression) noexcept;

 private:
  Calculator calculator_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_SRC_CONTROLLER_S21_CALCULATORCONTROLLER_H
