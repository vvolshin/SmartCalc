#include "s21_Tokenizer.h"

namespace s21 {
bool Tokenizer::isNumber(const std::string& str) const noexcept {
  try {
    std::stod(str);
    return true;
  } catch (std::invalid_argument&) {
    return false;
  }
}

bool Tokenizer::isNumberToken(const std::string& token,
                              size_t& pos) const noexcept {
  return isNumber(token.substr(pos, 1)) || token.substr(pos, 1) == "." ||
         token.substr(pos, 2) == "e-" || token.substr(pos, 2) == "e+";
}

std::string Tokenizer::extractNumberToken(const std::string& token,
                                          size_t& pos) const noexcept {
  std::string numberToken = "";
  bool hasDecimal = false;
  while (pos < token.length() &&
         (isNumber(token.substr(pos, 1)) ||
          (token.substr(pos, 1) == "." && !hasDecimal))) {
    numberToken += token.substr(pos, 1);
    if (token.substr(pos, 1) == ".") {
      hasDecimal = true;
    }
    pos++;
  }
  if (pos < token.length() &&
      (token.substr(pos, 2) == "e-" || token.substr(pos, 2) == "e+")) {
    numberToken += token.substr(pos, 2);
    pos += 2;
    while (pos < token.length() && isNumber(token.substr(pos, 1))) {
      numberToken += token.substr(pos, 1);
      pos++;
    }
  }
  return numberToken;
}

std::string Tokenizer::extractFunctionToken(const std::string& token,
                                            size_t& pos) const noexcept {
  std::string funcToken = "";
  while (pos < token.length() && isalpha(token[pos])) {
    funcToken += token[pos];
    pos++;
  }
  return funcToken;
}

std::string Tokenizer::extractSingleCharToken(const std::string& token,
                                              size_t& pos) const noexcept {
  std::string singleCharToken = token.substr(pos, 1);
  pos++;
  return singleCharToken;
}

const std::vector<std::string>& Tokenizer::createTokens(
    std::string expression) noexcept {
  tokens_.clear();
  std::stringstream ss(expression);
  std::string token;

  while (ss >> token) {
    size_t pos = 0;
    while (pos < token.length()) {
      if (isNumberToken(token, pos)) {
        std::string numberToken = extractNumberToken(token, pos);
        tokens_.push_back(numberToken);
      } else {
        std::string funcToken = extractFunctionToken(token, pos);
        if (operatorPriority.find(funcToken) != operatorPriority.end()) {
          tokens_.push_back(funcToken);
        } else {
          std::string singleCharToken = extractSingleCharToken(token, pos);
          tokens_.push_back(singleCharToken);
        }
      }
    }
  }

  return tokens_;
}
}  // namespace s21
