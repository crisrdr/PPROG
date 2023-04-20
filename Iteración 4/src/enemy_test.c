/** 
 * @brief It tests enemy module
 * 
 * @file enemy_test.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enemy.h"
#include "enemy_test.h"
#include "test.h"

#define MAX_TESTS 18

int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Enemy:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_enemy_create();
  if (all || test == 2) test2_enemy_create();
  if (all || test == 3) test1_enemy_destroy();
  if (all || test == 4) test2_enemy_destroy();
  if (all || test == 5) test1_enemy_get_id();
  if (all || test == 6) test2_enemy_get_id();
  if (all || test == 7) test1_enemy_set_name();
  if (all || test == 8) test2_enemy_set_name();
  if (all || test == 9) test1_enemy_get_name();
  if (all || test == 10) test2_enemy_get_name();
  if (all || test == 11) test1_enemy_get_location();
  if (all || test == 12) test2_enemy_get_location();
  if (all || test == 13) test3_enemy_get_location();
  if (all || test == 14) test1_enemy_set_location();
  if (all || test == 15) test2_enemy_set_location();
  if (all || test == 16) test1_enemy_get_health();
  if (all || test == 17) test2_enemy_get_health();
  if (all || test == 18) test1_enemy_set_health();
  if (all || test == 19) test2_enemy_set_health();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_enemy_create(){
    PRINT_TEST_RESULT(enemy_create(NO_ID) == NULL);
}

void test2_enemy_create(){
    PRINT_TEST_RESULT(enemy_create(12) != NULL);
}

void test1_enemy_destroy(){
    Enemy *enemy = NULL;
    PRINT_TEST_RESULT(enemy_destroy(enemy) == ERROR);
}

void test2_enemy_destroy(){
    Enemy *enemy = NULL;
    enemy = enemy_create(5);
    PRINT_TEST_RESULT(enemy_destroy(enemy) == OK);
}

void test1_enemy_get_id(){
    Enemy *enemy = NULL;
    PRINT_TEST_RESULT(enemy_get_id(enemy) == NO_ID);
}

void test2_enemy_get_id(){
    Enemy *enemy = NULL;
    enemy = enemy_create(12);
    PRINT_TEST_RESULT(enemy_get_id(enemy) != NO_ID);
    enemy_destroy(enemy);
}

void test1_enemy_get_name(){
    Enemy *enemy = NULL;
    PRINT_TEST_RESULT(enemy_get_name(enemy) == NULL);
}

void test2_enemy_get_name(){
    Enemy *enemy = NULL;
    enemy = enemy_create(5);
    enemy_set_name(enemy, "Paco");
    PRINT_TEST_RESULT(strcmp (enemy_get_name(enemy), "Paco") == 0);
    enemy_destroy(enemy);
}

void test1_enemy_set_name(){
    Enemy *enemy = NULL;
    enemy = enemy_create(2);
    PRINT_TEST_RESULT(enemy_set_name(enemy, NULL) == ERROR);
    enemy_destroy(enemy);
}

void test2_enemy_set_name(){
    Enemy *enemy = NULL;
    enemy = enemy_create(2);
    PRINT_TEST_RESULT(enemy_set_name(enemy, "Paco") == OK);
    enemy_destroy(enemy);
}

void test1_enemy_get_location(){
    Enemy *enemy = NULL;
    PRINT_TEST_RESULT(enemy_get_location(enemy) == NO_ID);
}

void test2_enemy_get_location(){
    Enemy *enemy = NULL;
    enemy = enemy_create(1);
    PRINT_TEST_RESULT(enemy_get_location(enemy) == NO_ID);
    enemy_destroy(enemy);
}

void test3_enemy_get_location(){
    Enemy *enemy = NULL;
    enemy = enemy_create(1);
    enemy_set_location(enemy, 28);
    PRINT_TEST_RESULT(enemy_get_location(enemy) == 28);
    enemy_destroy(enemy);
}

void test1_enemy_set_location(){
    Enemy *enemy = NULL;
    PRINT_TEST_RESULT(enemy_set_location(enemy, 19) == ERROR);
}

void test2_enemy_set_location(){
    Enemy *enemy = NULL;
    enemy = enemy_create(2);
    PRINT_TEST_RESULT(enemy_set_location(enemy, 19) == OK);
    enemy_destroy(enemy);
}

void test1_enemy_get_health(){
    Enemy *enemy = NULL;
    PRINT_TEST_RESULT(enemy_get_health(enemy) == NO_ID);
}

void test2_enemy_get_health(){
    Enemy *enemy = NULL;
    enemy = enemy_create(5);
    PRINT_TEST_RESULT(enemy_get_health(enemy) == 10);
    enemy_destroy(enemy);
}

void test1_enemy_set_health(){
    Enemy *enemy = NULL;
    PRINT_TEST_RESULT(enemy_set_health(enemy, 8) == ERROR);
}

void test2_enemy_set_health(){
    Enemy *enemy = NULL;
    enemy = enemy_create(2);
    PRINT_TEST_RESULT(enemy_set_health(enemy, 8) == OK);
}