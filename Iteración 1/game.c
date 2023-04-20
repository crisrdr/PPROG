/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"

/**
   Private functions
*/
/**
 * @brief Obtiene el id del espacio
 * @author Profesores PPROG
 *
 * @param game puntero a la partida
 * @param position posición actual
 * @return id del espacio
 */
Id game_get_space_id_at(Game *game, int position);
/**
 * @brief Establece la localizacion del jugador
 * @author Profesores PPROG
 *
 * @param game puntero a la partida
 * @param id  posición del jugador
 * @return OK si todo esta o ERROR si hay algun error
 */
STATUS game_set_player_location(Game *game, Id id);
/**
 * @brief Establece la localizacion del objeto
 * @author Profesores PPROG
 *
 * @param game puntero a la partida
 * @param id  posición del jugador
 * @return OK si todo esta o ERROR si hay algun error
 */
STATUS game_set_object_location(Game *game, Id id);
/**
 * @brief Obtiene el espacio del jugadpr
 * @author Profesores PPROG
 *
 * @param game puntero a la partida
 * @param player puntero al jugador
 * @return OK si todo esta o ERROR si hay algun error
 */
Space *game_get_player_space(Game *game, Player *player);

/**
 * @brief Ejecuta el comando unknown
 * @param game puntero a la partida
 */
void game_command_unknown(Game *game);
/**
 * @brief Ejecuta el comando exit
 * @param game puntero a la partida
 */
void game_command_exit(Game *game);
/**
 * @brief Ejecuta el comando next
 * @param game puntero a la partida
 */
void game_command_next(Game *game);
/**
 * @brief Ejecuta el comando back
 * @param game puntero a la partida
 */
void game_command_back(Game *game);
/**
 * @brief Ejecuta el comando take
 * @param game puntero a la partida
 */
void game_command_take(Game *game);
/**
 * @brief Ejecuta el comando drop
 * @param game puntero a la partida
 */
void game_command_drop(Game *game);
/**
   Game interface implementation
*/

STATUS game_create(Game *game)
{
  int i;
  /*Control errores*/
  if (!game)
  {
    return ERROR;
  }
  /*Crear el numero de espacios definido por MAX_SPACES*/
  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }
  /*Crear el jugador y el objeto*/
  game->player = player_create(PLAYER_ID);
  game->object = object_create(OBJECT_ID);
  game->last_cmd = NO_CMD;

  return OK;
}

STATUS game_create_from_file(Game *game, char *filename)
{
  /*Control errores*/
  if (!filename || !game)
  {
    return ERROR;
  }

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

STATUS game_destroy(Game *game)
{
  int i = 0;
  /*Control errores*/
  if (!game)
  {
    return ERROR;
  }
  /* Eliminar los espacios que se han creado */
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }
  /* Eliminar el objeto y el jugador */
  player_destroy(game->player);
  object_destroy(game->object);

  return OK;
}

STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;
  /*Control errores*/
  if (space == NULL || !game)
  {
    return ERROR;
  }
  /* Posicionamiento al último espacio para añadir el nuevo después de este */
  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }
  /* Comprobación de que no se haya superado el número máximo de espacios */
  if (i >= MAX_SPACES)
  {
    return ERROR;
  }
  /* Asignación del nuevo espacio a la última posición de espacios ocupados */
  game->spaces[i] = space;

  return OK;
}

Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space *game_get_space(Game *game, Id id)
{
  int i = 0;
  /*Control errores*/
  if (id == NO_ID || !game)
  {
    return NULL;
  }
  /* Busca en que espacio se encuentra */
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      /* Devuelve el espacio que ha buscado antes */
      return game->spaces[i];
    }
  }

  return NULL;
}

STATUS game_set_player_location(Game *game, Id id)
{
  /*Control errores*/

  if (id == NO_ID || !game)
  {
    return ERROR;
  }
  /*Asignar al juego la localización del jugador */
  player_set_location(game->player, id);
  return OK;
}

STATUS game_set_object_location(Game *game, Id id)
{
  int i;
  /*Control errores*/

  if (id == NO_ID || !game)
  {
    return ERROR;
  }
  /* Busca en que espacio se encuentra el id */
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == id)
    {
      /*Devuelve un espacio con el objeto*/
      return space_set_object(game->spaces[i], TRUE);
    }
  }

  return OK;
}

