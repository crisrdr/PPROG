/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG, Cristina Rodriguez de los Ríos Medina y Sofia Garcia Heras
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "command.h"
#include "types.h"
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
                            {"t", "Take"},
                            {"d", "Drop"},
                            {"a", "Attack"},
                            {"m", "Move"},
                            {"i", "Inspect"},
                            {"tn", "Turnon"},
                            {"tf", "Turnoff"},
                            {"o", "Open"},
                            {"s", "Save"},
                            {"l", "Load"}};

struct _Command
{
  char *arg[ARG_LEN]; /* Argumentos */
  T_Command type;     /* Uso del comando */
  STATUS st;          /* Retorno del comando */
};

/**
 * command_create allocates memory for a new command
 *  and initializes its members
 */
Command *command_create()
{
  Command *cmd = NULL;
  int i = 0;

  cmd = (Command *) malloc(sizeof(Command));
  if (cmd == NULL)
    return NULL;

  cmd->type = NO_CMD;
  cmd->st = ERROR;

  for (i = 0; i < MAX_ARG; i++) {
    cmd->arg[i] = (char *) malloc(ARG_LEN * sizeof(char));
    if (cmd->arg[i] == NULL)
      return NULL;
    strcpy(cmd->arg[i], "");
  }

  return cmd;
}

/** command_destroy frees the previous memory allocation
 *  for a command
 */
STATUS command_destroy(Command *cmd)
{
  if (!cmd)
    return ERROR;

  free(cmd);

  return OK;
}

/** It sets the argument of a command
 */
STATUS command_set_arg(Command *cmd, const char *arg, int argn)
{
  if (cmd == NULL || arg == NULL)
    return ERROR;

  strcpy(cmd->arg[argn], arg);

  return OK;
}

/** It gets the argument of a command
 */
char *command_get_arg(Command *cmd, int argn)
{
  if (cmd == NULL)
    return NULL;

  return cmd->arg[argn];
}

/** It sets the type of a command
 */
STATUS command_set_type(Command *cmd, T_Command type)
{
  if (!cmd || type == NO_CMD)
    return ERROR;

  cmd->type = type;

  return OK;
}

/** It gets the type of a command
 */
T_Command command_get_type(Command *cmd)
{
  if (!cmd)
    return NO_CMD;

  return cmd->type;
}

/** It sets the status of a command
 */
STATUS command_set_status(Command *cmd, STATUS st)
{
  if (!cmd)
    return ERROR;

  cmd->st = st;

  return OK;
}

/** It gets the status of a command
 */
STATUS command_get_status(Command *cmd)
{
  if (!cmd)
    return ERROR;

  return cmd->st;
}

/** command_get_user_input devuelve un comando de tipo Command
 *  de acuerdo con la entrada proporcionada por el usuario
 */
Command *command_get_user_input()
{
  Command *cmd = NULL;
  char input[WORD_SIZE] = "";
  char cmd_type[WORD_SIZE] = "";
  int i = UNKNOWN - NO_CMD + 1;

  cmd = command_create();
  if (!cmd)
    return NULL;

  /* Escanea el comando introducido por el usuario*/
  fgets(input, CMD_LENGHT, stdin);
  sscanf(input, "%s", cmd_type);

  cmd->type = UNKNOWN;

  /* Comprueba si conincide con algún comando */
  while (cmd->type == UNKNOWN && i < N_CMD)
  {
    /* It checks if it matches with any cmd */
    if (!strcasecmp(cmd_type, cmd_to_str[i][CMDS]) || !strcasecmp(cmd_type, cmd_to_str[i][CMDL]))
    {
      /* Compares the input with the strings stored in the cmd_to_str matrix */
      cmd->type = i + NO_CMD;
      if (cmd->type == TAKE || cmd->type == DROP || cmd->type == MOVE || cmd->type == INSPECT || cmd->type == TURNON || cmd->type == TURNOFF || cmd->type == SAVE || cmd->type == LOAD)
      {
        sscanf(input, "%s %s", cmd_type, cmd->arg[0]);
      }
      else if (cmd->type == OPEN)
      {
        sscanf(input, "%s %s %s %s", cmd_type, cmd->arg[0], cmd->arg[1], cmd->arg[2]);
      }
    }
    else
    {
      i++;
    }
  }

  return cmd;
}