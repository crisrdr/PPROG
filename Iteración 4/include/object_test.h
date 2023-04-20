/**
 * @brief It declares the tests for the object module
 *
 * @file object_test.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2021
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

/**
 * @test Test object creation
 * @pre NO_ID
 * @post Output == NULL
 */
void test1_object_create();

/**
 * @test Test object creation
 * @pre ID
 * @post Output == NULL
 */
void test2_object_create();

/**
 * @test Test object destruction
 * @pre null pointer to object
 * @post Output == ERROR
 */
void test1_object_destroy();

/**
 * @test Test object destruction
 * @pre existing object
 * @post Output == OK
 */
void test2_object_destroy();

/**
 * @test Test object_id get
 * @pre null pointer to object
 * @post Output == NO_ID
 */
void test1_object_get_id();

/**
 * @test Test object_id get
 * @pre existing objects
 * @post Output != NO_ID
 */
void test2_object_get_id();

/**
 * @test Test object_name get
 * @pre null pointer to object
 * @post Output == NULL
 */
void test1_object_get_name();

/**
 * @test Test object_name get
 * @pre existing object with name initialized
 * @post Output != NULL
 */
void test2_object_get_name();

/**
 * @test Test object_name setter
 * @pre null pointer to name
 * @post OUTPUT == ERROR
 */
void test1_object_set_name();

/**
 * @test Test object_name setter
 * @pre existing object and name
 * @post OUTPUT == OK
 */
void test2_object_set_name();

/**
 * @test Test object_descr setter
 * @pre null pointer to object
 * @post Output == ERROR
 */
void test1_object_set_descr();

/**
 * @test Test object_descr setter
 * @pre existing object and descr
 * @post Output == OK
 */
void test2_object_set_descr();

/**
 * @test Test object_descr get
 * @pre null pointer to object
 * @post Output == NULL
 */
void test1_object_get_descr();

/**
 * @test Test object_descr get
 * @pre existing object initialized
 * @post Output != NULL
 */
void test2_object_get_descr();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_is_movable();

void test2_object_is_movable();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_set_movable();

void test2_object_set_movable();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_get_dependency();

void test2_object_get_dependency();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_set_dependency();

void test2_object_set_dependency();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_get_open_id();

void test2_object_get_open_id();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_set_open_id();

void test2_object_set_open_id();

void test3_object_set_open_id();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_can_illuminate();

void test2_object_can_illuminate();

/**
 * @test
 * @pre
 * @post 
 */
void test1_object_set_illuminate();

void test2_object_set_illuminate();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_is_turnedon();

void test2_object_is_turnedon();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_set_turnedon();

void test2_object_set_turnedon();

/**
 * @test
 * @pre
 * @post
 */
void test1_object_can_be_taken();

void test2_object_can_be_taken();

void test3_object_can_be_taken();

#endif