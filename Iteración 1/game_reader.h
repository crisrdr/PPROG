/**
 * @brief It defines the game reader interface
 * 
 * @file game_reader.h
 * @author Sofía García Heras
 * @version 0.1
 * @date 24-03-2022 
 */
#ifndef GAME_READER_H
#define GAME_READER_H

#include "types.h"
#include "game.h"

/**
 * @brief it loads the spaces of the game from a file
 * @author Sofía and Cristina
 * 
 * @param game pointer to the game
 * @param filename pointer to the name of the file with the spaces
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_reader_load_spaces(Game *game, char *filename);

#endif