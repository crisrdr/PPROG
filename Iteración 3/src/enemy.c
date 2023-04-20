/**
 * @brief It implements the enemy module
 *
 * @file enemy.c
 * @author Cristina Rodríguez de los Ríos Medina y Sofía García Heras
 * @date 11-04-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enemy.h"

/**
 * @brief Enemy
 *
 * Esta estructura almacena toda la información de un enemigo
 */
struct _Enemy
{
  Id id;                    /*!< Número de identificacion del enemigo, debe ser único*/
  char name[WORD_SIZE + 1]; /*!< Nombre del enemigo */
  Id location;              /*!< Id de la ubicación del enemigo*/
  int health;               /*!< Salud del enemigo */
};

/** enemy_create reserva memoria para un nuevo enemigo e inicializa sus miembros
 */
Enemy *enemy_create(Id id)
{
  Enemy *newEnemy = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newEnemy = (Enemy *)malloc(sizeof(Enemy));
  if (newEnemy == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty space*/
  newEnemy->id = id;
  newEnemy->name[0] = '\0';
  newEnemy->location = NO_ID;
  newEnemy->health = 10;

  return newEnemy;
}

/** enemy_destroy libera la memoria que ha sido previamente reservada
 *  para un jugador
 */
STATUS enemy_destroy(Enemy *enemy)
{
  if (!enemy)
  {
    return ERROR;
  }

  free(enemy);
  enemy = NULL;
  return OK;
}

/** Obtiene el id de un enemigo
 */
Id enemy_get_id(Enemy *enemy)
{
  if (!enemy)
  {
    return NO_ID;
  }
  return enemy->id;
}

/** Obtiene el nombre de un enemigo
 */
const char *enemy_get_name(Enemy *enemy)
{
  if (!enemy)
  {
    return NULL;
  }
  return enemy->name;
}

/** Asigna el nombre a un enemigo
 */
STATUS enemy_set_name(Enemy *enemy, char *name)
{
  if (!enemy || !name)
  {
    return ERROR;
  }

  if (!strcpy(enemy->name, name))
  {
    return ERROR;
  }
  return OK;
}

/** Obtiene el id de la ubicación de un enemigo
 */
Id enemy_get_location(Enemy *enemy)
{
  if (!enemy)
  {
    return NO_ID;
  }
  return enemy->location;
}

/** Asigna el id de la ubicación a un enemigo
 */
STATUS enemy_set_location(Enemy *enemy, Id id)
{
  if (!enemy || !id)
    return ERROR;

  enemy->location = id;

  return OK;
}

/** Obtiene la salud de un enemigo
 */
int enemy_get_health(Enemy *enemy)
{
  if (!enemy)
    return NO_ID;

  return enemy->health;
}

/** Asigna la salud a un enemigo
 */
STATUS enemy_set_health(Enemy *enemy, int health)
{
  if (!enemy || health < 0)
    return ERROR;

  enemy->health = health;

  return OK;
}

/** Imprime la información de un enemigo
 */
STATUS enemy_print(Enemy *enemy)
{

  if (!enemy)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Enemy (Id: %ld; Name: %s; Location: %ld)\n", enemy->id, enemy->name, enemy->location);

  if (enemy_get_health(enemy) == 0)
  {
    fprintf(stdout, "---> Dead enemy !!!\n");
  }
  else
  {
    fprintf(stdout, "---> The enemy is alive (Health: %d).\n", enemy->health);
  }
  return OK;
}