/**
 * @brief It declares the tests for the set module
 *
 * @file set_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @test Test set creation
 * @pre set pointer
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test set creation
 * @pre number of ids of the new set
 * @post Ouput==0
 */
void test2_set_create();

/**
 * @test Test set_add
 * @pre new id
 * @post Ouput==OK
 */
void test1_set_add();

/**
 * @test Test set_add
 * @pre pointer to set = NULL
 * @post Output==ERROR
 */
void test2_set_add();

/**
 * @test Test function for set_name setting
 * @pre new id == NO_ID
 * @post Output==ERROR
 */
void test3_set_add();

/**
 * @test Test set remove ID
 * @pre Remove non-existing ID
 * @post Output==ERROR
 */
void test1_set_del();

/**
 * @test Test set remove ID
 * @pre pointer to set = NULL
 * @post Output==ERROR
 */
void test2_set_del();

/**
 * @test Test set remove ID
 * @pre ID
 * @post Output == OK
 */
void test3_set_del(); 

/**
 * @test Test set_has_id
 * @pre ID to find
 * @post Output == TRUE
 */
void test1_set_has_id();

/**
 * @test Test set_has_id
 * @pre pointer to set with 0 ids
 * @post Output == FALSE
 */
void test2_set_has_id();
/**
 * @test Test set_get_nids
 * @pre pointer to set with 0 ids
 * @post Output == 0
 */
void test1_set_get_nids(); 

/**
 * @test Test set_get_nids
 * @pre pointer to set = NULL
 * @post Output == INT_MIN
 */
void test2_set_get_nids(); 

#endif