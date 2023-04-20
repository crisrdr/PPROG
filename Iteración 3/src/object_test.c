/** 
 * @brief It tests object module
 * 
 * @file object_test.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "object_test.h"
#include "test.h"

#define MAX_TESTS 14

int main(int argc, char** argv) {
    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Object:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
        printf("Error: unknown test %d\t", test);
        exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_object_create();
    if (all || test == 2) test2_object_create();
    if (all || test == 3) test1_object_destroy();
    if (all || test == 4) test2_object_destroy();
    if (all || test == 5) test1_object_get_id();
    if (all || test == 6) test2_object_get_id();
    if (all || test == 7) test1_object_get_name();
    if (all || test == 8) test2_object_get_name();
    if (all || test == 9) test1_object_set_name();
    if (all || test == 10) test2_object_set_name();
    if (all || test == 11) test1_object_set_descr();
    if (all || test == 12) test2_object_set_descr();
    if (all || test == 13) test1_object_get_descr();
    if (all || test == 14) test2_object_get_descr();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_object_create(){
    PRINT_TEST_RESULT(object_create(NO_ID) == NULL);
}

void test2_object_create(){
    PRINT_TEST_RESULT(object_create(9) != NULL);
}

void test1_object_destroy(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_destroy(object) == ERROR);
}

void test2_object_destroy(){
    Object *object = NULL;
    object = object_create(1);
    PRINT_TEST_RESULT(object_destroy(object) == OK);
}

void test1_object_get_id(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_id(object) == NO_ID);
}

void test2_object_get_id(){
    Object *object = NULL;
    object = object_create(8);
    PRINT_TEST_RESULT(object_get_id(object) != NO_ID);
    object_destroy(object);
}

void test1_object_get_name(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_name(object) == NULL);
}

void test2_object_get_name(){
    Object *object = NULL;
    object = object_create(5);
    object_set_name(object, "regalo");
    PRINT_TEST_RESULT(strcmp(object_get_name(object), "regalo") == 0);
    object_destroy(object);
}

void test1_object_set_name(){
    Object *object = NULL;
    object = object_create(19);
    PRINT_TEST_RESULT(object_set_name(object, NULL) == ERROR);
    object_destroy(object);
}

void test2_object_set_name(){
    Object *object = NULL;
    object = object_create(19);
    PRINT_TEST_RESULT(object_set_name(object, "zanahoria") == OK);
    object_destroy(object);
}

void test1_object_set_descr(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_set_descr(object, "marcha") == ERROR);
}

void test2_object_set_descr(){
    Object *object = NULL;
    object = object_create(47);
    PRINT_TEST_RESULT(object_set_descr(object, "marcha") == OK);
    object_destroy(object);
}

void test1_object_get_descr(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_descr(object) == NULL);
}

void test2_object_get_descr(){
    Object *object = NULL;
    char *descr = NULL;
    object = object_create(6);
    object_set_descr(object, "pulga");
    PRINT_TEST_RESULT(strcmp (object_get_descr(object), "pulga") == 0);
    object_destroy(object);
}