#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../includes/parsing.h"

/**
 * \brief Parse, execute the queries and free the allocated memory 
 */
void parsing(char* path, char* commands){
    STATS stats = create_stats();
    CITY_STATS city_stats = create_city_stats();
    USERS users = read_users(path, stats);
    DRIVERS drivers = read_drivers(path, stats);
    RIDES rides = read_rides(path, stats, city_stats);
    queries (stats, city_stats, users, drivers, rides, commands);
    destroy_stats(stats);
    destroy_city_stats(city_stats);
    destroy_users(users);
    destroy_drivers(drivers);
    destroy_rides(rides);
}
