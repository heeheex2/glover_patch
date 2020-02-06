#ifndef __INPUTS_H__
#define __INPUTS_H__

#include "typedefs.h"

#define CONTROLLER_1 (WORD_T*)0xBFC007C4
#define CONTROLLER_2 (WORD_T*)0xBFC007CC

#define L_INPUT 0x15
#define CL_INPUT 0x11
#define CR_INPUT 0x10
#define CD_INPUT 0x12
#define CU_INPUT 0x13
#define A_INPUT 0xFF
#define B_INPUT 0x1E
#define START_INPUT 0x1C

#include "utility.h"

/**
 * Reads controller inputs
 * Returns:
 *  1 if input
 *  0 if no input
 */
BOOLEAN read_button(unsigned int, WORD_T *);

/**
 * Stores controller input in another location
 */
void store_inputs(WORD_T *, WORD_T *);

void clear_last_inputs(WORD_T*);

#endif