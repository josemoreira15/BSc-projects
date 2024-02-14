#ifndef CITY_STATS_H
#define CITY_STATS_H

typedef struct city *CITY;

CITY create_city(char* name);
void destroy_city(CITY city);
char* get_city_name(CITY city);
int* get_city_rides_ids(CITY city);
int get_city_rides_length(CITY city);
int get_city_rides_size(CITY city);
void add_city_ride(CITY city, int ride_id);


typedef struct city_stats *CITY_STATS;

CITY_STATS create_city_stats();
void destroy_city_stats(CITY_STATS city_stats);
int get_city_stats_size(CITY_STATS city_stats);
int get_city_stats_length(CITY_STATS city_stats);
CITY get_city_stats(CITY_STATS city_stats, char* city);
void add_city(CITY_STATS city_stats, char* name);
void add_city_stats_ride(CITY_STATS city_stats, int ride_id, char* city);

#endif
