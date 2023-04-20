/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

/**
 * @brief Graphic_engine
 * 
 * This struct stores all the information of the graphic engine
 * 
 */
typedef struct _Graphic_engine Graphic_engine;

/**
  * @brief It creates a new graphic engine, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @return the new graphic engine, initialized
  */
Graphic_engine *graphic_engine_create();

/**
  * @brief It destroys a graphic engine, freeing the allocated memory
  * @author Profesores PPROG
  * 
  * @param ge a pointer to the graphic engine that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
void graphic_engine_destroy(Graphic_engine *ge);

/**
  * @brief It prints the graphic engine of the game
  * @author Profesores PPROG
  * 
  * @param ge a pointer to the graphic engine
  * @param game a pointer to the game
  */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
