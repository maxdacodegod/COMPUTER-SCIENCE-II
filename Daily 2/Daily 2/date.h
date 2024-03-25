#ifndef DATE_H
#define DATE_H

typedef void* DATE; //Handle

DATE date_init_default(void);

void date_output(DATE hDate);

void date_destroy(DATE* phDate);


#endif