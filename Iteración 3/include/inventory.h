/**
 * @brief It defines the inventory interface
 *
 * @file inventory.h
 * @author Sofia Garcia
 * @version 1.0
 * @date 16-06-2022
 * @copyright GNU Public License
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "set.h"

/**
 * @brief Inventory data structure
 */
typedef struct _Inventory Inventory;


/**
  * @brief It creates a new inventory
  * @author Sofia Garcia
  *
  * @return a new inventory, initialized
  */
Inventory *inventory_create();

/**
  * @brief It destroys an inventory
  * @author Sofia Garcia
  *
  * @param inventory a pointer to the inventory that must be destroyed  
  */
void inventory_destroy(Inventory *inventory);

/**
  * @brief It sets the maximum objects of an inventory
  * @author Sofia Garcia
  *
  * @param inventory a pointer to the inventory
  * @param max_objs max objects a player can carry
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS inventory_set_max_objs(Inventory *inventory, int max_objs);

/**
  * @brief It gets the maximum objects of an inventory
  * @author Sofia Garcia
  *
  * @param inventory a pointer to the inventory
  * @return The maximum objects of an inventory or -1 if there was some mistake
  */
int inventory_get_max_objs(Inventory *inventory);

/**
  * @brief It sets the object set of an inventory
  * @author Sofia Garcia
  * 
  * @param inventory a pointer to the inventory 
  * @param objs new set of ids
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS inventory_set_objects(Inventory *inventory, Set *objs);

/**
  * @brief It gets the objects of an inventory
  * @author Sofia Garcia
  *
  * @param inventory a pointer to the inventory
  * @return a set with the object ids
  */
Set *inventory_get_objects(Inventory *inventory);

/**
  * @brief It adds an object to the inventory
  * @author Sofia Garcia
  *
  * @param inventory a pointer to the inventory
  * @param new_object id of the new object
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS inventory_add_object(Inventory *inventory, Id new_object);

/**
  * @brief It removes an object from the inventory
  * @author Sofia Garcia
  *
  * @param inventory a pointer to the inventory
  * @param object id of the object
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS inventory_remove_object(Inventory *inventory, Id object);

/**
  * @brief It prints the inventory information
  * @author Sofia Garcia
  *
  * @param inventory a pointer to the inventory
  * @return Number of characters printed or -1 if there was some mistake
  */
int inventory_print(Inventory *inventory);
#endif