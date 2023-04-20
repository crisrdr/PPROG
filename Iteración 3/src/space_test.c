/** 
 * @brief It tests space module
 * 
 * @file space_test.c
 * @author Profesores Pprog, Sofía García Heras y Cristina Rodríguez de los Ríos Medina
 * @version 3.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <limits.h>
#include "space.h"
#include "space_test.h"
#include "test.h"

#define MAX_TESTS 30
#define MAX_ROWS 5
#define MAX_COLUMS 9
/** 
 * @brief Main function for SPACE unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_space_create();
  if (all || test == 2) test2_space_create();
  if (all || test == 3) test1_space_destroy();
  if (all || test == 4) test2_space_destroy();
  if (all || test == 5) test1_space_get_id();
  if (all || test == 6) test2_space_get_id();
  if (all || test == 7) test1_space_set_name();
  if (all || test == 8) test2_space_set_name();
  if (all || test == 9) test3_space_set_name();
  if (all || test == 10) test1_space_get_name();
  if (all || test == 11) test2_space_get_name();
  if (all || test == 12) test1_space_get_objects();
  if (all || test == 13) test2_space_get_objects();
  if (all || test == 14) test1_space_add_object();
  if (all || test == 15) test2_space_add_object();
  if (all || test == 16) test3_space_add_object();
  if (all || test == 17) test1_space_remove_object();
  if (all || test == 18) test2_space_remove_object();
  if (all || test == 19) test1_space_has_object();
  if (all || test == 20) test2_space_has_object();
  if (all || test == 21) test3_space_has_object();
  if (all || test == 22) test4_space_has_object();
  if (all || test == 23) test1_space_get_gdesc();
  if (all || test == 24) test2_space_get_gdesc();
  if (all || test == 25) test1_space_set_gdesc();
  if (all || test == 26) test2_space_set_gdesc();
  if (all || test == 27) test1_space_get_descr();
  if (all || test == 28) test2_space_get_descr();
  if (all || test == 29) test1_space_set_descr();
  if (all || test == 30) test2_space_set_descr();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_space_create() {
  int result;
  Space *s;
  s = space_create(5);
  result=s!=NULL ;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_create() {
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_get_id(s) == 4);
  space_destroy(s);
}

void test1_space_destroy(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_destroy(s) == ERROR);
}

void test2_space_destroy(){
  Space *s = NULL;
  s = space_create(5);
  PRINT_TEST_RESULT(space_destroy(s) == OK);
}

void test1_space_get_id(){
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
  space_destroy(s);
}
void test2_space_get_id(){
   Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_get_objects(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_objects(s) == NULL);
}

void test2_space_get_objects(){
  Space *s = NULL;
  s = space_create(12);
  PRINT_TEST_RESULT(space_get_objects(s) != NULL);
  space_destroy(s);
}

void test1_space_add_object() {
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_add_object(s, 12) == OK);
  space_destroy(s);
}

void test2_space_add_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_add_object(s, 12) == ERROR);
}

void test3_space_add_object() {
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_add_object(s, NO_ID) == ERROR);
  space_destroy(s);
}

void test1_space_remove_object() {
  Space *s = NULL;
  s = space_create(5);
  space_add_object(s, 12);
  PRINT_TEST_RESULT(space_remove_object(s, 12) == OK);
  space_destroy(s);
}

void test2_space_remove_object() {
  Space *s = NULL;
  s = space_create(5);
  PRINT_TEST_RESULT(space_remove_object(s, 4) == ERROR);
  space_destroy(s);
}

void test1_space_has_object() {
  Space *s = NULL;
  s = space_create(5);
  PRINT_TEST_RESULT(space_has_object(s, 5) == FALSE);
  space_destroy(s);
}

void test2_space_has_object() {
  Space *s = NULL;
  s = space_create(5);
  PRINT_TEST_RESULT(space_has_object(s, NO_ID) == FALSE);
  space_destroy(s);
}

void test3_space_has_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_has_object(s, 3) == FALSE);
  space_destroy(s);
}
void test4_space_has_object() {
  Space *s = NULL;
  s = space_create(5);
  space_add_object(s, 10);
  PRINT_TEST_RESULT(space_has_object(s, 10) == TRUE);
  space_destroy(s);
}

void test1_space_get_gdesc() {
  Space *s = NULL; 
  char **gdesc = NULL;  
  int i;
  s = space_create(11);
  gdesc = (char**) malloc(N_S * sizeof(char*));
  for (i = 0; i < N_S; i++) {
    gdesc[i] = (char*) calloc(N_C+1, sizeof(char));
    strcpy(gdesc[i], "---------");
  }
  space_set_gdesc(s, gdesc);
  PRINT_TEST_RESULT(space_get_gdesc(s) != NULL);
  space_destroy(s);
  for (i=0; i < N_S; i++)
    free(gdesc[i]);
  free(gdesc);
}

void test2_space_get_gdesc() {
  Space *s = NULL; 
  PRINT_TEST_RESULT(space_get_gdesc(s) == NULL);
}

void test1_space_set_gdesc() {
  Space *s = NULL;
  char **gdesc = NULL; 
  s = space_create(14);
  PRINT_TEST_RESULT(space_set_gdesc(s, gdesc) == ERROR);
  space_destroy(s);
}

void test2_space_set_gdesc(){
  Space *s = NULL;
  char **gdesc = NULL;
  PRINT_TEST_RESULT(space_set_gdesc(s, gdesc) == ERROR);
}

void test1_space_get_descr(){
  Space *s = NULL;
  char **gdesc = NULL;
  int i;
  s = space_create(11);
  gdesc = (char **) malloc(N_S * sizeof(char *));
  for (i = 0; i < N_S; i++) {
    gdesc[i] = (char *) calloc(N_C + 1, sizeof(char));
    strcpy(gdesc[i], "---------");
  }
  space_set_gdesc(s, gdesc);
  PRINT_TEST_RESULT(space_get_gdesc(s) != NULL);
  space_destroy(s);
  for (i = 0; i < N_S; i++)
    free(gdesc[i]);
  free(gdesc);
}

void test2_space_get_descr(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_set_descr(){
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_descr(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_descr(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_descr(s, "hola") == ERROR);
}
