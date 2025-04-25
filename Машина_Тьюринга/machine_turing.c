#include <stdlib.h>
#include "machine_turing.h"

#define MAX_STEPS 10000 // Ограничение на число шагов работы машины

TuringMachine* create_machine(const char *tape_initial) {
    TuringMachine *tm = (TuringMachine*) malloc(sizeof(TuringMachine));
    
    return tm;
};

void add_transition(TuringMachine *tm, char current_state, char read_symbol, char write_symbol, char direction, char next_state);

void run_machine(TuringMachine *tm);

void destroy_machine(TuringMachine *tm);

int check_brackets(const char *input) {
    return REJECT;
}
