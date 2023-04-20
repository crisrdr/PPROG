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
#include "inventory.h"


#define PLAYER_ID 1
#define PLAYER_NAME "HORMIGA"
#define PLAYER_FIRST_LOCATION 11
#define PLAYER_HEALTH 10
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
  */
void player_destroy(Player *player);

/**
  * @brief It gets the id of a player
  * @author Sofía y Cristina
  * 
  * @param player a pointer to the player  
  * @return the id of player
  */
Id player_get_id(Player *player);

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
  * @brief It frees the previous inventory and sets a new one
  * @author Sofia Garcia
  *
  * @param player a pointer to the player
  * @param inventory new inventory of the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_inventory(Player *player, Inventory *inventory);

/**
  * @brief It gets the inventory of a player
  * @author Sofia Garcia
  *
  * @param player a pointer to the player
  * @return the inventory of the player
  */
Inventory *player_get_inventory(Player *player);

/**
  * @brief It adds an object to the player inventory
  * @author Sofia Garcia
  *
  * @param player a pointer to the player
  * @param object new object
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_add_object(Player *player, Id object);

/**
  * @brief It removes an object of a player inventory
  * @author Sofia Garcia
  *
  * @param player a pointer to the player
  * @param object object to remove
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_remove_object(Player *player, Id object);

/**
  * @brief It checks if a player has an object
  * @author Sofia Garcia
  *
  * @param player a pointer to the player
  * @param object object ID
  * @return TRUE if the object ID is in the inventory set, otherwise FALSE (or FALSE if there was some mistake)
  */
BOOL player_has_object(Player *player, Id object);

/**
  * @brief It checks if a player inventory is full
  * @author Sofia Garcia
  *
  * @param player a pointer to the player
  * @return TRUE if the inventory is full, otherwise FALSE (or TRUE if there was some mistake)
  */
BOOL player_inventory_is_full(Player *player);


/**
 * @brief It gets the health of the player
 * @author Cristina R
 * 
 * @param player pointer to the player
 * @return the health of the player
 */
int player_get_health(Player *player);

/**
 * @brief It sets the health of the player
 * @author Cristina R
 * 
 * @param player pointer to the player
 * @param n the new health of the player
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
STATUS player_set_health (Player *player, int n);

/**
  * @brief It prints the player information
  * @author Sofía y Cristina
  *
  * This function shows the player id, its name, player location, player object.
  * @param player a pointer to the player
  */
STATUS player_print(Player *player);


#endif