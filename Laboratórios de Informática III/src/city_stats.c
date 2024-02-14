#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/city_stats.h"

/**
 * \brief CITY struct
 */
struct city {
	char* name;

	int* rides;
	int rides_size;
	int rides_length;
};

/**
 * \brief Creates the CITY struct
 */
CITY create_city(char* name) {
	CITY city = (CITY) malloc(sizeof(*city));

	city->name = name;
	city->rides_length = 0;
	city->rides_size = 2000;
	city->rides = calloc(city->rides_size,sizeof(city->rides));

	return city;
}

/**
 * \brief Destroys/Frees the CITY struct
 */
void destroy_city(CITY city){
	free(city->name);
	free(city->rides);

	free(city);
}

/**
 * \brief Gets the name of a CITY
 */
char* get_city_name(CITY city) {
	return city->name;
}

/**
 * \brief Gets the array of ids of a CITY
 */
int* get_city_rides_ids(CITY city) {
	return city->rides;
}

/**
 * \brief Gets the length of the array in a CITY
 */
int get_city_rides_length(CITY city) {
	return city->rides_length;
}

/**
 * \brief Gets the size of the array in a CITY
 */
int get_city_rides_size(CITY city) {
	return city->rides_size;
}

/**
 * \brief Adds an int id to the CITY array
 */
void add_city_ride(CITY city, int ride_id) {
	if (city->rides_size == city->rides_length){
		city->rides_size *= 2;
		city->rides = realloc(city->rides,city->rides_size*sizeof(city->rides));
	}
	city->rides[city->rides_length++] = ride_id;
}

/**
 * \brief Struct with multiple CITY structs (array)
 */
struct city_stats {
	CITY* cities;
	int cities_size;
	int cities_length;
};

/**
 * \brief Creates the CITY_STATS struct
 */
CITY_STATS create_city_stats() {
	CITY_STATS city_stats = (CITY_STATS) malloc(sizeof(*city_stats));

	city_stats->cities_length = 0;
	city_stats->cities_size = 2;
	city_stats->cities = calloc(city_stats->cities_size,sizeof(city_stats->cities));

	return city_stats;
}

/**
 * \brief Destroys/frees the CITY_STATS struct
 */
void destroy_city_stats(CITY_STATS city_stats){
	for(int i=0; i<city_stats->cities_length; i++){
		destroy_city(city_stats->cities[i]);
	}
	free(city_stats->cities);

	free(city_stats);
}

/**
 * \brief Gets the size of the array
 */
int get_city_stats_size(CITY_STATS city_stats) {
	return city_stats->cities_size;
}

/**
 * \brief Gets the length of the array (number of CITY structs)
 */
int get_city_stats_length(CITY_STATS city_stats) {
	return city_stats->cities_length;
}

/**
 * \brief Returns a CITY in the CITY_STATS struct by its name
 */
CITY get_city_stats(CITY_STATS city_stats, char* city){
	int i;
	for(i=0; i<city_stats->cities_length && strcmp(city_stats->cities[i]->name,city); i++);

	if (i == city_stats->cities_length)
		return NULL;
	return city_stats->cities[i];
}

/**
 * \brief Adds a CITY to the CITY_STATS struct
 */
void add_city(CITY_STATS city_stats, char* name) {
	if(city_stats->cities_size == city_stats->cities_length){
		city_stats->cities_size *= 2;
		city_stats->cities = realloc(city_stats->cities,city_stats->cities_size*sizeof(city_stats->cities));
	}
	city_stats->cities[city_stats->cities_length++] = create_city(name);
}

/**
 * \brief Adds a ride id to a CITY in a CITY_STATS struct
 */
void add_city_stats_ride(CITY_STATS city_stats, int ride_id, char* city){
	int index;
	for(index = 0; index<city_stats->cities_length && strcmp(city_stats->cities[index]->name,city); index++);

	if (index == city_stats->cities_length) {
		add_city(city_stats,city);
	} 
	else
		free(city);
	
	add_city_ride(city_stats->cities[index],ride_id);
}
