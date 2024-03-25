#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include "status.h"

typedef void* MY_VECTOR;

MY_VECTOR my_vector_init_default(void);

// add values
// look at numbers
// find the biggest one
// put something in

int* my_vector_at(MY_VECTOR hVector, int index); //Address is garbage on resize

int my_vector_get_size(MY_VECTOR hVector);
int my_vector_get_capacity(MY_VECTOR hVector);

Status my_vector_push_back(MY_VECTOR hVector, int value);

Status my_vector_pop_back(MY_VECTOR hVector);

Boolean my_vector_is_empty(MY_VECTOR hVector);


// take something out
// Ask the container how many things its holding or how many it CAN hold.

void my_vector_destroy(MY_VECTOR* phVector);

#endif