/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2
#define N_CMD 10

#define ARG_LEN 30
#define CMD_LENGHT 60

/**
 * @brief T_CmdType
 * 
 * Enumeration for short (CMDS) and long commands (CMDL)
 * 
 */
typedef enum enum_CmdType {
  CMDS,
  CMDL} T_CmdType;

/**
 * @brief T_Command
 * 
 * Enumeration of the existing commads
 * 
 */
typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  NEXT,
  BACK,
  RIGHT,
  LEFT,
  TAKE,
  DROP,
  ATTACK} T_Command;

typedef struct _Command Command;

/**
  * @brief It creates a new command, allocating memory and initializing its members
  * @author Cristina R and Sofía G
  * 
  * @return a new command, initialized
  */
Command *command_create();

/**
  * @brief It destroys a command, freeing the allocated memory
  * @author Cristina and Sofía G
  * 
  * @param cmd a pointer to the command that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS command_destroy(Command *cmd);

/**
  * @brief It sets the argument of a command
  * @author Cristina R and Sofía G
  * 
  * @param cmd pointer to the command
  * @param name a string with the argument
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS command_set_arg(Command *cmd, const char *arg);

/**
  * @brief It gets the argument of a command
  * @author Cristina R and Sofía G
  * 
  * @param cmd pointer to the command
  * @return a string with the argumment of the command
  */
 char *command_get_arg(Command *cmd);

/**
  * @brief It sets the type of a command
  * @author Cristina R and Sofía G
  * 
  * @param cmd pointer to the command
  * @param type to be setted at the command
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS command_set_type(Command *cmd, T_Command type);

/**
 * @brief It gets the type of the command
 * @author Cristina R and Sofía G
 * 
 * @param cmd pointer to the command
 * @return the type of the command
 */
T_Command command_get_type(Command *cmd);

/**
  * @brief It sets the status of a command
  * @author Cristina R and Sofía G
  * 
  * @param cmd pointer to the command
  * @param st status to be setted at the command
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS command_set_status(Command *cmd, STATUS st);

/**
  * @brief It gets the status of a command
  * @author Cristina R and Sofía G
  * 
  * @param cmd pointer to the command
  * @return the status of the command
  */
STATUS command_get_status(Command *cmd);

/**
 * @brief Interpreta la entrada del usuario para un comando especifico
 * 
 * @return T_Command 
 */
Command *command_get_user_input();

#endif
