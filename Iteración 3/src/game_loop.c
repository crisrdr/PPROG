/**
 * @brief It implements the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 30-11-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "graphic_engine.h"
#include "game.h"
#include "command.h"

/**
 * @brief Initializates the game and the graphic engine.
 * @author Profesores PPROG
 *
 * @param game double pointer to the game data
 * @param gengine double pointer to the graphic engine
 * @param file_name name of the file that stores the game data
 * @return Returns 1 if an error ocurred or 0 if it initializates correctly.
 */
int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name);
/**
 * @brief It runs the game loop.
 * @author Sofia Garcia
 *
 * @param game pointer to the game data
 * @param gengine pointer to the graphic engine
 * @param log_file pointer to the log file or NULL if logging is not required
 */
void game_loop_run(Game *game, Graphic_engine *gengine, FILE *log_file);
/**
 * @brief Destroys the game and the graphic engine.
 * @author Sofia Garcia
 *
 * @param game pointer to the game data
 * @param gengine pointer to the graphic engine
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

int main(int argc, char *argv[])
{
  Game *game;
  Graphic_engine *gengine;
  FILE *log_file = NULL;

  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  if (argc > 3 && strcmp(argv[2], "-l") == 0)
  {
    log_file = fopen(argv[3], "w");
    if (!log_file)
    {
      fprintf(stderr, "Error opening log file\n");
      return 1;
    }
  }

  srand(time(NULL));

  if (!game_loop_init(&game, &gengine, argv[1]))
  {
    game_loop_run(game, gengine, log_file);
    game_loop_cleanup(game, gengine);
  }

  if (log_file)
    fclose(log_file);

  return 0;
}

int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name)
{
  if ((*game = game_create_from_file(file_name)) == NULL)
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL)
  {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(*game);
    return 1;
  }

  return 0;
}

void game_loop_run(Game *game, Graphic_engine *gengine, FILE *log_file)
{
  Command *cmd = NULL;
  char *cmd_name;
  char *cmd_arg;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  while ((command_get_type(cmd) != EXIT) && !game_is_over(game))
  {
    graphic_engine_paint_game(gengine, game);
    cmd = command_get_user_input();
    game_update(game, cmd);

    cmd_name = cmd_to_str[command_get_type(cmd) - NO_CMD][CMDL];
    cmd_arg = command_get_arg(cmd);

    if (log_file)
    {
      if (strlen(cmd_arg) > 0)
      {
        fprintf(log_file, "%s %s: %s\n", cmd_name, cmd_arg, command_get_status(cmd) == OK ? "OK" : "ERROR");
      }
      else
      {
        fprintf(log_file, "%s: %s\n", cmd_name, command_get_status(cmd) == OK ? "OK" : "ERROR");
      }
    }
  }
}
void game_loop_cleanup(Game *game, Graphic_engine *gengine)
{
  game_destroy(game);
  graphic_engine_destroy(gengine);
}
