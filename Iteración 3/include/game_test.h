/**
 * @brief It declares the tests for the game module
 *
 * @file game_test.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 24-05-2021
 */

#ifndef GAME_TEST_H
#define GAME_TEST_H

#include "game.h"

/**
 * @test Test game creation
 * @pre Game create
 * @post Output != NULL
 */
void test1_game_create();

/**
 * @test Test game creation from file
 * @pre null pointer to name
 * @post Outpt == NULL
 */
void test1_game_create_from_file();

/**
 * @test Test game creation from file
 * @pre existing file name
 * @post Outpt != NULL
 */
void test2_game_create_from_file();

/**
 * @test Test game destroy
 * @pre null pointer to game
 * @post Output == ERROR
 */
void test1_game_destroy();

/**
 * @test Test game destroy
 * @pre existing game
 * @post Output == OK
 */
void test2_game_destroy();

/**
 * @test Test game_space add
 * @pre null pointer to game and space
 * @post Output == ERROR
 */
void test1_game_add_space();

/**
 * @test Test game_space add
 * @pre null pointer to space
 * @post Output == ERROR
 */
void test2_game_add_space();

/**
 * @test Test game_space add
 * @pre existing game and space
 * @post Output == OK
 */
void test3_game_add_space();

/**
 * @test Test game_space get
 * @pre null pointer to game
 * @post Output == NULL
 */
void test1_game_get_space();

/**
 * @test Test game_space get
 * @pre NO_ID
 * @post Output == NULL
 */
void test2_game_get_space();

/**
 * @test Test game_space get
 * @pre existing game and space
 * @post Output != NULL
 */
void test3_game_get_space();

/**
 * @test Test game_player get
 * @pre null pointer to game
 * @post Output == NULL
 */
void test1_game_get_player();

/**
 * @test Test game_player get
 * @pre unitialized player
 * @post Output == NULL
 */
void test2_game_get_player();

/**
 * @test Test game_player get
 * @pre existing game and player
 * @post Output != NULL
 */
void test3_game_get_player();

/**
 * @test Test game_player setter
 * @pre existing game and player
 * @post Output == OK
 */
void test1_game_set_player();

/**
 * @test Test game_player setter
 * @pre null pointer to player
 * @post Output == ERROR
 */
void test2_game_set_player();

/**
 * @test Test game_player get location
 * @pre player unitialized
 * @post Output == NO_ID
 */
void test1_game_get_player_location();

/**
 * @test Test game_player get location
 * @pre existing game and player
 * @post Output != NO_ID
 */
void test2_game_get_player_location();

/**
 * @test Test game_player set location
 * @pre null pointer to game
 * @post Output == ERROR
 */
void test1_game_set_player_location();

/**
 * @test Test game_player set location
 * @pre existing game and player
 * @post Output == OK
 */
void test2_game_set_player_location();

/**
 * @test Test game_enemy setter
 * @pre existing game and enemy
 * @post Output == OK
 */
void test1_game_set_enemy();

/**
 * @test Test game_enemy setter
 * @pre null pointer to enemy
 * @post Output == ERROR
 */
void test2_game_set_enemy();

/**
 * @test Test game_enemy get
 * @pre null pointer to game
 * @post Output == NULL
 */
void test1_game_get_enemy();

/**
 * @test Test game_enemy get
 * @pre unitialized enemy
 * @post Output == NULL
 */
void test2_game_get_enemy();

/**
 * @test Test game_enemy get
 * @pre existing game and enemy
 * @post Output != NULL
 */
void test3_game_get_enemy();

/**
 * @test Test game_enemy set location
 * @pre null pointer to game
 * @post Output == ERROR
 */
void test1_game_set_enemy_location();

/**
 * @test Test game_enemy set location
 * @pre existing game and enemy
 * @post Output == OK
 */
void test2_game_set_enemy_location();

/**
 * @test Test game_enemy get location
 * @pre unitialized enemy
 * @post Output == NO_ID
 */
void test1_game_get_enemy_location();

/**
 * @test Test game_enemy get location
 * @pre existing game and enemy
 * @post Output != NO_ID
 */
