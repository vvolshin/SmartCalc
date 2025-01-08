/**
 * @file s21_Credits.h
 * @author Blanca Rafford blancara@student.21-school.ru
 * @brief Заголовочный файл проекта, содержащий объявления методов класса
 * s21::Credits, предназначенных для вычисления платежей по кредиту.
 * @date 21.05.2024
 *
 * @copyright School-21 (c) 2024
 */

#ifndef CPP3_SMARTCALC_SRC_MODEL_S21_CREDITS_H
#define CPP3_SMARTCALC_SRC_MODEL_S21_CREDITS_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

/**
 * @brief Пространство имён s21 содержит классы и функции для библиотеки
 * s21_Model.h.
 */
namespace s21 {

/**
 * @brief Структура для хранения параметров каждого месяца.
 */
struct MonthInfo {
  int month;                ///< Номер месяца
  double principalPayment;  ///< Платеж по основному долгу
  double interestPayment;   ///< Платеж по процентам
  double balanceOwed;       ///< Остаток долга
  double monthPayment;      ///< Ежемесячный платеж
};

/**
 * @brief Класс для рассчета платежей по кредиту.
 * @details Объект класса Credits принимает данные по кредиту: сумму кредита,
 * срок и процентную ставку, и вычисляет платежи по кредиту в зависимости от
 * типа расчета.
 */
class Credits {
 public:
  /**
   * @brief Конструктор по умолчанию для класса Credits.
   */
  Credits() noexcept = default;

  /**
   * @brief Деструктор по умолчанию для класса Credits.
   */
  ~Credits() noexcept = default;

  /**
   * @brief Устанавливает параметры кредита.
   * @param loan Сумма кредита.
   * @param period Количество месяцев.
   * @param interest Процентная ставка.
   * @throw std::invalid_argument Если какой-либо из параметров некорректен.
   */
  void setParams(double loan, size_t period, double interest);

  /**
   * @brief Вычисляет параметры аннуитетного платежа.
   */
  void calculateAnnuityPayment() noexcept;

  /**
   * @brief Вычисляет параметры дифференцированного платежа.
   */
  void calculateDifferentialPayment() noexcept;

  /**
   * @brief Возвращает общую сумму платежей (долг + проценты).
   * @return Общая сумма платежей.
   */
  double getTotalPayment() const noexcept;

  /**
   * @brief Возвращает общую сумму процентов.
   * @return Общая сумма процентов.
   */
  double getTotalInterest() const noexcept;

  /**
   * @brief Возвращает размер ежемесячного платежа.
   * @details Для аннуитетного платежа - ежемесячный платеж. Для
   * дифференцированного - платеж за первый и последний месяцы в виде диапазона
   * ("x..x")
   * @return Размер ежемесячного платежа.
   */
  std::string getMonthPayment() const noexcept;

  /**
   * @brief Возвращает массив с данными по месяцам.
   * @return Массив с данными по месяцам.
   */
  std::vector<MonthInfo> getSummaryData() const;

  /**
   * @brief Возвращает флаг валидности входных данных.
   * @return true - данные валидны, false - данные невалидны.
   */
  bool getValidity() const noexcept;

  /**
   * @brief Вывод результатов расчета в виде таблицы с графиком платежей или
   * сообщения об ошибке.
   * @return Таблица с графиком платежей или сообщение об ошибке.
   */
  std::string getResult() const noexcept;

 private:
  /**
   * @brief Вычисляет размер ежемесячного платежа.
   */
  void calculateMonthPayment() noexcept;

  /**
   * @brief Вычисляет ежемесячную процентную ставку.
   */
  void calculateMonthInerest() noexcept;

  bool isValid_;  ///< Флаг валидности входных данных
  std::string errorMessage_;  ///< Сообщение об ошибке
  std::vector<MonthInfo> summary_;  ///< Массив с данными по месяцам
  double loan_;                     ///< Сумма кредита
  size_t period_;                   ///< Количество месяцев
  double interest_;                 ///< Процентная ставка
  double monthPayment_;             ///< Ежемесячный платеж
  double monthInterest_;  ///< Ежемесячный процент
  double totalPayment_;   ///< Общая сумма платежей
  double totalInterest_;  ///< Общая сумма процентов
};                        // class Credits
}  // namespace s21
#endif  // CPP3_SMARTCALC_SRC_MODEL_S21_CREDITS_H
