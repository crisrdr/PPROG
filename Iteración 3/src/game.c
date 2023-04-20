/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Sofía Garcia
 * @author Cristina Rodriguez
 * @version 2.0
 * @date 19-06-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include "game.h"
#include "game_reader.h"
#include "link.h"

#define MAX_RAND 10
/**
 * @brief Game
 *
 * This struct stores all the information of a game.
 *
 */
struct _Game
{
  Player *player;               /*!< puntero al jugador */
  Enemy *enemy;                 /*!< puntero al enemigo */
  Object *objects[MAX_OBJECTS]; /*!< Array con objectos */
  Space *spaces[MAX_SPACES];    /*!< Array con espacios */
  Command *last_cmd;            /*!< Ultimo comando */
  Link *link[MAX_LINKS];        /*!< Array con enlaces */
};

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
 * @brief Ejecuta el comando right
 * @param game puntero a la partida
 */
void game_command_right(Game *game);
/**
 * @brief Ejecuta el comando left
 * @param game puntero a la partida
 */
void game_command_left(Game *game);
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
 * @brief Ejecuta el comando attack
 * @param game puntero a la partida
 */
void game_command_attack(Game *game);
/**
 * @brief Ejecuta el comando move
 * @param game puntero a la partida
 */
void game_command_move(Game *game);

/**
 * @brief Ejecuta el comando inspect
 * @param game puntero a la partida
 */
void game_command_inspect(Game *game);
/**
   Game interface implementation
*/

/*/////////////////////////////CREATE, DESTROY GAME/////////////////////////////////////*/

Game *game_create()
{
  int i;
  Game *game = NULL;

  game = (Game *)malloc(sizeof(Game));
  if (game == NULL)
    return NULL;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    game->objects[i] = NULL;
  }

  for (i = 0; i < MAX_LINKS; i++)
  {
    game->link[i] = NULL;
  }

  game->player = NULL;
  game->enemy = NULL;
  game->last_cmd = NULL;

  return game;
}

Game *game_create_from_file(char *filename)
{
  Game *game = NULL;
  /*Control errores*/
  if (!filename)
  {
    return NULL;
  }

  if ((game = game_create()) == ERROR)
    return NULL;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return NULL;

  if (game_reader_load_objects(game, filename) == ERROR)
    return NULL;

  if (game_reader_load_player(game, filename) == ERROR)
    return NULL;

  if (game_reader_load_enemy(game, filename) == ERROR)
    return NULL;

  if (game_reader_load_links(game, filename) == ERROR)
    return NULL;

  return game;
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

  /* Eliminar los objetos que se han creado */
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    object_destroy(game->objects[i]);
  }

  /* Eliminar los links que se han creado */
  for (i = 0; i < MAX_LINKS && game->link[i] != NULL; i++)
  {
    link_destroy(game->link[i]);
  }

  /* Eliminar el objeto y el jugador */
  player_destroy(game->player);
  enemy_destroy(game->enemy);
  command_destroy(game->last_cmd);

  free(game);

  return OK;
}
/*/////////////////////////////SPACE MODULE/////////////////////////////////////*/

STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;
  /*Control errores*/
  if (!space || !game)
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

  if (!game || position < 0 || position >= MAX_SPACES)
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

/*/////////////////////////////PLAYER MODULE/////////////////////////////////////*/

Player *game_get_player(Game *game)
{
  if (!game)
    return NULL;

  return game->player;
}
STATUS game_set_player(Game *game, Player *player)
{
  if (player == NULL)
    return ERROR;

  game->player = player;

  return OK;
}

STATUS game_set_object_location(Game *game, Id space, Id object)
{
  int i;
  /*Control errores*/

  if (!game || space == NO_ID || object == NO_ID)
  {
    return ERROR;
  }

  /* Commprueba que el object no se encuentre en ningun otro espacio y lo elimina si es así*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_has_object(game->spaces[i], object))
    {
      space_remove_object(game->spaces[i], object);
    }
  }

  /* Busca el espacio con id == space_id e inserta el object_id */
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == space)
    {
      return space_add_object(game->spaces[i], object);
    }
  }

  return OK;
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
/*/////////////////////////////ENEMY MODULE/////////////////////////////////////*/

STATUS game_set_enemy(Game *game, Enemy *enemy)
{
  if (enemy == NULL)
    return ERROR;

  game->enemy = enemy;

  return OK;
}

