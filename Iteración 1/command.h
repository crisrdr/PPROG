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

#define N_CMDT 2
#define N_CMD 7

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
  TAKE,
  DROP} T_Command;
/**
 * @brief Interpreta la entrada del usuario para un comando especifico
 * 
 * @return T_Command 
 */
T_Command command_get_user_input();

#endif
