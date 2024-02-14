#ifndef RIDE_H
#define RIDE_H

#include "validation.h"

typedef struct ride *RIDE;

RIDE create_ride (char* info);
void destroy_ride (RIDE ride);

char* get_ride_id (RIDE ride);
char* get_date (RIDE ride);
char* get_ride_driver_id (RIDE ride);
char* get_user (RIDE ride);
char* get_city (RIDE ride);
int get_distance (RIDE ride);
double get_score_user (RIDE ride);
double get_score_driver (RIDE ride);
double get_tip (RIDE ride);
char* get_comment (RIDE ride);

int ride_valid(RIDE ride);

#endif
