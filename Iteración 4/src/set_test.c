/**
 * @brief It tests set module
 *
 * @file set_test.c
 * @author Profesores Pprog
 * @version 3.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "set.h"
#include "set_test.h"
#include "test.h"

#define MAX_TESTS 14
int main(int argc, char **argv)
{

  int test = 0;
  int all = 1;

  if (argc < 2)
  {
    printf("Running all test for module Set:\n");
  }
  else
  {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS)
    {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }
  if (all || test == 1) test1_set_create();
  if (all || test == 2) test2_set_create();
  if (all || test == 3) test1_set_destroy();
  if (all || test == 4) test2_set_destroy();
  if (all || test == 5) test1_set_add();
  if (all || test == 6) test2_set_add();
  if (all || test == 7) test3_set_add();
  if (all || test == 8) test1_set_del();
  if (all || test == 9) test2_set_del();
  if (all || test == 10) test3_set_del();
  if (all || test == 11) test1_set_has_id();
  if (all || test == 12) test2_set_has_id();
  if (all || test == 13) test1_set_get_nids();
  if (all || test == 14) test2_set_get_nids();
  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_set_create()
{
  Set *set;
  set = set_create();
  PRINT_TEST_RESULT(set != NULL);
  set_destroy(set);
}

void test2_set_create()
{
  Set *set;
  set = set_create();
  PRINT_TEST_RESULT(set_get_nids(set) == 0);
  set_destroy(set);
}

void test1_set_destroy(){
  Set *set = NULL;
  PRINT_TEST_RESULT(set_destroy(set) == ERROR);
}

void test2_set_destroy(){
  Set *set = NULL;
  set = set_create();
  PRINT_TEST_RESULT(set_destroy(set) == OK);
}

void test1_set_add()
{
  Set *set = NULL;
  set = set_create();
  PRINT_TEST_RESULT(set_add(set, 5) == OK);
  set_destroy(set);
}
void test2_set_add()
{
  Set *set = NULL;
  PRINT_TEST_RESULT(set_add(set, 5) == ERROR);
}
void test3_set_add()
{
  Set *set;
  set = set_create();
  PRINT_TEST_RESULT(set_add(set, NO_ID) == ERROR);
  set_destroy(set);
}
void test1_set_del()
{
  Set *set;
  set = set_create();
  PRINT_TEST_RESULT(set_del(set, 6) == ERROR);
  set_destroy(set);
}
void test2_set_del()
{
  Set *set = NULL;
  PRINT_TEST_RESULT(set_del(set, NO_ID) == ERROR);
}
void test3_set_del()
{
  Set *set = NULL;
  set = set_create();
  set_add(set, 10);
  PRINT_TEST_RESULT(set_del(set, 10) == OK);
  set_destroy(set);
}
void test1_set_has_id()
{
  Set *set = NULL;
  set = set_create();
  set_add(set, 12);
  PRINT_TEST_RESULT(set_has_id(set, 12) == TRUE);
  set_destroy(set);
}
void test2_set_has_id()
{
  Set *set = NULL;
  set = set_create();
  PRINT_TEST_RESULT(set_has_id(set, 12) == FALSE);
  set_destroy(set);
}
void test1_set_get_nids()
{
  Set *set = NULL;
  set = set_create();
  PRINT_TEST_RESULT(set_get_nids(set) == 0);
  set_destroy(set);
}
void test2_set_get_nids()
{
  Set *set = NULL;
  PRINT_TEST_RESULT(set_get_nids(set) == INT_MIN);
}