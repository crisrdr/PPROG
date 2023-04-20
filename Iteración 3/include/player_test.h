/**
 * @brief It declares the tests for the player module
 *
 * @file player_test.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2021
 */

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include "player.h"

/**
 * @test Test player creation
 * @pre ID == NO_ID
 * @post Output == NULL
 */
void test1_player_create();

/**
 * @test Test player creation
 * @pre ID != NO_ID
 * @post Output != NULL
 */
void test2_player_create();

/**
 * @test Test player_id get
 * @pre null pointer to player
 * @post Output == NO_ID
 */
void test1_player_get_id();

/**
 * @test Test player_id get
 * @pre existing player
 * @post Output != NO_ID
 */
void test2_player_get_id();

/**
 * @test Test player_name get
 * @pre null pointer to player
 * @post Output == NULL
 */
void test1_player_get_name();

/**
 * @test Test player_name get
 * @pre existing player with initialized name
 * @post Output != NULL
 */
void test2_player_get_name();

/**
 * @test Test player_name setter
 * @pre null pointer to name
 * @post Output == ERROR
 */
void test1_player_set_name();

/**
 * @test Test player_name setter
 * @pre existing player and name
 * @post Output == OK
 */
void test2_player_set_name();

/**
 * @test Test player_location get
 * @pre null pointer to player
 * @post Output == NO_ID
 */
void test1_player_get_location();

/**
 * @test Test player_location get
 * @pre uninitialized location
 * @post Output == NO_ID
 */
void test2_player_get_location();

/**
 * @test Test player_location get
 * @pre existing player and initialized location
 * @post Output != NO_ID
 */
void test3_player_get_location();

/**
 * @test Test player_location setter
 * @pre null pointer to player
 * @post Output == ERROR
 */
void test1_player_set_location();

/**
 * @test Test player_location setter
 * @pre existing player and location
 * @post Output == OK
 */
void test2_player_set_location();

/**
 * @test Test player_inventory setter
 * @pre null pointer to inventory
 * @post Output == ERROR
 */
void test1_player_set_inventory();

/**
 * @test Test player_inventory setter
 * @pre existing player and inventory
 * @post Output == OK
 */
void test2_player_set_inventory();

/**
 * @test Test player_inventory get
 * @pre null pointer to player
 * @post Outpur == NULL
 */
void test1_player_get_inventory();

/**
 * @test Test player_inventory get
 * @pre existing player
 * @post Outpur != NULL
 */
void test2_player_get_inventory();

/**
 * @test Test player_object add
 * @pre null pointer to player
 * @post Output == ERROR
 */
void test1_player_add_object();

/**
 * @test Test player_object add
 * @pre NO_ID
 * @post Output == ERROR
 */
void test2_player_add_object();

/**
 * @test Test player_object add
 * @pre existing player and ID
 * @post Output == OK
 */
void test3_player_add_object();

/**
 * @test Test player_object remove
 * @pre null pointer to player
 * @post Output == ERROR
 */
void test1_player_remove_object();

/**
 * @test Test player_object remove
 * @pre NO_ID
 * @post Output == ERROR
 */
void test2_player_remove_object();

/**
 * @test Test player_object remove
 * @pre existing player with objects initialized
 * @post Output == OK
 */
void test3_player_remove_object();

/**
 * @test Test player_object has
 * @pre null pointer to player
 * @post Output == FALSE
 */
void test1_player_has_object();

/**
 * @test Test player_object has
 * @pre existing player with objects
 * @post Output == TRUE
 */
void test2_player_has_object();

/**
 * @test Test player_inventory is full
 * @pre null pointer to player
 * @post Output == TRUE
 */
void test1_player_inventory_is_full();

/**
 * @test Test player_inventory is full
 * @pre existing player with objects
 * @post Output == FALSE
 */
void test2_player_inventory_is_full();

/**
 * @test Test player_health get
 * @pre null pointer to player
 * @post Output == INT_MIN
 */
void test1_player_get_health();

/**
 * @test Test player_health get
 * @pre existing player
 * @post Output == 0
 */
void test2_player_get_health();

/**
 * @test Test player_health setter
 * @pre null pointer to player
 * @post Output == ERROR
 */
void test1_player_set_health ();

/**
 * @test Test player_health setter
 * @pre existing player
 * @post Output == OK
 */
void test2_player_set_health ();

#endif