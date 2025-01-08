#ifndef CPP3_SMARTCALC_SRC_CONTROLLER_S21_CREDITSCONTROLLER_H
#define CPP3_SMARTCALC_SRC_CONTROLLER_S21_CREDITSCONTROLLER_H

#include "model/s21_Credits.h"
namespace s21 {
class CreditsController {
 public:
  CreditsController() = default;
  ~CreditsController() = default;

  void setParams(double loan, size_t period, double interest);
  void calculateAnnuityPayment() noexcept;
  void calculateDifferentialPayment() noexcept;
  double getTotalPayment() const noexcept;
  double getTotalInterest() const noexcept;
  std::string getMonthPayment() const noexcept;
  std::vector<MonthInfo> getSummaryData() const;
  std::string getResult() const noexcept;
  bool getValidity() const noexcept;

 private:
  Credits credits_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_SRC_CONTROLLER_S21_CREDITSCONTROLLER_H
