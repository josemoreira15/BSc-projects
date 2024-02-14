#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <glib.h>

#include "../includes/stats.h"

/**
 * \brief STATS struct
 */
struct stats {
	GHashTable* drivers;
	GHashTable* users;

	GHashTable* users_indexs;
	GHashTable* drivers_indexs;
	GHashTable* rides_indexs;
};

/**
 * \brief Creates the struct STATS
 */
STATS create_stats(){
	STATS stats = calloc(1,sizeof(*stats));

	stats->drivers = g_hash_table_new(g_str_hash,g_str_equal);
	stats->users = g_hash_table_new(g_str_hash,g_str_equal);

	stats->users_indexs = g_hash_table_new(g_str_hash,g_str_equal);
	stats->drivers_indexs = g_hash_table_new(g_str_hash,g_str_equal);
	stats->rides_indexs = g_hash_table_new(g_str_hash,g_str_equal);

	return stats;
}

/**
 * \brief Destroys/Frees the struct STATS tables with a GSList in the value
 */
void destroy_list(gpointer key, gpointer value, gpointer data) {
	free(key);
 	g_slist_free(value);
 	free(data);
}

/**
 * \brief Destroys/Frees the struct STATS tables with an int in the value
 */
void destroy_index(gpointer key, gpointer value, gpointer data) {
	free(key);
	value = value;
	free(data);
}

/**
 * \brief Destroys/Frees the struct STATS
 */
void destroy_stats(STATS stats){
	g_hash_table_foreach(stats->drivers,destroy_list,NULL);
	g_hash_table_destroy(stats->drivers);

	g_hash_table_foreach(stats->users,destroy_list,NULL);
	g_hash_table_destroy(stats->users);

	g_hash_table_foreach(stats->users_indexs,destroy_index,NULL);
	g_hash_table_destroy(stats->users_indexs);

	g_hash_table_foreach(stats->drivers_indexs,destroy_index,NULL);
	g_hash_table_destroy(stats->drivers_indexs);

	g_hash_table_foreach(stats->rides_indexs,destroy_index,NULL);
	g_hash_table_destroy(stats->rides_indexs);

	free(stats);
}

/**
 * \brief Returns the size of the STATS->drivers hashtable
 */
int get_hash_drivers_size(STATS stats){
	return g_hash_table_size(stats->drivers);
}

/**
 * \brief Returns the size of the STATS->users hashtable
 */
int get_hash_users_size(STATS stats){
	return g_hash_table_size(stats->users);
}

/**
 * \brief Inserts a new ID in the STATS->users hash or in the STATS->drivers hash
 */
void add_person(STATS stats, char* id, char* type) {
	if(!strcmp(type,"driver"))
		g_hash_table_insert(stats->drivers,id,NULL);
	else
		g_hash_table_insert(stats->users,id,NULL);
}

/**
 * \brief Inserts a new ID in the STATS->users_indexs hash or in the STATS->drivers hash and its associated index in the catalog
 */
void add_person_index(STATS stats, char* id, int index, char* type){
	if (!strcmp(type,"user"))
		g_hash_table_insert(stats->users_indexs,id,GINT_TO_POINTER(index));
	else 
		g_hash_table_insert(stats->drivers_indexs,id,GINT_TO_POINTER(index));
}

/**
 * \brief Inserts a new ID in the STATS->rides_indexs and its associated index in the catalog
 */
void add_ride_index(STATS stats, char* id, int index){
	g_hash_table_insert(stats->rides_indexs,id,GINT_TO_POINTER(index));
}

/**
 * \brief Adds a new ride to the GSList of the STATS->users hash or the STATS->drivers hash
 */
void add_hash_ride(STATS stats, char* driver_id, char* user_id, char* ride_id) {
	if (g_hash_table_contains(stats->drivers,driver_id)) {
		g_hash_table_insert(stats->drivers, driver_id, g_slist_append(g_hash_table_lookup(stats->drivers, driver_id), ride_id));
		free(driver_id);
	}
	else
		g_hash_table_insert(stats->drivers, driver_id, g_slist_append(g_hash_table_lookup(stats->drivers, driver_id), ride_id));


	if (g_hash_table_contains(stats->users,user_id)){
		g_hash_table_insert(stats->users, user_id, g_slist_append(g_hash_table_lookup(stats->users, user_id), ride_id));
		free(user_id);
	}
	else
		g_hash_table_insert(stats->users, user_id, g_slist_append(g_hash_table_lookup(stats->users, user_id), ride_id));
}

/**
 * \brief Returns a void* with all the rides' ids of a person, by its id
 */
void* get_name_hash(STATS stats, char* id, char* type){
	if (!strcmp(type,"driver"))
		return g_hash_table_lookup(stats->drivers,id);
	else
		return g_hash_table_lookup(stats->users,id);
}

/**
 * \brief Returns the index in the catalog of a person, given its id
 */
int get_person_index(STATS stats, char* id, char* type) {
	if (!strcmp(type,"user"))
		return GPOINTER_TO_INT(g_hash_table_lookup(stats->users_indexs,id));
	else
		return GPOINTER_TO_INT(g_hash_table_lookup(stats->drivers_indexs,id));
}

/**
 * \brief Returns the index in the catalog of a ride, given its id
 */
int get_ride_index(STATS stats, char* id) {
	return GPOINTER_TO_INT(g_hash_table_lookup(stats->rides_indexs,id));
}

/**
 * \brief Prints the size of all STATS struct hashtables - debug function
 */
void print_param(STATS stats) {
  	printf("%d\n",g_hash_table_size(stats->users_indexs));
  	printf("%d\n",g_hash_table_size(stats->drivers_indexs));
  	printf("%d\n",g_hash_table_size(stats->rides_indexs));
  	printf("%d\n",g_hash_table_size(stats->drivers));
	printf("%d\n",g_hash_table_size(stats->users));
}
