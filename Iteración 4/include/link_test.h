/**
 * @brief It declares the tests for the link module
 *
 * @file link_test.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2021
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Test link creation
 * @pre NO_ID
 * @post Output == NULL
 */
void test1_link_create();

/**
 * @test Test link creation
 * @pre ID
 * @post Output != NULL
 */
void test2_link_create();

/**
 * @test Test link destruction
 * @pre null pointer to link
 * @post Output == ERROR
 */
void test1_link_destroy();

/**
 * @test Test link destruction
 * @pre existing link
 * @post Output == OK
 */
void test2_link_destroy();

/**
 * @test Test link_id get
 * @pre null pointer to link
 * @post Output == NULL
 */
void test1_link_get_id();

/**
 * @test Test link_id get
 * @pre existing link
 * @post Output != NULL
 */
void test2_link_get_id();

/**
 * @test Test link_name get
 * @pre null pointer to link
 * @post Output == NULL
 */
void test1_link_get_name();

/**
 * @test Test link_name get
 * @pre existing link initialized
 * @post Output != NULL
 */
void test2_link_get_name();

/**
 * @test Test link_name setter
 * @pre existing link and name
 * @post Output == OK
 */
void test1_link_set_name();

/**
 * @test Test link_name setter
 * @pre name == NULL
 * @post Output == ERROR
 */
void test2_link_set_name();

/**
 * @test Test link_origon get
 * @pre null pointer to link
 * @post Output == NO_ID
 */
void test1_link_get_origin();

/**
 * @test Test link_origon get
 * @pre existing link initialized
 * @post Output != NO_ID
 */
void test2_link_get_origin();

/**
 * @test Test link_origin setter
 * @pre null pointer to link
 * @post Output == ERROR
 */
void test1_link_set_origin();

/**
 * @test Test link_origin setter
 * @pre existing link
 * @post Output == OK
 */
void test2_link_set_origin();

/**
 * @test Test link_destination get
 * @pre existing link
 * @post Output == OK
 */
void test1_link_get_destination();

/**
 * @test Test link_destination get
 * @pre null pointer to link
 * @post Output == NULL
 */
void test2_link_get_destination();

/**
 * @test Test link_destination setter
 * @pre null pointer to link
 * @post Output == ERROR
 */
void test1_link_set_destination();

/**
 * @test Test link_destination setter
 * @pre existing link
 * @post Output == OK
 */
void test2_link_set_destination();

/**
 * @test Test link_direction get
 * @pre null pointer to link
 * @post Output == NULL
 */
void test1_link_get_direction();

/**
 * @test Test link_direction get
 * @pre existing link
 * @post Output == NO_ID
 */
void test2_link_get_direction();

/**
 * @test Test link_destination setter
 * @pre null pointer to link
 * @post Output == ERROR
 */
void test1_link_set_direction();

/**
 * @test Test link_destination setter
 * @pre NO_DIR
 * @post Output == ERROR
 */
void test2_link_set_direction();

/**
 * @test Test link_destination setter
 * @pre existing link and direction
 * @post Output == OK
 */
void test3_link_set_direction();

/**
 * @test Test link_status get
 * @pre null pointer to link
 * @post Output == UNDEFINED
 */
void test1_link_get_status();

/**
 * @test Test link_status get
 * @pre existing link
 * @post Output == UNDEFINED
 */
void test2_link_get_status();

/**
 * @test Test link_status setter
 * @pre null pointer to link
 * @post Output == ERROR
 */
void test1_link_set_status();

/**
 * @test Test link_status setter
 * @pre existing link and status
 * @post Output == OK
 */
void test2_link_set_status();

#endif
