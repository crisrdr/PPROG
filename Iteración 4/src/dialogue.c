/**
* @brief It implements the Dialogue module
 *
 * @file dialogue.c
 * @author Sofía Garcia
 * @version 1.0
 * @date 07-05-2022
 * @copyright GNU Public License
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dialogue.h"
#include "command.h"

/**
 * @brief Data structure for the Dialogue module
 */

struct _Dialogue {
  char message[MSG_MAX];          /*!< Message to be displayed */
  DIALOGUE_TYPE dialogue_type;        /*!< Type of dialogue enum */
  DIALOGUE_CMD last_errored_command;  /*!< Last errored command */
  int accumulated_errors;             /*!< Number of accumulated errors */
};

Dialogue *dialogue_create() {
  Dialogue *dialogue = malloc(sizeof(Dialogue));
  if (!dialogue) return NULL;

  dialogue->accumulated_errors = 0;
  dialogue->message[0] = '\0';
  dialogue->dialogue_type = NO_DIALOGUE;

  return dialogue;
}

STATUS dialogue_set_success_msg(Dialogue *dialogue, const char *msg, ...) {
  va_list args;
  char full_message[MSG_MAX];

  if (!dialogue || !msg) return ERROR;

  /* Create the message with the format string and args */
  va_start(args, msg);
  vsprintf(full_message, msg, args);
  va_end(args);

  /* Set the message and the type */
  dialogue->dialogue_type = SUCCESS_MSG;
  strcpy(dialogue->message, full_message);
  dialogue->accumulated_errors = 0;
  dialogue->last_errored_command = D_NO_COMMAND;

  return OK;
}

STATUS dialogue_set_error_msg(Dialogue *dialogue, DIALOGUE_CMD dialogue_cmd, const char *msg, ...) {
  va_list args;
  char full_message[MSG_MAX];

  if (!dialogue || !msg) return ERROR;

  if (dialogue->accumulated_errors >= 1 && dialogue->last_errored_command == dialogue_cmd) {
    /* If there are accumulated errors show this error message */
    dialogue->dialogue_type = ERROR_MSG;
    dialogue->accumulated_errors++;
    strcpy(dialogue->message, dialogue->accumulated_errors == 5 ? "I can do this all day": "You have done this before without success.");
    return OK;
  }

  /* Create the message with the format string and args */
  va_start(args, msg);
  vsprintf(full_message, msg, args);
  va_end(args);

  /* Set the message and the type */
  dialogue->dialogue_type = ERROR_MSG;
  strcpy(dialogue->message, full_message);
  dialogue->accumulated_errors++;
  dialogue->last_errored_command = dialogue_cmd;

  return OK;
}

char *dialogue_get_message(Dialogue *dialogue) {
  if (!dialogue) return NULL;
  return dialogue->message;
}

DIALOGUE_TYPE dialogue_get_type(Dialogue *dialogue) {
  if (!dialogue) return NO_DIALOGUE;
  return dialogue->dialogue_type;
}

void dialogue_destroy(Dialogue *dialogue) {
  if (!dialogue) return;
  free(dialogue);
}
