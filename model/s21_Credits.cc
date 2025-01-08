#include "s21_Credits.h"

namespace s21 {
void Credits::setParams(double loan, size_t period, double interest) {
  loan_ = loan;
  if (loan_ <= 0) {
    isValid_ = false;
    errorMessage_ = "Loan amount must be positive";
    throw std::invalid_argument(errorMessage_);
  }

  period_ = period;
  if (period_ <= 0 || period_ > 600) {
    isValid_ = false;
    errorMessage_ = "Period must be between 1 and 600 months";
    throw std::invalid_argument(errorMessage_);
  }

  interest_ = interest;
  if (interest_ <= 0.01 || interest_ > 100) {
    isValid_ = false;
    errorMessage_ = "Interest rate must be between 0.01 and 100%";
    throw std::invalid_argument(errorMessage_);
  }

  isValid_ = true;
}

void Credits::calculateMonthInerest() noexcept {
  monthInterest_ = (interest_ / 12) / 100;
}

void Credits::calculateMonthPayment() noexcept {
  calculateMonthInerest();
  double annuityCoef = monthInterest_ * pow((1 + monthInterest_), period_) /
                       (pow((1 + monthInterest_), period_) - 1);
  monthPayment_ = annuityCoef * loan_;
}

void Credits::calculateAnnuityPayment() noexcept {
  if (!isValid_) {
    return;
  }

  calculateMonthPayment();
  double balanceOwed = loan_;

  for (size_t i = 0; i < period_; ++i) {
    MonthInfo monthInfo;
    monthInfo.month = i + 1;
    monthInfo.monthPayment = monthPayment_;
    monthInfo.interestPayment = balanceOwed * monthInterest_;
    monthInfo.principalPayment = monthPayment_ - monthInfo.interestPayment;
    monthInfo.balanceOwed = balanceOwed - monthInfo.principalPayment;

    summary_.push_back(monthInfo);
    balanceOwed = monthInfo.balanceOwed;
    totalInterest_ += monthInfo.interestPayment;
    totalPayment_ += monthInfo.monthPayment;
  }
}

void Credits::calculateDifferentialPayment() noexcept {
  if (!isValid_) {
    return;
  }

  calculateMonthInerest();
  for (size_t i = 0; i < period_; ++i) {
    MonthInfo monthInfo;
    monthInfo.month = i + 1;
    monthInfo.principalPayment = loan_ / period_;

    if (i == 0) {
      monthInfo.interestPayment = loan_ * monthInterest_;
      monthInfo.monthPayment =
          monthInfo.principalPayment + monthInfo.interestPayment;
      monthInfo.balanceOwed = loan_ - monthInfo.principalPayment;
    } else {
      monthInfo.interestPayment = summary_[i - 1].balanceOwed * monthInterest_;
      monthInfo.monthPayment =
          monthInfo.principalPayment + monthInfo.interestPayment;
      monthInfo.balanceOwed =
          summary_[i - 1].balanceOwed - monthInfo.principalPayment;
    }

    totalInterest_ += monthInfo.interestPayment;
    totalPayment_ += monthInfo.monthPayment;
    summary_.push_back(monthInfo);
  }
}

double Credits::getTotalPayment() const noexcept { return totalPayment_; }

double Credits::getTotalInterest() const noexcept { return totalInterest_; }

std::string Credits::getMonthPayment() const noexcept {
  size_t last = summary_.size() - 1;
  std::string result;
  if (summary_[0].monthPayment == summary_[last].monthPayment) {
    result = std::to_string(summary_[0].monthPayment);
  } else {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << summary_[0].monthPayment
        << "..." << std::setprecision(2) << summary_[last].monthPayment;
    result = oss.str();
  }
  return result;
}

std::vector<MonthInfo> Credits::getSummaryData() const { return summary_; }

bool Credits::getValidity() const noexcept { return isValid_; }

std::string Credits::getResult() const noexcept {
  if (!isValid_) {
    return errorMessage_;
  }

  std::ostringstream text;

  text << "Month\tPayment\tPrincipal\tInterest\tBalance owed\n";

  for (size_t i = 0; i < period_; i++) {
    text << std::setw(4) << summary_[i].month << "\t";
    text << std::fixed << std::setprecision(2) << std::setw(8)
         << summary_[i].monthPayment << "\t";
    text << std::fixed << std::setprecision(2) << std::setw(8)
         << summary_[i].principalPayment << "\t";
    text << std::fixed << std::setprecision(2) << std::setw(8)
         << summary_[i].interestPayment << "\t";
    text << std::fixed << std::setprecision(2) << std::setw(8)
         << summary_[i].balanceOwed << "\n";
  }

  return text.str();
}
}  // namespace s21
