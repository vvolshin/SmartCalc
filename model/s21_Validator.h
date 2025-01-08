/**
 * @file s21_Validator.h
 * @author Blanca Rafford blancara@student.21-school.ru
 * @brief Заголовочный файл проекта, содержащий объявления методов класса
 * s21::Validator, предназначенных для валидации выражения и подготовки его к
 * вычислению.
 * @date 21.05.2024
 *
 * @copyright School-21 (c) 2024
 */

#ifndef CPP3_SMARTCALC_SRC_MODEL_S21_VALIDATOR_H
#define CPP3_SMARTCALC_SRC_MODEL_S21_VALIDATOR_H

#pragma once

#include <regex>

#include "s21_Common.h"

/**
 * @brief Пространство имён s21 содержит классы и функции для библиотеки
 * s21_Model.h.
 */
namespace s21 {
#define MAX_EXPRESSION_LENGTH 255  ///< Максимальная длина входного выражения

/**
 * @brief Перечисление, представляющее результаты проверки.
 */
enum ValidatorResults {
  VALID,           ///< Валидное выражение
  INPUT_OVERFLOW,  ///< Входное выражение больше установленной длины
  UNBALANCED_BRACKETS,  ///< Несбалансированные скобки
  EMPTY_BRACKETS,       ///< Пустые скобки
  MISSED_OPERAND,       ///< Отсутствует операнд
  UNKNOWN_OPERATOR,     ///< Неизвестный оператор
  MULTIPLE_DECIMALS,  ///< Несколько десятичных знаков в числе
  WRONG_X_USAGE  ///< Некорректное использование х
};

/**
 * @brief Класс для валидации выражения.
 * @details Объект класса Validator принимает строку выражения и проверяет ее на
 * пригодность к вычислению. Помимо валидации класс немного трансформирует
 * выражение для упрощения вычислений: меняет регистр на нижний, удаляет пробелы
 * и преобразует унарный минус и mod.
 */
class Validator {
 public:
  /**
   * @brief Конструктор по умолчанию для класса Validator.
   */
  Validator() noexcept = default;

  /**
   * @brief Деструктор класса Validator.
   */
  ~Validator() noexcept = default;

  /**
   * @brief Принимает строку, валидирует ее на пригодность к вычислению и
   * определяет статус валидации через флаг.
   * @param expression строка выражения, которую нужно завалидировать.
   * @return Строка после трансформаций и проверок, которая пригодна в
   * вычислению.
   */
  std::string checkExpression(std::string expression) noexcept;

  /**
   * @brief Сообщает о наличии ошибки.
   * @return true, если есть ошибка, иначе false.
   */
  bool hasError() const noexcept;

 private:
  /**
   * @brief Проверяет размер входного выражения.
   * @return VALID, если входное выражение не превышает максимальной длины,
   * иначе INPUT_OVERFLOW.
   */
  ValidatorResults validateSize() const noexcept;

  /**
   * @brief Удаляет пробелы.
   */
  void removeSpaces() noexcept;

  /**
   * @brief Переводит входное выражение в нижний регистр.
   */
  void transformToLowerCase() noexcept;

  /**
   * @brief Заменяет унарный минус на '~'.
   */
  void transformUnaryMinus() noexcept;

  /**
   * @brief Заменяет mod минус на '%'.
   */
  void transformMod() noexcept;

  /**
   * @brief Проверяет корректность скобок.
   * @return VALID - если скобки использованы верно, EMPTY_BRACKETS - если
   * скобки пустые, UNBALANCED_BRACKETS - если скобки несбалансированы.
   */
  ValidatorResults validateBrackets() const noexcept;

  /**
   * @brief Проверяет корректность чисел с плавающей точкой.
   * @return VALID - если числа корректны, MULTIPLE_DECIMALS - если в числе
   * присутствуют несколько десятичных точек.
   */
  ValidatorResults validateMultipleDecimals() const noexcept;

  /**
   * @brief Проверяет наличие в строке неутвержденных операторов.
   * @return VALID - если все операторы утверждены, UNKNOWN_OPERATOR - если в
   * строке присутствуют неизвестные операторы.
   */
  ValidatorResults validateUnapprovedOperators() noexcept;

  /**
   * @brief Проверяет, является ли символ одним из операторов '+', '-', '*', '/'
   * или '^'.
   * @return true, если символ является 'простым' оператором, иначе false.
   */
  bool isSimpleOperator(char symbol) const noexcept;

  /**
   * @brief Проверяет правильность расположения чисел между операторами.
   * @return VALID - если все операторы и числа расставлены верно, иначе
   * MISSED_OPERAND.
   */
  ValidatorResults checkOperands() const noexcept;

  /**
   * @brief Проверяет правильность расположения 'x'.
   * @return VALID - если 'x' используется верно, иначе WRONG_X_USAGE.
   */
  ValidatorResults xUsageCheck() const noexcept;

  /**
   * @brief Проверяет наличие ошибок во входном выражении и при их наличии
   * заменяет выражение сообщением ошибки.
   * @return Строка с сообщением об ошибке при наличии или пустая при
   * отстутсвии.
   */
  std::string getErrorMessage(ValidatorResults result) noexcept;

  /**
   * @brief Функция запуска трансформации и валидации.
   * @return Сообщение об ошибке при наличии, иначе VALID.
   */
  ValidatorResults validateExpression() noexcept;

  std::string expression_;  ///< Входное выражение
  bool hasError_ = false;   ///< Флаг наличия ошибки
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_SRC_MODEL_S21_VALIDATOR_H
