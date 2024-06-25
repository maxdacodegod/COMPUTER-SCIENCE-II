#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void); //Intialize

Status queue_insert(QUEUE hQ, int value); //Insert one, End of the line

Status queue_service(QUEUE hQ); // Removes one

int queue_front(QUEUE hQ, Status* pStatus); // Whats in the front?

Boolean queue_is_empty(QUEUE hQ); // True/False is it empty?

void queue_destroy(QUEUE* phQ); //Destroy

#endif