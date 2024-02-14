#ifndef QUERIES_AUX_H
#define QUERIES_AUX_H

#include "param_queries.h"

typedef struct all_rides *ALL_RIDES;

ALL_RIDES create_all_rides();
void destroy_all_rides(ALL_RIDES all_rides);
void add_all_rides_ride(ALL_RIDES all_rides, int ride_id);
void print_all_rides_gender(STATS stats, PARAM param, DRIVERS drivers, RIDES rides, char* file);
void print_all_rides(STATS stats, PARAM param, RIDES rides, char* file);

typedef struct result *RESULT;

RESULT create_result(int index, int age, double av, int nr, double money, char* type);
void destroy_result(RESULT result);
void print_result(RESULT result, char* file, USERS users, DRIVERS drivers, int flag);

int is_user_active(USERS users, int index);
int is_driver_active(DRIVERS drivers, int index);
double total_distance(STATS stats, void* rides_ids, RIDES rides);
double tariff(char* car_class, int distance);
char* last_ride_date(STATS stats, void* rides_ids, RIDES rides);
double media_av(STATS stats, void* rides_ids, RIDES rides);
double media_av_city(STATS stats, void* rides_ids, RIDES rides, char* city);

RESULT query1_aux(STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line);
PARAM query2_aux(STATS stats, DRIVERS drivers, RIDES rides, char* line);
PARAM query3_aux(STATS stats, USERS users, RIDES rides, char* line);
double query4_aux(STATS stats, CITY_STATS city_stats, RIDES rides, DRIVERS drivers, char* line);
double query5_aux(STATS stats, RIDES rides, DRIVERS drivers, char* line);
double query6_aux(CITY_STATS city_stats, RIDES rides, char* line);
PARAM query7_aux(STATS stats, DRIVERS drivers, RIDES rides, char* line);
PARAM query8_aux (STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line);
PARAM query9_aux (RIDES rides, char* line);

#endif
