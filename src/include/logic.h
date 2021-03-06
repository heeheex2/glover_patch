#ifndef __LOGIC_H__
#define __LOGIC_H__

#include "memory.h"
#include "utility.h"
#include "savefile.h"

/**
 * Contains functions that manipulate the global state of the game
 * and update components of the romhack that do not require rendering.
 *
 * Also contains a global gpatch object that keeps track of global state
 */

// max slots should have all bits set for &ing
#define MAX_RESTORE_SLOTS 3

typedef struct gpatch_t {
    BOOLEAN infinite_hp;
    BOOLEAN infinite_lives;
    BOOLEAN lock_pos;
    BOOLEAN infinite_jump;
    u32 frame_advance;
    u8 menu_toggle; // TODO this is a hack to prevent a crash
    BOOLEAN cutscene_skip;
    BOOLEAN lockrng;
	BOOLEAN disable_pause;
    BOOLEAN resume_restore; // was map loaded? resume restore of actors now
    u8 resume_timer; // run up until 60 to delay
    u16 restore_slot;
} gpatch_t;

extern gpatch_t gpatch;

void logic();

void enable_timer();
void level_select();

void frame_advance();

void complete_file(save_file *);

void store_glover_pos();
void restore_glover_pos();

/**
 * Clones a pointer, adds size and original location to dest
 * size must be divisible by 4
 * returns new dest ptr
 */
WORD_T* clone_additional(WORD_T *, WORD_T *, WORD_T);

// finds all actors
// in the heap starting at glover
// all actors loop on each other and are stored in a linked list
// and memcpys them using the following format:
// actor backup format:
// 	4 bytes for original start address
//	4 bytes of actor size
// 	ACTOR_SIZE of data
//	List ends with a word of $00
//	at the end of the list the following helper values
//	are stored:
//		RNG - WORD
//		Camera Values - CAMERA_ACTOR_SIZE
// uses A1 as the pointer to the next free backup heap location
// each actor is ACTOR_SIZE bytes
// the backup heap is locates at the start of exp pack memory
void clone_actors(WORD_T *, u16 slot);
// same as clone_actors but just dumps everything in obj_bank
void clone_obj_bank();

// reverses actor backup
// uses A0 as actor heap pointer
void restore_actors(WORD_T *, u16 slot);

void toggle_collision();
void toggle_fog();

void toggle_show_objects();

/**
 * forward definition of menu
 */
typedef struct menudef menudef;
void trigger_al(menudef *);

#endif
