/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Cristina Rodríguez de los Ríos Medina
 * @version 0.1
 * @date 24-03-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"



/**
 * @brief Object
 *
 * Esta estructura almacena toda la información de un objeto
 */
struct _Object
{
  Id id;                     /*!< Id number of the objects */
  char name[WORD_SIZE + 1];  /*!< Name of the object */
  char descr[WORD_SIZE + 1]; /*!< Description of the object */
  BOOL movable;              /*!< If the object is movable */
  Id dependency;             /*!< ID of object it depends on*/
  Id open;                   /*!< ID of the link this object can open */
  BOOL illuminate;           /*!< If the object can illuminate spaces */
  BOOL turnedon;             /*!< If illumination on the object is turned on or off */
};
/** object_create reserva memoria para un nuevo objeto e inicializa sus miembros
 */
Object *object_create(Id id)
{
  Object *newObject = NULL;

  if (id == NO_ID)
    return NULL;

  newObject = (Object *)malloc(sizeof(Object));
  if (!newObject)
    return NULL;

  newObject->id = id;
  newObject->name[0] = '\0';
  newObject->movable = FALSE;
  newObject->dependency = NO_ID;
  newObject->open = NO_ID;
  newObject->illuminate = FALSE;
  newObject->turnedon = FALSE;

  return newObject;
}

/** object_destroy libera la memoria que ha sido previamente reservada
 *  para un objeto
 */
STATUS object_destroy(Object *object)
{
  if (!object)
    return ERROR;

  free(object);
  object = NULL;
  return OK;
}

/** Obtiene el id de un objeto
 */
Id object_get_id(Object *object)
{
  if (!object)
    return NO_ID;

  return object->id;
}

/** Obtiene el nombre de un objeto
 */
const char *object_get_name(Object *object)
{
  if (!object)
    return NULL;

  return object->name;
}

/** Asigna el nombre a un objeto
 */
STATUS object_set_name(Object *object, char *name)
{
  if (!object || !name)
    return ERROR;

  if (!strcpy(object->name, name))
    return ERROR;

  return OK;
}

STATUS object_set_descr(Object *object, char *desc)
{

  if (object == NULL || desc == NULL)
  {
    return ERROR;
  }

  if (!strcpy(object->descr, desc))
    return ERROR;

  return OK;
}

const char *object_get_descr(Object *object)
{

  if (object == NULL)
    return NULL;

  return object->descr;
}

BOOL object_is_movable(Object *object) {
  if (!object) return FALSE;

  return object->movable;
}

STATUS object_set_movable(Object *object, BOOL movable) {
  if (!object) return ERROR;

  object->movable = movable;
  return OK;
}

Id object_get_dependency(Object *object) {
  if (!object) return NO_ID;

  return object->dependency;
}

STATUS object_set_dependency(Object *object, Id dependency) {
  if (!object) return ERROR;

  object->dependency = dependency;
  return OK;
}

Id object_get_open_id(Object *object) {
  if (!object) return NO_ID;

  return object->open;
}

STATUS object_set_open_id(Object *object, Id space_id) {
  if (!object || space_id == NO_ID) return ERROR;

  object->open = space_id;
  return OK;
}

BOOL object_can_illuminate(Object *object) {
  if (!object) return FALSE;

  return object->illuminate;
}

STATUS object_set_illuminate(Object *object, BOOL illuminate) {
  if (!object) return ERROR;

  object->illuminate = illuminate;
  return OK;
}

BOOL object_is_turnedon(Object *object) {
  if (!object) return FALSE;

  return object->turnedon;
}

STATUS object_set_turnedon(Object *object, BOOL turnedon) {
  if (!object) return ERROR;

  object->turnedon = turnedon;
  return OK;
}

BOOL object_can_be_taken(Object *object, Inventory *inventory) {
  if (!object || !inventory) return FALSE;

  if (object->movable == FALSE) return FALSE; /* if the object isn't movable, no need to check anything else */

  if (object->dependency != NO_ID) {
    /* The inventory needs to be checked if the object has a dependency */
    /* The object can be taken if the dependency is in the inventory */
    return set_has_id(inventory_get_objects(inventory), object->dependency);
  }

  return TRUE;
}
/** Imprime la información del objeto
 */
STATUS object_print(Object *object)
{
  if (!object)
    return ERROR;

 fprintf(stdout, "--> Object (Id: %ld; Name: %s; Description: %s, Movable: %s, Can illuminate: %s, Turned on: %s)\n", object->id, object->name, object->descr, object->movable ? "TRUE" : "FALSE", object->illuminate ? "TRUE" : "FALSE", object->turnedon ? "TRUE" : "FALSE");
  return OK;
}