Space *game_get_player_space(Game *game, Player *player)
{
  int i = 0;
  Id player_locat;
  Space *player_spc = NULL;
  /*Control errores*/
  if (!game || !player)
  {
    return NULL;
  }
  /*Obtener el id del espacio de donde está el jugador*/
  player_locat = game_get_player_location(game);

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
      /* Busca el espacio que hempos obtenido antes*/
    if (player_locat == space_get_id(game->spaces[i]))
    {
      player_spc = game->spaces[i];
    }
  }
  return player_spc;
}
Id game_get_player_location(Game *game)
{
  /*Control errores*/

  if (!game)
  {
    return NO_ID;
  }
  return player_get_location(game->player);
}

Id game_get_object_location(Game *game)
{
  int i = 0;
  Id obj_spc = NO_ID;
  /*Control errores*/

  if (!game)
    return NO_ID;
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    /*Busca si el objeto esta en los espacios previamente recorridos*/
    if (space_get_object(game->spaces[i]) != FALSE)
    {
      /*Devuelve el id del espacio*/
      obj_spc = space_get_id(game->spaces[i]);
      return obj_spc;
    }
  }
  return NO_ID;
}

STATUS game_update(Game *game, T_Command cmd)
{
  /*Control errores*/
  if (!game)
    return ERROR;

  game->last_cmd = cmd;

  switch (cmd)
  {
  case UNKNOWN:
    game_command_unknown(game);
    break;

  case EXIT:
    game_command_exit(game);
    break;

  case NEXT:
    game_command_next(game);
    break;

  case BACK:
    game_command_back(game);
    break;

  case TAKE:
    game_command_take(game);
    break;

  case DROP:
    game_command_drop(game);
    break;

  default:
    break;
  }

  return OK;
}

T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}

void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)game_get_object_location(game));
  printf("=> Player location: %d\n", (int)game_get_player_location(game));
}

BOOL game_is_over(Game *game)
{
  return FALSE;
}

/**
   Calls implementation for each action
*/
void game_command_unknown(Game *game) {}

void game_command_exit(Game *game) {}

void game_command_next(Game *game)
{
  int i = 0;
  Id id_curr = NO_ID;
  Id id_spc = NO_ID;
  /*Obtiene la localizacion del jugador*/
  id_spc = game_get_player_location(game);
  /*Control errores*/
  if (id_spc == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    
    id_curr = space_get_id(game->spaces[i]);
    if (id_curr == id_spc)
    {
      /*Cuando ha encontrado al jugador en el espacio lo desplaza al sur*/
      id_curr = space_get_south(game->spaces[i]);
      if (id_curr != NO_ID)
      {
        game_set_player_location(game, id_curr);
      }
      return;
    }
  }
}

void game_command_back(Game *game)
{
  int i = 0;
  Id id_curr = NO_ID;
  Id id_spc = NO_ID;
  /*Obtiene la localizacion del jugador*/
  id_spc = game_get_player_location(game);
  /*Control errores*/
  if (NO_ID == id_spc)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    id_curr = space_get_id(game->spaces[i]);
    if (id_curr == id_spc)
    {
      /*Cuando ha encontrado al jugador en el espacio lo desplaza al norte*/
      id_curr = space_get_north(game->spaces[i]);
      if (id_curr != NO_ID)
      {
        game_set_player_location(game, id_curr);
      }
      return;
    }
  }
}

void game_command_take(Game *game)
{
  Space *player_space;

  /*Control errores*/
  if (!game || player_get_object_id(game->player) != NO_ID)
  {
    return;
  }

  player_space = game_get_player_space(game, game->player);

  /*Comprobar si en el espacio hay un objeto */
  if (space_get_object(player_space) == TRUE)
  {
    /*Asociar al jugador el id del objeto */
    player_set_object_id(game->player, object_get_id(game->object));
    /* Quitar el id al espacio */
    space_set_object(player_space, FALSE);
  }

  return;
}

void game_command_drop(Game *game)
{
  Space *player_space;

  /*Control errores*/
  if (!game || player_get_object_id(game->player) == NO_ID)
  {
    return;
  }

  player_space = game_get_player_space(game, game->player);

  /*Si no hay objeto en el espacio  */
  if (space_get_object(player_space) == FALSE)
  {
    /*Quitar al jugador el id del objeto */
    player_set_object_id(game->player, NO_ID);
    /* Asociar el id al espacio */
    game_set_object_location(game, space_get_id(player_space));
  }

  return;
}