/**
 * @brief It declares the tests for the game management module
 *
 * @file game_management_test.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 24-05-2021
 */

#ifndef GAME_MANAGEMENT_TEST_H
#define GAME_MANAGEMENT_TEST_H

#include "game.h"

/**
 * @test Test load spaces
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_management_load_spaces();

/**
 * @test Test load spaces
 * @pre loads the spaces from the file
 * @post Output == OK
 */
void test2_game_management_load_spaces();

/**
 * @test Test load objects
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_management_load_objects();

/**
 * @test Test load objects
 * @pre loads the objects from the file
 * @post Output == OK
 */
void test2_game_management_load_objects();

/**
 * @test Test load player
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_management_load_player();

/**
 * @test Test load player
 * @pre loads the player from the file
 * @post Output == OK
 */
void test2_game_management_load_player();

/**
 * @test Test load enemy
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_management_load_enemy();

/**
 * @test Test load enemy
 * @pre loads the enemy from the file
 * @post Output == OK
 */
void test2_game_management_load_enemy();

/**
 * @test Test load link
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_management_load_links();

/**
 * @test Test load links
 * @pre loads the links from the file
 * @post Output == OK
 */
void test2_game_management_load_links();

void test1_game_management_save();

void test2_game_management_save();

void test1_game_management_load();

void test2_game_management_load();

#endif