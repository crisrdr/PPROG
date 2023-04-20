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
#include <limits.h>
#include <time.h>
#include "game.h"
#include "game_reader.h"

#define MAX_RAND 10

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
STATUS game_set_object_location(Game *game, Id space_id, Id object_id);
/**
 * @brief Establece la localización del Enemigo
 * @author Cristina R
 *
 * @param game puntero a la partida
 * @param id posición del enemigo
 * @return Ok si todo está bien o ERROR si ha ocurrido algún fallo
 */
STATUS game_set_enemy_location(Game *game, Id id);
/**
 * @brief Obtiene el espacio del jugador
 * @author Profesores PPROG
 *
 * @param game puntero a la partida
 * @param player puntero al jugador
 * @return OK si todo esta o ERROR si hay algun error
 */
Space *game_get_player_space(Game *game, Player *player);
/**
 * @brief Obtiene el espacio del enemigo
 * @author Cristina R
 *
 * @param game puntero a la partida
 * @param enemy puntero al enemigo
 * @return OK si todo esta o ERROR si hay algun error
 */
Space *game_get_enemy_space(Game *game, Enemy *enemy);

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
   Game interface implementation
*/

/*/////////////////////////////CREATE, DESTROY GAME/////////////////////////////////////*/

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
  /*Crear el numero de objetos definido por MAX_OBJECTS*/
  for (i = 0; i < MAX_OBJECTS; i++)
  {
    game->objects[i] = NULL;
  }
  /*Crear el jugador y el objeto*/
  game->player = player_create(PLAYER_ID);
  game->enemy = enemy_create(ENEMY_ID);
  game->last_cmd = command_create();

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

  if (game_reader_load_objects(game, filename) == ERROR)
    return ERROR;

  /* The player is located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  /* The enemy is located in the third space */
  game_set_enemy_location(game, game_get_space_id_at(game, 3));

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
  /* Eliminar los objetos que se han creado */
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    object_destroy(game->objects[i]);
  }
  /* Eliminar el objeto y el jugador */
  player_destroy(game->player);
  enemy_destroy(game->enemy);
  command_destroy(game->last_cmd);

  return OK;
}
/*/////////////////////////////SPACE MODULE/////////////////////////////////////*/

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
STATUS game_load_player(Game *game) 
{
  Player *new_player = NULL;

  if (!game)
    return ERROR;

  new_player = player_create(PLAYER_ID);
  player_set_name(new_player, PLAYER_NAME);
  player_set_health(new_player, PLAYER_HEALTH);
  game_set_player(game, new_player);
  game_set_player_location(game, PLAYER_FIRST_LOCATION);

  return OK;
}
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

Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
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

STATUS game_load_enemy(Game *game) 
{
  Enemy *new_enemy = NULL;

  if (!game)
    return ERROR;

  new_enemy = enemy_create(ENEMY_ID);
  enemy_set_name(new_enemy, ENEMY_NAME);
  enemy_set_health(new_enemy, ENEMY_HEALTH);
  game_set_enemy(game, new_enemy);
  game_set_enemy_location(game, ENEMY_FIRST_LOCATION);

  return OK;
}

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
  return game->enemy;
}


/** Sets the enemy location
  */
STATUS game_set_enemy_location(Game *game, Id id)
{
  if (id == NO_ID)
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
  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return object_get_id(game->objects[position]);
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
/*/////////////////////////////COMMAND MODULE/////////////////////////////////////*/

STATUS game_update(Game *game, Command *cmd)
{
  /*Control errores*/
  if (!game || !cmd)
    return ERROR;

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

  default:
    break;
  }

  return OK;
}

Command *game_get_last_command(Game *game)
{
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

  printf("=> Player location: %d\n", (int)game_get_player_location(game));
  printf("=> Enemy location: %d\n", (int)game_get_enemy_location(game));
  printf("=> Object location: \n");
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    object_print(game->objects[i]);
  }

  printf("=> Last command: %s %s", cmd_to_str[command_get_type(game->last_cmd)][CMDL], command_get_arg(game->last_cmd));

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

Space *game_get_enemy_space(Game *game, Enemy *enemy)
{
  int i = 0;
  Id enemy_locat;
  Space *enemy_spc = NULL;
  /*Control errores*/
  if (!game || !enemy)
  {
    return NULL;
  }
  /*Obtener el id del espacio de donde está el enemigo*/
  enemy_locat = game_get_player_location(game);

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    /* Busca el espacio que hempos obtenido antes*/
    if (enemy_locat == space_get_id(game->spaces[i]))
    {
      enemy_spc = game->spaces[i];
    }
  }
  return enemy_spc;
}



int game_get_player_health(Game *game)
{
  if (!game)
    return INT_MIN;

  return player_get_health(game->player);
}

int game_get_enemy_health(Game *game)
{
  if (!game)
    return INT_MIN;

  return enemy_get_health(game->enemy);
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
    command_set_status(game->last_cmd, ERROR);
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
  /*Obtiene la localizacion del jugador*/
  id_spc = game_get_player_location(game);
  /*Control errores*/
  if (NO_ID == id_spc)
  {
    command_set_status(game->last_cmd, ERROR);
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
  int i;

  id_spc = game_get_player_location(game);

  if (id_spc == NO_ID)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    id_curr = space_get_id(game->spaces[i]);
    if (id_curr == id_spc)
    {
      id_curr = space_get_east(game->spaces[i]);
      if (id_curr != NO_ID)
      {
        game_set_player_location(game, id_curr);
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

  id_spc = game_get_player_location(game);

  if (id_spc == NO_ID)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    id_curr = space_get_id(game->spaces[i]);
    if (id_curr == id_spc)
    {
      id_curr = space_get_west(game->spaces[i]);
      if (id_curr != NO_ID)
      {
        game_set_player_location(game, id_curr);
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

  if (!game || player_get_object_id(game->player) != NO_ID)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  if (!strncmp(command_get_arg(game->last_cmd), "O", 1) || !strncmp(command_get_arg(game->last_cmd), "o", 1))
  {
    obj = atol(command_get_arg(game->last_cmd) + 1);
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
      if (game_get_player_location(game) == space_get_id(game->spaces[i]))
      {
        if (player_get_object_id(game->player) == NO_ID && space_has_object(game->spaces[i], obj))
        {
          player_set_object_id(game->player, obj);
          space_remove_object(game->spaces[i], obj);
          command_set_status(game->last_cmd, OK);
          return;
        }
      }
    }
  }

  command_set_status(game->last_cmd, ERROR);
}

void game_command_drop(Game *game)
{
  int i;
  Id id_obj = NO_ID;

  if (!game)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  id_obj = player_get_object_id(game->player);
  if (id_obj == NO_ID)
  {
    command_set_status(game->last_cmd, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (game_get_player_location(game) == space_get_id(game->spaces[i]))
    {
      space_add_object(game->spaces[i], id_obj);
      player_set_object_id(game->player, NO_ID);
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

  /*player_loc = player_get_location(game->player);
  enemy_loc = enemy_get_location(game->enemy);*/
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
