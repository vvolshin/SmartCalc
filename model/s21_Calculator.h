/**
 * @file s21_Calculator.h
 * @author Blanca Rafford blancara@student.21-school.ru
 * @brief Заголовочный файл проекта, содержащий объявления методов класса
 * s21::Calculator, предназначенных для вычисления выражений.
 * @date 21.05.2024
 *
 * @copyright School-21 (c) 2024
 */

#ifndef CPP3_SMARTCALC_SRC_MODEL_S21_CALCULATOR_H
#define CPP3_SMARTCALC_SRC_MODEL_S21_CALCULATOR_H

#include "s21_Common.h"
#include "s21_Tokenizer.h"
#include "s21_Validator.h"

/**
 * @brief Пространство имён s21 содержит классы и функции для библиотеки
 * s21_Model.h.
 */
namespace s21 {

/**
 * @brief Класс для вычисления математических выражений.
 * @details Объект класса Calculator принимает строку выражения и возвращает
 * результат в виде просчитанного ответа или сообщения об ошибке. Сперва входная
 * строка проверяется классом s21::Validator на пригодность к вычислению. Если
 * проверка пройдена - строка разбивается на токены классом s21::Tokenizer.
 * Далее токены преобразуются в обратную польскую запись и вычисляются.
 */
class Calculator {
 public:
  /**
   * @brief Конструктор по умолчанию для класса Calculator.
   */
  Calculator() noexcept = default;

  /**
   * @brief Деструктор класса Calculator.
   */
  ~Calculator() noexcept = default;

  /**
   * @brief Устанавливает переменную x_value.
   * @param number Значение переменной.
   */
  void setX(double number) noexcept;

  /**
   * @brief Получает от валидатора факт ошибки.
   * @return true, если ошибок нет, false в противном случае.
   */
  bool checkErrors() const noexcept;

  /**
   * @brief Вычисляет значение выражения.
   * @param expression Строка с выражением.
   */
  std::string calculate(std::string expression) noexcept;

 private:
  /**
   * @brief Валидатор - принимает строку и проверяет на пригодность к
   * вычислениям.
   */
  Validator validator_;

  /**
   * @brief Токенизатор - разбивает строку на токены для вычисления.
   */
  Tokenizer tokenizer_;

  /**
   * @brief Устанавливает строку с выражением в поле expression_ и выполняет
   * проверку валидатором. Если строка не прошла проверку - она заменяется на
   * сообщение об ошибке, и валидатор будет хранить его в поле hasError_.
   * @param expression Строка с выражением.
   */
  void setExpression(std::string expression) noexcept;

  /**
   * @brief Строка разбивается на токены через s21::Tokenizer.
   */
  void createTokens() noexcept;

  /**
   * @brief Токены перестраиваются в порядке обратной польской записи.
   */
  void infixToPostfix() noexcept;

  /**
   * @brief Проверяет, является ли токен оператором.
   * @param token Токен.
   * @return true, если токен оператор, false в противном случае.
   */
  bool isOperator(const std::string& token) const noexcept;

  /**
   * @brief Получает приоритет токена-оператора из operatorPriority (см.
   * s21::Common.h).
   * @param token Токен.
   * @return Приоритет.
   */
  int priority(const std::string& token) const noexcept;

  /**
   * @brief Произовдит операцию в зависимости от оператора.
   * @param operand1 Операнд 1.
   * @param operand2 Операнд 2.
   * @param op Операция.
   * @return Результат вычисления операции над операндами.
   */
  double performOperation(double operand1, double operand2,
                          const std::string& op) const noexcept;

  /**
   * @brief Вычисляет выражение в обратной польской записи.
   * @return Результат вычисления.
   */
  double calculatePostfixExpression() const noexcept;

  std::string expression_;  ///< Строка с выражением
  double x_value_ = 0;      ///< Значение переменной x
  std::vector<std::string> tokens_;  ///< Токены выражения
  double result_;  ///< Результат выражения в числовом виде
};                 // class Calculator
}  // namespace s21

#endif  // CPP3_SMARTCALC_SRC_MODEL_S21_CALCULATOR_H
