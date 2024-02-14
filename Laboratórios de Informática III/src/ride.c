#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../includes/ride.h"

/**
 * \brief Ride structure
 */
struct ride {
	char* ride_id;
	char* date;
	char* driver_id;
	char* user;
	char* city;
	char* distance;
	char* score_user;
	char* score_driver;
	char* tip;
	char* comment;
};

/**
 * \brief Creates a ride
 */
RIDE create_ride (char* info) {
	RIDE ride = (RIDE) malloc(sizeof(*ride));

	ride->ride_id = strdup(strsep (&info, ";"));
	ride->date = strdup(strsep (&info, ";"));
	ride->driver_id = strdup(strsep (&info, ";"));
	ride->user = strdup(strsep (&info, ";"));
	ride->city = strdup(strsep (&info, ";"));
	ride->distance = strdup(strsep (&info, ";"));
	ride->score_user = strdup(strsep (&info, ";"));
	ride->score_driver = strdup(strsep (&info, ";"));
	ride->tip = strdup(strsep (&info, ";"));
	ride->comment = strdup(strsep (&info, ";"));

	return ride;
}

/**
 * \brief Frees the space in memory of a ride
 */
void destroy_ride (RIDE ride) {
	free(ride->ride_id);
	free(ride->date);
	free(ride->driver_id);
	free(ride->user);
	free(ride->city);
	free(ride->distance);
	free(ride->score_user);
	free(ride->score_driver);
	free(ride->tip);
	free(ride->comment);
	
	free(ride);
}

/**
 * \brief Returns the ID of a ride
 */
char* get_ride_id (RIDE ride) {
	return strdup(ride->ride_id);
}

/**
 * \brief Returns the date of a ride
 */
char* get_date (RIDE ride) {
	return strdup(ride->date);
}

/**
 * \brief Returns the driver ID of a ride
 */
char* get_ride_driver_id (RIDE ride) {
	return strdup(ride->driver_id);
}

/**
 * \brief Returns the user of a ride
 */
char* get_user (RIDE ride) {
	return strdup(ride->user);
}

/**
 * \brief Returns the city of a ride
 */
char* get_city (RIDE ride) {
	return strdup(ride->city);
}

/**
 * \brief Returns the distance of a ride
 */
int get_distance (RIDE ride) {
	return atoi(ride->distance);
}

/**
 * \brief Returns the user score of a ride
 */
double get_score_user (RIDE ride) {
	return atof(ride->score_user);
}

/**
 * \brief Returns the driver score of a ride
 */
double get_score_driver (RIDE ride) {
	return atof(ride->score_driver);
}

/**
 * \brief Returns the value oof the tip of a ride
 */
double get_tip (RIDE ride) {
	return atof(ride->tip);
}

/**
 * \brief Returns the comment of a ride
 */
char* get_comment (RIDE ride) {
	return strdup(ride->comment);
}

/**
 * \brief Validates a ride
 */
int ride_valid(RIDE ride){
	
	if (verify_ride_fields(ride->ride_id,ride->driver_id,ride->user,ride->city) &&
	    verify_date(ride->date) &&
        verify_distance(ride->distance) &&
	    verify_score_user_driver_tip(ride->score_user, "score") &&
	    verify_score_user_driver_tip(ride->score_driver, "score") &&
	    verify_score_user_driver_tip(ride->tip,"tip"))
		
		return 1;

	return 0;
}
