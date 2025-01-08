/**
 * @file s21_Common.h
 * @author Blanca Rafford blancara@student.21-school.ru
 * @brief Заголовочный файл проекта, содержащий общие включения для модулей
 * s21_Model.h.
 * @date 21.05.2024
 *
 * @copyright School-21 (c) 2024
 */

#ifndef CPP3_SMARTCALC_SRC_MODEL_S21_COMMON_H
#define CPP3_SMARTCALC_SRC_MODEL_S21_COMMON_H

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

/**
 * @brief Хранение приоритетов каждого математического оператора.
 *
 * Этот массив используется для определения приоритета операторов при вычислении
 * математических выражений. Ключи представляют операторы, а значения - их
 * приоритет.
 */
const std::unordered_map<std::string, int> operatorPriority = {
    {"pi", 0},   {"exp", 0},  {"x", 0},    {"(", 0},   {"+", 1},
    {"-", 1},    {"*", 2},    {"/", 2},    {"%", 2},   {"^", 3},
    {"~", 3},    {"sqrt", 4}, {"sin", 4},  {"cos", 4}, {"tan", 4},
    {"asin", 4}, {"acos", 4}, {"atan", 4}, {"log", 4}, {"ln", 4}};

#endif  // CPP3_SMARTCALC_SRC_MODEL_S21_COMMON_H
