/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1

/* Tipo Id */
typedef long Id;

/* Enumeracion del tipo booleano */
typedef enum
{
  FALSE,
  TRUE
} BOOL;

/* Enumeración del tipo estado */
typedef enum
{
  ERROR,
  OK
} STATUS;

/* Enumeración del tipo dirección */
typedef enum {
  NO_DIR = -1,
  N,
  S,
  E,
  W
} DIRECTION;

/* Enumeración del tipo puerta */
typedef enum
{
  CLOSE,
  OPEN,
  UNDEFINED
} LINK_ST;

#endif
