/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 30

/**
 * @brief cmd_to_str
 *
 * puntero de tipo char y dos dimensiones, interpreta el
 * char que se recibe con el nombre de un comando
 *
 */
char *cmd_to_str[N_CMD]
                [N_CMDT] = {{"", "No command"},
                            {"", "Unknown"},
                            {"e", "Exit"},
                            {"n", "Next"},
                            {"b", "Back"},
                            {"t", "Take"},
                            {"d", "Drop"}};

/** command_get_user_input devuelve un comando de tipo T_Command
 *  de acuerdo con la entrada proporcionada por el usuario
 */
T_Command command_get_user_input()
{
  T_Command cmd = NO_CMD;
  char input[CMD_LENGHT] = "";
  int i = UNKNOWN - NO_CMD + 1;

  if (scanf("%s", input) > 0)
  {
    cmd = UNKNOWN;
    while (cmd == UNKNOWN && i < N_CMD)
    {
      if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL]))
      {
        cmd = i + NO_CMD;
      }
      else
      {
        i++;
      }
    }
  }

  return cmd;
}
