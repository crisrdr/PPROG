/** 
 * @brief It tests game reader module
 * 
 * @file game_reader_test.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 24-05-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "game_reader.h"
#include "game_reader_test.h"
#include "test.h"

#define MAX_TESTS 10

int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Game reader:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_game_reader_load_spaces();
  if (all || test == 2) test2_game_reader_load_spaces();
  if (all || test == 3) test1_game_reader_load_objects();
  if (all || test == 4) test2_game_reader_load_objects();
  if (all || test == 5) test1_game_reader_load_player();
  if (all || test == 6) test2_game_reader_load_player();
  if (all || test == 7) test1_game_reader_load_enemy();
  if (all || test == 8) test2_game_reader_load_enemy();
  if (all || test == 9) test1_game_reader_load_links();
  if (all || test == 10) test2_game_reader_load_links();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_game_reader_load_spaces(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  PRINT_TEST_RESULT (game_reader_load_spaces(game, filename) == ERROR);
}

void test2_game_reader_load_spaces(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  game = game_create();
  PRINT_TEST_RESULT (game_reader_load_spaces(game, filename) == OK);
  game_destroy(game);
}

void test1_game_reader_load_objects(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  PRINT_TEST_RESULT (game_reader_load_objects(game, filename) == ERROR);
}

void test2_game_reader_load_objects(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  game = game_create();
  PRINT_TEST_RESULT (game_reader_load_objects(game, filename) == OK);
  game_destroy(game);
}

void test1_game_reader_load_player(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  PRINT_TEST_RESULT (game_reader_load_player(game, filename) == ERROR);
}

void test2_game_reader_load_player(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  game = game_create();
  PRINT_TEST_RESULT (game_reader_load_player(game, filename) == OK);
  game_destroy(game);
}

void test1_game_reader_load_enemy(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  PRINT_TEST_RESULT (game_reader_load_enemy(game, filename) == ERROR);
}

void test2_game_reader_load_enemy(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  game = game_create();
  PRINT_TEST_RESULT (game_reader_load_enemy(game, filename) == OK);
  game_destroy(game);
}

void test1_game_reader_load_links(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  PRINT_TEST_RESULT (game_reader_load_links(game, filename) == ERROR);
}

void test2_game_reader_load_links(){
  Game *game = NULL;
  char *filename = "hormiguero.dat";
  game = game_create();
  PRINT_TEST_RESULT (game_reader_load_links(game, filename) == OK);
  game_destroy(game);
}