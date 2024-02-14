#ifndef STATS_H
#define STATS_H

#include "util.h"
#include "glib.h"

typedef struct stats *STATS;

STATS create_stats();
void destroy_list(gpointer key, gpointer value, gpointer data);

void destroy_stats(STATS stats);
void destroy_index(gpointer key, gpointer value, gpointer data);
int get_hash_drivers_size(STATS stats);
int get_hash_users_size(STATS stats);

void add_person(STATS stats, char* id, char* type);
void add_person_index(STATS stats, char* id, int index, char* type);
void add_ride_index(STATS stats, char* id, int index);
void add_hash_ride(STATS stats, char* driver_id, char* user_id, char* ride_id);
void* get_name_hash(STATS stats, char* id, char* type);
int get_person_index(STATS stats, char* id, char* type);
int get_ride_index(STATS stats, char* id);
void print_param(STATS stats);

#endif
