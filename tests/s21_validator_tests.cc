#include <gtest/gtest.h>

#include "test_assist.h"

namespace s21 {

/****************************************************************************/
/***************************** SIZE TESTS START *****************************/
/****************************************************************************/

TEST(validator, size_longValidString) {
  EXPECT_EQ(validator.checkExpression(longValidString), longValidString);
}

TEST(validator, size_longUnvalidString) {
  EXPECT_EQ(validator.checkExpression(longUnvalidString), inputOverflow);
}

/****************************************************************************/
/************************ VALID OPERATORS TESTS START ***********************/
/****************************************************************************/

TEST(validator, operatorValid_1) {
  EXPECT_EQ(validator.checkExpression("sin(30)"), "sin(30)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_2) {
  EXPECT_EQ(validator.checkExpression("cos(30)"), "cos(30)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_3) {
  EXPECT_EQ(validator.checkExpression("30+x"), "30+x");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_4) {
  EXPECT_EQ(validator.checkExpression("sqrt(8)"), "sqrt(8)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_5) {
  EXPECT_EQ(validator.checkExpression("tan(15)"), "tan(15)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_6) {
  EXPECT_EQ(validator.checkExpression("asin(15)"), "asin(15)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_7) {
  EXPECT_EQ(validator.checkExpression("acos(15)"), "acos(15)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_8) {
  EXPECT_EQ(validator.checkExpression("atan(15)"), "atan(15)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_9) {
  EXPECT_EQ(validator.checkExpression("log(4)"), "log(4)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_10) {
  EXPECT_EQ(validator.checkExpression("ln(8)"), "ln(8)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_11) {
  EXPECT_EQ(validator.checkExpression("pi+exp"), "pi+exp");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_12) {
  EXPECT_EQ(validator.checkExpression("30"), "30");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_13) {
  EXPECT_EQ(validator.checkExpression("30.15"), "30.15");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_14) {
  EXPECT_EQ(validator.checkExpression("30e10"), "30e10");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_15) {
  EXPECT_EQ(validator.checkExpression("30E-10"), "30e-10");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_16) {
  EXPECT_EQ(validator.checkExpression("30+50"), "30+50");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_17) {
  EXPECT_EQ(validator.checkExpression("30.15-50"), "30.15-50");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_18) {
  EXPECT_EQ(validator.checkExpression("30e10*50.12"), "30e10*50.12");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_19) {
  EXPECT_EQ(validator.checkExpression("30e10/50.12"), "30e10/50.12");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_20) {
  EXPECT_EQ(validator.checkExpression("30e10+50.12"), "30e10+50.12");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_21) {
  EXPECT_EQ(validator.checkExpression("30e10/50.12"), "30e10/50.12");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_22) {
  EXPECT_EQ(validator.checkExpression("(30e10^50.12)"), "(30e10^50.12)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_23) {
  EXPECT_EQ(validator.checkExpression("-1+-2*(-3)"), "~1+~2*(~3)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_24) {
  EXPECT_EQ(validator.checkExpression(" -1 + 2 * (-3) "), "~1+2*(~3)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_25) {
  EXPECT_EQ(validator.checkExpression("sin(30)"), "sin(30)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, operatorValid_26) {
  EXPECT_EQ(validator.checkExpression("30*(50-sin(30))"), "30*(50-sin(30))");
  EXPECT_FALSE(validator.hasError());
}

/****************************************************************************/
/*************************** BRACKETS TESTS START ***************************/
/****************************************************************************/

TEST(validator, unbalancedBrackets_1) {
  EXPECT_EQ(validator.checkExpression("(30))"), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unbalancedBrackets_2) {
  EXPECT_EQ(validator.checkExpression("30)"), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unbalancedBrackets_3) {
  EXPECT_EQ(validator.checkExpression("(30"), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unbalancedBrackets_4) {
  EXPECT_EQ(validator.checkExpression("2*(3+4"), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unbalancedBrackets_5) {
  EXPECT_EQ(validator.checkExpression("2*3+4)"), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unbalancedBrackets_6) {
  EXPECT_EQ(validator.checkExpression(")("), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unbalancedBrackets_7) {
  EXPECT_EQ(validator.checkExpression(")+("), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unbalancedBrackets_8) {
  EXPECT_EQ(validator.checkExpression("1+2)(1"), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unbalancedBrackets_9) {
  EXPECT_EQ(validator.checkExpression("1+2)+(1"), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unbalancedBrackets_11) {
  EXPECT_EQ(validator.checkExpression("((30)"), unbalancedBrackets);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, emptyBrackets) {
  EXPECT_EQ(validator.checkExpression("()"), emptyBrackets);
  EXPECT_TRUE(validator.hasError());
}

/****************************************************************************/
/*************************** OPERATORS TESTS START **************************/
/****************************************************************************/

TEST(validator, unknownOperator_1) {
  EXPECT_EQ(validator.checkExpression("si(30)"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_2) {
  EXPECT_EQ(validator.checkExpression("coscos(30)"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_3) {
  EXPECT_EQ(validator.checkExpression("30e10$50.12"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_4) {
  EXPECT_EQ(validator.checkExpression("tan5"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_5) {
  EXPECT_EQ(validator.checkExpression("sqrtx"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_6) {
  EXPECT_EQ(validator.checkExpression("tg(9.87654321)"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_7) {
  EXPECT_EQ(validator.checkExpression("2+sqrttan(9.87654321)"),
            unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_8) {
  EXPECT_EQ(validator.checkExpression(".1"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_9) {
  EXPECT_EQ(validator.checkExpression("-1."), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_10) {
  EXPECT_EQ(validator.checkExpression("-1."), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_11) {
  EXPECT_EQ(validator.checkExpression("-.1"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_12) {
  EXPECT_EQ(validator.checkExpression(".12345+9.87654321"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_13) {
  EXPECT_EQ(validator.checkExpression("0.12345+.87654321"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_14) {
  EXPECT_EQ(validator.checkExpression("sinx"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_15) {
  EXPECT_EQ(validator.checkExpression("sin x"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_16) {
  EXPECT_EQ(validator.checkExpression("sin1"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_17) {
  EXPECT_EQ(validator.checkExpression("sin.1"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_18) {
  EXPECT_EQ(validator.checkExpression("sincos(2)"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_19) {
  EXPECT_EQ(validator.checkExpression("+1."), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_20) {
  EXPECT_EQ(validator.checkExpression("+.1"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_21) {
  EXPECT_EQ(validator.checkExpression("1."), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, unknownOperator_22) {
  EXPECT_EQ(validator.checkExpression("1.5e-5e6"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

/****************************************************************************/
/************************ MISSED OPERAND TESTS START ************************/
/****************************************************************************/

TEST(validator, missedOperand_1) {
  EXPECT_EQ(validator.checkExpression("(4.545-7.56)2"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, missedOperand_2) {
  EXPECT_EQ(validator.checkExpression("1000-7(4.545-7.56)"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, missedOperand_3) {
  EXPECT_EQ(validator.checkExpression("(*)"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, missedOperand_4) {
  EXPECT_EQ(validator.checkExpression("2^^3"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, missedOperand_5) {
  EXPECT_EQ(validator.checkExpression("1+(*3)"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, missedOperand_6) {
  EXPECT_EQ(validator.checkExpression("1+(*3)"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, missedOperand_7) {
  EXPECT_EQ(validator.checkExpression("(4.545-7.56)sin(12)"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, missedOperand_8) {
  EXPECT_EQ(validator.checkExpression("3^"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, missedOperand_9) {
  EXPECT_EQ(validator.checkExpression("(1000-7/)"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, missedOperand_10) {
  EXPECT_EQ(validator.checkExpression("mod(2)"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

/****************************************************************************/
/***************************** MOD TESTS START ******************************/
/****************************************************************************/

TEST(validator, mod_1) {
  EXPECT_EQ(validator.checkExpression("7.77modsin(666)"), "7.77%sin(666)");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, mod_2) {
  EXPECT_EQ(validator.checkExpression("17mod-3"), "17%~3");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, mod_3) {
  EXPECT_EQ(validator.checkExpression("5mod3"), "5%3");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, mod_4) {
  EXPECT_EQ(validator.checkExpression("xmodx"), "x%x");
  EXPECT_FALSE(validator.hasError());
}

TEST(validator, mod_5) {
  EXPECT_EQ(validator.checkExpression("x mod"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, mod_6) {
  EXPECT_EQ(validator.checkExpression("mod"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, mod_7) {
  EXPECT_EQ(validator.checkExpression("mod 5"), missedOperand);
  EXPECT_TRUE(validator.hasError());
}

/****************************************************************************/
/*************************** WRONG X TESTS START ****************************/
/****************************************************************************/

TEST(validator, xError_1) {
  EXPECT_EQ(validator.checkExpression("xx"), wrongX);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, xError_2) {
  EXPECT_EQ(validator.checkExpression("x1"), wrongX);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, xError_3) {
  EXPECT_EQ(validator.checkExpression("1x"), wrongX);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, xError_4) {
  EXPECT_EQ(validator.checkExpression("0.50x+2"), wrongX);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, xError_5) {
  EXPECT_EQ(validator.checkExpression("1.x"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, xError_6) {
  EXPECT_EQ(validator.checkExpression("x.1"), unknownOperator);
  EXPECT_TRUE(validator.hasError());
}

/****************************************************************************/
/********************** MULTIPLE DECIMALS TESTS START ***********************/
/****************************************************************************/

TEST(validator, multipleDecimals_1) {
  EXPECT_EQ(validator.checkExpression("0.25.1*6"), multipleDecimals);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, multipleDecimals_2) {
  EXPECT_EQ(validator.checkExpression("1..1*6"), multipleDecimals);
  EXPECT_TRUE(validator.hasError());
}

TEST(validator, multipleDecimals_3) {
  EXPECT_EQ(validator.checkExpression("10.15.25"), multipleDecimals);
  EXPECT_TRUE(validator.hasError());
}

/****************************************************************************/
/************************** END OF VALIDATOR TESTS **************************/
/****************************************************************************/

}  // namespace s21
