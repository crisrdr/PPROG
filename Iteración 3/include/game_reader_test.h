/**
 * @brief It declares the tests for the game reader module
 *
 * @file game_reader_test.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 24-05-2021
 */

#ifndef GAME_READER_TEST_H
#define GAME_READER_TEST_H

#include "game.h"

/**
 * @test Test load spaces
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_reader_load_spaces();

/**
 * @test Test load spaces
 * @pre loads the spaces from the file
 * @post Output == OK
 */
void test2_game_reader_load_spaces();

/**
 * @test Test load objects
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_reader_load_objects();

/**
 * @test Test load objects
 * @pre loads the objects from the file
 * @post Output == OK
 */
void test2_game_reader_load_objects();

/**
 * @test Test load player
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_reader_load_player();

/**
 * @test Test load player
 * @pre loads the player from the file
 * @post Output == OK
 */
void test2_game_reader_load_player();

/**
 * @test Test load enemy
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_reader_load_enemy();

/**
 * @test Test load enemy
 * @pre loads the enemy from the file
 * @post Output == OK
 */
void test2_game_reader_load_enemy();

/**
 * @test Test load link
 * @pre game pointer == NULL
 * @post Output == ERROR
 */
void test1_game_reader_load_links();

/**
 * @test Test load links
 * @pre loads the links from the file
 * @post Output == OK
 */
void test2_game_reader_load_links();

#endif