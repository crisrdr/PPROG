/** 
 * @brief It tests command module
 * 
 * @file command_test.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "command_test.h"
#include "test.h"

#define MAX_TESTS 18

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


  if (all || test == 1) test1_command_create();
  if (all || test == 2) test1_command_destroy();
  if (all || test == 3) test2_command_destroy();
  if (all || test == 4) test1_command_set_arg();
  if (all || test == 5) test2_command_set_arg();
  if (all || test == 6) test1_command_get_arg();
  if (all || test == 7) test2_command_get_arg();
  if (all || test == 8) test1_command_set_type();
  if (all || test == 9) test2_command_set_type();
  if (all || test == 10) test3_command_set_type();
  if (all || test == 11) test1_command_get_type();
  if (all || test == 12) test2_command_get_type();
  if (all || test == 13) test3_command_get_type();
  if (all || test == 14) test1_command_set_status();
  if (all || test == 15) test2_command_set_status();
  if (all || test == 16) test1_command_get_status();
  if (all || test == 17) test2_command_get_status();
  if (all || test == 18) test3_command_get_status();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_command_create(){
    Command *cmd = NULL;
    cmd = command_create();
    PRINT_TEST_RESULT(cmd != NULL);
    command_destroy(cmd);
}

void test1_command_destroy(){
  Command *cmd = NULL;
  PRINT_TEST_RESULT(command_destroy(cmd) == ERROR);
}

void test2_command_destroy(){
  Command *cmd = NULL;
  cmd = command_create();
  PRINT_TEST_RESULT(command_destroy(cmd) == OK);
}

void test1_command_set_arg(){
  Command *cmd = NULL;
  cmd = command_create();
  PRINT_TEST_RESULT(command_set_arg(cmd, "take") == OK);
  command_destroy(cmd);
}

void test2_command_set_arg(){
  Command *cmd = NULL;
  cmd = command_create();
  PRINT_TEST_RESULT(command_set_arg(cmd, NULL) == ERROR);
  command_destroy(cmd);
}

void test1_command_get_arg(){
  Command *cmd = NULL;
  cmd = command_create();
  command_set_arg(cmd, "adios");
  PRINT_TEST_RESULT(strcmp(command_get_arg(cmd), "adios") == 0);
  command_destroy(cmd);
}

void test2_command_get_arg(){
  Command *s = NULL;
  PRINT_TEST_RESULT(command_get_arg(s) == NULL);
}

void test1_command_set_type(){
  Command *cmd = NULL;
  PRINT_TEST_RESULT(command_set_type(cmd, NEXT) == ERROR);
}

void test2_command_set_type(){
  Command *cmd = NULL;
  cmd = command_create();
  PRINT_TEST_RESULT(command_set_type(cmd, NEXT) == OK);
  command_destroy(cmd);
}

void test3_command_set_type(){
  Command *cmd = NULL;
  cmd = command_create();
  PRINT_TEST_RESULT(command_set_type(cmd, NO_CMD) == ERROR);
  command_destroy(cmd);
}

void test1_command_get_type(){
  Command *cmd = NULL;
  PRINT_TEST_RESULT(command_get_type(cmd) == NO_CMD);
}

void test2_command_get_type(){
  Command *cmd = NULL;
  cmd = command_create();
  PRINT_TEST_RESULT(command_get_type(cmd) == NO_CMD);
  command_destroy(cmd);
}

void test3_command_get_type(){
  Command *cmd = NULL;
  cmd = command_create();
  command_set_type(cmd, NEXT);
  PRINT_TEST_RESULT(command_get_type(cmd) == NEXT);
  command_destroy(cmd);
}

void test1_command_set_status(){
  Command *cmd = NULL;
  PRINT_TEST_RESULT(command_set_status(cmd, OK) == ERROR);
}

void test2_command_set_status(){
  Command *cmd = NULL;
  cmd = command_create();
  PRINT_TEST_RESULT(command_set_status(cmd, ERROR) == OK);
  command_destroy(cmd);
}

void test1_command_get_status(){
  Command *cmd = NULL;
  PRINT_TEST_RESULT(command_get_status(cmd) == ERROR);
}

void test2_command_get_status(){
  Command *cmd = NULL;
  cmd = command_create();
  PRINT_TEST_RESULT(command_get_status(cmd) == ERROR);
  command_destroy(cmd); 
}

void test3_command_get_status(){
  Command *cmd = NULL;
  cmd = command_create();
  command_set_status(cmd, OK);
  PRINT_TEST_RESULT(command_get_status(cmd) == OK);
  command_destroy(cmd);
}