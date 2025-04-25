#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "machine_turing.h"

void run_test(const char *input, int expected_result) {
    int result = check_brackets(input);
    if (result == expected_result) {
        printf("[OK]   \"%s\"\n", input);
    } else {
        printf("[FAIL] \"%s\" → expected %d, got %d\n", input, expected_result, result);
    }
}

int naive_validate(const char *s) {
    int balance = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') balance++;
        else if (s[i] == ')') balance--;
        if (balance < 0) return REJECT;
    }
    return (balance == 0) ? ACCEPT : REJECT;
}

void generate_random_bracket_string(char *buffer, int n) {
    for (int i = 0; i < n; i++) {
        buffer[i] = (rand() % 2) ? '(' : ')';
    }
    buffer[n] = '\0';
}

int main() {
    srand(time(NULL));
    printf("=== Fixed tests ===\n");

    run_test("()", ACCEPT);
    run_test("())", REJECT);
    run_test("()()", ACCEPT);
    run_test("((()()))", ACCEPT);
    run_test(")(", REJECT);
    run_test("", ACCEPT);
    run_test("(((((())))))", ACCEPT);
    run_test("(()", REJECT);
    run_test("())(", REJECT);
    run_test("((()))", ACCEPT);
    run_test("()(()())", ACCEPT);
    run_test("()(()()))", REJECT);
    run_test("(()(()()))", ACCEPT);
    run_test("((((((()))))))", ACCEPT);
    run_test("(()(()(())))", ACCEPT);
    run_test("(((((((((((((((((((((())))))))))))))))))))))", ACCEPT);
    run_test("(((((((((((((((((((())))))))))))))))))", REJECT);
    run_test("()())()(", REJECT);
    run_test("((((())()(()())))((()))())", ACCEPT);

    printf("\n=== Randomized tests ===\n");

    char buf[1024];
    for (int i = 0; i < 50; i++) {
        int len = rand() % 50 + 1;
        generate_random_bracket_string(buf, len);
        int expected = naive_validate(buf);
        run_test(buf, expected);
    }

    return 0;
}