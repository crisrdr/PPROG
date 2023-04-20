/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "object.h"
#include "set.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1

#define N_S 5    /* Number of strings on the graphic description */
#define N_C 9   /* Number of chars for the strings on the graphic description */

/**
  * @brief It creates a new space, allocating memory and initializing its members
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
Space* space_create(Id id);

/**
  * @brief It destroys a space, freeing the allocated memory
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_destroy(Space* space);

/**
  * @brief It gets the id of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space  
  * @return the id of space
  */
Id space_get_id(Space* space);

/**
  * @brief It sets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @brief It gets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a string with the name of the space
  */
const char* space_get_name(Space* space);

/**
  * @brief It gets all the ids of the object of the space
  * @author Sofía Garcia
  *
  * @param space a pointer to the space
  * @return set with all the object ids
  */
Set *space_get_objects(Space *space);

/**
 * @brief It adds an object to the set of the space
 * @author Cristina R
 * 
 * @param space pointer to the space
 * @param id of the object to be added to the space
 * @return OK if everything goes well or ERROR if there was any problem
 */
STATUS space_add_object (Space *space, Id id);

/**
 * @brief It removes the id of the set of objects of the space
 * @author Cristina R
 *  
 * @param space pointer to the space
 * @param id of the object to be remove
 * @return OK if everything goes well or ERROR if there was any problem
 */
STATUS space_remove_object (Space *space, Id id);

/**
 * @brief It gets wheter the space has an object or not
 * @author Cristina R
 * 
 * @param space pointer to the space
 * @param id of the object to be searched
 * @return TRUE if the space has the object or FALSE if not
 */
BOOL space_has_object(Space* space, Id id);

/**
 * @brief It sets the graphic description of the space
 * @author
 * 
 * @param space pointer to the space 
 * @param gdesc pointer to the graphiic description to be setted
 * @return Ok if everything went well or ERROR if there was any problem
 */
STATUS space_set_gdesc (Space *space, char **gdesc);

/**
 * @brief It gets the graphic description of the space
 * @author
 * 
 * @param space pointer to the space 
 * @return the graphic description of the space
 */
char **space_get_gdesc (Space *space);

/**
  * @brief It sets the short description of a space
  * @author Sofia Garcia
  * 
  * @param space a pointer to the space
  * @param desc a string with the new description
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_sdesc(Space *space, char *desc);

/**
  * @brief It gets the short description of a space
  * @author Sofia Garcia
  * 
  * @param space a pointer to the space
  * @return a string with the description of the space
  */
const char *space_get_sdesc(Space *space);

/**
  * @brief It sets the long description of a space
  * @author Sofia Garcia
  * 
  * @param space a pointer to the space
  * @param desc a string with the new description
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_ldesc(Space *space, char *desc);

/**
  * @brief It gets the long description of a space
  * @author Sofia Garcia
  * 
  * @param space a pointer to the space
  * @return a string with the description of the space
  */
const char *space_get_ldesc(Space *space);

/**
  * @brief It prints the space information
  * @author Profesores PPROG
  *
  * This fucntion shows the id and name of the space, the spaces that surrounds it and the id of the object in it
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_print(Space* space);

/**
 * @brief It sets the light of the space
 * @author Sofia Garcia
 * 
 * @param space pointer to the space 
 * @param light light if the space has or not light
 * @return Ok if everything went well or ERROR if there was any problem
 */
STATUS space_set_light(Space *space, BOOL light);
/**
  * @brief It gets the light of a space
  * @author Sofia Garcia
  * 
  * @param space a pointer to the space
  * @return TRUE if it has light, or FALSE otherwise
  */
BOOL space_get_light(Space *space);
#endif
