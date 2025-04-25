#ifndef CONSTANT_PROPAGATION_H
#define CONSTANT_PROPAGATION_H

// Тип константы: число, неизвестное (U) или вычисляемое во время выполнения (T)
typedef enum { CONST_NUMBER, CONST_UNKNOWN, CONST_RUNTIME } ConstType;

// Структура команды (операции)
typedef struct {
    char action[64];    // Действие: "add", "mult", "minus", "div" (целочисленное деление), "init" или иное имя функции
    char var[64];       // Имя переменной, которой присваивается результат
    char operand1[64];  // Первый операнд (число, переменная или функция)
    char operand2[64];  // Второй операнд
} Command;

// Структура константы: тип и числовое значение (если тип — число)
typedef struct {
    ConstType type;
    int value;
} Constant;

// Таблица переменных (простая реализация на массиве)
typedef struct {
    char name[64];       // Имя переменной
    Constant constant;   // Хранимая константа
} VarEntry;

// Структура-обёртка для массива и его размера
typedef struct {
    VarEntry* entries;
    int count;
} VarEntryArray;

/*
 * Функция: get_constanta_propagation
 * ------------------------
 * Оснавная функция программы, на вход подаётся массив команд и колличество команд.
 * Возвращает массив значений констант
 */
VarEntryArray get_constants_propagation(Command* commands, int num_commands);

#endif