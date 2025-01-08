#include <gtest/gtest.h>

#include "test_assist.h"

namespace s21 {

/****************************************************************************/
/************************** TOKENIZER TESTS START ***************************/
/****************************************************************************/

TEST(tokenizer, test_1) {
  std::vector<std::string> reference{"5", "*", "(", "3", "+",
                                     "2", ")", "/", "10"};
  std::vector<std::string> result = tokenizer.createTokens("5 *(3 + 2) /10");
  EXPECT_EQ(reference.size(), result.size());
  for (size_t i = 0; i < reference.size(); ++i) {
    EXPECT_EQ(reference[i], result[i]);
  }
}

TEST(tokenizer, test_2) {
  std::vector<std::string> result = tokenizer.createTokens("cos((-3+2)*4^2)");
  std::vector<std::string> reference{"cos", "(", "(", "-", "3", "+", "2",
                                     ")",   "*", "4", "^", "2", ")"};
  EXPECT_EQ(reference.size(), result.size());
  for (size_t i = 0; i < reference.size(); ++i) {
    EXPECT_EQ(reference[i], result[i]);
  }
}

TEST(tokenizer, test_3) {
  std::vector<std::string> result =
      tokenizer.createTokens("sin(pi/2) + exp + 3^2");
  std::vector<std::string> reference{"sin", "(",   "pi", "/", "2", ")",
                                     "+",   "exp", "+",  "3", "^", "2"};
  EXPECT_EQ(reference.size(), result.size());
  for (size_t i = 0; i < reference.size(); ++i) {
    EXPECT_EQ(reference[i], result[i]);
  }
}

TEST(tokenizer, test_4) {
  std::vector<std::string> result = tokenizer.createTokens("30e-10-50.12");
  std::vector<std::string> reference{"30e-10", "-", "50.12"};
  EXPECT_EQ(reference.size(), result.size());
  for (size_t i = 0; i < reference.size(); ++i) {
    EXPECT_EQ(reference[i], result[i]);
  }
}

TEST(tokenizer, test_5) {
  std::vector<std::string> result =
      tokenizer.createTokens("asin(-0.144) + acos(0.144) - atan(1)");
  std::vector<std::string> reference{"asin", "(",    "-", "0.144", ")",
                                     "+",    "acos", "(", "0.144", ")",
                                     "-",    "atan", "(", "1",     ")"};
  EXPECT_EQ(reference.size(), result.size());
  for (size_t i = 0; i < reference.size(); ++i) {
    EXPECT_EQ(reference[i], result[i]);
  }
}

TEST(tokenizer, test_6) {
  std::vector<std::string> result =
      tokenizer.createTokens("log(32) + ln(8) - sqrt(4) * x");
  std::vector<std::string> reference{"log", "(", "32", ")", "+",    "ln",
                                     "(",   "8", ")",  "-", "sqrt", "(",
                                     "4",   ")", "*",  "x"};
  EXPECT_EQ(reference.size(), result.size());
  for (size_t i = 0; i < reference.size(); ++i) {
    EXPECT_EQ(reference[i], result[i]);
  }
}

/****************************************************************************/
/************************** END OF TOKENIZER TESTS **************************/
/****************************************************************************/

}  // namespace s21
