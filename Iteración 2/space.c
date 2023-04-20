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
#include "space.h"
#include "set.h"

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space {
  Id id;                        /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1];     /*!< Name of the space */
  Id north;                     /*!< Id of the space at the north */
  Id south;                     /*!< Id of the space at the south */
  Id east;                      /*!< Id of the space at the east */
  Id west;                      /*!< Id of the space at the west */
  Set *objs;                    /*!< Pointer to the set of objs */
  char **gdesc;                 /*!< Graphic description */
};

/** space_create allocates memory for a new space
  *  and initializes its members
  */
Space* space_create(Id id) {
  Space *newSpace = NULL;
  Set *objs = NULL;
  char **gdesc = NULL;
  int i;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));
  if (newSpace == NULL) {
    return NULL;
  }

  objs = set_create();
  if (objs == NULL) {
    free (newSpace);
    return NULL;
  }

  gdesc = (char**) malloc(N_S * sizeof(char*));
  if (gdesc == NULL) {
    free (newSpace);
    set_destroy(objs);
    return NULL;
  }

  for (i = 0; i < N_S; i++) {
    gdesc[i] = (char*) calloc(N_C+1, sizeof(char));
    if (gdesc[i] == NULL) {
      free (newSpace);
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
  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  newSpace->objs = objs;
  newSpace->gdesc = gdesc;

  return newSpace;
}

/** space_destroy frees the previous memory allocation 
  *  for a space
  */
STATUS space_destroy(Space* space) {
  int i;
  if (!space) {
    return ERROR;
  }

  set_destroy(space->objs);
    for (i=0; i < N_S; i++)
    free(space->gdesc[i]);
  free(space->gdesc);

  free(space);
  space = NULL;
  return OK;
}

/** It gets the id of a space
  */
Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

/** It sets the name of a space
  */
STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }
  return OK;
}

/** It gets the name of a space
  */
const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

/** It sets the id of the space located at the north
  */
STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

/** It gets the id of the space located at the north
  */
Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

/** It sets the id of the space located at the south
  */
STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

/** It gets the id of the space located at the south
  */
Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

/** It sets the id of the space located at the east
  */
STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

/** It gets the id of the space located at the east
  */
Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

/** It sets the id of the space located at the west
  */
STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

/** It gets the id of the space located at the west
  */
Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

/** It sets a new set 
 */
STATUS space_set_set(Space *space, Set *set){
  if (!space || !set) return ERROR;

  space->objs = set;

  return OK;
}

/** It gets the set of objs of a space
 */
Set *space_get_set (Space *space){
  if (!space) return NULL;

  return space->objs;  
}

/** It adds an object to the set of the space by its id
 */
STATUS space_add_object (Space *space, Id id){
  if (!space || id == NO_ID) return ERROR;

  return set_add(space->objs, id);
}

/** It removes an object from the set of space 
 */
STATUS space_remove_object (Space *space, Id id){
  if (!space || id == NO_ID) return ERROR;

  return set_del(space->objs, id);
}

/** It gets whether an space has an object or not
 */
BOOL space_has_object(Space* space, Id id) {
  if (!space || id == NO_ID) return FALSE;

  return set_has_id (space->objs, id);
}

/** It gets the number of objs in the space
 */
int space_get_nObjects (Space *space){
  if (!space) return INT_MIN;

  return set_get_nids(space->objs);
}

STATUS space_set_gdesc (Space *space, char **gdesc){
  int i;

  if(!space || !gdesc){
    return ERROR; 
  }

  for (i = 0; i < N_S; i++) {
    if ((*gdesc) == NULL) {
      return ERROR;
    }
  }

  for (i = 0; i < N_S; i++)
    strncpy(space->gdesc[i], gdesc[i], N_C);

  return OK; 
}

char **space_get_gdesc (Space *space){
    if(!space){
    return NULL; 
  }

  return space->gdesc; 
}

/** It prints the space information
  */
STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  int n_objs, i;

  /* Error Control */
  if (!space) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
 
  /* 2. Print the graphic description of the space */
  fprintf (stdout, "---> Graphic description:\n");
  for (i = 0; i < N_S; i++){
    fprintf(stdout, "%s\n", space->gdesc[i]);
  }
  fprintf(stdout, "\n");

  /* 3. For each direction, print its link */ 
  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  /* 4. Print the object of the space if there's some */
  n_objs = space_get_nObjects(space);
  if (n_objs == 0) {
    fprintf(stdout, "---> No objs in the space.\n");
  }
  else {
    set_print(stdout, space->objs);
  }

  return OK;
}

