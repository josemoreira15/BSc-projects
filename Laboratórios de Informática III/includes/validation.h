#ifndef VALIDATION_H
#define VALIDATION_H

#include "util.h"

int verify_date (char* date);
int verify_car_class (char* car_class);
int verify_account_status(char* account_status);
int verify_distance (char* distance);
int verify_score_user_driver_tip (char* value, char* type);
int verify_driver_fields (char* id, char* name, char* gender, char* license_plate, char* city);
int verify_user_fields (char* username, char* name, char* gender, char* pay_method);
int verify_ride_fields (char* id, char* driver, char* user, char* city);

#endif
