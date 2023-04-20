/**
 * @brief It tests inventory module
 *
 * @file inventory_test.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 24-05-2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "inventory_test.h"
#include "test.h"


#define MAX_TESTS 16

int main(int argc, char** argv){
  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Inventory:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_inventory_create();
    if (all || test == 2) test1_inventory_set_max_objs();
    if (all || test == 3) test2_inventory_set_max_objs();
    if (all || test == 4) test1_inventory_get_max_objs();
    if (all || test == 5) test2_inventory_get_max_objs();
    if (all || test == 6) test1_inventory_set_objects();
    if (all || test == 7) test2_inventory_set_objects();
    if (all || test == 8) test3_inventory_set_objects();
    if (all || test == 9) test1_inventory_get_objects();
    if (all || test == 10) test2_inventory_get_objects();
    if (all || test == 11) test1_inventory_add_object();
    if (all || test == 12) test2_inventory_add_object();
    if (all || test == 13) test3_inventory_add_object();
    if (all || test == 14) test1_inventory_remove_object();
    if (all || test == 15) test2_inventory_remove_object();
    if (all || test == 16) test3_inventory_remove_object();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_inventory_create(){
    PRINT_TEST_RESULT(inventory_create() != NULL);
}

void test1_inventory_set_max_objs(){
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_set_max_objs(i, 10) == ERROR);
}

void test2_inventory_set_max_objs(){
    Inventory *i = NULL;
    i = inventory_create();
    PRINT_TEST_RESULT(inventory_set_max_objs(i, 10) == OK);
    inventory_destroy(i);
}

void test1_inventory_get_max_objs(){
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_get_max_objs(i) == -1);
}

void test2_inventory_get_max_objs(){
    Inventory *i = NULL;
    i = inventory_create();
    inventory_set_max_objs(i, 19);
    PRINT_TEST_RESULT(inventory_get_max_objs(i) == 19);
    inventory_destroy(i);
}

void test1_inventory_set_objects(){
    Inventory *i = NULL;
    Set *set = NULL;
    PRINT_TEST_RESULT(inventory_set_objects(i, set) == ERROR);
}

void test2_inventory_set_objects(){
    Inventory *i = NULL;
    Set *set = NULL;
    i = inventory_create();
    PRINT_TEST_RESULT(inventory_set_objects(i, set) == ERROR);
    inventory_destroy(i);
}

void test3_inventory_set_objects(){
    Inventory *i = NULL;
    Set *set = NULL;
    i = inventory_create();
    set = set_create();
    PRINT_TEST_RESULT(inventory_set_objects(i, set) == OK);
    inventory_destroy(i);
}

void test1_inventory_get_objects(){
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_get_objects(i) == NULL);
}

void test2_inventory_get_objects(){
    Inventory *i = NULL;
    i = inventory_create();
    PRINT_TEST_RESULT(inventory_get_objects(i) != NULL);
    inventory_destroy(i);
}

void test1_inventory_add_object(){
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_add_object(i, 14) == ERROR);
}

void test2_inventory_add_object(){
    Inventory *i = NULL;
    i = inventory_create();
    PRINT_TEST_RESULT(inventory_add_object(i, 14) == ERROR);
    inventory_destroy(i);
}

void test3_inventory_add_object(){
    Inventory *i = NULL;
    i = inventory_create();
    inventory_set_max_objs(i, 2);
    PRINT_TEST_RESULT(inventory_add_object(i, 14) == OK);
    inventory_destroy(i);
}

void test1_inventory_remove_object(){
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_remove_object(i, 19) == ERROR);
}

void test2_inventory_remove_object(){
    Inventory *i = NULL;
    i = inventory_create();
    PRINT_TEST_RESULT(inventory_remove_object(i, 19) == ERROR);
    inventory_destroy(i);
}

void test3_inventory_remove_object(){
    Inventory *i = NULL;
    i = inventory_create();
    inventory_set_max_objs(i, 3);
    inventory_add_object(i, 19);
    PRINT_TEST_RESULT(inventory_remove_object(i, 19) == OK);
    inventory_destroy(i);
}