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
  * @brief It prints the object information
  * @author Sofía y Cristina
  *
  * This function shows the object id and its name.
  * @param object a pointer to the object
  */
STATUS object_print(Object* object);

#endif