#include <gtest/gtest.h>

#include "test_assist.h"

namespace s21 {

/****************************************************************************/
/********************* INCOME ERROR MESSAGE TESTS START *********************/
/****************************************************************************/

TEST(calculate, unbalancedBrackets) {
  EXPECT_EQ(calculator.calculate("((30)"), unbalancedBrackets);
}

TEST(calculate, emptyBrackets) {
  EXPECT_EQ(calculator.calculate("()"), emptyBrackets);
}

TEST(calculate, multipleDecimals) {
  EXPECT_EQ(calculator.calculate("10.15.25"), multipleDecimals);
}

TEST(calculate, unknownOperator) {
  EXPECT_EQ(calculator.calculate("coscos(30)"), unknownOperator);
}

TEST(calculate, wrongX) { EXPECT_EQ(calculator.calculate("xx"), wrongX); }

TEST(calculate, inputOverflow) {
  EXPECT_EQ(calculator.calculate(longUnvalidString), inputOverflow);
}

/****************************************************************************/
/************************ WORKING CASES TESTS START *************************/
/****************************************************************************/

/********************************* GENERAL **********************************/

TEST(calculate, case_1) {
  double ref = 5 * (3 + 2) / 10.0;
  EXPECT_NEAR(std::stod(calculator.calculate("5 * (3 + 2) / 10")), ref, BC_TOL);
}

TEST(calculate, case_2) {
  double ref = -3 + 2 * std::pow(4, 2);
  EXPECT_NEAR(std::stod(calculator.calculate("-3 + 2 * 4 ^ 2")), ref, BC_TOL);
}

TEST(calculate, case_3) {
  double ref = -1 + 2;
  EXPECT_NEAR(std::stod(calculator.calculate("-1+2")), ref, BC_TOL);
}

TEST(calculate, case_4) {
  double ref = std::sin(30);
  EXPECT_NEAR(std::stod(calculator.calculate("sin(30)")), ref, BC_TOL);
}

TEST(calculate, case_5) {
  double ref = std::sin(M_PI / 2) + 4.12 + std::pow(3, 2);
  EXPECT_NEAR(std::stod(calculator.calculate("sin(pi/2) + 4.12 + 3^2")), ref,
              BC_TOL);
}

TEST(calculate, case_6) {
  double ref = std::cos((-3 + 2) * std::pow(4, 2));
  EXPECT_NEAR(std::stod(calculator.calculate("cos((-3+2)*4^2)")), ref, BC_TOL);
}

TEST(calculate, case_7) {
  double ref = std::sin(M_PI / 2) + M_E + std::pow(3, 2);
  EXPECT_NEAR(std::stod(calculator.calculate("sin(pi/2) + exp + 3^2")), ref,
              BC_TOL);
}

TEST(calculate, case_8) {
  double ref = std::pow(4, 2) - std::fmod(3, 4) - std::tan(0.444);
  EXPECT_NEAR(std::stod(calculator.calculate("4 ^ 2 - 3 mod 4 - tan(0.444)")),
              ref, BC_TOL);
}

TEST(calculate, case_9) {
  double ref = 30e-2 - 50.12;
  EXPECT_NEAR(std::stod(calculator.calculate("(30e-2-50.12)")), ref, BC_TOL);
}

TEST(calculate, case_10) {
  double ref = (-1 + 2) - 3;
  EXPECT_NEAR(std::stod(calculator.calculate("(-1+2) - 3")), ref, BC_TOL);
}

TEST(calculate, case_11) {
  double ref = std::asin(-0.144) + std::acos(0.144) - std::atan(1);
  EXPECT_NEAR(
      std::stod(calculator.calculate("asin(-0.144) + acos(0.144) - atan(1)")),
      ref, BC_TOL);
}

TEST(calculate, case_12) {
  double ref = -4 + -5;
  EXPECT_EQ(std::stod(calculator.calculate("-4+-5")), ref);
}

TEST(calculate, case_13) {
  double ref = 1 + (5 + (-23));
  EXPECT_EQ(std::stod(calculator.calculate("1+(5+(-23))")), ref);
}

TEST(calculate, case_14) {
  double ref = std::pow(4, std::pow(3, 2));
  EXPECT_EQ(std::stod(calculator.calculate("4^3^2")), ref);
}

/********************************* WITH X ***********************************/

TEST(calculate, xCase_1) {
  double x = -1;
  double ref = 45 * std::pow(x, 2) + 500;

  calculator.setX(x);
  EXPECT_EQ(std::stod(calculator.calculate("45 * x^2 + 500")), ref);
}

TEST(calculate, xCase_2) {
  double x = 2;
  double ref = std::log10(32) + std::log(8) - std::sqrt(4) * x;

  calculator.setX(x);
  EXPECT_NEAR(std::stod(calculator.calculate("log(32) + ln(8) - sqrt(4) * x")),
              ref, BC_TOL);
}

TEST(calculate, xCase_3) {
  double x = 2;
  double ref = std::sin(x);

  calculator.setX(x);
  EXPECT_NEAR(std::stod(calculator.calculate("sin(x)")), ref, BC_TOL);
}

TEST(calculate, xCase_4) {
  double x = 1.124;
  double ref =
      std::sin(std::sin(std::sin(std::sin(1.0 / std::log(std::pow(x, 123))))));

  calculator.setX(x);
  EXPECT_NEAR(
      std::stod(calculator.calculate("sin(sin(sin(sin(1.0/ln(x^123)))))")), ref,
      BC_TOL);
}

/********************************** MOD *************************************/

TEST(calculate, modCase_1) {
  double ref = std::fmod(7.77, std::sin(666));
  EXPECT_NEAR(std::stod(calculator.calculate("7.77modsin(666)")), ref, BC_TOL);
}

TEST(calculate, modCase_2) {
  double ref = std::fmod(17, -3);
  EXPECT_NEAR(std::stod(calculator.calculate("17mod-3")), ref, BC_TOL);
}

TEST(calculate, modCase_3) {
  double ref = std::fmod(5, 3);
  EXPECT_NEAR(std::stod(calculator.calculate("5mod3")), ref, BC_TOL);
}

TEST(calculate, modCase_4) {
  double x = 4;
  double ref = std::fmod(x, x);

  calculator.setX(x);
  EXPECT_NEAR(std::stod(calculator.calculate("xmodx")), ref, BC_TOL);
}

/****************************************************************************/
/************************* END OF CALCULATOR TESTS **************************/
/****************************************************************************/

}  // namespace s21
