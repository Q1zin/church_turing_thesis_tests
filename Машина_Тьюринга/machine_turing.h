#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#define ACCEPT 0   // Возвращается, в случае корректных входных данных
#define REJECT -1  // Возвращается, в случае неверных входных данных

// Структура для описания одного правила перехода
typedef struct {
    char current_state;    // Текущее состояние
    char read_symbol;      // Символ, считанный с ленты
    char write_symbol;     // Символ, который будет записан
    char direction;        // Направление перемещения головки: 'L' (влево) или 'R' (вправо)
    char next_state;       // Новое состояние после применения правила
} Transition;

// Структура, описывающая машину Тьюринга
typedef struct {
    char *tape;             // Лента
    int tape_size;          // Текущий размер ленты
    int head;               // Индекс текущей позиции головки
    char current_state;     // Текущее состояние машины
    Transition *transitions;// Массив правил переходов
    int num_transitions;    // Количество загруженных переходов
    int transitions_capacity; // Текущая емкость массива переходов
} TuringMachine;

/*
 * Функция: create_machine
 * ------------------------
 * Создаёт экземпляр машины Тьюринга.
 * Входной параметр tape_initial – строка, содержащая исходное содержимое ленты.
 */
TuringMachine* create_machine(const char *tape_initial);

/*
 * Функция: add_transition
 * ------------------------
 * Добавляет новое правило перехода в машину.
 */
void add_transition(TuringMachine *tm, char current_state, char read_symbol, char write_symbol, char direction, char next_state);

/*
 * Функция: run_machine
 * ---------------------
 * Симулирует работу машины Тьюринга, последовательно применяя правила переходов,
 */
void run_machine(TuringMachine *tm);

/*
 * Функция: destroy_machine
 * -------------------------
 * Освобождает память, выделенную под машину Тьюринга.
 */
void destroy_machine(TuringMachine *tm);

/*
 * Функция: check_brackets
 * -------------------------
 * ACCEPT - Возвращается, в случае корректных входных данных
 * REJECT - Возвращается, в случае неверных входных данных
*/
int check_brackets(const char *input);

#endif