/** 
 * @brief It tests dialogue module
 * 
 * @file dialogue_test.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 14-06-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "dialogue.h"
#include "dialogue_test.h"
#include "test.h"

#define MAX_TESTS 12

int main(int argc, char** argv) {
    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Command:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
        printf("Error: unknown test %d\t", test);
        exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_dialogue_create();
    if (all || test == 2) test1_dialogue_set_success_msg();
    if (all || test == 3) test2_dialogue_set_success_msg();
    if (all || test == 4) test3_dialogue_set_success_msg();
    if (all || test == 5) test1_dialogue_set_error_msg();
    if (all || test == 6) test2_dialogue_set_error_msg();
    if (all || test == 7) test3_dialogue_set_error_msg();
    if (all || test == 8) test1_dialogue_get_message();
    if (all || test == 9) test2_dialogue_get_message();
    if (all || test == 10) test1_dialogue_get_type();
    if (all || test == 11) test2_dialogue_get_type();
    if (all || test == 12) test3_dialogue_get_type();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_dialogue_create(){
    PRINT_TEST_RESULT(dialogue_create() != NULL);
}


void test1_dialogue_set_success_msg(){
    Dialogue *d = NULL;
    char *msg = "Congratulations!";
    PRINT_TEST_RESULT(dialogue_set_success_msg(d, msg, "Keep playing.") == ERROR);
}

void test2_dialogue_set_success_msg(){
    Dialogue *d = NULL;
    char *msg = NULL;
    d = dialogue_create();
    PRINT_TEST_RESULT(dialogue_set_success_msg(d, msg, "Keep playing.") == ERROR);
    dialogue_destroy(d);
}

void test3_dialogue_set_success_msg(){
    Dialogue *d = NULL;
    char *msg = "Congratulations!";
    d = dialogue_create();
    PRINT_TEST_RESULT(dialogue_set_success_msg(d, msg, "Keep playing.") == OK);
    dialogue_destroy(d);
}

void test1_dialogue_set_error_msg(){
    Dialogue *d = NULL;
    char *msg = "Oh you failed!";
    PRINT_TEST_RESULT(dialogue_set_error_msg (d, D_ATTACK_ENEMY, msg, "Try again.") == ERROR); 
}

void test2_dialogue_set_error_msg(){
    Dialogue *d = NULL;
    char *msg = NULL;
    d = dialogue_create();
    PRINT_TEST_RESULT(dialogue_set_error_msg (d, D_ATTACK_ENEMY, msg, "Try again.") == ERROR); 
    dialogue_destroy(d);
}

void test3_dialogue_set_error_msg(){
    Dialogue *d = NULL;
    char *msg = "Oh you failed!";
    d = dialogue_create();
    PRINT_TEST_RESULT(dialogue_set_error_msg (d, D_ATTACK_ENEMY, msg, "Try again.") == OK); 
    dialogue_destroy(d);
}

void test1_dialogue_get_message(){
    Dialogue *d = NULL;
    PRINT_TEST_RESULT(dialogue_get_message(d) == NULL);
}

void test2_dialogue_get_message(){
    Dialogue *d = NULL;
    d = dialogue_create();
    PRINT_TEST_RESULT(dialogue_get_message(d) != NULL);
}

void test1_dialogue_get_type(){
    Dialogue *d = NULL;
    PRINT_TEST_RESULT(dialogue_get_type(d) == NO_DIALOGUE);
}

void test2_dialogue_get_type(){
    Dialogue *d = NULL;
    d = dialogue_create();
    PRINT_TEST_RESULT(dialogue_get_type(d) == NO_DIALOGUE);
}

void test3_dialogue_get_type(){
    Dialogue *d = NULL;
    d = dialogue_create();
    dialogue_set_success_msg(d, "Congratulations.", "Keep playing.");
    PRINT_TEST_RESULT(dialogue_get_type(d) == SUCCESS_MSG);
}