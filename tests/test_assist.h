#ifndef CPP3_S21_SMARTCALC_SRC_TESTS_S21_TEST_ASSIST_H
#define CPP3_S21_SMARTCALC_SRC_TESTS_S21_TEST_ASSIST_H

#include "../model/s21_Model.h"

#define BC_TOL 1e-6
#define CR_TOL 1

namespace s21 {
inline Validator validator;
inline Calculator calculator;
inline Tokenizer tokenizer;

inline std::string unbalancedBrackets = "Error: unbalanced brackets";
inline std::string emptyBrackets = "Error: empty brackets";
inline std::string unknownOperator = "Error: unknown operator";
inline std::string inputOverflow = "Error: input overflow";
inline std::string multipleDecimals = "Error: multiple decimals in a number";
inline std::string missedOperand = "Error: missed operand";
inline std::string wrongX = "Error: wrong x usage";

inline std::string longValidString =
    "11111111111111111111111111111111111111111111111111111111111111111111111111"
    "11111111111111111111111111111111111111111111111111111111111111111111111111"
    "11111111111111111111111111111111111111111111111111111111111111111111111111"
    "111111111111111111111111111111111";
inline std::string longUnvalidString =
    "11111111111111111111111111111111111111111111111111111111111111111111111111"
    "11111111111111111111111111111111111111111111111111111111111111111111111111"
    "11111111111111111111111111111111111111111111111111111111111111111111111111"
    "1111111111111111111111111111111111";
}  // namespace s21

#endif  // CPP3_S21_SMARTCALC_SRC_TESTS_S21_TEST_ASSIST_H
