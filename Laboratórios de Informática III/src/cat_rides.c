#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <glib.h>
#include <unistd.h>

#include "../includes/cat_rides.h"

/**
 * \brief Rides array - catalog
 **/
struct cat_rides {
    RIDE* ride;
    int length;
    int size;
};

/**
 * \brief Creates a rides catalog
 **/
RIDES create_rides(){
    RIDES rides = calloc(1, sizeof(*rides));
    rides->length = 0;
    rides->size = 10000;
    rides->ride = calloc(rides->size, sizeof(rides->ride));
    return rides;
}

/**
 * \brief Adds a ride to a catalog of rides 
 **/
void add_ride(RIDE ride, RIDES rides){
    if(rides->size == rides->length){
        rides->size *= 2;
        rides->ride = realloc(rides->ride, rides->size*sizeof(rides->ride));
    }
    rides->ride[rides->length++] = ride;
}

/**
 * \brief Frees the space in memory ocupied by a ride catalog
 **/
void destroy_rides(RIDES rides){
    for(int i=0; i<rides->length; i++){
        destroy_ride(rides->ride[i]);
    }  

    free(rides->ride);
    free(rides);
}

/**
 * \brief Returns the length of a rides catalog
 */
int get_length_rides(RIDES rides){
    return rides->length;
}

/**
 * \brief Returns the ID of the ride in index i in a ride catalog
 */
char* get_rides_ride_id (RIDES rides, int i) {
    return get_ride_id(rides->ride[i]);
}

/**
 * \brief Returns the date of the ride in index i in a ride catalog
 */
char* get_rides_date (RIDES rides, int i) {
    return get_date(rides->ride[i]);
}

/**
 * \brief Returns the driver id of the ride in index i in a ride catalog
 */
char* get_rides_ride_driver_id (RIDES rides, int i) {
    return get_ride_driver_id(rides->ride[i]);
}

/**
 * \brief Returns the user of the ride in index i in a ride catalogue
 */
char* get_rides_user (RIDES rides, int i) {
    return get_user(rides->ride[i]);
}

/**
 * \brief Returns the city of the ride in index i in a ride catalog
 */
char* get_rides_city (RIDES rides, int i) {
    return get_city(rides->ride[i]);
}

/**
 * \brief Returns the distance of the ride in index i in a ride catalog
 */
int get_rides_distance (RIDES rides, int i) {
    return get_distance(rides->ride[i]);
}

/**
 * \brief Returns the user score of the ride in index i in a ride catalog
 */
double get_rides_score_user (RIDES rides, int i) {
    return get_score_user(rides->ride[i]);
}

/**
 * \brief Returns the driver score of the ride in index i in a ride catalog
 */
double get_rides_score_driver (RIDES rides, int i) {
    return get_score_driver(rides->ride[i]);
}

/**
 * \brief Returns the value of the tip of the ride in index i in a ride catalog
 */
double get_rides_tip (RIDES rides, int i) {
    return get_tip(rides->ride[i]);
}

/**
 * \brief Returns the comment of the ride in index i in a ride catalogue
 */
char* get_rides_comment (RIDES rides, int i) {
    return get_comment(rides->ride[i]);
}

/**
 * \brief Parsing the rides.csv file into a rides catalogue
 */
RIDES read_rides(char* path, STATS stats, CITY_STATS city_stats) {
    
    char* file = str_connect(path,"/rides.csv");
    FILE* data_file = fopen(file,"r");
    free(file);

    if(data_file == NULL){
        printf("»»» Error opening RIDES dataset «««\n");
        fclose(data_file);
        exit(1);
    }

    else{
        char* line = NULL;
        size_t size = 0;
        RIDES rides = create_rides();
        getline(&line,&size, data_file);
        while (getline(&line,&size, data_file) != -1){
            RIDE ride = create_ride(line);
            if (ride_valid(ride)){
                char* ride_id = get_ride_id(ride);

                add_ride(ride,rides);
                add_ride_index(stats, ride_id, rides->length-1);

                add_hash_ride(stats,get_ride_driver_id(ride),get_user(ride),ride_id);
                add_city_stats_ride(city_stats, rides->length-1, get_city(ride));
            }
            else
                destroy_ride(ride);
        }
        free(line);

        printf("»»» RIDES dataset loaded «««\n");
        fclose(data_file);
        return rides;
    } 
}
