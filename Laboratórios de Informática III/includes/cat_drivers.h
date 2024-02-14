#ifndef CAT_DRIVERS_H
#define CAT_DRIVERS_H

#include "driver.h"
#include "stats.h"

typedef struct cat_drivers *DRIVERS;

DRIVERS create_drivers();
void add_driver (DRIVER driver, DRIVERS drivers);
void destroy_drivers (DRIVERS drivers);

int get_length_drivers (DRIVERS drivers);

char* get_drivers_driver_id(DRIVERS drivers, int i);
char* get_drivers_driver_name(DRIVERS drivers, int i);
char* get_drivers_birthday(DRIVERS drivers, int i);
char* get_drivers_driver_gender(DRIVERS drivers, int i);
char* get_drivers_car_class(DRIVERS drivers, int i);
char* get_drivers_licence_plate(DRIVERS drivers, int i);
char* get_drivers_driver_city(DRIVERS drivers, int i);
char* get_drivers_account_creation(DRIVERS drivers, int i);
char* get_drivers_driver_account_status(DRIVERS drivers, int i);

DRIVERS read_drivers(char* path, STATS stats);

#endif
