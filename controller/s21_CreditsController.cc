#include "s21_CreditsController.h"

namespace s21 {
void CreditsController::setParams(double loan, size_t period, double interest) {
  credits_.setParams(loan, period, interest);
}

void CreditsController::calculateAnnuityPayment() noexcept {
  credits_.calculateAnnuityPayment();
}

void CreditsController::calculateDifferentialPayment() noexcept {
  credits_.calculateDifferentialPayment();
}

double CreditsController::getTotalPayment() const noexcept {
  return credits_.getTotalPayment();
}

double CreditsController::getTotalInterest() const noexcept {
  return credits_.getTotalInterest();
}

std::string CreditsController::getMonthPayment() const noexcept {
  return credits_.getMonthPayment();
}

std::vector<MonthInfo> CreditsController::getSummaryData() const {
  return credits_.getSummaryData();
}

std::string CreditsController::getResult() const noexcept {
  return credits_.getResult();
}

bool CreditsController::getValidity() const noexcept {
  return credits_.getValidity();
}

}  // namespace s21
