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

#define MAX_TESTS 38

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
    if (all || test == 15) test1_object_is_movable();
    if (all || test == 16) test2_object_is_movable();
    if (all || test == 17) test1_object_set_movable();
    if (all || test == 18) test2_object_set_movable();
    if (all || test == 19) test1_object_get_dependency();
    if (all || test == 20) test2_object_get_dependency();
    if (all || test == 21) test1_object_set_dependency();
    if (all || test == 22) test2_object_set_dependency();
    if (all || test == 23) test1_object_get_open_id();
    if (all || test == 24) test2_object_get_open_id();
    if (all || test == 25) test1_object_set_open_id();
    if (all || test == 26) test2_object_set_open_id();
    if (all || test == 27) test3_object_set_open_id();
    if (all || test == 28) test1_object_can_illuminate();
    if (all || test == 29) test2_object_can_illuminate();
    if (all || test == 30) test1_object_set_illuminate();
    if (all || test == 31) test2_object_set_illuminate();
    if (all || test == 32) test1_object_is_turnedon();
    if (all || test == 33) test2_object_is_turnedon();
    if (all || test == 34) test1_object_set_turnedon();
    if (all || test == 35) test2_object_set_turnedon();
    if (all || test == 36) test1_object_can_be_taken();
    if (all || test == 37) test2_object_can_be_taken();
    if (all || test == 38) test3_object_can_be_taken();

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

void test1_object_is_movable(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_is_movable(object) == FALSE);
}

void test2_object_is_movable(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_is_movable(object) == FALSE);
    object_destroy(object);
}

void test1_object_set_movable(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_set_movable(object, TRUE) == ERROR);
}

void test2_object_set_movable(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_set_movable(object, TRUE) == OK);
    object_destroy(object);
}

void test1_object_get_dependency(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_dependency(object) == NO_ID);
}

void test2_object_get_dependency(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_get_dependency(object) == NO_ID);
    object_destroy(object);
}

void test1_object_set_dependency(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_set_dependency(object, 4) == ERROR);
}

void test2_object_set_dependency(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_set_dependency(object, 5) == OK);
    object_destroy(object);
}

void test1_object_get_open_id(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_get_open_id(object) == NO_ID);
}

void test2_object_get_open_id(){
    Object *object = NULL;
    object = object_create(5);
    object_set_open_id(object, 6);
    PRINT_TEST_RESULT(object_get_open_id(object) == 6); 
    object_destroy(object);  
}

void test1_object_set_open_id(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_set_open_id(object, NO_ID) == ERROR);
}

void test2_object_set_open_id(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_set_open_id(object, NO_ID) == ERROR);
    object_destroy(object);
}

void test3_object_set_open_id(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_set_open_id(object, 4) == OK);
    object_destroy(object);
}

void test1_object_can_illuminate(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_can_illuminate(object) == FALSE);
}

void test2_object_can_illuminate(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_can_illuminate(object) == FALSE);
}

void test1_object_set_illuminate(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_set_illuminate(object, TRUE) == ERROR);
}

void test2_object_set_illuminate(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_set_illuminate(object, TRUE) == OK);
}

void test1_object_is_turnedon(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_is_turnedon(object) == FALSE);
}

void test2_object_is_turnedon(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_is_turnedon(object) == FALSE);
}

void test1_object_set_turnedon(){
    Object *object = NULL;
    PRINT_TEST_RESULT(object_set_turnedon(object, TRUE) == ERROR);
}

void test2_object_set_turnedon(){
    Object *object = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_set_turnedon(object, TRUE) == OK);
}

void test1_object_can_be_taken(){
    Object *object = NULL;
    Inventory *i = NULL;
    PRINT_TEST_RESULT(object_can_be_taken(object, i) == FALSE);
}

void test2_object_can_be_taken(){
    Object *object = NULL;
    Inventory *i = NULL;
    object = object_create(5);
    PRINT_TEST_RESULT(object_can_be_taken(object, i) == FALSE);
}

void test3_object_can_be_taken(){
    Object *object = NULL;
    Inventory *i = NULL;
    object = object_create(5);
    object_set_movable(object, TRUE);
    i = inventory_create();
    PRINT_TEST_RESULT(object_can_be_taken(object, i) == TRUE);
}