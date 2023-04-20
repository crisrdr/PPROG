/**
 * @brief It defines the enemy interface
 *
 * @file enemy.h
 * @author Cristina Rodríguez de los Ríos Medina y Sofía García Heras
 * @date 11-04-2022
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "types.h"


#define ENEMY_ID 13
#define ENEMY_NAME "ARAÑA"
#define ENEMY_FIRST_LOCATION 124
#define ENEMY_HEALTH 8

/**
 * @brief Enemy
 * 
 * This struct stores all the information of a enemy.
 * 
 */
typedef struct _Enemy Enemy;

/**
  * @brief It creates a new enemy, allocating memory and initializing its memebers
  * @author Sofía y Cristina
  * 
  * @param id the identification number for the new enemy
  * @return a new enemy, initialized
  */
Enemy *enemy_create(Id id);

/**
  * @brief It destroys a enemy, freeing the allocated memory
  * @author Sofía y Cristina
  * 
  * @param enemy a pointer to the enemy that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_destroy(Enemy *enemy);

/**
  * @brief It gets the id of a enemy
  * @author Sofía y Cristina
  * 
  * @param enemy a pointer to the enemy  
  * @return the id of enemy
  */
Id enemy_get_id(Enemy *enemy);

/**
  * @brief It sets the id of the enemy
  * @author Sofía y Cristina
  *
  * @param enemy a pointer to the enemy
  * @param id the id number of the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_id(Enemy *enemy, Id id);

/**
  * @brief It gets the name of a enemy
  * @author Sofía y Cristina
  * 
  * @param enemy a pointer to the enemy  
  * @return the name of the enemy
  */
const char *enemy_get_name(Enemy *enemy);

/**
  * @brief It sets the name of the enemy
  * @author Sofía y Cristina
  *
  * @param enemy a pointer to the enemy
  * @param name the new name of the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_name(Enemy *enemy, char *name);

/**
  * @brief It gets the location of a enemy
  * @author Sofía y Cristina
  * 
  * @param enemy a pointer to the enemy  
  * @return the location of the enemy
  */
Id enemy_get_location(Enemy *enemy);

/**
  * @brief It sets the location of the enemy
  * @author Sofía y Cristina
  *
  * @param enemy a pointer to the enemy
  * @param id of new location of the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_location(Enemy* enemy, Id id);

/**
  * @brief It gets the health of a enemy
  * @author Sofía y Cristina
  * 
  * @param enemy a pointer to the enemy  
  * @return the health of the enemy
  */
Id enemy_get_health(Enemy *enemy);

/**
  * @brief It sets the helath of the enemy
  * @author Sofía y Cristina
  *
  * @param enemy a pointer to the enemy
  * @param health the health of the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_health(Enemy *enemy, int health);


/**
  * @brief It prints the enemy information
  * @author Sofía y Cristina
  *
  * This function shows the enemy id, its name, enemy location, enemy object.
  * @param enemy a pointer to the enemy
  */
STATUS enemy_print(Enemy *enemy);


#endif