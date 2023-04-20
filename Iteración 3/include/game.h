/** 
 * @brief It defines the game interface
 * 
 * @file game.h
 * @author Sofía García Heras y Cristina Rodríguez de los Ríos Medina
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "object.h"
#include "player.h"
#include "enemy.h"
#include "set.h"
#include "link.h"

typedef struct _Game Game;

/*/////////////////////////////CREATE, DESTROY GAME/////////////////////////////////////*/


/**
 * @brief It creates a new game, allocating memory and initializing its memebers
 * @author Sofía y Cristina
 *
 * @return a new game, initialized
 */
Game *game_create();

/**
 * @brief It creates a game from a file
 * @author Sofía and Cristina
 *
 * @param game pointer to the game to be created
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Game *game_create_from_file(char *filename);

/**
 * @brief It destroys a game, freeing the allocated memory
 * @author Sofia y Cristina
 *
 * @param game a pointer to the game that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_destroy(Game *game);

/*/////////////////////////////SPACE MODULE/////////////////////////////////////*/

/**
 * @brief Add a new space to the game
 * @author Sofía and Cristina
 *
 * @param game pointer to the game
 * @param space pointer to the space to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_add_space(Game *game, Space *space);

/**
 * @brief It gets a space of a game
 * @author Sofía y Cristina
 *
 * @param game a pointer to the game
 * @param id id of the space
 * @return the space
 */
Space *game_get_space(Game *game, Id id);

/*/////////////////////////////PLAYER MODULE/////////////////////////////////////*/

/**
 * @brief It gets the Player of the game
 * @author Sofía and Cristina
 *
 * @param game pointer to the game
 * @return pointer to the player of the game
 */
Player *game_get_player(Game *game);
/**
  * @brief It sets the player pointer
  * @author Sofía
  *
  * @param game pointer to the game
  * @param player pointer to the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS game_set_player(Game *game, Player *player);

/**
 * @brief It gets the location of the player of the game
 * @author Sofía y Cristina
 *
 * @param game a pointer to the game
 * @return a pointer to the player of the game
 */
Id game_get_player_location(Game *game);


/**
 * @brief It sets the player location.
 * @author Sofía
 *
 * @param game pointer to the game data
 * @param id id of the new space of the new player location
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_player_location(Game *game, Id id);

/*/////////////////////////////ENEMY MODULE/////////////////////////////////////*/

/**
  * @brief It sets the enemy pointer
  * @author Sofia
  *
  * @param game pointer to the game
  * @param enemy a pointer to the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS game_set_enemy(Game *game, Enemy *enemy);

/**
  * @brief It gets the pointer of the enemy
  * @author Sofia
  *
  * @param game pointer to the game
  * @return a pointer to the enemy
  */
Enemy *game_get_enemy(Game *game);

/**
  * @brief It sets the enemy location.
  * @author Sofia
  *
  * @param game pointer to the game data
  * @param id id of the new space where the enemy is located
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS game_set_enemy_location(Game *game, Id id);

/**
  * @brief It returns the enemy location
  * @author Sofia
  *
  * @param game pointer to the game
  * @return ID of the space where the enemy is located
  */
Id game_get_enemy_location(Game *game);

/*/////////////////////////////OBJECT MODULE/////////////////////////////////////*/
/**
 * @brief Add a new object to the game
 * @author Cristina  R
 *
 * @param game pointer to the game
 * @param space pointer to the object to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_add_object(Game *game, Object *object);
/**
 * @brief It gets an object of a game
 * @author Cristina R
 *
 * @param game a pointer to the game
 * @param id of the object
 * @return the objects
 */
Object *game_get_object(Game *game, Id id);
/**
 * @brief Obtiene el id del espacio en el que se encuentra el objeto
 *@author Cristina R
 * 
 * @param game puntero a la partida
 * @param position posición actual
 * @return id del objeto
 */
Id game_get_object_id_at(Game *game, int position);
/**
  * @brief It gets an object from the game array from its name.
  * @author Sofia Garcia
  *
  * @param game pointer to the game
  * @param name name of the object
  * @return pointer to the object
  */
Object *game_get_object_by_name(Game *game, char *name);
/**
 * @brief It gets the location of the object with the id passed
 * @author Sofía y Cristina
 *
 * @param game a pointer to the game
 * @param object id of the object to get its location
 * @return a pointer to the object of the game
 */
Id game_get_object_location(Game *game, Id object);
/**
  * @brief It sets the object location
  * @author Sofia Garcia
  *
  * @param game a pointer to the game
  * @param object id of the object
  * @param new_location id of the space where we want to move the object
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS game_move_object(Game *game, Id object, Id new_location);

/*/////////////////////////////COMMAND MODULE/////////////////////////////////////*/

/**
 * @brief It update the last command recieved
 * @author Sofía and Cristina
 *
 * @param game pointer to the game
 * @param cmd the new command
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_update(Game *game, Command *cmd);
/**
 * @brief It gets the last command of the game
 * @author Sofía y Cristina
 *
 * @param game pointer to the game
 * @return the last command recieved
 */
Command *game_get_last_command(Game *game);


/**
 * @brief It gets whether the game is over or not
 * @author Sofia y Cristina
 *
 * @param game a pointer to the game
 * @return TRUE, if the game is over or FALSE if not.
 */
BOOL game_is_over(Game *game);

/**
 * @brief It prints the game information
 * @author Sofía y Cristina
 *
 * This function shows the info of the player, object and each of the spaces.
 * @param game a pointer to the game
 */
void game_print_data(Game *game);

/*/////////////////////////////LINK MODULE/////////////////////////////////////*/


/**
  * @brief It gets the conection status of a game link
  * @author Sofia Garcia
  *
  * @param game a pointer to the game
  * @param origin ID of the origin space of a link
  * @param direction direction of the link (NO_DIR = -1, N (NORTH) = 0, S (SOUTH) = 1, E (EAST) = 2, W (WEST) = 3)
  * @return FALSE if the link is open, otherwise TRUE (or TRUE if there was an error)
  */
BOOL game_get_connection_status(Game *game, Id origin, DIRECTION direction) ;
/**
  * @brief It gets the destionation of a game link
  * @author Sofia Garcia
  *
  * @param game a pointer to the game
  * @param origin ID of the origin space of a link
  * @param direction direction of the link (NO_DIR = -1, N (NORTH) = 0, S (SOUTH) = 1, E (EAST) = 2, W (WEST) = 3)
  * @return destination of the link
  */
Id game_get_connection(Game *game, Id origin, DIRECTION direction);
/**
 * @brief Add a new link to the game
 * @author Sofia Garcia
 *
 * @param game pointer to the game
 * @param link pointer to the link to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_add_link(Game *game, Link *link);
/**
  * @brief It gets the conection status of a game link from its origin and its destination
  * @author Sofia Garcia
  *
  * @param game pointer to the game
  * @param origin ID of the origin space of a link
  * @param destination ID of the destination space of a link
  * @return FALSE if the link is open, otherwise TRUE (or TRUE if there was an error)
  */
BOOL game_get_dest_connection_status(Game *game, Id origin, Id destination);


#endif
