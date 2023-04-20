/**
 * @brief It declares the tests for the command module
 *
 * @file command_test.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 21-05-2021
 */

#ifndef COMMAND_TEST_H
#define COMMAND_TEST_H

/**
 * @test Test command creation
 * @pre Creates a new command
 * @post Output != NULL
 */
void test1_command_create();

/**
 * @test Test command destrcution
 * @pre null pointer to command
 * @post Output == ERROR
 */
void test1_command_destroy();

/**
 * @test Test command destrcution
 * @pre existing command
 * @post Output == OK
 */
void test2_command_destroy();

/**
 * @test Test function for command_arg setting
 * @pre String with command argument
 * @post Output == OK
 */
void test1_command_set_arg();

/**
 * @test Test function for command_arg setting
 * @pre pointer to command argument == NULL
 * @post Output == NULL
 */
void test2_command_set_arg();

/**
 * @test Test function for command_arg get
 * @pre String with the argument
 * @post Output == 0
 */
void test1_command_get_arg();

/**
 * @test Test function for command_arg get
 * @pre pointer to command == NULL
 * @post Output == NULL
 */
void test2_command_get_arg();

/**
 * @test Test function for command_type setting
 * @pre pointer to command == NULL
 * @post Output == ERROR
 */
void test1_command_set_type();

/**
 * @test Test function for command_type setting
 * @pre existing pointer to command and existing command
 * @post Output == OK
 */
void test2_command_set_type();

/**
 * @test Test function for command_type setting
 * @pre command passed == NO_CMD
 * @post Output == ERROR
 */
void test3_command_set_type();

/**
 * @test Test function for command_type get
 * @pre pointer to command == NULL
 * @post Output == NO_CMD
 */
void test1_command_get_type();

/**
 * @test Test function for command_type get
 * @pre type of the command not initialized
 * @post Output == NO_CMD
 */
void test2_command_get_type();

/**
 * @test Test function for command_type get
 * @pre existing pointer to the command and command setted
 * @post Output == NO_CMD
 */
void test3_command_get_type();

/**
 * @test Test function for command_status setting
 * @pre pointer to command == NULL
 * @post Output == ERROR
 */
void test1_command_set_status();

/**
 * @test Test function for command_status setting
 * @pre Set the status "ERROR"
 * @post Output == OK
 */
void test2_command_set_status();

/**
 * @test Test function for command_status get
 * @pre Get the status of a non existing command
 * @post Output == NULL
 */
void test1_command_get_status();

/**
 * @test Test function for command_status get
 * @pre Gets the status of an exiting command
 * @post Output == ERROR
 */
void test2_command_get_status();

/**
 * @test Test function for command_status get
 * @pre Gets the status of an existing command initialized as OK
 * @post Output == OK;
 */
void test3_command_get_status();

#endif