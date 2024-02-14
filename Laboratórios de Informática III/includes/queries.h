#ifndef QUERIES_H
#define QUERIES_H

#include "queries_aux.h"

void query1 (char* file, STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line);
void query2 (char* file, STATS stats, DRIVERS drivers, RIDES rides, char* line);
void query3 (char* file, STATS stats, USERS users, RIDES rides, char* line);
void query4 (char* file, STATS stats, CITY_STATS city_stats, RIDES rides, DRIVERS drivers, char* line);
void query5 (char* file, STATS stats, RIDES rides, DRIVERS drivers, char* line);
void query6 (char* file, CITY_STATS, RIDES rides, char* line);
void query7 (char* file, STATS stats, DRIVERS drivers, RIDES rides, char* line);
void query8 (char* file, STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line);
void query9 (char* file, STATS stats, RIDES rides, char* line);
void choose_query(int indice, char *line, STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides);
void queries (STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, char* commands);

#endif
