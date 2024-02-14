#ifndef EXECUTION_H
#define EXECUTION_H

#include "queries.h"
#include "ui.h"

double query1_time (char* file, STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line);
double query2_time (char* file, STATS stats, DRIVERS drivers, RIDES rides, char* line);
double query3_time (char* file, STATS stats, USERS users, RIDES rides, char* line);
double query4_time (char* file, STATS stats, CITY_STATS city_stats, RIDES rides, DRIVERS drivers, char* line);
double query5_time (char* file, STATS stats, RIDES rides, DRIVERS drivers, char* line);
double query6_time (char* file, CITY_STATS city_stats, RIDES rides, char* line);
double query7_time (char* file, STATS stats, DRIVERS drivers, RIDES rides, char* line);
double query8_time (char* file, STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line);
double query9_time (char* file, STATS stats, RIDES rides, char* line);
double choose_execution(int query_id, STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides);
double* fill_times(STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, int flag);
int* fill_compare(int flag);
int compare_files(int option, int query);
void start_tests(STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, int flag);
void load_it(char* path, int flag);
void init_tests();

#endif