void test2_game_get_enemy_location();

/**
 * @test Test game_object add
 * @pre null pointer to game and object
 * @post Output == ERROR
 */
void test1_game_add_object();

/**
 * @test Test game_object add
 * @pre existing game and object
 * @post Output == OK
 */
void test2_game_add_object();

/**
 * @test Test game_object add
 * @pre null pointer to game and object
 * @post Output == ERROR
 */
void test3_game_add_object();

/**
 * @test Test game_object get
 * @pre NO_ID
 * @post Output == NULL
 */
void test1_game_get_object();

/**
 * @test Test game_object get
 * @pre existing game and object
 * @post Output != NULL
 */
void test2_game_get_object();

/**
 * @test Test game_object get id at
 * @pre null pointer to game
 * @post Output == NO_ID
 */
void test1_game_get_object_id_at();

/**
 * @test Test game_object get id at
 * @pre objects not added
 * @post Output == NO_ID
 */
void test2_game_get_object_id_at();

/**
 * @test Test game_object get id at
 * @pre existing game and objects
 * @post Output != NO_ID
 */
void test3_game_get_object_id_at();

/**
 * @test Test game_object add by name
 * @pre unitialized object
 * @post Output == NULL
 */
void test1_game_get_object_by_name();

/**
 * @test Test game_object add by name
 * @pre null pointer to name
 * @post Output == NULL
 */
void test2_game_get_object_by_name();

/**
 * @test Test game_object add by name
 * @pre existing game, object and name
 * @post Output != NULL
 */
void test3_game_get_object_by_name();

/**
 * @test Test game_object get location
 * @pre NO_ID
 * @post Output == NO_ID
 */
void test1_game_get_object_location();

/**
 * @test Test game_object get location
 * @pre existing game and object
 * @post Output != NO_ID
 */
void test2_game_get_object_location();

/**
 * @test Test game_object move
 * @pre existing game and object
 * @post Output == OK
 */
void test1_game_move_object();

/**
 * @test Test game_object move
 * @pre non existing space
 * @post Output == ERROR
 */
void test2_game_move_object();

/**
 * @test Test game_update
 * @pre null pointer to command
 * @post Output == ERROR
 */
void test1_game_update();

/**
 * @test Test game_update
 * @pre existing pointer to game and command
 * @post Output == OK
 */
void test2_game_update();

/**
 * @test Test game_last command get
 * @pre null pointer to game
 * @post Output == NULL
 */
void test1_game_get_last_command();

/**
 * @test Test game_last command get
 * @pre uninitialized command
 * @post Output == NULL
 */
void test2_game_get_last_command();

/**
 * @test Test game_last command get
 * @pre existing game and command
 * @post Output != NULL
 */
void test3_game_get_last_command();

/**
 * @test Test game is over
 * @pre null pointer to game
 * @post Output == TRUE
 */
void test1_game_is_over();

/**
 * @test Test game is over
 * @pre existing game and player with max health
 * @post Output == FALSE
 */
void test2_game_is_over();

/**
 * @test Test game_connection get status
 * @pre null pointer to game
 * @post Output == TRUE
 */
void test1_game_get_connection_status();

/**
 * @test Test game_connection get status
 * @pre existing game
 * @post Output == TRUE
 */

void test2_game_get_connection_status();

/**
 * @test Test game_connection get
 * @pre NO_ID, NO_DIR
 * @post Output == NO_ID
 */
void test1_game_get_connection();

/**
 * @test Test game_connection get
 * @pre existing game and initialized link
 * @post Output != NO_ID
 */
void test2_game_get_connection();

/**
 * @test Test game_link add
 * @pre null pointer to link
 * @post Output == ERROR
 */
void test1_game_add_link();

/**
 * @test Test game_link add
 * @pre existing game and link
 * @post Output == OK
 */
void test2_game_add_link();

/**
 * @test Test game get dest connection status
 * @pre uninitialized link
 * @post Output == TRUE
 */
void test1_game_get_dest_connection_status();

/**
 * @test Test game get dest connection status
 * @pre null pointer to game
 * @post Output == TRUE
 */
void test2_game_get_dest_connection_status();

#endif