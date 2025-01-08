/**
 * @file s21_Tokenizer.h
 * @author Blanca Rafford blancara@student.21-school.ru
 * @brief Заголовочный файл проекта, содержащий объявления методов класса
 * s21::Tokenizer, предназначенных для парсинга входного выражения на токены.
 * @date 21.05.2024
 *
 * @copyright School-21 (c) 2024
 */

#ifndef CPP3_SMARTCALC_SRC_MODEL_S21_TOKENIZER_H
#define CPP3_SMARTCALC_SRC_MODEL_S21_TOKENIZER_H

#pragma once

#include <sstream>

#include "s21_Common.h"

/**
 * @brief Пространство имён s21 содержит классы и функции для библиотеки
 * s21_Model.h.
 */
namespace s21 {

/**
 * @brief Класс для разбора выражения на токены.
 * @details Объект класса Tokenizer принимает строку выражения и разбивает ее на
 * токены для полседуищих преобразований и вычислений. Функция createTokens с
 * помощью stringstream разбивает выражение на токены, которые обрабатываются
 * вспомогательными функциями и записываются в вектор tokens_.
 */
class Tokenizer {
 public:
  /**
   * @brief Конструктор по умолчанию для класса Tokenizer.
   */
  Tokenizer() noexcept = default;

  /**
   * @brief Деструктор класса Tokenizer.
   */
  ~Tokenizer() noexcept = default;

  /**
   * @brief Разбивает строку на токены и записывает их в вектор tokens_.
   * @param expression строка выражения, которую нужно разбить на токены.
   * @return Вектор токенов.
   */
  const std::vector<std::string>& createTokens(std::string expression) noexcept;

 private:
  /**
   * @brief Проверяет, является ли подстрока числом.
   * @details Функция принимает символ и пытается преобразовать его в число.
   * @return true, если подстрока является числом, false в противном случае.
   */
  bool isNumber(const std::string& str) const noexcept;

  /**
   * @brief Проверяет, является ли токен числом.
   * @details Для проверки экспоненциальной записи предусмотрено использование
   * подстрок "e", "e+" и "e-".
   * @param token токен для проверки.
   * @param pos позиция в токене.
   * @return true, если токен является числом, false в противном случае.
   */
  bool isNumberToken(const std::string& token, size_t& pos) const noexcept;

  /**
   * @brief Извлекает токен-число из строки.
   * @param token строка, из которой извлекается токен.
   * @param pos позиция в строке.
   * @return Токен-число.
   */
  std::string extractNumberToken(const std::string& token,
                                 size_t& pos) const noexcept;

  /**
   * @brief Извлекает токен-функцию из строки.
   * @param token строка, из которой извлекается токен.
   * @param pos позиция в строке.
   * @return Токен-функция.
   */
  std::string extractFunctionToken(const std::string& token,
                                   size_t& pos) const noexcept;

  /**
   * @brief Извлекает токен из одного символа.
   * @param token строка, из которой извлекается токен.
   * @param pos позиция в строке.
   * @return Токен-символ.
   */
  std::string extractSingleCharToken(const std::string& token,
                                     size_t& pos) const noexcept;

  std::vector<std::string> tokens_;  ///< Токены выражения
};
}  // namespace s21

#endif