/** Gets the pointer to the enemy
 */
Enemy *game_get_enemy(Game *game)
{
  if (!game) return NULL;

  return game->enemy;
}

/** Sets the enemy location
 */
STATUS game_set_enemy_location(Game *game, Id id)
{
  if (!game || id == NO_ID)
    return ERROR;

  enemy_set_location(game->enemy, id);

  return OK;
}

/** Returns the enemy location
 */
Id game_get_enemy_location(Game *game)
{
  return enemy_get_location(game->enemy);
}

/*/////////////////////////////OBJECT MODULE/////////////////////////////////////*/
STATUS game_add_object(Game *game, Object *object)
{
  int i = 0;
  /*Control errores*/
  if (!object || !game)
  {
    return ERROR;
  }
  /* Posicionamiento al último espacio para añadir el nuevo después de este */
  while (i < MAX_OBJECTS && game->objects[i] != NULL)
  {
    i++;
  }
  /* Comprobación de que no se haya superado el número máximo de espacios */
  if (i >= MAX_SPACES)
  {
    return ERROR;
  }
  /* Asignación del nuevo espacio a la última posición de espacios ocupados */
  game->objects[i] = object;

  return OK;
}

Object *game_get_object(Game *game, Id id)
{
  int i = 0;
  /*Control errores*/
  if (id == NO_ID || !game)
  {
    return NULL;
  }
  /* Recorre el array de objetos */
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (id == object_get_id(game->objects[i]))
    {
      /* Devuelve el objeto con ese id */
      return game->objects[i];
    }
  }

  return NULL;
}

Id game_get_object_id_at(Game *game, int position)
{
  if (!game || position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return object_get_id(game->objects[position]);
}
Object *game_get_object_by_name(Game *game, char *name)
{
  int i;

  if (!game || !name)
  {
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (!strcasecmp(name, object_get_name(game->objects[i])))
      break;
  }

  return game->objects[i];
}

Id game_get_object_location(Game *game, Id object)
{
  int i = 0;
  Id obj_spc = NO_ID;
  /*Control errores*/

  if (!game || object == NO_ID)
    return NO_ID;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    /*Busca si el objeto esta en los espacios previamente recorridos*/
    if (space_has_object(game->spaces[i], object))
    {
      /*Devuelve el id del espacio*/
      obj_spc = space_get_id(game->spaces[i]);
      return obj_spc;
    }
  }
  return NO_ID;
}

STATUS game_move_object(Game *game, Id object, Id new_location)
{
  int i, st = OK;

  if (new_location == NO_ID || object == NO_ID || !game)
    return ERROR;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_has_object(game->spaces[i], object))
    {
      st = space_remove_object(game->spaces[i], object);
      if (st == ERROR)
        return ERROR;

      st = space_add_object(game_get_space(game, new_location), object);
      return st;
    }
  }

  return ERROR;
}
/*/////////////////////////////COMMAND MODULE/////////////////////////////////////*/

STATUS game_update(Game *game, Command *cmd)
{
  /*Control errores*/
  if (!game || !cmd)
    return ERROR;

  command_destroy(game->last_cmd);
  game->last_cmd = cmd;

  switch (command_get_type(cmd))
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

  case RIGHT:
    game_command_right(game);
    break;

  case LEFT:
    game_command_left(game);
    break;

  case TAKE:
    game_command_take(game);
    break;

  case DROP:
    game_command_drop(game);
    break;

  case ATTACK:
    game_command_attack(game);
    break;
  case MOVE:
    game_command_move(game);
    break;

  case INSPECT:
    game_command_inspect(game);

  default:
    break;
  }

  return OK;
}

Command *game_get_last_command(Game *game)
{
  if (!game) return NULL;
  return game->last_cmd;
}

BOOL game_is_over(Game *game)
{
  if (!game || player_get_health(game->player) == 0)
    return TRUE;

  return FALSE;
}

void game_print_data(Game *game)
{
  int i = 0;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Player: \n");
  player_print(game->player);

  printf("=> Enemy: \n");
  enemy_print(game->enemy);

  printf("=> Objects: \n");
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    object_print(game->objects[i]);
  }

  printf("=> Links: \n");
  for (i = 0; i < MAX_LINKS && game->link[i] != NULL; i++)
  {
    link_print(game->link[i]);
  }

  printf("=> Last command: %s %s",
         cmd_to_str[command_get_type(game->last_cmd)][CMDL],
         command_get_arg(game->last_cmd));
}

