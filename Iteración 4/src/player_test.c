/** 
 * @brief It tests player module
 * 
 * @file player_test.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "player.h"
#include "player_test.h"
#include "test.h"

#define MAX_TESTS 31

int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Player:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_player_create();
    if (all || test == 2) test2_player_create();
    if (all || test == 3) test1_player_get_id();
    if (all || test == 4) test2_player_get_id();
    if (all || test == 5) test1_player_get_name();
    if (all || test == 6) test2_player_get_name();
    if (all || test == 7) test1_player_set_name();
    if (all || test == 8) test2_player_set_name();
    if (all || test == 9) test1_player_get_location();
    if (all || test == 10) test2_player_get_location();
    if (all || test == 11) test3_player_get_location();
    if (all || test == 12) test1_player_set_location();
    if (all || test == 13) test2_player_set_location();
    if (all || test == 14) test1_player_set_inventory();
    if (all || test == 15) test2_player_set_inventory();
    if (all || test == 16) test1_player_get_inventory();
    if (all || test == 17) test2_player_get_inventory();
    if (all || test == 18) test1_player_add_object();
    if (all || test == 19) test2_player_add_object();
    if (all || test == 20) test3_player_add_object();
    if (all || test == 21) test1_player_remove_object();
    if (all || test == 22) test2_player_remove_object();
    if (all || test == 23) test3_player_remove_object();
    if (all || test == 24) test1_player_has_object();
    if (all || test == 25) test2_player_has_object();
    if (all || test == 26) test1_player_inventory_is_full();
    if (all || test == 27) test2_player_inventory_is_full();
    if (all || test == 28) test1_player_get_health();
    if (all || test == 29) test2_player_get_health();
    if (all || test == 30) test1_player_set_health ();
    if (all || test == 31) test2_player_set_health ();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_player_create(){
    PRINT_TEST_RESULT(player_create(NO_ID) == NULL);
}

void test2_player_create(){
    PRINT_TEST_RESULT(player_create(1) != NULL);
}

void test1_player_get_id(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_id(player) == NO_ID);
}

void test2_player_get_id(){
    Player *player = NULL;
    player = player_create(2);
    PRINT_TEST_RESULT(player_get_id(player) != NO_ID);
    player_destroy(player);
}

void test1_player_get_name(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_name(player) == NULL);
}

void test2_player_get_name(){
    Player *player = NULL;
    player = player_create(2);
    player_set_name(player, "Vencedor");
    PRINT_TEST_RESULT(strcmp (player_get_name(player), "Vencedor") == 0);
    player_destroy(player);
}

void test1_player_set_name(){
    Player *player = NULL;
    player = player_create(2);
    PRINT_TEST_RESULT(player_set_name(player, NULL) == ERROR);
    player_destroy(player);
}

void test2_player_set_name(){
    Player *player = NULL;
    player = player_create(2);
    PRINT_TEST_RESULT(player_set_name(player, "Paco") == OK);
    player_destroy(player);
}

void test1_player_get_location(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_location(player) == NO_ID);
}

void test2_player_get_location(){
    Player *player = NULL;
    player = player_create(1);
    PRINT_TEST_RESULT(player_get_location(player) == NO_ID);
    player_destroy(player);
}

void test3_player_get_location(){
    Player *player = NULL;
    player = player_create(1);
    player_set_location(player, 28);
    PRINT_TEST_RESULT(player_get_location(player) == 28);
    player_destroy(player);
}

void test1_player_set_location(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_location(player, 19) == ERROR);
}

void test2_player_set_location(){
    Player *player = NULL;
    player = player_create(2);
    PRINT_TEST_RESULT(player_set_location(player, 19) == OK);
    player_destroy(player);
}

void test1_player_set_inventory(){
    Player *player = NULL;
    Inventory *i = NULL;
    player = player_create(2);
    PRINT_TEST_RESULT(player_set_inventory(player, i) == ERROR);
    player_destroy(player);
}

void test2_player_set_inventory(){
    Player *player = NULL;
    Inventory *i = NULL;
    player = player_create(2);
    i = inventory_create();
    PRINT_TEST_RESULT(player_set_inventory(player, i) == OK);
    player_destroy(player);
}

void test1_player_get_inventory(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_inventory(player) == NULL);
}

void test2_player_get_inventory(){
    Player *player = NULL;
    player = player_create(2);
    PRINT_TEST_RESULT(player_get_inventory(player) != NULL);
}

void test1_player_add_object(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_add_object(player, 25) == ERROR);
}

void test2_player_add_object(){
    Player *player = NULL;
    player = player_create(2);
    PRINT_TEST_RESULT(player_add_object(player, NO_ID) == ERROR);
    player_destroy(player);
}

void test3_player_add_object(){
    Player *player = NULL;
    player = player_create(2);
    inventory_set_max_objs(player_get_inventory(player), 4);
    PRINT_TEST_RESULT(player_add_object(player, 24) == OK);
    player_destroy(player);
}

void test1_player_remove_object(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_remove_object(player, 35) == ERROR);    
}

void test2_player_remove_object(){
    Player *player = NULL;
    player = player_create(2);
    PRINT_TEST_RESULT(player_remove_object(player, NO_ID) == ERROR);    
    player_destroy(player);
}

void test3_player_remove_object(){
    Player *player = NULL;
    player = player_create(2);
    inventory_set_max_objs(player_get_inventory(player), 4);
    player_add_object(player, 35);
    PRINT_TEST_RESULT(player_remove_object(player, 35) == OK);    
    player_destroy(player);
}

void test1_player_has_object(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_has_object(player, 35) == FALSE);    
}

void test2_player_has_object(){
    Player *player = NULL;
    player = player_create(7);
    inventory_set_max_objs(player_get_inventory(player), 5);
    player_add_object(player, 48);
    player_add_object(player, 64);
    PRINT_TEST_RESULT(player_has_object(player, 48) == TRUE);   
    player_destroy(player); 
}

void test1_player_inventory_is_full(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_inventory_is_full(player) == TRUE);
}

void test2_player_inventory_is_full(){
    Player *player = NULL;
    player = player_create(8);
    inventory_set_max_objs(player_get_inventory(player), 10);
    PRINT_TEST_RESULT(player_inventory_is_full(player) == FALSE);
    player_destroy(player);
}

void test1_player_get_health(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_health(player) == INT_MIN);
}

void test2_player_get_health(){
    Player *player = NULL;
    player = player_create(5);
    PRINT_TEST_RESULT(player_get_health(player) == 0);
    player_destroy(player);
}

void test1_player_set_health(){
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_health(player, 8) == ERROR);
}

void test2_player_set_health(){
    Player *player = NULL;
    player = player_create(2);
    PRINT_TEST_RESULT(player_set_health(player, 8) == OK);
}