/**
 * @brief It declares the tests for the inventory module
 *
 * @file inventory_test.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @date 24-05-2021
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

#include "inventory.h"

/**
 * @test Test inventory creation
 * @pre Inventory create
 * @post Output != NULL
 */
void test1_inventory_create();

/**
 * @test Test inventory_max objects set
 * @pre null pointer to inventory
 * @post Output == ERROR
 */
void test1_inventory_set_max_objs();

/**
 * @test Test inventory_max objects set
 * @pre existing inventory
 * @post Output == OK
 */
void test2_inventory_set_max_objs();

/**
 * @test Test inventory_max objects get
 * @pre null pointer to inventory
 * @post Output == -1
 */
void test1_inventory_get_max_objs();

/**
 * @test Test inventory_max objects get
 * @pre existing inventory and max_objs initialized
 * @post Output != -1
 */
void test2_inventory_get_max_objs();

/**
 * @test Test inventory_objects set
 * @pre null pointer to inventory and set
 * @post Output == ERROR
 */
void test1_inventory_set_objects();

/**
 * @test Test inventory_objects setter
 * @pre null pointer to set
 * @post Output == ERROR
 */
void test2_inventory_set_objects();

/**
 * @test Test inventory_objects setter
 * @pre existing inventory and set
 * @post Output == OK
 */
void test3_inventory_set_objects();

/**
 * @test Test inventory_objects get
 * @pre null pointer to inventory
 * @post Output == NULL
 */
void test1_inventory_get_objects();

/**
 * @test Test inventory_objects get
 * @pre existing inventory
 * @post Output != NULL
 */
void test2_inventory_get_objects();

/**
 * @test Test inventory_objects add
 * @pre null pointer to inventory
 * @post Output == ERROR
 */
void test1_inventory_add_object();

/**
 * @test Test inventory_objects add
 * @pre unexisting object
 * @post Output == ERROR
 */
void test2_inventory_add_object();

/**
 * @test Test inventory_objects add
 * @pre existing inventory and object
 * @post Output == OK
 */
void test3_inventory_add_object();

/**
 * @test Test inventory_objects remove
 * @pre null pointer to inventory
 * @post Output == ERROR
 */
void test1_inventory_remove_object();

/**
 * @test Test inventory_objects remove
 * @pre unexisting object
 * @post Output == ERROR
 */
void test2_inventory_remove_object();

/**
 * @test Test inventory_objects remove
 * @pre existing inventory and object
 * @post Output == OK
 */
void test3_inventory_remove_object();

#endif