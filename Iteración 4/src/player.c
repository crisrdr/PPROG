/**
 * @brief It implements the player module
 *
 * @file player.c
 * @author Sofía García Heras
 * @date 24-03-2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "player.h"
#include "inventory.h"

/**
 * @brief Player
 *
 * Esta estructura almacena toda la información de un jugador
 */
struct _Player
{
  Id id;                    /*!< Número de identificacion del jugador, debe ser único*/
  char name[WORD_SIZE + 1]; /*!< Nombre del jugador */
  Id location;              /*!< Id de la ubicación del jugador*/
  Id object_id;             /*!< Id del objeto del jugador */
  Inventory *inventory;     /*!< Inventory of the player */
  int health;               /*!< Nivel de salud del jugador */
};

/** player_create reserva memoria para un nuevo jugador e inicializa sus miembros
 */
Player *player_create(Id id)
{
  Player *newPlayer = NULL;
  Inventory *new_inventory = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *)malloc(sizeof(Player));
  if (newPlayer == NULL)
  {
    return NULL;
  }

  new_inventory = inventory_create();
  if (new_inventory == NULL)
  {
    free(new_inventory);
    return NULL;
  }

  /* Initialization of an empty space*/
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  newPlayer->inventory = new_inventory;
  newPlayer->health = 0;

  return newPlayer;
}

/** player_destroy libera la memoria que ha sido previamente reservada
 *  para un jugador
 */
void player_destroy(Player *player)
{
  if (!player)
  {
    return;
  }
  inventory_destroy(player->inventory);
  free(player);
}

/** Obtiene el id de un jugador
 */
Id player_get_id(Player *player)
{
  if (!player)
  {
    return NO_ID;
  }
  return player->id;
}

/** Obtiene el nombre de un jugador
 */
const char *player_get_name(Player *player)
{
  if (!player)
  {
    return NULL;
  }
  return player->name;
}

/** Asigna el nombre a un jugador
 */
STATUS player_set_name(Player *player, char *name)
{
  if (!player || !name)
  {
    return ERROR;
  }

  if (!strcpy(player->name, name))
  {
    return ERROR;
  }
  return OK;
}

/** Obtiene el id de la ubicación de un jugador
 */
Id player_get_location(Player *player)
{
  if (!player)
  {
    return NO_ID;
  }
  return player->location;
}

/** Asigna el id de la ubicación a un jugador
 */
STATUS player_set_location(Player *player, Id id)
{
  if (!player || !id)
    return ERROR;

  player->location = id;

  return OK;
}

STATUS player_set_inventory(Player *player, Inventory *inventory)
{

  if (!player || !inventory)
    return ERROR;

  inventory_destroy(player->inventory);
  player->inventory = inventory;

  return OK;
}

Inventory *player_get_inventory(Player *player)
{

  if (!player)
    return NULL;

  return player->inventory;
}

STATUS player_add_object(Player *player, Id object)
{

  if (!player || object == NO_ID)
    return ERROR;

  return inventory_add_object(player->inventory, object);
}

STATUS player_remove_object(Player *player, Id object)
{

  if (!player || object == NO_ID)
    return ERROR;

  return inventory_remove_object(player->inventory, object);
}

/** Obtiene la salud del jugador
 */
int player_get_health(Player *player)
{
  if (!player)
    return INT_MIN;

  return player->health;
}

BOOL player_has_object(Player *player, Id object)
{

  if (!player || object == NO_ID)
    return FALSE;

  return set_has_id(inventory_get_objects(player->inventory), object);
}

BOOL player_inventory_is_full(Player *player)
{

  if (!player)
    return TRUE;

  if (set_get_nids(inventory_get_objects(player->inventory)) == inventory_get_max_objs(player->inventory))
    return TRUE;

  return FALSE;
}
/** Modifica la salud del jugador al valor pasado como argumento
 */
STATUS player_set_health(Player *player, int n)
{
  if (!player || n < 0)
    return ERROR;

  player->health = n;

  return OK;
}

/** Imprime la información de un jugador
 */
STATUS player_print(Player *player)
{

  if (!player)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location: %ld)\n", player->id, player->name, player->location);
  inventory_print(player->inventory);
  if (player_get_health(player) != 0)
  {
    fprintf(stdout, "---> PLAYER ALIVE (health: %d).\n", player->health);
  }
  else
  {
    fprintf(stdout, "---> PLAYER DEATH !!!!!.\n");
  }
  return OK;
}