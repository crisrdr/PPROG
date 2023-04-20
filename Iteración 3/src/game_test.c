/**
 * @brief It tests game module
 *
 * @file game_test.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 24-05-2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "game_test.h"
#include "test.h"

#define MAX_TESTS 59

int main(int argc, char** argv){
  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Game:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_game_create();
    if (all || test == 2) test1_game_create_from_file();
    if (all || test == 3) test2_game_create_from_file();
    if (all || test == 4) test1_game_destroy();
    if (all || test == 5) test2_game_destroy();
    if (all || test == 6) test1_game_add_space();
    if (all || test == 7) test2_game_add_space();
    if (all || test == 8) test3_game_add_space();
    if (all || test == 9) test1_game_get_space();
    if (all || test == 10) test2_game_get_space();
    if (all || test == 11) test3_game_get_space();
    if (all || test == 12) test1_game_get_player();
    if (all || test == 13) test2_game_get_player();
    if (all || test == 14) test3_game_get_player();
    if (all || test == 15) test1_game_set_player();
    if (all || test == 16) test2_game_set_player();
    if (all || test == 17) test1_game_get_player_location();
    if (all || test == 18) test2_game_get_player_location();
    if (all || test == 19) test1_game_set_player_location();
    if (all || test == 20) test2_game_set_player_location();
    if (all || test == 21) test1_game_set_enemy();
    if (all || test == 22) test2_game_set_enemy();
    if (all || test == 23) test1_game_get_enemy();
    if (all || test == 24) test2_game_get_enemy();
    if (all || test == 25) test3_game_get_enemy();
    if (all || test == 26) test1_game_set_enemy_location();
    if (all || test == 27) test2_game_set_enemy_location();
    if (all || test == 28) test1_game_get_enemy_location();
    if (all || test == 29) test2_game_get_enemy_location();
    if (all || test == 30) test1_game_add_object();
    if (all || test == 31) test2_game_add_object();
    if (all || test == 32) test3_game_add_object();
    if (all || test == 33) test1_game_get_object();
    if (all || test == 34) test2_game_get_object();
    if (all || test == 35) test1_game_get_object_id_at();
    if (all || test == 36) test2_game_get_object_id_at();
    if (all || test == 37) test3_game_get_object_id_at();
    if (all || test == 38) test1_game_get_object_by_name();
    if (all || test == 39) test2_game_get_object_by_name();
    if (all || test == 40) test3_game_get_object_by_name();
    if (all || test == 41) test1_game_get_object_location();
    if (all || test == 42) test2_game_get_object_location();
    if (all || test == 43) test1_game_move_object();
    if (all || test == 44) test2_game_move_object();
    if (all || test == 45) test1_game_update();
    if (all || test == 46) test2_game_update();
    if (all || test == 47) test1_game_get_last_command();
    if (all || test == 48) test2_game_get_last_command();
    if (all || test == 49) test3_game_get_last_command();
    if (all || test == 50) test1_game_is_over();
    if (all || test == 51) test2_game_is_over();
    if (all || test == 52) test1_game_get_connection_status();
    if (all || test == 53) test1_game_get_connection_status();
    if (all || test == 54) test1_game_get_connection();
    if (all || test == 55) test2_game_get_connection();
    if (all || test == 56) test1_game_add_link();
    if (all || test == 57) test2_game_add_link();
    if (all || test == 58) test1_game_get_dest_connection_status();
    if (all || test == 59) test2_game_get_dest_connection_status();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_game_create(){
    PRINT_TEST_RESULT(game_create() != NULL);
}

void test1_game_create_from_file(){
    PRINT_TEST_RESULT(game_create_from_file(NULL) == NULL);
}

void test2_game_create_from_file(){
    PRINT_TEST_RESULT(game_create_from_file("hormiguero.dat") != NULL);
}

void test1_game_destroy(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_destroy(game) == ERROR);
}

void test2_game_destroy(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_destroy(game) == OK);
}

void test1_game_add_space(){
    Game *game = NULL;
    Space *space = NULL;
    PRINT_TEST_RESULT(game_add_space(game, space) == ERROR);
}

void test2_game_add_space(){
    Game *game = NULL;
    Space *space = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_add_space (game, space) == ERROR);
    game_destroy(game);
}

void test3_game_add_space(){
    Game *game = NULL;
    Space *space = NULL;
    game = game_create();
    space = space_create(5);
    PRINT_TEST_RESULT(game_add_space (game, space) == OK);
    game_destroy(game);
}

void test1_game_get_space(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_get_space(game, NO_ID) == NULL);
}

void test2_game_get_space(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_space(game, NO_ID) == NULL);
    game_destroy(game);
}

void test3_game_get_space(){
    Game *game = NULL;
    Space *space = NULL;
    game = game_create();
    space = space_create(5);
    game_add_space(game, space);
    PRINT_TEST_RESULT(game_get_space(game, 5) == space);
    game_destroy(game);
}

void test1_game_get_player(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_get_player(game) == NULL);
}

void test2_game_get_player(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_player(game) == NULL);
    game_destroy(game);
}

void test3_game_get_player(){
    Game *game = NULL;
    Player *player = NULL;
    game = game_create();
    player = player_create(5);
    game_set_player(game, player);
    PRINT_TEST_RESULT(game_get_player(game) == player);
    game_destroy(game);
}

void test1_game_set_player(){
    Game *game = NULL;
    Player *player = NULL;
    game = game_create();
    player = player_create(5);
    PRINT_TEST_RESULT(game_set_player(game, player) == OK);
    game_destroy(game);
}

void test2_game_set_player(){
    Game *game = NULL;
    Player *player = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_set_player(game, player) == ERROR);
    game_destroy(game);
}

void test1_game_get_player_location(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_player_location(game) == NO_ID);
    game_destroy(game);
}

void test2_game_get_player_location(){
    Game *game = NULL;
    Player *player = NULL;
    game = game_create();
    player = player_create(5);
    game_set_player(game, player);
    game_set_player_location(game, 28);
    PRINT_TEST_RESULT(game_get_player_location(game) == 28);
    game_destroy(game);
}

void test1_game_set_player_location(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_set_player_location(game, 19) == ERROR);
}

void test2_game_set_player_location(){
    Game *game = NULL;
    Player *player = NULL;
    game = game_create();
    player = player_create(6);
    game_set_player(game, player);
    PRINT_TEST_RESULT(game_set_player_location(game, 18) == OK);
    game_destroy(game);
}

void test1_game_set_enemy(){
    Game *game = NULL;
    Enemy *enemy = NULL;
    game = game_create();
    enemy = enemy_create(5);
    PRINT_TEST_RESULT(game_set_enemy(game, enemy) == OK);
    game_destroy(game);
}

void test2_game_set_enemy(){
    Game *game = NULL;
    Enemy *enemy = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_set_enemy(game, enemy) == ERROR);
    game_destroy(game);
}

void test1_game_get_enemy(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_get_enemy(game) == NULL);
}

void test2_game_get_enemy(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_enemy(game) == NULL);    
    game_destroy(game);
}

void test3_game_get_enemy(){
    Game *game = NULL;
    Enemy *enemy = NULL;
    game = game_create();
    enemy = enemy_create(8);
    game_set_enemy(game, enemy);
    PRINT_TEST_RESULT(game_get_enemy(game) == enemy);    
    game_destroy(game);
}

void test1_game_set_enemy_location(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_set_enemy_location(game, 10) == ERROR);
}

void test2_game_set_enemy_location(){
    Game *game = NULL;
    Enemy *enemy = NULL;
    game = game_create();
    enemy = enemy_create(5);
    game_set_enemy(game, enemy);
    PRINT_TEST_RESULT(game_set_enemy_location(game, 10) == OK);
    game_destroy(game);
}

void test1_game_get_enemy_location(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_enemy_location(game) == NO_ID);
    game_destroy(game);
}

void test2_game_get_enemy_location(){
    Game *game = NULL;
    Enemy *enemy = NULL;
    game = game_create();
    enemy = enemy_create(8);
    game_set_enemy(game, enemy);
    game_set_enemy_location(game, 19);
    PRINT_TEST_RESULT(game_get_enemy_location(game) == 19);
    game_destroy(game);
}

void test1_game_add_object(){
    Game *game = NULL;
    Object *object = NULL;
    PRINT_TEST_RESULT(game_add_object(game, object) == ERROR);
}

void test2_game_add_object(){
    Game *game = NULL;
    Object *object = NULL;
    game = game_create();
    object = object_create(5);
    PRINT_TEST_RESULT(game_add_object(game, object) == OK);
    game_destroy(game);
}

void test3_game_add_object(){
    Game *game = NULL;
    Object *object = NULL;
    game = game_create();
    object = object_create(NO_ID);
    PRINT_TEST_RESULT(game_add_object(game, object) == ERROR);
    game_destroy(game);
}

void test1_game_get_object(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_object(game, NO_ID) == NULL);
    game_destroy(game);
}

void test2_game_get_object(){
    Game *game = NULL;
    Object *object = NULL;
    game = game_create();
    object = object_create(6);
    game_add_object(game, object);
    PRINT_TEST_RESULT(game_get_object(game, 6) == object);
    game_destroy(game);
}

void test1_game_get_object_id_at(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_get_object_id_at(game, 3) == NO_ID);
}

void test2_game_get_object_id_at(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_object_id_at(game, 3) == NO_ID);
    game_destroy(game);
}

void test3_game_get_object_id_at(){
    Game *game = NULL;
    Object *o1 = NULL, *o2 = NULL;
    game = game_create();
    o1 = object_create(1);
    o2 = object_create(2);
    game_add_object(game, o1);
    game_add_object(game, o2);
    PRINT_TEST_RESULT(game_get_object_id_at(game, 1) == 2);
    game_destroy(game);
}

void test1_game_get_object_by_name(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_object_by_name(game, "rosa") == NULL);
    game_destroy(game);
}

void test2_game_get_object_by_name(){
    Game *game = NULL;
    Object *object = NULL;
    game = game_create();
    object = object_create(6);
    object_set_name(object, "rosa");
    game_add_object(game, object);
    PRINT_TEST_RESULT(game_get_object_by_name(game, NULL) == NULL);
    game_destroy(game);
}

void test3_game_get_object_by_name(){
    Game *game = NULL;
    Object *object = NULL;
    game = game_create();
    object = object_create(6);
    object_set_name(object, "rosa");
    game_add_object(game, object);
    PRINT_TEST_RESULT(game_get_object_by_name(game, "rosa") == object);
    game_destroy(game);
}

void test1_game_get_object_location(){
    Game *game = NULL;
    Object *object = NULL;
    game = game_create();
    object = object_create(9);
    game_add_object(game, object);
    PRINT_TEST_RESULT(game_get_object_location(game, 9) == NO_ID);
    game_destroy(game);
}

void test2_game_get_object_location(){
    Game *game = NULL;
    Object *object = NULL;
    Space *space = NULL;
    game = game_create();
    object = object_create(9);
    space = space_create(10);
    game_add_space(game, space);
    game_add_object(game, object);
    space_add_object(space, 9);
    PRINT_TEST_RESULT(game_get_object_location(game, 9) == 10);
    game_destroy(game);
}

void test1_game_move_object(){
    Game *game = NULL;
    Object *object = NULL;
    Space *space1 = NULL, *space2 = NULL;
    game = game_create();
    object = object_create(9);
    space1 = space_create(10);
    space2  = space_create(4);
    game_add_space(game, space1);
    game_add_space(game, space2);
    game_add_object(game, object);
    space_add_object(space1, 9);
    PRINT_TEST_RESULT(game_move_object(game, 9, 4) == OK);
    game_destroy(game);
}

void test2_game_move_object(){
    Game *game = NULL;
    Object *object = NULL;
    Space *space = NULL;
    game = game_create();
    object = object_create(9);
    space = space_create(10);
    game_add_space(game, space);
    game_add_object(game, object);
    space_add_object(space, 9);
    PRINT_TEST_RESULT(game_move_object(game, 9, 4) == ERROR);
    game_destroy(game);
}

void test1_game_update(){
    Game *game = NULL;
    Command *cmd = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_update(game, cmd) == ERROR);
    game_destroy(game);
}

void test2_game_update(){
    Game *game = NULL;
    Command *cmd = NULL;
    game = game_create();
    cmd = command_create();
    PRINT_TEST_RESULT(game_update(game, cmd) == OK);
    game_destroy(game);
}

void test1_game_get_last_command(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_get_last_command(game) == NULL);
}

void test2_game_get_last_command(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_last_command(game) == NULL);
    game_destroy(game);
}

void test3_game_get_last_command(){
    Game *game = NULL;
    Command *cmd = NULL;
    game = game_create();
    cmd = command_create();
    game_update(game, cmd);
    PRINT_TEST_RESULT(game_get_last_command(game) != NULL);
    game_destroy(game);
}

void test1_game_is_over(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_is_over(game) == TRUE);
}

void test2_game_is_over(){
    Game *game = NULL;
    Player *player = NULL;
    game = game_create();
    player = player_create(7);
    player_set_health(player, 10);
    game_set_player(game, player);
    PRINT_TEST_RESULT(game_is_over(game) == FALSE);
    game_destroy(game);
}

void test1_game_get_connection_status(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_get_connection_status(game, 1, 2) == TRUE);
}

void test2_game_get_connection_status(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_connection_status(game, 1, 2) == TRUE);
    game_destroy(game);
}

void test1_game_get_connection(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_connection(game, NO_ID, NO_DIR) == NO_ID);
    game_destroy(game);
}

void test2_game_get_connection(){
    Game *game = NULL;
    Space *space1 = NULL, *space2 = NULL;
    Link *link = NULL;
    game = game_create();
    space1 = space_create(1);
    space2 = space_create(2);
    game_add_space(game, space1);
    game_add_space(game, space2);
    link = link_create(3);
    link_set_origin(link, 1);
    link_set_destination(link, 2);
    link_set_direction(link, N);
    game_add_link(game, link);
    PRINT_TEST_RESULT(game_get_connection(game, 1, N) == 2);
    game_destroy(game);
}

void test1_game_add_link(){
    Game *game = NULL;
    Link *link = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_add_link(game, link) == ERROR);
    game_destroy(game);
}

void test2_game_add_link(){
    Game *game = NULL;
    Link *link = NULL;
    game = game_create();
    link = link_create(6);
    PRINT_TEST_RESULT(game_add_link(game, link) == OK);
    game_destroy(game);
}

void test1_game_get_dest_connection_status(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_get_dest_connection_status(game, 1, 2) == TRUE);
    game_destroy(game);
}

void test2_game_get_dest_connection_status(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_get_dest_connection_status(game, 1, 2) == TRUE);
}