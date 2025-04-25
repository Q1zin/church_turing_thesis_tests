#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constant_propagation.h"

void run_test(Command* commands, int num_commands, const char* expected[]) {
    printf("=== Input commands ===\n");
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].action, "init") == 0) {
            printf("%s %s\n", commands[i].action, commands[i].var);
        } else {
            printf("%s %s %s %s\n", commands[i].action, commands[i].var, commands[i].operand1, commands[i].operand2);
        }
    }

    VarEntryArray vars = get_constants_propagation(commands, num_commands);

    for (int i = 0; i < vars.count; i++) {
        int expected_type;
        int expected_value = 0;

        if (strcmp(expected[i], "U") == 0) {
            expected_type = CONST_UNKNOWN;
        } else if (strcmp(expected[i], "T") == 0) {
            expected_type = CONST_RUNTIME;
        } else {
            expected_type = CONST_NUMBER;
            expected_value = atoi(expected[i]);
        }

        int correct = 0;
        if (expected_type == CONST_NUMBER && vars.entries[i].constant.type == CONST_NUMBER && vars.entries[i].constant.value == expected_value) {
            correct = 1;
        }
        if (expected_type != CONST_NUMBER && vars.entries[i].constant.type == expected_type) {
            correct = 1;
        }

        printf("%s \"%s\"", correct ? "[OK]   " : "[FAIL]", vars.entries[i].name);

        if (!correct) {
            if (expected_type == CONST_NUMBER)
                printf(" → expected %d, got ", expected_value);
            else if (expected_type == CONST_UNKNOWN)
                printf(" → expected U, got ");
            else
                printf(" → expected T, got ");

            if (vars.entries[i].constant.type == CONST_NUMBER)
                printf("%d", vars.entries[i].constant.value);
            else if (vars.entries[i].constant.type == CONST_UNKNOWN)
                printf("U");
            else
                printf("T");
        }
        printf("\n");
    }

    printf("\n");
    free(vars.entries);
}

int main() {
    printf("=== Fixed tests ===\n");

    Command commands1[] = {
        {"add", "x", "5", "3"},
        {"add", "y", "x", "10"},
        {"init", "z", "", ""},
        {"add", "k", "get_time", "5"}
    };
    const char* expected1[] = { "8", "18", "U", "T" };
    run_test(commands1, 4, expected1);

    Command commands2[] = {
        {"init", "a", "", ""},
        {"init", "b", "", ""},
        {"init", "c", "", ""}
    };
    const char* expected2[] = { "U", "U", "U" };
    run_test(commands2, 3, expected2);

    Command commands3[] = {
        {"mult", "p", "4", "5"},
        {"minus", "q", "p", "6"},
        {"div", "r", "q", "2"},
        {"add", "s", "r", "1"}
    };
    const char* expected3[] = { "20", "14", "7", "8" };
    run_test(commands3, 4, expected3);

    Command commands4[] = {
        {"add", "m", "runtime_func", "10"},
        {"mult", "n", "m", "2"},
        {"minus", "o", "n", "1"}
    };
    const char* expected4[] = { "T", "T", "T" };
    run_test(commands4, 3, expected4);

    Command commands5[] = {
        {"init", "a", "", ""},
        {"add", "b", "a", "runtime_func"},
        {"mult", "c", "b", "10"},
        {"div", "d", "c", "5"}
    };
    const char* expected5[] = { "U", "T", "T", "T" };
    run_test(commands5, 4, expected5);

    Command commands6[] = {
        {"add", "x", "10", "5"},
        {"div", "y", "x", "5"},
        {"minus", "z", "y", "2"}
    };
    const char* expected6[] = { "15", "3", "1" };
    run_test(commands6, 3, expected6);

    Command commands7[] = {
        {"add", "a", "10", "5"},
        {"add", "b", "c", "1"}
    };
    const char* expected7[] = { "15", "T" };
    run_test(commands7, 2, expected7);

    return 0;
}