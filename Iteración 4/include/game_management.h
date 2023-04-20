/**
 * @brief It defines thegame_management interface
 * 
 * @file game_management.h
 * @author Sofía García Heras
 * @version 0.1
 * @date 24-03-2022 
 */
#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "types.h"
#include "game.h"
#include "space.h"
#include "object.h"

/**
 * @brief it loads the spaces of the game from a file
 * @author Sofía and Cristina
 * 
 * @param game pointer to the game
 * @param filename pointer to the name of the file with the spaces
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_spaces(Game *game, char *filename);

/**
 * @brief it loads the objects of the game from a file
 * @author Cristina R
 * 
 * @param game pointer to the game
 * @param filename pointer to the name of the file with the objects
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_objects(Game *game, char *filename);
/**
 * @brief it loads the players of the game from a file
 * @author Sofia Garcia
 * 
 * @param game pointer to the game
 * @param filename pointer to the name of the file with the players
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_player(Game *game, char *filename);

/**
 * @brief it loads the enemies of the game from a file
 * @author Sofia Garcia
 * 
 * @param game pointer to the game
 * @param filename pointer to the name of the file with the enemies
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_enemy(Game *game, char *filename);
/**
 * @brief it loads the links of the game from a file
 * @author Sofia Garcia
 * 
 * @param game pointer to the game
 * @param filename pointer to the name of the file with the links
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_links(Game *game, char *filename);

/**
  * @brief It saves all the info of the game in a file
  * @author Sofia Garcia
  *
  * @param game a pointer to the game
  * @param filename name of the file where we want to save the information
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS game_management_save(Game *game, char *filename);

/**
  * @brief It loads the info of the game from a file
  * @author Sofia Garcia
  *
  * @param game a pointer to the game
  * @param filename name of the file
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS game_management_load(Game *game, char *filename);
#endif