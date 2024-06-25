#include <stdio.h>
#include "priority_queue.h"
#include "heap.h"
#include "status.h"

int main(int argc, char* argv[])
{
    PRIORITY_QUEUE hQueue = priority_queue_init_default();

    //priority_queue_insert(OBJECT, KEY, VALUE);
    priority_queue_insert(hQueue, 10, 1);
    priority_queue_insert(hQueue, 9, 2);
    priority_queue_insert(hQueue, 8, 3);
    priority_queue_insert(hQueue, 7, 4);
    priority_queue_insert(hQueue, 6, 5);
    priority_queue_insert(hQueue, 5, 6);
    priority_queue_insert(hQueue, 4, 7);
    priority_queue_insert(hQueue, 3, 8);
    priority_queue_insert(hQueue, 2, 9);
    priority_queue_insert(hQueue, 1, 10);
    // Tests 1-10
    while (!priority_queue_is_empty(hQueue))
    {
        printf("%d\n", priority_queue_front(hQueue, NULL)); //Print
        priority_queue_service(hQueue); //Remove
    }
    priority_queue_destroy(hQueue); // Destroy Queue
    return 0;
}