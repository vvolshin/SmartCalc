#include <gtest/gtest.h>

#include "test_assist.h"

namespace s21 {

/****************************************************************************/
/************************ WORKING CASES TESTS START *************************/
/****************************************************************************/

/********************************* ANNUITY **********************************/

TEST(credits, annuityPayment) {
  Credits credits;
  credits.setParams(100000, 12, 5);
  credits.calculateAnnuityPayment();

  credits.getResult();

  EXPECT_NEAR(std::stod(credits.getMonthPayment()), 8560.75, CR_TOL);
  EXPECT_NEAR(credits.getTotalInterest(), 2729, CR_TOL);
  EXPECT_NEAR(credits.getTotalPayment(), 102729, CR_TOL);

  std::vector<MonthInfo> monthlyResults = credits.getSummaryData();
  EXPECT_EQ(monthlyResults[0].month, 1);
  EXPECT_NEAR(monthlyResults[0].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[0].principalPayment, 8144.08, CR_TOL);
  EXPECT_NEAR(monthlyResults[0].interestPayment, 416.67, CR_TOL);
  EXPECT_NEAR(monthlyResults[0].balanceOwed, 91855.92, CR_TOL);

  EXPECT_EQ(monthlyResults[1].month, 2);
  EXPECT_NEAR(monthlyResults[1].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[1].principalPayment, 8178.02, CR_TOL);
  EXPECT_NEAR(monthlyResults[1].interestPayment, 382.73, CR_TOL);
  EXPECT_NEAR(monthlyResults[1].balanceOwed, 83677.90, CR_TOL);

  EXPECT_EQ(monthlyResults[2].month, 3);
  EXPECT_NEAR(monthlyResults[2].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[2].principalPayment, 8212.09, CR_TOL);
  EXPECT_NEAR(monthlyResults[2].interestPayment, 348.66, CR_TOL);
  EXPECT_NEAR(monthlyResults[2].balanceOwed, 75465.81, CR_TOL);

  EXPECT_EQ(monthlyResults[3].month, 4);
  EXPECT_NEAR(monthlyResults[3].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[3].principalPayment, 8246.31, CR_TOL);
  EXPECT_NEAR(monthlyResults[3].interestPayment, 314.44, CR_TOL);
  EXPECT_NEAR(monthlyResults[3].balanceOwed, 67219.50, CR_TOL);

  EXPECT_EQ(monthlyResults[4].month, 5);
  EXPECT_NEAR(monthlyResults[4].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[4].principalPayment, 8280.67, CR_TOL);
  EXPECT_NEAR(monthlyResults[4].interestPayment, 280.08, CR_TOL);
  EXPECT_NEAR(monthlyResults[4].balanceOwed, 58938.83, CR_TOL);

  EXPECT_EQ(monthlyResults[5].month, 6);
  EXPECT_NEAR(monthlyResults[5].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[5].principalPayment, 8315.17, CR_TOL);
  EXPECT_NEAR(monthlyResults[5].interestPayment, 245.58, CR_TOL);
  EXPECT_NEAR(monthlyResults[5].balanceOwed, 50623.66, CR_TOL);

  EXPECT_EQ(monthlyResults[6].month, 7);
  EXPECT_NEAR(monthlyResults[6].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[6].principalPayment, 8349.82, CR_TOL);
  EXPECT_NEAR(monthlyResults[6].interestPayment, 210.93, CR_TOL);
  EXPECT_NEAR(monthlyResults[6].balanceOwed, 42273.9, CR_TOL);

  EXPECT_EQ(monthlyResults[7].month, 8);
  EXPECT_NEAR(monthlyResults[7].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[7].principalPayment, 8384.61, CR_TOL);
  EXPECT_NEAR(monthlyResults[7].interestPayment, 176.14, CR_TOL);
  EXPECT_NEAR(monthlyResults[7].balanceOwed, 33889.23, CR_TOL);

  EXPECT_EQ(monthlyResults[8].month, 9);
  EXPECT_NEAR(monthlyResults[8].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[8].principalPayment, 8419.54, CR_TOL);
  EXPECT_NEAR(monthlyResults[8].interestPayment, 141.21, CR_TOL);
  EXPECT_NEAR(monthlyResults[8].balanceOwed, 25469.69, CR_TOL);

  EXPECT_EQ(monthlyResults[9].month, 10);
  EXPECT_NEAR(monthlyResults[9].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[9].principalPayment, 8454.61, CR_TOL);
  EXPECT_NEAR(monthlyResults[9].interestPayment, 106.14, CR_TOL);
  EXPECT_NEAR(monthlyResults[9].balanceOwed, 17015.06, CR_TOL);

  EXPECT_EQ(monthlyResults[10].month, 11);
  EXPECT_NEAR(monthlyResults[10].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[10].principalPayment, 8489.85, CR_TOL);
  EXPECT_NEAR(monthlyResults[10].interestPayment, 70.90, CR_TOL);
  EXPECT_NEAR(monthlyResults[10].balanceOwed, 8525.21, CR_TOL);

  EXPECT_EQ(monthlyResults[11].month, 12);
  EXPECT_NEAR(monthlyResults[11].monthPayment, 8560.75, CR_TOL);
  EXPECT_NEAR(monthlyResults[11].principalPayment, 8525.23, CR_TOL);
  EXPECT_NEAR(monthlyResults[11].interestPayment, 35.52, CR_TOL);
  EXPECT_NEAR(monthlyResults[11].balanceOwed, -0.02, CR_TOL);
}

/****************************** DIFFERENTIAL ********************************/

TEST(credits, differentialPayment) {
  Credits credits;
  credits.setParams(100000, 12, 5);
  credits.calculateDifferentialPayment();

  credits.getResult();

  EXPECT_EQ(credits.getMonthPayment(), "8750.00...8368.06");
  EXPECT_NEAR(credits.getTotalInterest(), 2708.33, CR_TOL);
  EXPECT_NEAR(credits.getTotalPayment(), 102708.33, CR_TOL);

  std::vector<MonthInfo> monthlyResults = credits.getSummaryData();
  EXPECT_EQ(monthlyResults[0].month, 1);
  EXPECT_NEAR(monthlyResults[0].monthPayment, 8750.00, CR_TOL);
  EXPECT_NEAR(monthlyResults[0].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[0].interestPayment, 416.67, CR_TOL);
  EXPECT_NEAR(monthlyResults[0].balanceOwed, 91666.67, CR_TOL);

  EXPECT_EQ(monthlyResults[1].month, 2);
  EXPECT_NEAR(monthlyResults[1].monthPayment, 8715.28, CR_TOL);
  EXPECT_NEAR(monthlyResults[1].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[1].interestPayment, 381.94, CR_TOL);
  EXPECT_NEAR(monthlyResults[1].balanceOwed, 83333.33, CR_TOL);

  EXPECT_EQ(monthlyResults[2].month, 3);
  EXPECT_NEAR(monthlyResults[2].monthPayment, 8680.56, CR_TOL);
  EXPECT_NEAR(monthlyResults[2].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[2].interestPayment, 347.22, CR_TOL);
  EXPECT_NEAR(monthlyResults[2].balanceOwed, 75000.00, CR_TOL);

  EXPECT_EQ(monthlyResults[3].month, 4);
  EXPECT_NEAR(monthlyResults[3].monthPayment, 8645.83, CR_TOL);
  EXPECT_NEAR(monthlyResults[3].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[3].interestPayment, 312.50, CR_TOL);
  EXPECT_NEAR(monthlyResults[3].balanceOwed, 66666.67, CR_TOL);

  EXPECT_EQ(monthlyResults[4].month, 5);
  EXPECT_NEAR(monthlyResults[4].monthPayment, 8611.11, CR_TOL);
  EXPECT_NEAR(monthlyResults[4].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[4].interestPayment, 277.78, CR_TOL);
  EXPECT_NEAR(monthlyResults[4].balanceOwed, 58333.33, CR_TOL);

  EXPECT_EQ(monthlyResults[5].month, 6);
  EXPECT_NEAR(monthlyResults[5].monthPayment, 8576.39, CR_TOL);
  EXPECT_NEAR(monthlyResults[5].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[5].interestPayment, 243.06, CR_TOL);
  EXPECT_NEAR(monthlyResults[5].balanceOwed, 50000.00, CR_TOL);

  EXPECT_EQ(monthlyResults[6].month, 7);
  EXPECT_NEAR(monthlyResults[6].monthPayment, 8541.67, CR_TOL);
  EXPECT_NEAR(monthlyResults[6].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[6].interestPayment, 208.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[6].balanceOwed, 41666.67, CR_TOL);

  EXPECT_EQ(monthlyResults[7].month, 8);
  EXPECT_NEAR(monthlyResults[7].monthPayment, 8506.94, CR_TOL);
  EXPECT_NEAR(monthlyResults[7].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[7].interestPayment, 173.61, CR_TOL);
  EXPECT_NEAR(monthlyResults[7].balanceOwed, 33333.33, CR_TOL);

  EXPECT_EQ(monthlyResults[8].month, 9);
  EXPECT_NEAR(monthlyResults[8].monthPayment, 8472.22, CR_TOL);
  EXPECT_NEAR(monthlyResults[8].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[8].interestPayment, 138.89, CR_TOL);
  EXPECT_NEAR(monthlyResults[8].balanceOwed, 25000.00, CR_TOL);

  EXPECT_EQ(monthlyResults[9].month, 10);
  EXPECT_NEAR(monthlyResults[9].monthPayment, 8437.50, CR_TOL);
  EXPECT_NEAR(monthlyResults[9].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[9].interestPayment, 104.17, CR_TOL);
  EXPECT_NEAR(monthlyResults[9].balanceOwed, 16666.67, CR_TOL);

  EXPECT_EQ(monthlyResults[10].month, 11);
  EXPECT_NEAR(monthlyResults[10].monthPayment, 8402.78, CR_TOL);
  EXPECT_NEAR(monthlyResults[10].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[10].interestPayment, 69.44, CR_TOL);
  EXPECT_NEAR(monthlyResults[10].balanceOwed, 8333.33, CR_TOL);

  EXPECT_EQ(monthlyResults[11].month, 12);
  EXPECT_NEAR(monthlyResults[11].monthPayment, 8368.06, CR_TOL);
  EXPECT_NEAR(monthlyResults[11].principalPayment, 8333.33, CR_TOL);
  EXPECT_NEAR(monthlyResults[11].interestPayment, 34.72, CR_TOL);
  EXPECT_NEAR(monthlyResults[11].balanceOwed, 0.00, CR_TOL);
}

/****************************************************************************/
/********************* INCOME ERROR MESSAGE TESTS START *********************/
/****************************************************************************/

TEST(credits, wrongLoanAmount) {
  Credits credits;
  EXPECT_THROW(credits.setParams(-100000, -12, -5), std::invalid_argument);
  EXPECT_EQ(credits.getResult(), "Loan amount must be positive");

  credits.calculateAnnuityPayment();
  credits.calculateDifferentialPayment();
  EXPECT_FALSE(credits.getValidity());
}

TEST(credits, wrongPeriod) {
  Credits credits;
  EXPECT_THROW(credits.setParams(100000, -12, -5), std::invalid_argument);
  EXPECT_EQ(credits.getResult(), "Period must be between 1 and 600 months");

  credits.calculateAnnuityPayment();
  credits.calculateDifferentialPayment();
  EXPECT_FALSE(credits.getValidity());
}

TEST(credits, wrongInterestRate) {
  Credits credits;
  EXPECT_THROW(credits.setParams(100000, 12, -5), std::invalid_argument);
  EXPECT_EQ(credits.getResult(), "Interest rate must be between 0.01 and 100%");

  credits.calculateAnnuityPayment();
  credits.calculateDifferentialPayment();
  EXPECT_FALSE(credits.getValidity());
}

/****************************************************************************/
/*************************** END OF CREDITS TESTS ***************************/
/****************************************************************************/

}  // namespace s21
