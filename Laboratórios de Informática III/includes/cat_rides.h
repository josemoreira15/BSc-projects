#ifndef CAT_RIDES_H
#define CAT_RIDES_H

#include "ride.h"
#include "stats.h"
#include "city_stats.h"

typedef struct cat_rides *RIDES;

RIDES create_rides();
void add_ride (RIDE ride, RIDES rides);
void destroy_rides (RIDES rides);

int get_length_rides (RIDES rides);

char* get_rides_ride_id (RIDES rides, int i);
char* get_rides_date (RIDES rides, int i);
char* get_rides_ride_driver_id (RIDES rides, int i);
char* get_rides_user (RIDES rides, int i);
char* get_rides_city (RIDES rides, int i);
int get_rides_distance (RIDES rides, int i);
double get_rides_score_user (RIDES rides, int i);
double get_rides_score_driver (RIDES rides, int i);
double get_rides_tip (RIDES rides, int i);
char* get_rides_comment (RIDES rides, int i);

RIDES read_rides(char* path, STATS stats, CITY_STATS city_stats);

#endif
