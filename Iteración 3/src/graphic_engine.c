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
  Area *map;      /*!< Area where the map is printed */
  Area *descript; /*!< Area where the descriptions are printed */
  Area *banner;   /*!< Area where the banner is printed */
  Area *help;     /*!< Area where the help is printed */
  Area *feedback; /*!< Area where the feedback is printed */
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
  int i = 0;
  Id id_act = NO_ID;
  Id id_back = NO_ID;
  Id id_next = NO_ID;
  Id id_right = NO_ID;
  Id id_left = NO_ID;
  Space *space_act = NULL;
  char **gdesc = NULL;
  char **space_gdesc_right = NULL;
  char **space_gdesc_left = NULL;
  char enemy[CMD_LENGHT] = "";
  char link1_gdesc[CMD_LENGHT] = "";
  char link2_gdesc[CMD_LENGHT] = "";
  char str[WORD_SIZE];
  Command *last_cmd = NULL;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  char obj0[CMD_LENGHT] = " ";
  char obj1[CMD_LENGHT] = " ";
  char obj2[CMD_LENGHT] = " ";

  last_cmd = game_get_last_command(game);

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = game_get_connection(game, id_act, N);
    id_next = game_get_connection(game, id_act, S);
    id_right = game_get_connection(game, id_act, E);
    id_left = game_get_connection(game, id_act, W);

    gdesc = space_get_gdesc(game_get_space(game, id_back));
    if (id_back != NO_ID)
    {
      if (!game_get_dest_connection_status(game, id_act, id_back))
        strcpy(link1_gdesc, " ^ ");
      else
        strcpy(link1_gdesc, " x ");
    }
    else
    {
      strcpy(link1_gdesc, "   ");
    }

    strcpy(obj0, " ");
    strcpy(obj1, " ");
    strcpy(obj2, " ");

    for (i = 0; i < MAX_OBJECTS; i++)
    {
      if (space_has_object(game_get_space(game, id_back), game_get_object_id_at(game, i)))
      {
        if (!strcmp(obj0, " "))
        {
          strcpy(obj0, object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
        }
        else if (!strcmp(obj1, " "))
        {
          strcpy(obj1, object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
        }
        else if (!strcmp(obj2, " "))
        {
          strcpy(obj2, object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
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
      sprintf(str, "                |%5s %4s %4s|", obj0, obj1, obj2);
      screen_area_puts(ge->map, str);
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                       %-3s", link1_gdesc);
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
    space_gdesc_right = space_get_gdesc(game_get_space(game, id_right));
    space_gdesc_left = space_get_gdesc(game_get_space(game, id_left));

    if (id_left != NO_ID)
    {
      if (!game_get_connection_status(game, id_act, W))
        strcpy(link1_gdesc, " < ");
      else
        strcpy(link1_gdesc, " x ");
    }
    else
    {
      strcpy(link1_gdesc, "   ");
    }

    if (id_right != NO_ID)
    {
      if (!game_get_connection_status(game, id_act, E))
        strcpy(link2_gdesc, " > ");
      else
        strcpy(link2_gdesc, " x ");
    }
    else
    {
      strcpy(link2_gdesc, "   ");
    }

    if (id_act == game_get_enemy_location(game) && enemy_get_health(game_get_enemy(game)) > 0)
      strcpy(enemy, "/\\OO/\\");
    else if (id_act == game_get_enemy_location(game))
      strcpy(enemy, "_/oo\\_");
    else
      strcpy(enemy, " ");

    strcpy(obj0, " ");
    strcpy(obj1, " ");
    strcpy(obj2, " ");

    for (i = 0; i < MAX_OBJECTS; i++)
    {
      if (space_has_object(game_get_space(game, id_act), game_get_object_id_at(game, i)))
      {
        if (!strcmp(obj0, " "))
        {
          strcpy(obj0, object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
        }
        else if (!strcmp(obj1, " "))
        {
          strcpy(obj1, object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
        }
        else if (!strcmp(obj2, " "))
        {
          strcpy(obj2, object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
        }
      }
    }

    if (id_act != NO_ID && id_right != NO_ID && id_left != NO_ID)
    {
      sprintf(str, "------------+   +---------------+   +-----------");
      screen_area_puts(ge->map, str);
      sprintf(str, "        %3d |   | mO^ %-6s %3d|   | %3d       ", (int)id_left, enemy, (int)id_act, (int)id_right);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|   |%-9s      |   |%-9s  ", space_gdesc_left[0], gdesc[0], space_gdesc_right[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|   |%-9s      |   |%-9s  ", space_gdesc_left[1], gdesc[1], space_gdesc_right[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|%-3s|%-9s      |%-3s|%-9s  ", space_gdesc_left[2], link1_gdesc, gdesc[2], link2_gdesc, space_gdesc_right[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|   |%-9s      |   |%-9s  ", space_gdesc_left[3], gdesc[3], space_gdesc_right[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|   |%-9s      |   |%-9s  ", space_gdesc_left[4], gdesc[4], space_gdesc_right[4]);
      screen_area_puts(ge->map, str);
      sprintf(str, "            |   |%5s %4s %4s|   |           ", obj0, obj1, obj2);
      screen_area_puts(ge->map, str);
      sprintf(str, "------------+   +---------------+   +-----------");
      screen_area_puts(ge->map, str);
    }
    else if (id_act != NO_ID && id_right != NO_ID)
    {
      sprintf(str, "                +---------------+   +-----------");
      screen_area_puts(ge->map, str);
      sprintf(str, "                | mO^ %-6s %3d|   | %3d       ", enemy, (int)id_act, (int)id_right);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |   |%-9s  ", gdesc[0], space_gdesc_right[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |   |%-9s  ", gdesc[1], space_gdesc_right[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |%-3s|%-9s  ", gdesc[2], link2_gdesc, space_gdesc_right[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |   |%-9s  ", gdesc[3], space_gdesc_right[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%-9s      |   |%-9s  ", gdesc[4], space_gdesc_right[4]);
      screen_area_puts(ge->map, str);
      sprintf(str, "                |%5s %4s %4s|   |           ", obj0, obj1, obj2);
      screen_area_puts(ge->map, str);
      sprintf(str, "                +---------------+   +-----------");
      screen_area_puts(ge->map, str);
    }
    else if (id_act != NO_ID && id_left != NO_ID)
    {
      sprintf(str, "------------+   +---------------+               ");
      screen_area_puts(ge->map, str);
      sprintf(str, "        %3d |   | mO^ %-6s %3d|               ", (int)id_left, enemy, (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|   |%-9s      |               ", space_gdesc_left[0], gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|   |%-9s      |               ", space_gdesc_left[1], gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|%-3s|%-9s      |               ", space_gdesc_left[2], link1_gdesc, gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|   |%-9s      |               ", space_gdesc_left[3], gdesc[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "   %-9s|   |%-9s      |               ", space_gdesc_left[4], gdesc[4]);
      screen_area_puts(ge->map, str);
      sprintf(str, "            |   |%5s %4s %4s|               ", obj0, obj1, obj2);
      screen_area_puts(ge->map, str);
      sprintf(str, "------------+   +---------------+               ");
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
      sprintf(str, "                |%5s %4s %4s|", obj0, obj1, obj2);
      screen_area_puts(ge->map, str);
      sprintf(str, "                +---------------+");
      screen_area_puts(ge->map, str);
    }

    gdesc = space_get_gdesc(game_get_space(game, id_next));

    if (id_next != NO_ID)
    {
      if (!game_get_dest_connection_status(game, id_act, id_next))
        strcpy(link1_gdesc, " v ");
      else
        strcpy(link1_gdesc, " x ");
    }
    else
    {
      strcpy(link1_gdesc, "   ");
    }

    strcpy(obj0, " ");
    strcpy(obj1, " ");
    strcpy(obj2, " ");

    for (i = 0; i < MAX_OBJECTS; i++)
    {
      if (space_has_object(game_get_space(game, id_next), game_get_object_id_at(game, i)))
      {
        if (!strcmp(obj0, " "))
        {
          strcpy(obj0, object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
        }
        else if (!strcmp(obj1, " "))
        {
          strcpy(obj1, object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
        }
        else if (!strcmp(obj2, " "))
        {
          strcpy(obj2, object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
        }
      }
    }

    if (id_next != NO_ID)
    {
      sprintf(str, "                       %-3s", link1_gdesc);
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
      sprintf(str, "                |%5s %4s %4s|", obj0, obj1, obj2);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Objects location:");
  screen_area_puts(ge->descript, str);

  for (i = 0; i < MAX_OBJECTS && game_get_object(game, game_get_object_id_at(game, i)) != NULL; i++)
  {
    if (!player_has_object(game_get_player(game), game_get_object_id_at(game, i)))
    {
      sprintf(str, "   - %s: %ld", object_get_name(game_get_object(game, game_get_object_id_at(game, i))), game_get_object_location(game, game_get_object_id_at(game, i)));
      screen_area_puts(ge->descript, str);
    }
  }
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Player location: %ld", game_get_player_location(game));
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Player health: %d", player_get_health(game_get_player(game)));
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Player inventory: ");
  screen_area_puts(ge->descript, str);
  for (i = 0; i < MAX_OBJECTS && game_get_object(game, game_get_object_id_at(game, i)) != NULL; i++)
  {
    if (player_has_object(game_get_player(game), game_get_object_id_at(game, i)))
    {
      sprintf(str, "   - %s", object_get_name(game_get_object(game, game_get_object_id_at(game, i))));
      screen_area_puts(ge->descript, str);
    }
  }
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Enemy location: %ld", game_get_enemy_location(game));
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Enemy health: %d", enemy_get_health(game_get_enemy(game)));
  screen_area_puts(ge->descript, str);
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  if (command_get_type(last_cmd) == INSPECT && command_get_status(last_cmd) == OK)
  {
    if (!strcasecmp("s", command_get_arg(last_cmd)) || !strcasecmp("space", command_get_arg(last_cmd)))
    {
      sprintf(str, "  Description (%s): ", space_get_name(space_act));
      screen_area_puts(ge->descript, str);
      sprintf(str, "   %-18s", space_get_descr(space_act));
      screen_area_puts(ge->descript, str);
    }
    else
    {
      sprintf(str, "  Description (%s): ", object_get_name(game_get_object_by_name(game, command_get_arg(last_cmd))));
      screen_area_puts(ge->descript, str);
      sprintf(str, "   %-18s", object_get_descr(game_get_object_by_name(game, command_get_arg(last_cmd))));
      screen_area_puts(ge->descript, str);
    }
  }

  /* Paint in the banner area */
  screen_area_puts(ge->banner, "    The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "  next or n, back or b, r or right, l or left, take or t, drop or d, attack");
  screen_area_puts(ge->help, str);
  sprintf(str, "  or a, move m, inspect i or exit e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */

  if (command_get_status(last_cmd))
    sprintf(str, " %s (%s): OK", cmd_to_str[command_get_type(last_cmd) - NO_CMD][CMDL],
            cmd_to_str[command_get_type(last_cmd) - NO_CMD][CMDS]);
  else
    sprintf(str, " %s (%s): ERROR", cmd_to_str[command_get_type(last_cmd) - NO_CMD][CMDL],
            cmd_to_str[command_get_type(last_cmd) - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}