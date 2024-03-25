#ifndef STACK_H
#define STACK_H
#include "status.h"

typedef void* STACK;//Pointer without context

STACK stack_init_default(void);

//Push
Status stack_push(STACK hStack, int value);

//Pop
Status stack_pop(STACK hStack);

//Top
int stack_top(STACK hStack, Status* pStatus);
				//Status stack_top(STACK hStack, int* pTop);// We will not use this way

//Empty
Boolean stack_is_empty(STACK hStack);

void stack_destroy(STACK* phStack);

#endif