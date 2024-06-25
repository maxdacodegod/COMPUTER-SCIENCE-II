#ifndef HEAP_H
#define HEAP_H

struct node;
typedef struct node Node;

void heap_insert(Node* pHeap, int* pSize, int priority, int value);

void fix_up(Node* pHeap, int index);

void remove_max(Node* pHeap, int* pSize);

void fix_down(Node* pHeap, int* size, int index);

#endif