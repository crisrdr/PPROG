/**
 * @brief It implements the game reader module
 *
 * @file game_reader.c
 * @author Sofía García Heras
 * @date 24-03-2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_reader.h"
#include "space.h"
#include "game.h"
#include "object.h"
#include "enemy.h"
#include "types.h"
#include "player.h"
#include "link.h"

/** Carga los datos de un fichero donde se encuentra el juego almacenado
 */

STATUS game_reader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
  char *toks = NULL;
  char **gdesc = NULL;
  Id id = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  int i = 0;

  /* Control de errores */
  if (!game || !filename)
    return ERROR;

  /* Reserva de memoria para la descripción gráfica */
  gdesc = (char **)malloc(N_S * sizeof(char *));
  if (!gdesc)
    return ERROR;

  for (i = 0; i < N_S; i++)
  {
    gdesc[i] = (char *)calloc(N_C + 1, sizeof(char));
    if (!gdesc[i])
    {
      for (i--; i >= 0; i--)
        free(gdesc[i]);
      free(gdesc);
    }
  }

  /* Apertura del fichero */
  file = fopen(filename, "r");
  if (!file)
  {
    for (i = 0; i < N_S; i++)
      free(gdesc[i]);
    free(gdesc);
    return ERROR;
  }

  /* Lectura del fichero */
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      for (i = 0; i < N_S; i++)
      {
        strcpy(gdesc[i], " ");
        toks = strtok(NULL, "|");
        if (toks != NULL)
          strcpy(gdesc[i], toks);
      }
      toks = strtok(NULL, "|");
      if (toks != NULL)
        strcpy(desc, toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s|\n", id, name, gdesc[0], gdesc[1], gdesc[2], gdesc[3], gdesc[4], desc);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_gdesc(space, gdesc);
        space_set_descr(space, desc);
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file))
    status = ERROR;

  /* Liberacion de la descripción gráfica */
  for (i = 0; i < N_S; i++)
    free(gdesc[i]);
  free(gdesc);

  /* Cierre del fichero */
  fclose(file);

  return status;
}

STATUS game_reader_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

  if (!game || !filename)
    return ERROR;

  /* Apertura del fichero */
  if ((file = fopen(filename, "r")) == NULL)
    return ERROR;

  /* Lectura del fichero */
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      if (toks != NULL)
        strcpy(desc, toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%s|\n", id, name, location, desc);
#endif
      object = object_create(id);
      if (object != NULL)
      {
        object_set_name(object, name);
        object_set_descr(object, desc);
        space_add_object(game_get_space(game, location), id);
        game_add_object(game, object);
      }
    }
  }

  if (ferror(file))
    status = ERROR;

  /* Cierre del fichero */
  fclose(file);

  return status;
}

STATUS game_reader_load_player(Game *game, char *filename)
{
  FILE *f = NULL;
  char line[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  char name[WORD_SIZE] = "";
  Player *player = NULL;
  int health = 0, nobj = 0;
  STATUS status = OK;

  if (!game || !filename)
  {
    return ERROR;
  }

  /* FILE OPENING */
  f = fopen(filename, "r");
  if (f == NULL)
  {
    return ERROR;
  }

  /* FILE READING */
  while (fgets(line, WORD_SIZE, f)) /* Reads one line */
  {
    if (strncmp("#p:", line, 3) == 0) /* Checks if the first three char follow the format "#p:" */
    {
      toks = strtok(line + 3, "|"); /* Splits the line in tokens divided by "|" */
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      health = (int)atol(toks);
      toks = strtok(NULL, "|");
      nobj = (int)atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%d|%d\n", id, name, location, health, nobj);
#endif
      player = player_create(id);
      if (player != NULL)
      {
        player_set_name(player, name);
        player_set_location(player, location);
        player_set_health(player, health);
        inventory_set_max_objs(player_get_inventory(player), nobj);
        game_set_player(game, player);
      }
    }
  }

  if (ferror(f)) /* Checks any errors in reading */
  {
    status = ERROR;
  }

  fclose(f);

  return status;
}

STATUS game_reader_load_enemy(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  char name[WORD_SIZE] = "";
  Enemy *enemy = NULL;
  int health = 0;
  STATUS status = OK;

  if (!game || !filename)
  {
    return ERROR;
  }

  /* FILE OPENING */
  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  /* FILE READING */
  while (fgets(line, WORD_SIZE, file)) /* Reads one line */
  {
    if (strncmp("#e:", line, 3) == 0) /* Checks if the first three char follow the format "#e:" */
    {
      toks = strtok(line + 3, "|"); /* Splits the line in tokens divided by "|" */
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      health = (int)atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%d\n", id, name, location, health);
#endif
      enemy = enemy_create(id);
      if (enemy != NULL)
      {
        enemy_set_name(enemy, name);
        enemy_set_location(enemy, location);
        enemy_set_health(enemy, health);
        game_set_enemy(game, enemy);
      }
    }
  }

  if (ferror(file)) /* It checks any errors in reading */
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_reader_load_links(Game *game, char *filename)
{
  FILE *file = NULL;
  char name[WORD_SIZE] = "";
  char line[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, origin = NO_ID, destination = NO_ID;
  DIRECTION direction = NO_DIR;
  LINK_ST status = CLOSE;
  Link *link = NULL;
  STATUS st = OK;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "r");
  if (file == NULL)
    return ERROR;

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#l:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      origin = atol(toks);
      toks = strtok(NULL, "|");
      destination = atol(toks);
      toks = strtok(NULL, "|");
      direction = atol(toks);
      toks = strtok(NULL, "|");
      status = atol(toks);
#ifdef DEBUG
      printf("Read: %ld|%s|%ld|%ld|%d|%d|", id, name, origin, destination, direction, status);
#endif
      link = link_create(id);
      if (link != NULL)
      {
        link_set_name(link, name);
        link_set_origin(link, origin);
        link_set_destination(link, destination);
        link_set_direction(link, direction);
        link_set_status(link, status);
        game_add_link(game, link);
      }
    }
  }

  if (ferror(file))
  {
    st = ERROR;
  }

  fclose(file);

  return st;
}
