#include "s21_Validator.h"

namespace s21 {
ValidatorResults Validator::validateSize() const noexcept {
  if (expression_.size() > MAX_EXPRESSION_LENGTH) {
    return INPUT_OVERFLOW;
  }
  return VALID;
}

void Validator::removeSpaces() noexcept {
  std::string tmp;
  for (size_t i = 0; i < expression_.size(); i++) {
    if (expression_[i] != ' ') {
      tmp += expression_[i];
    }
  }
  expression_ = tmp;
}

void Validator::transformToLowerCase() noexcept {
  std::transform(expression_.begin(), expression_.end(), expression_.begin(),
                 ::tolower);
}

void Validator::transformUnaryMinus() noexcept {
  std::string tmp;
  bool prevWasOperator = true;
  for (size_t i = 0; i < expression_.size(); i++) {
    if (expression_[i] == '-' &&
        (i == 0 || expression_[i - 1] == '(' || prevWasOperator)) {
      tmp += "~";
    } else if ((i + 2 < expression_.size() &&
                strncmp(expression_.c_str() + i, "mod", 3) == 0 &&
                i + 3 < expression_.size() && expression_[i + 3] == '-')) {
      tmp += "mod~";
      i += 3;
    } else {
      tmp += expression_[i];
    }

    prevWasOperator = (operatorPriority.find(std::string(1, expression_[i])) !=
                       operatorPriority.end());
  }
  expression_ = tmp;
}

void Validator::transformMod() noexcept {
  std::string modToken = "mod";
  size_t pos = 0;
  while ((pos = expression_.find(modToken, pos)) != std::string::npos) {
    expression_.replace(pos, modToken.length(), "%");
    pos += 1;
  }
}

ValidatorResults Validator::validateBrackets() const noexcept {
  std::stack<char> bracketsStack;

  for (size_t i = 0; i < expression_.size(); i++) {
    if (expression_[i] == '(') {
      if (i < expression_.size() - 1 && expression_[i + 1] == ')') {
        return EMPTY_BRACKETS;
      } else {
        bracketsStack.push('(');
      }
    } else if (expression_[i] == ')') {
      if (bracketsStack.empty() || bracketsStack.top() != '(') {
        return UNBALANCED_BRACKETS;
      } else {
        bracketsStack.pop();
      }
    }
  }

  if (!bracketsStack.empty()) {
    return UNBALANCED_BRACKETS;
  }

  return VALID;
}

ValidatorResults Validator::validateMultipleDecimals() const noexcept {
  for (size_t i = 0; i < expression_.size(); i++) {
    if (expression_[i] == '.') {
      int j = i - 1;
      while (j >= 0 && isdigit(expression_[j])) {
        j--;
      }
      if (j >= 0 && expression_[j] == '.') {
        return MULTIPLE_DECIMALS;
      }
    }
  }
  return VALID;
}

ValidatorResults Validator::validateUnapprovedOperators() noexcept {
  std::string approvedOperators =
      "x|sqrt\\(|sin\\(|cos\\(|tan\\(|asin\\(|acos\\(|atan\\(|log\\(|ln\\(|pi|"
      "exp";  // pow
  std::string approvedOperations = "\\+|\\-|\\*|/|\\^|\\(|\\)|~|\\%";
  std::string approvedFloatNumbers =
      "[+-]?(0|[1-9][0-9]*)(\\.(?=\\d)\\d+)?([eE][+-]?\\d+)?";

  std::regex validExpressionRegex("(" + approvedOperators + "|" +
                                  approvedFloatNumbers + "|" +
                                  approvedOperations + ")+");

  if (!std::regex_match(expression_, validExpressionRegex)) {
    return UNKNOWN_OPERATOR;
  }
  return VALID;
}

bool Validator::isSimpleOperator(char symbol) const noexcept {
  return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
          symbol == '^');
}

