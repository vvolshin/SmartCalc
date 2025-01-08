#include "s21_Calculator.h"

#include "s21_Common.h"

namespace s21 {
void Calculator::setX(double number) noexcept { x_value_ = number; }

void Calculator::setExpression(const std::string expression) noexcept {
  expression_ = validator_.checkExpression(expression);
}

bool Calculator::checkErrors() const noexcept { return validator_.hasError(); }

void Calculator::createTokens() noexcept {
  tokens_ = tokenizer_.createTokens(expression_);
}

bool Calculator::isOperator(const std::string& token) const noexcept {
  return operatorPriority.find(token) != operatorPriority.end();
}

int Calculator::priority(const std::string& token) const noexcept {
  return operatorPriority.at(token);
}

void Calculator::infixToPostfix() noexcept {
  std::vector<std::string> postfix;
  std::stack<std::string> stack;

  for (const auto& token : tokens_) {
    if (isdigit(token[0]) || token == "x" || token == "pi" || token == "exp") {
      postfix.push_back(token);
    } else if (token == "(") {
      stack.push(token);
    } else if (token == ")") {
      while (stack.top() != "(") {
        postfix.push_back(stack.top());
        stack.pop();
      }
      stack.pop();
    } else if (isOperator(token)) {
      while (!stack.empty() &&
             (priority(stack.top()) > priority(token) ||
              (priority(stack.top()) == priority(token) && token != "^"))) {
        postfix.push_back(stack.top());
        stack.pop();
      }
      stack.push(token);
    }
  }

  while (!stack.empty()) {
    postfix.push_back(stack.top());
    stack.pop();
  }

  tokens_ = postfix;
}

double Calculator::performOperation(double op1, double op2,
                                    const std::string& token) const noexcept {
  if (token == "+") {
    return op1 + op2;
  } else if (token == "-") {
    return op1 - op2;
  } else if (token == "*") {
    return op1 * op2;
  } else if (token == "/") {
    return op1 / op2;
  } else if (token == "%") {
    return std::fmod(op1, op2);
  } else if (token == "^") {
    return std::pow(op1, op2);
  } else if (token == "sqrt") {
    return std::sqrt(op1);
  } else if (token == "sin") {
    return std::sin(op1);
  } else if (token == "cos") {
    return std::cos(op1);
  } else if (token == "tan") {
    return std::tan(op1);
  } else if (token == "asin") {
    return std::asin(op1);
  } else if (token == "acos") {
    return std::acos(op1);
  } else if (token == "atan") {
    return std::atan(op1);
  } else if (token == "log") {
    return std::log10(op1);
  } else if (token == "ln") {
    return std::log(op1);
  } else if (token == "~") {
    return -op1;
  }

  return 0;
}

double Calculator::calculatePostfixExpression() const noexcept {
  std::stack<double> stack;

  for (const std::string& token : tokens_) {
    if (std::isdigit(token[0])) {
      stack.push(std::stod(token));
    } else if (token == "x") {
      stack.push(x_value_);
    } else if (token == "pi") {
      stack.push(M_PI);
    } else if (token == "exp") {
      stack.push(M_E);
    } else if (isOperator(token)) {
      if (token == "~") {
        double op1 = stack.top();
        stack.pop();
        stack.push(-1 * op1);
      } else {
        if (token == "sin" || token == "cos" || token == "tan" ||
            token == "asin" || token == "acos" || token == "atan" ||
            token == "log" || token == "ln" || token == "sqrt") {
          double op1 = stack.top();
          stack.pop();
          double result = performOperation(op1, 0, token);
          stack.push(result);
        } else {
          double op2 = stack.top();
          stack.pop();

          double op1 = stack.top();
          stack.pop();

          double result = performOperation(op1, op2, token);
          stack.push(result);
        }
      }
    }
  }

  return stack.top();
}

std::string Calculator::calculate(std::string expression) noexcept {
  setExpression(expression);

  if (checkErrors()) return expression_;

  createTokens();
  infixToPostfix();
  result_ = calculatePostfixExpression();

  expression_.clear();
  expression_ = std::to_string(result_);

  return expression_;
}
}  // namespace s21
