/**
 * @brief It implements the inventory module
 *
 * @file inventory.c
 * @author Sofia Garcia
 * @version 1.0
 * @date 16-06-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "inventory.h"
#include "object.h"
#include "set.h"

/**
 * @brief Inventory
 *
 * Esta estructura almacena toda la información del inventario
 */
struct _Inventory
{
  Set *objs;    /*!< Set of ids of the objects contained */
  int max_objs; /*!< Maximum number of objects that the user can carry */
};

Inventory *inventory_create()
{
  Inventory *inv = NULL;
  Set *objects = NULL;

  inv = (Inventory *)malloc(sizeof(Inventory));
  if (inv == NULL)
    return NULL;

  objects = set_create();
  if (objects == NULL)
  {
    free(inv);
    return NULL;
  }

  inv->max_objs = 0;
  inv->objs = objects;

  return inv;
}

void inventory_destroy(Inventory *inventory)
{
  if (!inventory)
    return;

  set_destroy(inventory->objs);
  free(inventory);
}

STATUS inventory_set_max_objs(Inventory *inventory, int max_objs)
{
  if (!inventory || max_objs < 0 || max_objs > MAX_IDS)
    return ERROR;

  inventory->max_objs = max_objs;

  return OK;
}

int inventory_get_max_objs(Inventory *inventory)
{
  if (!inventory)
    return -1;

  return inventory->max_objs;
}

STATUS inventory_set_objects(Inventory *inventory, Set *objs)
{
  if (!inventory || !objs || set_get_nids(objs) > inventory->max_objs)
    return ERROR;

  inventory->objs = objs;

  return OK;
}

Set *inventory_get_objects(Inventory *inventory)
{
  if (!inventory)
    return NULL;

  return inventory->objs;
}

STATUS inventory_add_object(Inventory *inventory, Id new_object)
{
  if (!inventory || new_object == NO_ID || set_get_nids(inventory->objs) == inventory->max_objs)
    return ERROR;

  return set_add(inventory->objs, new_object);
}

STATUS inventory_remove_object(Inventory *inventory, Id object)
{

  if (!inventory || object == NO_ID || set_get_nids(inventory->objs) == 0)
    return ERROR;

  return set_del(inventory->objs, object);
}

int inventory_print(Inventory *inventory)
{
  int printed_chars = 0;

  if (!inventory)
    return -1;

  printed_chars += fprintf(stdout, "---> Inventory (size: %d)\n", inventory->max_objs);
  printed_chars += set_print(stdout, inventory->objs);

  return printed_chars;
}