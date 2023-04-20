/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @version 0.1
 * @date 2022-06-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/link.h"

/**
 * @brief Link
 *
 * This struct stores all the information of a Link
 */

struct _Link
{
    Id id;                    /*!< Id number of the link, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the space */
    Id origin;                /*!< Id of the space origin */
    Id destination;           /*!< Id of the space destination */
    DIRECTION dir;            /*!< Direction of the link */
    LINK_ST st;               /*!< Status of the link (close or open) */
};

/** link_create allocates memory for a new link and initializes its members
 */

Link *link_create(Id id)
{
    if (id == NO_ID) return NULL;
    
    Link *link = NULL;

    link = (Link *)malloc(sizeof(Link));
    if (!link)
        return NULL;

    link->id = id;
    link->name[0] = '\0';
    link->origin = NO_ID;
    link->destination = NO_ID;
    link->dir = NO_DIR;
    link->st = UNDEFINED;

    return link;
}

/** link_destroy frees the previous memory allocation for a space
 */
STATUS link_destroy(Link *link)
{
    if (!link)
        return ERROR;

    free(link);
    link = NULL;
    return OK;
}

/** It gets the id of a link
 */
Id link_get_id(Link *link)
{
    if (!link)
        return NO_ID;

    return link->id;
}

/** It gets the name of a link
 */
const char *link_get_name(Link *link)
{
    if (!link)
        return NULL;

    return link->name;
}

/** It sets the name of a link
 */
STATUS link_set_name(Link *link, char *name)
{
    if (!link || !name)
        return ERROR;

    if (!strcpy(link->name, name))
        return ERROR;

    return OK;
}

/** It gets the origin of a link
 */
Id link_get_origin(Link *link)
{
    if (!link)
        return NO_ID;

    return link->origin;
}

/** It sets the origin of a link
 */
STATUS link_set_origin(Link *link, Id id)
{
    if (!link || id == NO_ID)
        return ERROR;

    link->origin = id;
    return OK;
}

/** It gets the destination of a link
 */
Id link_get_destination(Link *link)
{
    if (!link)
        return NO_ID;

    return link->destination;
}

/** It sets the destination of a link
 */
STATUS link_set_destination(Link *link, Id id)
{
    if (!link || id == NO_ID)
        return ERROR;

    link->destination = id;
    return OK;
}

/** It gets the direction of a link
 */
DIRECTION link_get_direction(Link *link)
{
    if (!link)
        return NO_DIR;

    return link->dir;
}

/** It sets the direction of a link
 */
STATUS link_set_direction(Link *link, DIRECTION dir)
{
    if (!link || dir == NO_DIR)
        return ERROR;

    link->dir = dir;
    return OK;
}

/** It gets the status of a link
 */
LINK_ST link_get_status(Link *link)
{
    if (!link)
        return UNDEFINED;

    return link->st;
}

/** It sets the status of a link
 */
STATUS link_set_status(Link *link, LINK_ST st)
{
    if (!link || st == UNDEFINED)
        return ERROR;

    link->st = st;
    return OK;
}

/** It prints the link information
 */
int link_print(Link *link)
{

    if (!link)
        return -1;

    return fprintf(stdout, "--> Link (Id: %ld; Name: %s; Origin space:< %ld; Destination space: %ld; Link direction: %d; Link status: %d)\n", link->id, link->name, link->origin, link->destination, link->dir, link->st);
}