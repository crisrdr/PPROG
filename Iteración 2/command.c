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
                            {"n", "Next"},
                            {"b", "Back"},
                            {"r", "Right"},
                            {"l", "Left"},
                            {"t", "Take"},
                            {"d", "Drop"},
                            {"a", "Attack"}};

struct _Command {
  char arg[ARG_LEN];        /* Argumentos */
  T_Command type;           /* Uso del comando */
  STATUS st;                /* Retorno del comando */
};

/**
 * command_create allocates memory for a new command
 *  and initializes its members 
 */
Command *command_create(){
  Command *cmd = NULL;

  cmd = (Command*) malloc (sizeof(Command));

  if (!cmd) return NULL;

  cmd->arg[0] = '\0';
  cmd->type = NO_CMD;
  cmd->st = ERROR;

  return cmd;
}

/** command_destroy frees the previous memory allocation 
  *  for a command
  */
STATUS command_destroy(Command *cmd){
  if (!cmd) return ERROR;

  free(cmd);
  cmd = NULL;

  return OK;
}

/** It sets the argument of a command
 */
STATUS command_set_arg(Command *cmd, const char *arg){
  if (!cmd || !arg) return ERROR;

  strcpy(cmd->arg, arg);

  return OK;
}

/** It gets the argument of a command
 */
 char *command_get_arg(Command *cmd){
  if (!cmd) return NULL;

  return cmd->arg;
}

/** It sets the type of a command
 */
STATUS command_set_type(Command *cmd, T_Command type){
  if (!cmd) return ERROR;

  cmd->type = type;

  return OK;
}

/** It gets the type of a command
 */
T_Command command_get_type(Command *cmd){
  if (!cmd) return NO_CMD;

  return cmd->type;
}

/** It sets the status of a command
 */
STATUS command_set_status(Command *cmd, STATUS st){
  if (!cmd) return ERROR;

  cmd->st = st;

  return OK;
}

/** It gets the status of a command
 */
STATUS command_get_status(Command *cmd){
  if (!cmd) return ERROR;

  return cmd->st;
}

/** command_get_user_input devuelve un comando de tipo Command
 *  de acuerdo con la entrada proporcionada por el usuario
 */
Command *command_get_user_input() {
  Command *cmd = NULL;
  char input[WORD_SIZE] = "";
  char cmd_type[WORD_SIZE] = "";
  char arg[ARG_LEN] = "";
  int i = UNKNOWN - NO_CMD + 1;

  cmd = command_create();
  if (!cmd) return NULL;

  /* Escanea el comando introducido por el usuario*/
  fgets(input, CMD_LENGHT, stdin);
  sscanf(input, "%s %s", cmd_type, arg);

  cmd->type = UNKNOWN;

  /* Comprueba si conincide con algún comando */
  while (cmd->type == UNKNOWN && i < N_CMD){
    if (!strcasecmp(cmd_type, cmd_to_str[i][CMDS]) || !strcasecmp(cmd_type, cmd_to_str[i][CMDL])){
      cmd->type = i + NO_CMD;
      strcpy(cmd->arg, arg);
    } else{
      i++;
    }
  }

  return cmd;
}