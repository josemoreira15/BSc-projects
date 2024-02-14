#ifndef DRIVER_H
#define DRIVER_H

#include "validation.h"

typedef struct driver *DRIVER;

DRIVER create_driver (char* info);
void destroy_driver (DRIVER driver);

char* get_driver_id(DRIVER driver);
char* get_driver_name(DRIVER driver);
char* get_birthday(DRIVER driver);
char* get_driver_gender(DRIVER driver);
char* get_car_class(DRIVER driver);
char* get_license_plate(DRIVER driver);
char* get_driver_city(DRIVER driver);
char* get_driver_account_creation(DRIVER driver);
char* get_driver_account_status(DRIVER driver);

int driver_valid(DRIVER driver);

#endif


