/**
 * @brief It defines the object module
 * 
 * @file object.c
 * @author Cristina Rodríguez de los Ríos Medina y Sofía García Heras
 * @version 0.1
 * @date 24-03-2022
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"
#include "inventory.h"

#define OBJECT_ID 2
#define MAX_OBJECTS 30

/**
 * @brief Object
 * 
 * This struct stores all the information of an object.
 * 
 */
typedef struct _Object Object;

/**
  * @brief It creates a new object, allocating memory and initializing its memebers
  * @author Sofía y Cristina
  * 
  * @param id the identification number for the new object
  * @return a new object, initialized
  */
Object* object_create(Id id);

/**
  * @brief It destroys an object, freeing the allocated memory
  * @author Sofía y Cristina
  * 
  * @param object a pointer to the object that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_destroy(Object* object);

/**
  * @brief It gets the id of an object
  * @author Sofía y Cristina
  * 
  * @param object a pointer to the object  
  * @return the id of object
  */
Id object_get_id(Object* object);

/**
  * @brief It gets the name of an object
  * @author Sofía y Cristina
  * 
  * @param object a pointer to the object  
  * @return the name of the object
  */
const char * object_get_name(Object* object);

/**
  * @brief It sets the name of the object
  * @author Sofía y Cristina
  *
  * @param object a pointer to the object
  * @param name the new name of the object
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_name(Object* object, char* name);
/**
  * @brief It sets the description of the object
  * @author Sofía 
  *
  * @param object a pointer to the object
  * @param desc a pointer to the description
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_descr(Object *object, char *desc);
/**
  * @brief It gets the description of the object
  * @author Sofía 
  *
  * @param object a pointer to the object
  * @param name the new name of the object
  * @return the description of the object
  */
const char *object_get_descr(Object *object);

/**
 * @brief Checks if the object is movable
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @return TRUE if the object is movable, FALSE otherwise
 */
BOOL object_is_movable(Object *object);

/**
 * @brief Sets the movable property of an object
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @param movable the movable boolean
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_movable(Object *object, BOOL movable);

/**
 * @brief Gets the dependency (object ID) of the object
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @return the dependency object ID of the object
 */
Id object_get_dependency(Object *object);

/**
 * @brief Sets the dependency (object ID) of the object
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @param dependency the dependency object ID of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_dependency(Object *object, Id dependency);

/**
 * @brief Gets the space ID this object can open
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @return the space ID this object can open
 */
Id object_get_open_id(Object *object);

/**
 * @brief Sets the space ID this object can open
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @param space_id the space ID this object can open
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_open_id(Object *object, Id space_id);

/**
 * @brief Gets if the object can illuminate
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @return TRUE if the object can illuminate, FALSE otherwise
 */
BOOL object_can_illuminate(Object *object);

/**
 * @brief Sets if the object can illuminate
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @param illuminate the can_illuminate boolean
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_illuminate(Object *object, BOOL illuminate);

/**
 * @brief Gets if the object is turned on (can illuminate spaces)
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @return TRUE if the object is turned on, FALSE otherwise
 */
BOOL object_is_turnedon(Object *object);

/**
 * @brief Sets if the object is turned on (can illuminate spaces)
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @param turnedon the turnedon boolean
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_turnedon(Object *object, BOOL turnedon);
/**
 * @brief Checks if the object can be taken with the take command
 * @author Sofia Garcia
 *
 * @param object a pointer to the object
 * @param inventory a pointer to the inventory of the player
 * @return TRUE, if the object can be taken, otherwise FALSE
 */
BOOL object_can_be_taken(Object *object, Inventory *inventory);
/**
  * @brief It prints the object information
  * @author Sofía y Cristina
  *
  * This function shows the object id and its name.
  * @param object a pointer to the object
  */
STATUS object_print(Object* object);

#endif