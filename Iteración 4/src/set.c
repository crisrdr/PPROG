/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Sofía García Heras
 * @version 2.0
 * @date 11-04-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "set.h"
#include "types.h"
/**
 * @brief Set
 *
 * Esta estructura almacena toda la información del set
 */
struct _Set
{
  Id ids[MAX_IDS]; /*!< Array de ids */
  int n_ids;       /*!< Numero de ids */
};

/** set_create reserva memoria para el set e inicializa sus miembros
 */
Set *set_create()
{
  int i;
  Set *set = NULL;

  /* Mem alloc */
  set = (Set *)malloc(sizeof(Set));
  if (set == NULL)
    return NULL;

  /* Initialization of the new object */
  set->n_ids = 0;
  for (i = 0; i < MAX_IDS; i++)
  {
    set->ids[i] = NO_ID;
  }

  return set;
}

/** set_destroy libera la memoria que ha sido previamente reservada
 *  para un set
 */
STATUS set_destroy(Set *set)
{
  if (!set)
    return ERROR;

  free(set);
  set = NULL;
  return OK;
}

/** set_add añade un id al set
 */
STATUS set_add(Set *set, Id id)
{
  if (set == NULL || id == NO_ID)
    return ERROR;

  if (set_has_id(set, id) == TRUE)
    return OK;

  if (set->n_ids == MAX_IDS)
    return ERROR;

  set->ids[set->n_ids] = id;
  (set->n_ids)++;

  return OK;
}
/** Elimina un id del set y reduce el tamaño del set
 */
STATUS set_del(Set *set, Id id)
{
  int i = 0;

  if (set == NULL || id == NO_ID || set->n_ids == 0)
    return ERROR;

  for (i = 0; i < set->n_ids && i < MAX_IDS; i++)
  {
    if (set->ids[i] == id)
    {
      if (i != set->n_ids - 1)
      {
        set->ids[i] = set->ids[set->n_ids - 1];
      }
      set->ids[set->n_ids - 1] = NO_ID;
      (set->n_ids)--;
      return OK;
    }
  }

  return ERROR;
}
/** Imprime los ids
 */
int set_print(FILE *pf, const void *set)
{
  int i = 0, print = 0;

  if (!set || pf == NULL)
    return INT_MIN;

  print += fprintf(pf, "=> Set [%d id(s)]: \n", ((Set *)set)->n_ids);
  for (i = 0; i < ((Set *)set)->n_ids; i++)
  {
    print += fprintf(pf, " - %ld\n", ((Set *)set)->ids[i]);
  }

  return print;
}
/** Comprueba si en el set hay un id
 */
BOOL set_has_id(Set *set, Id id)
{
  int i = 0;

  if (set == NULL || id == NO_ID || set->n_ids == 0)
    return FALSE;

  for (i = 0; i < set->n_ids && set->ids[i] != NO_ID; i++)
  {
    if (set->ids[i] == id)
      return TRUE;
  }

  return FALSE;
}
/** Devuelve el numero de ids que hay en el set
 */
int set_get_nids(Set *set)
{
  if (set == NULL)
    return INT_MIN;

  return set->n_ids;
}