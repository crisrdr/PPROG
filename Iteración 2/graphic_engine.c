/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"

#define ROWS 35
#define COLUMNS 80

struct _Graphic_engine
{
  Area *map, *descript, *banner, *help, *feedback;
};
/** Inicializa la graphic engine y las áreas de la pantalla
 */
Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 1, 48, 25);
  ge->descript = screen_area_init(50, 1, 29, 25);
  ge->banner = screen_area_init(29, 27, 22, 1);
  ge->help = screen_area_init(1, 28, 78, 3);
  ge->feedback = screen_area_init(1, 32, 78, 2);

  return ge;
}

/** Destruye toda la graphic engine y libera la memoria
 */
void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

/** Representa la pantalla, los espacios y las áreas de la graphic engine
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID;
  Id id_back = NO_ID;
  Id id_next = NO_ID;
  Id id_right = NO_ID;
  Id id_left = NO_ID;
  Space *space_act = NULL;
  
  char str[255];
  Command *last_cmd = NULL;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  int i = 0;
  char **gdesc = NULL;
  char enemy[7] = "";

  char obj0[4] = " ";
  char obj1[4] = " ";
  char obj2[4] = " ";
  char obj3[4] = " ";
  char objA[4] = " ";

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    id_right = space_get_east(space_act);
    id_left = space_get_west(space_act);

    gdesc = space_get_gdesc(game_get_space(game, id_back));

    strcpy(obj0, " ");
    strcpy(obj1, " ");
    strcpy(obj2, " ");
    strcpy(obj3, " ");

    for (i = 0; i < MAX_OBJECTS; i++)
    {
      if (space_has_object(game_get_space(game, id_back), game_get_object_id_at(game, i)))
      {
        if (!strcmp(obj0, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj0, objA);
        }
        else if (!strcmp(obj1, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj1, objA);
        }
        else if (!strcmp(obj2, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj2, objA);
        }
        else if (!strcmp(obj3, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj3, objA);
        }
      }
    }

    if (id_back != NO_ID)
    {
      sprintf(str, "                |%-9s      |", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[4]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-3s %-3s %-3s %-3s|", obj0, obj1, obj2, obj3);
      screen_area_puts(ge->map, str);
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                        ^");
      screen_area_puts(ge->map, str);
    }
    else
    {
      sprintf(str, " ");
      screen_area_puts(ge->map, str);
      screen_area_puts(ge->map, str);
      screen_area_puts(ge->map, str);
      screen_area_puts(ge->map, str);
      screen_area_puts(ge->map, str);
      screen_area_puts(ge->map, str);
      screen_area_puts(ge->map, str);
    }

    gdesc = space_get_gdesc(space_act);

    if (id_act == game_get_enemy_location(game) && game_get_enemy_health(game) > 0)
      strcpy(enemy, "/\\OO/\\");
    else if (id_act == game_get_enemy_location(game))
      strcpy(enemy, "_/oo\\_");
    else
      strcpy(enemy, " ");

    strcpy(obj0, " ");
    strcpy(obj1, " ");
    strcpy(obj2, " ");
    strcpy(obj3, " ");
    for (i = 0; i < MAX_OBJECTS; i++)
    {
      if (space_has_object(space_act, game_get_object_id_at(game, i)))
      {
        if (!strcmp(obj0, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj1, objA);
        }
        else if (!strcmp(obj1, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj2, objA);
        }
        else if (!strcmp(obj2, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj3, objA);
        }
        else if (!strcmp(obj3, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj3, objA);
        }
      }
    }

    if (id_act != NO_ID && id_right != NO_ID && id_left != NO_ID)
    {
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                | mO^ %-6s %3d|", enemy, (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "--------+       |%-9s      |       +-------", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "     %3d|       |%-9s      |       |%d", (int)id_left, gdesc[1], (int)id_right);
      screen_area_puts(ge->map, str);
      sprintf(str, "        |   <   |%-9s      |   >   |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "        |       |%-9s      |       |", gdesc[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "--------+       |%-9s      |       +-------", gdesc[4]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-3s %-3s %-3s %-3s|", obj0, obj1, obj2, obj3);
      screen_area_puts(ge->map, str);
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
    }
    else if (id_act != NO_ID && id_right != NO_ID)
    {
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                | mO^ %-6s %3d|", enemy, (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |       +-------", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |       |%d", gdesc[1], (int)id_right);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |   >   |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |       |", gdesc[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |       +-------", gdesc[4]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-3s %-3s %-3s %-3s|", obj0, obj1, obj2, obj3);
      screen_area_puts(ge->map, str);
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
    }
    else if (id_act != NO_ID && id_left != NO_ID)
    {
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                | mO^ %-6s %3d|", enemy, (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "--------+       |%-9s      |", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "     %3d|       |%-9s      |", (int)id_left, gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "        |   <   |%-9s      |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "        |       |%-9s      |", gdesc[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "--------+       |%-9s      |", gdesc[4]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-3s %-3s %-3s %-3s|", obj0, obj1, obj2, obj3);
      screen_area_puts(ge->map, str);
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
    }
    else if (id_act != NO_ID)
    {
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                | mO^ %-6s %3d|", enemy, (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[4]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-3s %-3s %-3s %-3s|", obj0, obj1, obj2, obj3);
      screen_area_puts(ge->map, str);
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
    }

    gdesc = space_get_gdesc(game_get_space(game, id_next));

    if (id_next == game_get_enemy_location(game) && game_get_enemy_health(game) > 0)
      strcpy(enemy, "/\\OO/\\");
    else if (id_next == game_get_enemy_location(game))
      strcpy(enemy, "_/oo\\_");
    else
      strcpy(enemy, " ");

    strcpy(obj0, " ");
    strcpy(obj1, " ");
    strcpy(obj2, " ");
    strcpy(obj3, " ");
    for (i = 0; i < MAX_OBJECTS; i++)
    {
      if (space_has_object(game_get_space(game, id_next), game_get_object_id_at(game, i)))
      {
        if (!strcmp(obj0, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj0, objA);
        }
        else if (!strcmp(obj1, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj1, objA);
        }
        else if (!strcmp(obj2, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj2, objA);
        }
        else if (!strcmp(obj3, " "))
        {
          sprintf(objA, "O%2.ld", game_get_object_id_at(game, i));
          strcpy(obj3, objA);
        }
      }
    }

        if (id_next != NO_ID)
    {
      sprintf(str, "                        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                |     %-6s %3d|", enemy, (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |", gdesc[4]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-3s %-3s %-3s %-3s|", obj0, obj1, obj2, obj3);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Objects location:");
  screen_area_puts(ge->descript, str);
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  for (i=0; game_get_object(game, game_get_object_id_at(game, i)) != NULL; i++)
  {
    if (player_get_object_id(game_get_player(game)) != game_get_object_id_at(game, i))
    {
      sprintf(str, "   - O%ld: %ld", game_get_object_id_at(game, i), game_get_object_location(game, game_get_object_id_at(game, i)));
      screen_area_puts(ge->descript, str);
    }
  }
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Player location: %ld", game_get_player_location(game));
  screen_area_puts(ge->descript, str);
  if (player_get_object_id(game_get_player(game)) != NO_ID)
  {
    sprintf(str, "  Player object: %ld", player_get_object_id(game_get_player(game)));
    screen_area_puts(ge->descript, str);
  }
  sprintf(str, "  Player health: %d", player_get_health(game_get_player(game)));
  screen_area_puts(ge->descript, str);
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Enemy location: %ld", game_get_enemy_location(game));
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Enemy health: %d", game_get_enemy_health(game));
  screen_area_puts(ge->descript, str);
  if (enemy_get_health(game_get_enemy(game)) == 0){
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "  The enemy has been killed!!");
    screen_area_puts(ge->descript, str);
  }

  /* Paint in the banner area */
  screen_area_puts(ge->banner, "    The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, r or right, l or left, take or t, drop or d, attack or a, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */

  last_cmd = game_get_last_command(game);
  if (command_get_status(last_cmd))
    sprintf(str, " %s (%s): OK", cmd_to_str[command_get_type(last_cmd) - NO_CMD][CMDL], cmd_to_str[command_get_type(last_cmd) - NO_CMD][CMDS]);
  else
    sprintf(str, " %s (%s): ERROR", cmd_to_str[command_get_type(last_cmd) - NO_CMD][CMDL], cmd_to_str[command_get_type(last_cmd) - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
