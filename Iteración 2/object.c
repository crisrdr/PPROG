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
struct _Object {
    Id id;
    char name[WORD_SIZE + 1];
};
/** object_create reserva memoria para un nuevo objeto e inicializa sus miembros
  */
Object* object_create(Id id){
    Object *newObject = NULL;

    if (!id) return NULL;

    newObject = (Object*) malloc (sizeof(Object));
    if (!newObject) return NULL;

    newObject->id = id;
    newObject->name[0] = '\0';

    return newObject;

}

/** object_destroy libera la memoria que ha sido previamente reservada
  *  para un objeto
  */
STATUS object_destroy(Object* object){
    if (!object) return ERROR;

    free(object);
    object = NULL;
    return OK;
}

/** Obtiene el id de un objeto
  */
Id object_get_id(Object* object){
    if (!object) return NO_ID;

    return object->id;
}

/** Asigna el id a un objeto
  */
STATUS object_set_id(Object* object, Id id){
    if (!object || !id) return ERROR;

    object->id = id;
    return OK;
}

/** Obtiene el nombre de un objeto
  */
const char * object_get_name(Object* object){
    if (!object) return NULL;

    return object->name;
}

/** Asigna el nombre a un objeto
  */
STATUS object_set_name(Object* object, char* name){
    if (!object || !name) return ERROR;

    if (!strcpy(object->name,name)) return ERROR;

    return OK;
}

/** Imprime la información del objeto
  */
STATUS object_print(Object* object){
    if (!object) return ERROR;

    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

    return OK;
}
