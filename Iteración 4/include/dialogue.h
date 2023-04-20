/**
 * @brief It defines de Dialogue interface
 *
 * @file dialogue.h
 * @author Sofia Garcia
 * @date 07-05-2022
 * @copyright GNU Public License
*/

#ifndef DIALOGUE_H
#define DIALOGUE_H

#include "types.h"
#include "command.h"

/**
 * @brief Maximum string length of a dialogue message
 */
#define MSG_MAX 256

/**
 * @brief Dialogue message type enumeration
 */
typedef enum {
  NO_DIALOGUE, /*!< No dialogue */
  SUCCESS_MSG, /*!< Success message */
  ERROR_MSG    /*!< Error message */
} DIALOGUE_TYPE;

/**
 * @brief Dialogue last command type enumeration
 */
typedef enum {
  D_NO_COMMAND,     /*!< No command */
  D_MOVE_NORTH,     /*!< Move north */
  D_MOVE_EAST,      /*!< Move east */
  D_MOVE_SOUTH,     /*!< Move south */
  D_MOVE_WEST,      /*!< Move west */
  D_MOVE_UP,        /*!< Move up */
  D_MOVE_DOWN,      /*!< Move down */
  D_TAKE_OBJECT,    /*!< Take object */
  D_DROP_OBJECT,    /*!< Drop object */
  D_ATTACK_ENEMY,   /*!< Attack enemy */
  D_INSPECT_SPACE,  /*!< Inspect space */
  D_INSPECT_OBJECT, /*!< Inspect object */
  D_SAVE_GAME,      /*!< Save game */
  D_LOAD_GAME,      /*!< Load game */
  D_TURNON_OBJECT,  /*!< Turnon object */
  D_TURNOFF_OBJECT, /*!< Turnoff object */
  D_OPEN            /*!< Open with */
} DIALOGUE_CMD;

/**
 * @brief Dialogue data structure
 */
typedef struct _Dialogue Dialogue;

/**
 * @brief Creates a new dialogue
 * @author Sofia Garcia
 *
 * @return pointer to the new dialogue, or NULL in case of error
 */
Dialogue *dialogue_create();

/**
 * @brief Set the success message of a dialogue box
 * @author Sofia Garcia
 *
 * @param dialogue pointer to the Dialogue
 * @param msg message to be set
 * @param ... additional formatting args for the message string
 * @return OK if the message was set, ERROR otherwise
 */
STATUS dialogue_set_success_msg(Dialogue *dialogue, const char *msg, ...);

/**
 * @brief Set the error message of a dialogue box
 * @author Sofia Garcia
 *
 * @param dialogue pointer to the Dialogue
 * @param dialogue_cmd enum value of the command that generated the error
 * @param msg message to be set
 * @param ... additional formatting args for the message string
 * @return OK if the message was set, ERROR otherwise
 */
STATUS dialogue_set_error_msg(Dialogue *dialogue, DIALOGUE_CMD dialogue_cmd, const char *msg, ...);

/**
 * @brief Gets the message of a dialogue box
 * @author Sofia Garcia
 *
 * @param dialogue pointer to the Dialogue
 * @return pointer to the message string
 */
char *dialogue_get_message(Dialogue *dialogue);

/**
 * @brief Gets the type of a dialogue box
 * @author Sofia Garcia
 *
 * @param dialogue pointer to the Dialogue
 * @return the type of the dialogue (enum)
 */
DIALOGUE_TYPE dialogue_get_type(Dialogue *dialogue);

/**
 * @brief Destroys a dialogue
 * @author Sofia Garcia
 *
 * @param dialogue pointer to the Dialogue
 */
void dialogue_destroy(Dialogue *dialogue);


#endif /* DIALOGUE_H */