ValidatorResults Validator::checkOperands() const noexcept {
  size_t last = expression_.size();
  char lastSymbol = (last > 0) ? expression_[last - 1] : '\0';

  for (size_t i = 0; i < last; ++i) {
    char currentSymbol = expression_[i];
    char prevSymbol = (i > 0) ? expression_[i - 1] : '\0';
    char nextSymbol = (i < last) ? expression_[i + 1] : '\0';

    // если в начале строки стоят операторы +-*/^
    if (i == 0 && isSimpleOperator(currentSymbol) && currentSymbol != '~') {
      return MISSED_OPERAND;
    }
    // если после оператора стоит конец строки, например "3^"
    if (isSimpleOperator(currentSymbol) && nextSymbol == '\0') {
      return MISSED_OPERAND;
    }
    // если строка заканчивается на символе (кроме х)
    if (isalpha(lastSymbol) &&
        !(lastSymbol == 'x' || lastSymbol == 'i' || lastSymbol == 'p')) {
      return MISSED_OPERAND;
    }
    // если идут несколько операторов подряд, например: "2^^3"
    if (isSimpleOperator(currentSymbol) &&
        (isSimpleOperator(prevSymbol) || isSimpleOperator(nextSymbol))) {
      return MISSED_OPERAND;
    }
    // если перед '(' стоит число, например: "45(23)"
    if (currentSymbol == '(' && isdigit(prevSymbol)) {
      return MISSED_OPERAND;
    }
    // если после '(' стоит оператор, например: "1+(*3)"
    if (currentSymbol == '(' && isSimpleOperator(nextSymbol)) {
      return MISSED_OPERAND;
    }
    // если перед ')' не стоит число или другая ')', например: "(5+(-23))"
    if (currentSymbol == ')' &&
        (i == 0 ||
         (!isdigit(prevSymbol) && prevSymbol != ')' && prevSymbol != 'x'))) {
      return MISSED_OPERAND;
    }
    // если после ')' не стоит простой оператор или другая ')' или конец строки
    if (currentSymbol == ')' && !(isSimpleOperator(nextSymbol) ||
                                  nextSymbol == '\0' || nextSymbol == ')')) {
      return MISSED_OPERAND;
    }
    // если перед '%'-mod стоит не число, не 'x' и не ')'
    if (currentSymbol == '%' &&
        (!isdigit(prevSymbol) && prevSymbol != 'x' && prevSymbol != ')')) {
      return MISSED_OPERAND;
    }
    // если '%'-mod стоит в конце или в начале строки
    if (lastSymbol == '%' || expression_[0] == '%') {
      return MISSED_OPERAND;
    }
  }

  return VALID;
}

ValidatorResults Validator::xUsageCheck() const noexcept {
  for (size_t i = 0; i < expression_.size(); ++i) {
    // если стоит несколько х подряд без операторов
    if (expression_[i] == 'x' && expression_[i + 1] == 'x') {
      return WRONG_X_USAGE;
    }

    // если вокруг х есть другие числа без операторов
    if (expression_[i] == 'x' &&
        (isdigit(expression_[i + 1]) || isdigit(expression_[i - 1]))) {
      return WRONG_X_USAGE;
    }
  }
  return VALID;
}

ValidatorResults Validator::validateExpression() noexcept {
  ValidatorResults result;

  result = validateSize();
  if (result != VALID) return result;

  removeSpaces();
  transformToLowerCase();
  transformUnaryMinus();
  transformMod();

  result = validateBrackets();
  if (result != VALID) return result;

  result = validateMultipleDecimals();
  if (result != VALID) return result;

  result = xUsageCheck();
  if (result != VALID) return result;

  result = validateUnapprovedOperators();
  if (result != VALID) return result;

  result = checkOperands();
  if (result != VALID) return result;

  return VALID;
}

std::string Validator::getErrorMessage(ValidatorResults result) noexcept {
  std::string errorMessage;

  switch (result) {
    case INPUT_OVERFLOW:
      errorMessage = "Error: input overflow";
      break;
    case WRONG_X_USAGE:
      errorMessage = "Error: wrong x usage";
      break;
    case EMPTY_BRACKETS:
      errorMessage = "Error: empty brackets";
      break;
    case UNBALANCED_BRACKETS:
      errorMessage = "Error: unbalanced brackets";
      break;
    case MULTIPLE_DECIMALS:
      errorMessage = "Error: multiple decimals in a number";
      break;
    case UNKNOWN_OPERATOR:
      errorMessage = "Error: unknown operator";
      break;
    case MISSED_OPERAND:
      errorMessage = "Error: missed operand";
      break;
    default:
      break;
  }

  return errorMessage;
}

bool Validator::hasError() const noexcept { return hasError_; }

std::string Validator::checkExpression(std::string expression) noexcept {
  expression_ = expression;

  ValidatorResults result = validateExpression();

  std::string errorMessage = getErrorMessage(result);

  if (!errorMessage.empty()) {
    hasError_ = true;
    return errorMessage;
  }

  hasError_ = false;
  return expression_;
}
}  // namespace s21
