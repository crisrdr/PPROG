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
#include "set.h"

/** Carga los datos de un fichero donde se encuentra el juego almacenado
 */

STATUS game_reader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  char **gdesc = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  int i=0;

  /* Control de errores */
  if (!filename)
    return ERROR;

  /* Reserva de memoria para la descripción gráfica */
  gdesc = (char**) malloc (N_S * sizeof(char*));
  if (!gdesc) return ERROR;

  for (i = 0; i < N_S; i++){
    gdesc[i] = (char*) calloc (N_C + 1, sizeof(char));
    if (!gdesc[i]){
      for (i--; i >= 0; i--){
        free(gdesc[i]);
      }
      free(gdesc);
    }
  }

  /* Apertura del fichero */
  file = fopen(filename, "r");
  if (!file) {
    for (i = 0; i < N_S; i++){
      free(gdesc[i]);
    }
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
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      for (i = 0; i < N_S; i++){
        strcpy(gdesc[i], " ");
        toks = strtok (NULL, "|");
        if (toks != NULL){
          strcpy(gdesc[i], toks);
        }
      }
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        space_set_gdesc(space, gdesc);
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file))
    status = ERROR;

  /* Liberacion de la descripción gráfica */
  for (i = 0; i < N_S; i++){
    free(gdesc[i]);
  }
  free(gdesc);

  /* Cierre del fichero */
  fclose(file);

  return status;
}

STATUS game_reader_load_objects(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, space = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

  if (!game || !filename) return ERROR;

  /* Apertura del fichero */
  if ((file = fopen(filename, "r")) == NULL) return ERROR;

  /* Lectura del fichero */
  while (fgets(line, WORD_SIZE, file)){
    if (strncmp("#o:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, space);
#endif
      object = object_create(id);
      if (object != NULL){
        object_set_name(object, name);
        space_add_object(game_get_space(game, space), id);
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

