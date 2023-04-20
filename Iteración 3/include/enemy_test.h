/**
 * @brief It declares the tests for the enemy module
 *
 * @file enemy_test.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2021
 */
#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H

/**
 * @test Test enemy creation
 * @pre Enemy ID == NO_ID
 * @post Output == NULL
 */
void test1_enemy_create();

/**
 * @test Test enemy creation
 * @pre Enemy ID != NULL
 * @post Output != NULL
 */
void test2_enemy_create();

/**
 * @test Test enemy destruction
 * @pre null pointer to enemy
 * @post Output == ERROR 
 */
void test1_enemy_destroy();

/**
 * @test Test enemy destruction
 * @pre existing enemy
 * @post Output == OK 
 */
void test2_enemy_destroy();

/**
 * @test Test enemy_id get
 * @pre Enemy == null pointer
 * @post Output == NO_ID
 */
void test1_enemy_get_id();

/**
 * @test Test enemy_id get
 * @pre Space ID
 * @post Output == NO_ID
 */
void test2_enemy_get_id();

/**
 * @test Test enemy_name get
 * @pre Enemy == null pointer
 * @post Output == NO_ID
 */
void test1_enemy_get_name();

/**
 * @test Test enemy_name get
 * @pre Enemy name initialized
 * @post Output != 0
 */
void test2_enemy_get_name();

/**
 * @test Test enemy_name setter
 * @pre Name == null pointer
 * @post Output == ERROR
 */
void test1_enemy_set_name();

/**
 * @test Test enemy_name setter
 * @pre pointer to string with name
 * @post Output == OK
 */
void test2_enemy_set_name();

/**
 * @test Test enemy_location get
 * @pre Enemy == null pointer
 * @post Output == NO_ID
 */
void test1_enemy_get_location();

/**
 * @test Test enemy_location get
 * @pre location not initialized
 * @post Output == NO_ID
 */
void test2_enemy_get_location();

/**
 * @test Test enemy_location get
 * @pre location initializec
 * @post Output != NO_ID
 */
void test3_enemy_get_location();

/**
 * @test Test enemy_location setter
 * @pre enemy == null pointer
 * @post Output == ERROR
 */
void test1_enemy_set_location();

/**
 * @test Test enemy_location setter
 * @pre existing enemy
 * @post Output == OK
 */
void test2_enemy_set_location();

/**
 * @test Test enemy_health get
 * @pre enemy == null pointer
 * @post Outpur == NO_ID
 */
void test1_enemy_get_health();

/**
 * @test Test enemy_health get
 * @pre existing enemy
 * @post Outpur != NO_ID
 */
void test2_enemy_get_health();

/**
 * @test Test enemy_health setter
 * @pre enemy == null pointer
 * @post Output == ERROR
 */
void test1_enemy_set_health();

/**
 * @test Test enemy_health setter
 * @pre existing enemy
 * @post Output == OK
 */
void test2_enemy_set_health();

#endif