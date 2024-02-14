#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/driver.h"

/**
 * \brief Driver structure
 */
struct driver {
	char* driver_id;
	char* driver_name;
	char* birthday;
	char* gender;
	char* car_class;
	char* license_plate;
	char* driver_city;
	char* account_creation;
	char* account_status;
};

/**
 * \brief Creates driver
 */
DRIVER create_driver (char* info) {
	DRIVER driver = (DRIVER) malloc(sizeof(*driver));

	driver->driver_id = strdup(strsep (&info, ";"));
	driver->driver_name = strdup(strsep (&info, ";"));
	driver->birthday = strdup(strsep (&info, ";"));
	driver->gender = strdup(strsep (&info, ";"));
	driver->car_class = strdup(strsep (&info, ";"));
	driver->license_plate = strdup(strsep (&info, ";"));
	driver->driver_city = strdup(strsep (&info, ";"));
	driver->account_creation = strdup(strsep (&info, ";"));
	driver->account_status = strdup(strsep (&info, ";"));

	return driver;
}

/**
 * \brief Removes the driver
 */
void destroy_driver (DRIVER driver) {
	free(driver->driver_id);
	free(driver->driver_name);
	free(driver->birthday);
	free(driver->gender);
	free(driver->car_class);
	free(driver->license_plate);
	free(driver->driver_city);
	free(driver->account_creation);
	free(driver->account_status);
	
	free(driver);
}

/**
 * \brief Returns the id of the driver
 */
char* get_driver_id(DRIVER driver) {
	return strdup(driver->driver_id);
}

/**
 * \brief Returns the name of the driver
 */
char* get_driver_name(DRIVER driver) {
	return strdup(driver->driver_name);
}

/**
 * \brief Returns the birthday of the driver
 */
char* get_birthday(DRIVER driver) {
	return strdup(driver->birthday);
}

/**
 * \brief Returns the gender of the driver
 */
char* get_driver_gender(DRIVER driver) {
	return strdup(driver->gender);
}

/**
 * \brief Returns the car class of the driver
 */
char* get_car_class(DRIVER driver) {
	return strdup(driver->car_class);
}

/**
 * \brief Returns the license plate of the driver
 */
char* get_license_plate(DRIVER driver) {
	return strdup(driver->license_plate);
}

/**
 * \brief Returns the city of the driver
 */
char* get_driver_city(DRIVER driver) {
	return strdup(driver->driver_city);
}

/**
 * \brief Returns the Account Creation of the driver
 */
char* get_driver_account_creation(DRIVER driver) {
	return strdup(driver->account_creation);
}

/**
 * \brief Returns the Account Status of the driver
 */
char* get_driver_account_status(DRIVER driver) {
	return strdup(driver->account_status);
}

/**
 * \brief Validates a driver
 */
int driver_valid(DRIVER driver){

	if(verify_driver_fields(driver->driver_id,driver->driver_name,driver->gender,driver->license_plate,driver->driver_city) &&
	  (verify_date(driver->birthday)) &&
	  (verify_date(driver->account_creation)) &&
	  (verify_car_class(driver->car_class)) &&
	  (verify_account_status(driver->account_status)))
		
		return 1;

	return 0;
}
