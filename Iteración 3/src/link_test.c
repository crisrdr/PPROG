/** 
 * @brief It tests link module
 * 
 * @file link_test.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/link.h"
#include "link_test.h"
#include "test.h"

#define MAX_TESTS 27

int main(int argc, char** argv) {
    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Link:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
        printf("Error: unknown test %d\t", test);
        exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1) test1_link_create();
    if (all || test == 2) test2_link_create();
    if (all || test == 3) test1_link_destroy();
    if (all || test == 4) test2_link_destroy();
    if (all || test == 5) test1_link_get_id();
    if (all || test == 6) test2_link_get_id();
    if (all || test == 7) test1_link_get_name();
    if (all || test == 8) test2_link_get_name();
    if (all || test == 9) test1_link_set_name();
    if (all || test == 10) test2_link_set_name();
    if (all || test == 11) test1_link_get_origin();
    if (all || test == 12) test2_link_get_origin();
    if (all || test == 13) test1_link_set_origin();
    if (all || test == 14) test2_link_set_origin();
    if (all || test == 15) test1_link_get_destination();
    if (all || test == 16) test2_link_get_destination();
    if (all || test == 17) test1_link_set_destination();
    if (all || test == 18) test2_link_set_destination();
    if (all || test == 19) test1_link_get_direction();
    if (all || test == 20) test2_link_get_direction();
    if (all || test == 21) test1_link_set_direction();
    if (all || test == 22) test2_link_set_direction();
    if (all || test == 23) test3_link_set_direction();
    if (all || test == 24) test1_link_get_status();
    if (all || test == 25) test2_link_get_status();
    if (all || test == 26) test1_link_set_status();
    if (all || test == 27) test2_link_set_status();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_link_create(){
    PRINT_TEST_RESULT(link_create(NO_ID) == NULL);
}

void test2_link_create(){
    PRINT_TEST_RESULT(link_create(12) != NULL);
}

void test1_link_destroy(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_destroy(link) == ERROR);
}

void test2_link_destroy(){
    Link *link = NULL;
    link = link_create(2);
    PRINT_TEST_RESULT(link_destroy(link) == OK);
}

void test1_link_get_id(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_id(link) == NO_ID);
}

void test2_link_get_id(){
    Link *link = NULL;
    link = link_create(12);
    PRINT_TEST_RESULT(link_get_id(link) == 12);
    link_destroy(link);
}

void test1_link_get_name(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_name(link) == NULL);
}

void test2_link_get_name(){
    Link *link = NULL;
    link = link_create(4);
    link_set_name(link, "puente");
    PRINT_TEST_RESULT(strcmp (link_get_name(link), "puente") == 0);
    link_destroy(link);
}

void test1_link_set_name(){
    Link *link = NULL;
    link = link_create(3);
    PRINT_TEST_RESULT(link_set_name(link, "rio") == OK);
}

void test2_link_set_name(){
    Link *link = NULL;
    link = link_create(3);
    PRINT_TEST_RESULT(link_set_name(link, NULL) == ERROR);
}

void test1_link_get_origin(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_origin(link) == NO_ID);
}

void test2_link_get_origin(){
    Link *link = NULL;
    link = link_create(49);
    link_set_origin(link, 22);
    PRINT_TEST_RESULT(link_get_origin(link) != NO_ID);
}

void test1_link_set_origin(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_set_origin(link, 3) == ERROR);
}

void test2_link_set_origin(){
    Link *link = NULL;
    link = link_create(5);
    PRINT_TEST_RESULT(link_set_origin(link, 3) == OK);
    link_destroy(link);
}

void test1_link_get_destination(){
    Link *link = NULL;
    link = link_create(8);
    PRINT_TEST_RESULT(link_get_destination(link) == NO_ID);
    link_destroy(link);
}

void test2_link_get_destination(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_destination(link) == NO_ID);
}

void test1_link_set_destination(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_set_destination(link, 7) == ERROR);
}

void test2_link_set_destination(){
    Link *link = NULL;
    link = link_create(8);
    PRINT_TEST_RESULT(link_set_destination(link, 7) == OK);
}

void test1_link_get_direction(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_direction(link) == NO_ID);
}

void test2_link_get_direction(){
    Link *link = NULL;
    link = link_create(8);
    PRINT_TEST_RESULT(link_get_direction(link) == NO_ID);
    link_destroy(link);
}

void test1_link_set_direction(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_set_direction(link, W) == ERROR);
}

void test2_link_set_direction(){
    Link *link = NULL;
    link = link_create(9);
    PRINT_TEST_RESULT(link_set_direction(link, NO_DIR) == ERROR);
    link_destroy(link);
}

void test3_link_set_direction(){
    Link *link = NULL;
    link = link_create(9);
    PRINT_TEST_RESULT(link_set_direction(link, N) == OK);
    link_destroy(link);
}

void test1_link_get_status(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_status(link) == UNDEFINED);   
}

void test2_link_get_status(){
    Link *link = NULL;
    link = link_create(6);
    PRINT_TEST_RESULT(link_get_status(link) == UNDEFINED);   
}

void test1_link_set_status(){
    Link *link = NULL;
    PRINT_TEST_RESULT(link_set_status(link, OPEN) == ERROR);
}

void test2_link_set_status(){
    Link *link = NULL;
    link = link_create(12);
    PRINT_TEST_RESULT(link_set_status(link, OPEN) == OK);
}