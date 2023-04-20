/** 
 * @brief It implements the set module
 * 
 * @file set.h
 * @author Cristina y Sofía
 * @version 1.0 
 * @date 02-06-2021 
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

#include <stdio.h>
#include "types.h"

#define MAX_IDS 100
/**
 * @brief Set
 * 
 * This struct stores all the information of a set.
 * 
 */
typedef struct _Set Set;

/**
  * @brief It creates a new set, allocating memory and initializing its memebers
  * @author Sofía y Cristina
  * 
  * @param id the identification number for the new set
  * @return a new set, initialized
  */
Set *set_create();
/**
  * @brief It destroys a set, freeing the allocated memory
  * @author Sofía y Cristina
  * 
  * @param object a pointer to the set that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS set_destroy(Set *set);
/**
  * @brief It adds to the set an id
  * @author Sofía y Cristina
  *
  * @param set a pointer to the set 
  * @param id the new id you want to add
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS set_add(Set *set, Id id);
/**
  * @brief It deletes from the set an id
  * @author Sofía y Cristina
  *
  * @param set a pointer to the set 
  * @param id the new id you want to delete
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS set_del(Set *set, Id id);
/**
  * @brief It prints the ids
  * @author Sofía y Cristina
  * 
  * @param pf FILE pointer
  * @param set a pointer to the set
  * @return the number of characters printed or INT_MIN if there was some mistake
  */
int set_print(FILE *pf, const void *set);
/**
  * @brief It checks there is an id in the set
  * @author Sofía y Cristina
  *
  * @param set a pointer to the set 
  * @param id the id we want to search
  * @return TRUE if there is an id in the set or FALSE if there was some mistake)
  */
BOOL set_has_id(Set *set, Id id) ;

/**
  * @brief It returns the number of ids in the set
  * @author Sofía y Cristina
  *
  * @param set a pointer to the set 
  * @return the number of ids stored or INT_MIN if there was some mistake
  */
int set_get_nids(Set *set) ;
#endif