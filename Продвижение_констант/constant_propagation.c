#include <stdlib.h>
#include <string.h>
#include "constant_propagation.h"

VarEntryArray get_constants_propagation(Command* commands, int num_commands) {
    VarEntryArray vars;
    vars.entries = malloc(sizeof(VarEntry) * num_commands);
    vars.count = num_commands;

    for (int i = 0; i < num_commands; i++) {
        strcpy(vars.entries[i].name, commands[i].var);
        vars.entries[i].constant.type = CONST_UNKNOWN;
        vars.entries[i].constant.value = 0;
    }

    return vars;
}