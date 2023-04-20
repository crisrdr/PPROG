/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "types.h"
#include "space.h"
#include "set.h"
#include "link.h"

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space
{
  Id id;                     /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1];  /*!< Name of the space */
  Set *objs;                 /*!< Pointer to the set of objs */
  char **gdesc;              /*!< Graphic description */
  char descr[WORD_SIZE + 1]; /*!< Description of the space */
};

/** space_create allocates memory for a new space
 *  and initializes its members
 */
Space *space_create(Id id)
{
  Space *newSpace = NULL;
  Set *objs = NULL;
  char **gdesc = NULL;
  int i;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));
  if (newSpace == NULL)
  {
    return NULL;
  }

  objs = set_create();
  if (objs == NULL)
  {
    free(newSpace);
    return NULL;
  }

  gdesc = (char **)malloc(N_S * sizeof(char *));
  if (gdesc == NULL)
  {
    free(newSpace);
    set_destroy(objs);
    return NULL;
  }

  for (i = 0; i < N_S; i++)
  {
    gdesc[i] = (char *)calloc(N_C + 1, sizeof(char));
    if (gdesc[i] == NULL)
    {
      free(newSpace);
      set_destroy(objs);
      for (i--; i >= 0; i--)
        free(gdesc[i]);
      free(gdesc);
      return NULL;
    }
  }
  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->descr[0] = '\0';
  newSpace->objs = objs;
  newSpace->gdesc = gdesc;

  return newSpace;
}

/** space_destroy frees the previous memory allocation
 *  for a space
 */
STATUS space_destroy(Space *space)
{
  int i;
  if (!space)
  {
    return ERROR;
  }

  set_destroy(space->objs);
  for (i = 0; i < N_S; i++)
    free(space->gdesc[i]);
  free(space->gdesc);

  free(space);
  space = NULL;
  return OK;
}

/** It gets the id of a space
 */
Id space_get_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
}

/** It sets the name of a space
 */
STATUS space_set_name(Space *space, char *name)
{
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }
  return OK;
}

/** It gets the name of a space
 */
const char *space_get_name(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->name;
}

/** It gets the set of object of a space
 */
Set *space_get_objects(Space *space)
{

  if (!space)
  {
    return NULL;
  }

  return space->objs;
}

/** It adds an object to the set of the space by its id
 */
STATUS space_add_object(Space *space, Id id)
{
  if (!space || id == NO_ID)
    return ERROR;

  return set_add(space->objs, id);
}

/** It removes an object from the set of space
 */
STATUS space_remove_object(Space *space, Id id)
{
  if (!space || id == NO_ID)
    return ERROR;

  return set_del(space->objs, id);
}

/** It gets whether an space has an object or not
 */
BOOL space_has_object(Space *space, Id id)
{
  if (!space || id == NO_ID)
    return FALSE;

  return set_has_id(space->objs, id);
}

/** It sets the graphic description of the space
 */
STATUS space_set_gdesc(Space *space, char **gdesc)
{
  int i;

  if (!space || !gdesc)
  {
    return ERROR;
  }

  for (i = 0; i < N_S; i++)
  {
    if ((*gdesc) == NULL)
    {
      return ERROR;
    }
  }

  for (i = 0; i < N_S; i++)
    strncpy(space->gdesc[i], gdesc[i], N_C);

  return OK;
}

/** It gets the graphic description of a space
 */
char **space_get_gdesc(Space *space)
{
  if (!space)
  {
    return NULL;
  }

  return space->gdesc;
}

/** It sets the description of a space
 */
STATUS space_set_descr(Space *space, char *descr)
{
  if (!space || !descr)
  {
    return ERROR;
  }

  if (!strcpy(space->descr, descr))
  {
    return ERROR;
  }

  return OK;
}

/** It gets the description of a space
 */
char *space_get_descr(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->descr;
}

/** It prints the space information
 */
STATUS space_print(Space *space)
{
  Id idaux = NO_ID;
  int n_objs, i;

  /* Error Control */
  if (!space)
  {
    return ERROR;
  }
  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s; Description: %s)\n", space->id, space->name, space->descr);

  /* 2. Print the graphic description of the space */
  fprintf(stdout, "---> Graphic description:\n");
  for (i = 0; i < N_S; i++)
  {
    fprintf(stdout, "%s\n", space->gdesc[i]);
  }
  fprintf(stdout, "\n");

  /* 3. Print if there is an object in the space or not */
  fprintf(stdout, "---> Objects in the space:\n");
  set_print(stdout, space->objs);

  return OK;
}