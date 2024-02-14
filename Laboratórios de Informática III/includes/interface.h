#ifndef INTERFACE_H
#define INTERFACE_H

#include "pages.h"

void retry(STATS stats,CITY_STATS city_stats,USERS users,DRIVERS drivers,RIDES rides);
void query_pages(PAGES pages);
void query1_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void query2_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void query3_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void query4_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void query5_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void query6_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void query7_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void query8_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void query9_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void choose_queryIO(int query_id, STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param);
void start_query(STATS stats,CITY_STATS city_stats,USERS users,DRIVERS drivers,RIDES rides);
void start_interface();

#endif
