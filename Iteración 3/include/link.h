/**
 * @brief It defines the link inteface
 * 
 * @file links.h
 * @author Cristina Rodríguez de los Ríos Medina
 * @version 0.1
 * @date 2022-06-17
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

#define MAX_LINKS 300

typedef struct _Link Link;

/**
 * @brief It creates a new link, allocating memory and initializing its members
 * @author Cristina Rodríguez de los Ríos Medina
 * 
 * @param id the identification number for the new Link
 * @return a new link, initialized
 */
Link *link_create(Id id);

/**
 * @brief It destroys a link, freeing the allocated memory
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_destroy(Link *link);

/**
 * @brief It gets the id of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @return the id of the link
 */
Id link_get_id(Link *link);

/**
 * @brief It gets the name of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @return the name of the link
 */
const char *link_get_name(Link *link);

/**
 * @brief It sets the name of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @param name array with the name to be setted
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
STATUS link_set_name(Link *link, char *name);

/**
 * @brief It gets the origin of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @return the id of the origin space
 */
Id link_get_origin(Link *link);

/**
 * @brief It sets the origin
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @param id of the origin to be setted
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
STATUS link_set_origin(Link *link, Id id);

/**
 * @brief It gets the destination of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @return id of the destination space of the link
 */
Id link_get_destination(Link *link);

/**
 * @brief It sets the destination of the space
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @param id of the destination space to be setted
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
STATUS link_set_destination(Link *link, Id id);

/**
 * @brief It gets the direction of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @return the direction of the link
 */
DIRECTION link_get_direction(Link *link);

/**
 * @brief It sets the direction of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @param dir direction to be setted
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
STATUS link_set_direction(Link *link, DIRECTION dir);

/**
 * @brief It gets the status of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @return the status of the link
 */
LINK_ST link_get_status(Link *link);

/**
 * @brief It sets the status of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link
 * @param st status to be setted
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
STATUS link_set_status(Link *link, LINK_ST st);

/**
 * @brief It prints all the information of the link
 * @author Cristina Rodríguez de los Ríos Medina 
 * 
 * @param link pointer to the link to be printed
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
int link_print(Link *link);

#endif