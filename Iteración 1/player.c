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
#include "player.h"

/**
 * @brief Player
 * 
 * Esta estructura almacena toda la información de un jugador
 */
struct _Player
{
    Id id;                      /*!< Número de identificacion del jugador, debe ser único*/
    char name[WORD_SIZE + 1];   /*!< Nombre del jugador */
    Id location;                /*!< Id de la ubicación del jugador*/
    Id object_id;                  /*!< Id del objeto del jugador */
};

/** player_create reserva memoria para un nuevo jugador e inicializa sus miembros
  */
Player *player_create(Id id)
{
    Player *newPlayer = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    newPlayer = (Player *)malloc(sizeof(Player));
    if (newPlayer == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty space*/
    newPlayer->id = id;
    newPlayer->name[0] = '\0';
    newPlayer->location = NO_ID;
    newPlayer->object_id = NO_ID;

    return newPlayer;
}

/** player_destroy libera la memoria que ha sido previamente reservada
  *  para un jugador
  */
STATUS player_destroy(Player *player)
{
    if (!player)
    {
        return ERROR;
    }

    free(player);
    player = NULL;
    return OK;
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

/** Asigna el id a un jugador
  */
STATUS player_set_id(Player *player, Id id)
{
    if (!player || !id) return ERROR;

    player->id = id;

    return OK;
}

/** Obtiene el nombre de un jugador
  */
const char *player_get_name(Player *player)
{
     if (!player) {
    return NULL;
  }
  return player->name;
}

/** Asigna el nombre a un jugador
  */
STATUS player_set_name(Player *player, char *name)
{
    if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }
  return OK;
}

/** Obtiene el id de la ubicación de un jugador
  */
Id player_get_location(Player *player) {
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
    if (!player || !id) return ERROR;

    player->location = id;

    return OK;
}

/** Obtiene el id del objeto de un jugador
  */
Id player_get_object_id(Player *player)
{
    if (!player) return NO_ID;

    return player->object_id;
}

/** Asigna el id del objeto a un jugador
  */
STATUS player_set_object_id(Player *player, Id id)
{
    if (!player || !id) return ERROR;

    player->object_id = id;

    return OK;
}

/** Imprime la información de un jugador
  */
STATUS player_print(Player *player)
{

  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location: %ld; Object id: %ld)\n", player->id, player->name, player->location, player->object_id);
  return OK;
}