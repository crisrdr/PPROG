/**
 * @brief It defines the player interface
 *
 * @file player.h
 * @author Cristina Rodríguez de los Ríos Medina y Sofía García Heras
 * @date 24-03-2022
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

#define PLAYER_ID 1

/**
 * @brief Player
 * 
 * This struct stores all the information of a player.
 * 
 */
typedef struct _Player Player;

/**
  * @brief It creates a new player, allocating memory and initializing its memebers
  * @author Sofía y Cristina
  * 
  * @param id the identification number for the new player
  * @return a new player, initialized
  */
Player *player_create(Id id);

/**
  * @brief It destroys a player, freeing the allocated memory
  * @author Sofía y Cristina
  * 
  * @param player a pointer to the player that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_destroy(Player *player);

/**
  * @brief It gets the id of a player
  * @author Sofía y Cristina
  * 
  * @param player a pointer to the player  
  * @return the id of player
  */
Id player_get_id(Player *player);

/**
  * @brief It sets the id of the player
  * @author Sofía y Cristina
  *
  * @param player a pointer to the player
  * @param id the id number of the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_id(Player *player, Id id);

/**
  * @brief It gets the name of a player
  * @author Sofía y Cristina
  * 
  * @param player a pointer to the player  
  * @return the name of the player
  */
const char *player_get_name(Player *player);

/**
  * @brief It sets the name of the player
  * @author Sofía y Cristina
  *
  * @param player a pointer to the player
  * @param name the new name of the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_name(Player *player, char *name);

/**
  * @brief It gets the location of a player
  * @author Sofía y Cristina
  * 
  * @param player a pointer to the player  
  * @return the location of the player
  */
Id player_get_location(Player *player);

/**
  * @brief It sets the location of the player
  * @author Sofía y Cristina
  *
  * @param player a pointer to the player
  * @param id of new location of the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_location(Player* player, Id id);

/**
  * @brief It gets the object of a player
  * @author Sofía y Cristina
  * 
  * @param player a pointer to the player  
  * @return the id of the object of the player
  */
Id player_get_object_id(Player* player);

/**
  * @brief It sets the object of the player
  * @author Sofía y Cristina
  *
  * @param player a pointer to the player
  * @param id the new object id of the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_object_id(Player* player, Id id);

/**
  * @brief It prints the player information
  * @author Sofía y Cristina
  *
  * This function shows the player id, its name, player location, player object.
  * @param player a pointer to the player
  */
STATUS player_print(Player *player);


#endif