/**
   Calls implementation for each action
*/
void game_command_unknown(Game *game)
{
  if (!game)
    return;

  command_set_status(game->last_cmd, ERROR);
}

void game_command_exit(Game *game)
{
  if (!game)
    return;

  command_set_status(game->last_cmd, OK);
}

void game_command_next(Game *game)
{
  int i = 0;
  Id id_curr = NO_ID;
  Id id_spc = NO_ID;
  Id player_locat = NO_ID;
  if (!game)
    return;

  player_locat = game_get_player_location(game);
  if (player_locat == NO_ID)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {

    id_curr = space_get_id(game->spaces[i]);
    if (id_curr == player_locat)
    {
      if (id_curr != NO_ID && game_get_connection_status(game, id_curr, S) == FALSE)
      {
        id_spc = game_get_connection(game, id_curr, S);
        game_set_player_location(game, id_spc);
        command_set_status(game->last_cmd, OK);
      }
      return;
    }
  }
  command_set_status(game->last_cmd, ERROR);
}

void game_command_back(Game *game)
{
  int i = 0;
  Id id_curr = NO_ID;
  Id id_spc = NO_ID;
  Id player_locat = NO_ID;

  if (!game)
    return;

  player_locat = game_get_player_location(game);
  if (player_locat == NO_ID)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    id_curr = space_get_id(game->spaces[i]);
    if (id_curr == player_locat)
    {
      if (id_curr != NO_ID && game_get_connection_status(game, id_curr, N) == FALSE)
      {
        id_spc = game_get_connection(game, id_curr, N);
        game_set_player_location(game, id_spc);
        command_set_status(game->last_cmd, OK);
      }
      return;
    }
  }

  command_set_status(game->last_cmd, ERROR);
}

void game_command_right(Game *game)
{ /* East*/
  Id id_spc = NO_ID, id_curr = NO_ID;
  int i = 0;
  Id player_locat = NO_ID;

  if (!game)
    return;

  player_locat = game_get_player_location(game);
  if (player_locat == NO_ID)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    id_curr = space_get_id(game->spaces[i]);
    if (id_curr == player_locat)
    {
      if (id_curr != NO_ID && game_get_connection_status(game, id_curr, E) == FALSE)
      {
        id_spc = game_get_connection(game, id_curr, E);
        game_set_player_location(game, id_spc);
        command_set_status(game->last_cmd, OK);
      }
      return;
    }
  }

  command_set_status(game->last_cmd, ERROR);
}

void game_command_left(Game *game)
{ /* West*/
  Id id_spc = NO_ID, id_curr = NO_ID;
  int i;
  Id player_locat = NO_ID;

  if (!game)
    return;

  player_locat = game_get_player_location(game);
  if (player_locat == NO_ID || !game)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    id_curr = space_get_id(game->spaces[i]);
    if (id_curr == player_locat)
    {
      if (id_curr != NO_ID && game_get_connection_status(game, id_curr, W) == FALSE)
      {
        id_spc = game_get_connection(game, id_curr, W);
        game_set_player_location(game, id_spc);
        command_set_status(game->last_cmd, OK);
      }
      return;
    }
  }

  command_set_status(game->last_cmd, ERROR);
}

void game_command_take(Game *game)
{
  int i;
  Id obj = NO_ID;

  if (!game || command_get_arg(game->last_cmd) == NULL || player_inventory_is_full(game->player))
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (!strcasecmp(command_get_arg(game->last_cmd), object_get_name(game->objects[i])))
      obj = object_get_id(game->objects[i]);
  }

  if (obj == NO_ID)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (game_get_player_location(game) == space_get_id(game->spaces[i]))
    {
      if (space_has_object(game->spaces[i], obj))
      {
        player_add_object(game->player, obj);
        space_remove_object(game->spaces[i], obj);
        command_set_status(game->last_cmd, OK);
        return;
      }
    }
  }

  command_set_status(game->last_cmd, ERROR);
}

void game_command_drop(Game *game)
{
  int i;
  Id obj = NO_ID;

  if (!game || command_get_arg(game->last_cmd) == NULL)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (!strcasecmp(command_get_arg(game->last_cmd), object_get_name(game->objects[i])))
      obj = object_get_id(game->objects[i]);
  }
  if (obj == NO_ID || !player_has_object(game->player, obj))
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (game_get_player_location(game) == space_get_id(game->spaces[i]))
    {
      space_add_object(game->spaces[i], obj);
      player_remove_object(game->player, obj);
      command_set_status(game->last_cmd, OK);
      return;
    }
  }

  command_set_status(game->last_cmd, ERROR);
}

void game_command_attack(Game *game)
{
  /*Id player_loc, enemy_loc;*/
  int player_h, enemy_h;
  int attackpow = -1;

  if (!game)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  player_h = player_get_health(game->player);
  enemy_h = enemy_get_health(game->enemy);

  if (enemy_h == 0 || game_get_enemy_location(game) != game_get_player_location(game))
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  srand(time(NULL));
  attackpow = rand() % 10;

  if (attackpow >= 0 && attackpow <= 4)
  {
    player_set_health(game->player, player_h - 1);
  }
  else if (attackpow >= 5 && attackpow <= 9)
  {
    enemy_set_health(game->enemy, enemy_h - 1);
  }

  command_set_status(game->last_cmd, OK);
}

void game_command_move(Game *game)
{
  char *argums = NULL;

  if (!game)
    return;

  argums = command_get_arg(game->last_cmd);

  if (!strcasecmp(argums, "n") || !strcasecmp(argums, "north"))
    game_command_back(game);
  else if (!strcasecmp(argums, "s") || !strcasecmp(argums, "south"))
    game_command_next(game);
  else if (!strcasecmp(argums, "e") || !strcasecmp(argums, "east"))
    game_command_right(game);
  else if (!strcasecmp(argums, "w") || !strcasecmp(argums, "west"))
    game_command_left(game);
}

void game_command_inspect(Game *game)
{
  int i;
  char *argum = NULL;
  Id space_act = NO_ID;

  if (!game)
    return;

  argum = command_get_arg(game->last_cmd);
  space_act = game_get_player_location(game);

  if (!strcasecmp("s", argum) || !strcasecmp("space", argum))
  {
    command_set_status(game->last_cmd, OK);
    return;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (!strcasecmp(argum, object_get_name(game->objects[i])) && (game_get_object_location(game, object_get_id(game->objects[i])) == space_act || player_has_object(game->player, object_get_id(game->objects[i]))))
    {
      command_set_status(game->last_cmd, OK);
      return;
    }
  }

  command_set_status(game->last_cmd, ERROR);
}

/*/////////////////////////////LINK MODULE/////////////////////////////////////*/

BOOL game_get_connection_status(Game *game, Id origin, DIRECTION direction)
{
  int i;

  if (!game || origin == NO_ID || direction == NO_DIR)
    return TRUE;

  for (i = 0; i < MAX_LINKS && game->link[i] != NULL; i++)
  {
    if (link_get_origin(game->link[i]) == origin && link_get_direction(game->link[i]) == direction)
    {
      return link_get_status(game->link[i]);
    }
  }

  return TRUE;
}

Id game_get_connection(Game *game, Id origin, DIRECTION direction)
{
  int i;

  if (!game || origin == NO_ID || direction == NO_DIR)
    return NO_ID;

  for (i = 0; i < MAX_LINKS && game->link[i] != NULL; i++)
  {
    if (link_get_origin(game->link[i]) == origin && link_get_direction(game->link[i]) == direction)
    {
      return link_get_destination(game->link[i]);
    }
  }

  return NO_ID;
}
STATUS game_add_link(Game *game, Link *link)
{
  int i = 0;

  if (!link || !game)
    return ERROR;

  while (i < MAX_LINKS && game->link[i] != NULL)
  {
    i++;
  }

  game->link[i] = link;

  return OK;
}
BOOL game_get_dest_connection_status(Game *game, Id origin, Id destination)
{
  int i;

  if (!game || origin == NO_ID || destination == NO_ID)
    return TRUE;

  for (i = 0; i < MAX_LINKS && game->link[i]; i++)
  {
    if (link_get_origin(game->link[i]) == origin && link_get_destination(game->link[i]) == destination)
    {
      return link_get_status(game->link[i]);
    }
  }

  return TRUE;
}
