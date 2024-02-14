#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/validation.h"

/**
 * \brief Verifies if the date is valid
 */
int verify_date (char* date){
	if (strlen(date) == 0)
		return 0;
	for (int i=0; i<(int)strlen(date); i++){
		if ((i == 2 || i == 5) && date[i] != '/')
			return 0;
		else if ((i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7 || i == 8 || i == 9) && !isdigit(date[i]))
			return 0;
	}
	
	if (date[0]-'0' > 3 || (date[0]-'0' == 3 && date[1]-'0' > 1))
		return 0;
	if (date[3]-'0' > 1 || (date[3]-'0' == 1 && date[4]-'0' > 2))
		return 0;

	return 1;
}

/**
 * \brief Verifies if a car class is valid
 */
int verify_car_class(char* car_class){

	if(strlen(car_class) == 5){
		if ((car_class[0] == 'B' || car_class[0] == 'b') && 
			(car_class[1] == 'A' || car_class[1] == 'a') &&
		    (car_class[2] == 'S' || car_class[2] == 's') &&
		    (car_class[3] == 'I' || car_class[3] == 'i') &&
		    (car_class[4] == 'C' || car_class[4] == 'c'))
		    return 1;

		if ((car_class[0] == 'G' || car_class[0] == 'g') && 
			(car_class[1] == 'R' || car_class[1] == 'r') &&
		    (car_class[2] == 'E' || car_class[2] == 'e') &&
		    (car_class[3] == 'E' || car_class[3] == 'e') &&
		    (car_class[4] == 'N' || car_class[4] == 'n'))
		    return 1;
	}

	if(strlen(car_class) == 7){
		if ((car_class[0] == 'P' || car_class[0] == 'p') && 
			(car_class[1] == 'R' || car_class[1] == 'r') &&
		    (car_class[2] == 'E' || car_class[2] == 'e') &&
		    (car_class[3] == 'M' || car_class[3] == 'm') &&
		    (car_class[4] == 'I' || car_class[4] == 'i') &&
		    (car_class[5] == 'U' || car_class[5] == 'u') &&
		    (car_class[6] == 'M' || car_class[6] == 'm'))
		    return 1;
	}

	return 0;
}

/**
 * \brief Verifies if the account status is valid
 */
int verify_account_status(char* account_status){

    if(strlen(account_status) == 7){
		if ((account_status[0] == 'A' || account_status[0] == 'a') && 
			(account_status[1] == 'C' || account_status[1] == 'c') &&
		    (account_status[2] == 'T' || account_status[2] == 't') &&
		    (account_status[3] == 'I' || account_status[3] == 'i') &&
		    (account_status[4] == 'V' || account_status[4] == 'v') &&
		    (account_status[5] == 'E' || account_status[5] == 'e'))
		    return 1;
	}

	if(strlen(account_status) == 9){
		if ((account_status[0] == 'I' || account_status[0] == 'i') && 
			(account_status[1] == 'N' || account_status[1] == 'n') &&
		    (account_status[2] == 'A' || account_status[2] == 'a') &&
		    (account_status[3] == 'C' || account_status[3] == 'c') &&
		    (account_status[4] == 'T' || account_status[4] == 't') &&
		    (account_status[5] == 'I' || account_status[5] == 'i') &&
		    (account_status[6] == 'V' || account_status[6] == 'v') &&
		    (account_status[7] == 'E' || account_status[7] == 'e'))
		    return 1;
	}
	
	return 0;
}

/**
 * \brief Verifies if the distance is valid
 */
int verify_distance (char* distance) {
	if (strlen(distance) == 0 || distance[0] == '0')
		return 0;

	for (int i=0; i<(int)strlen(distance);i++)
		if (!isdigit(distance[i]))
			return 0;
	return 1;
}

/**
 * \brief Verifies if the score is valid
 */
int verify_score_user_driver_tip (char* value, char* type) {
	int points = 0;
	int size = (int)strlen(value);
	if (size == 0 || (value[0] == '0' && !strcmp(type,"score")))
		return 0;

	for (int i=0; i<size;i++){
		if (!isdigit(value[i])){
			if(value[i] != '.')
				return 0;
			else {
				if (i != size - 2)
					return 0;
				points++;
			}
		}
	}

	if ((points > 1 && !strcmp(type,"tip")) || (points > 0 && !strcmp(type,"score")))
		return 0;
		
	return 1;
}

/**
 * \brief Verifies some of the driver fields
 */
int verify_driver_fields (char* id, char* name, char* gender, char* license_plate, char* city){

	if (strlen(id) == 0 || strlen(name) == 0 || strlen(gender) == 0 || strlen(license_plate) == 0 || strlen(city) == 0)
		return 0;
	return 1;
}

/**
 * \brief Verifies some of the user fields
 */
int verify_user_fields (char* username, char* name, char* gender, char* pay_method){

	if (strlen(username) == 0 || strlen(name) == 0 || strlen(gender) == 0 || strlen(pay_method) == 0)
		return 0;
	return 1;
}

/**
 * \brief Verifies some of the ride fields
 */
int verify_ride_fields (char* id, char* driver, char* user, char* city){

    if (strlen(id) == 0 || strlen(driver) == 0 || strlen(user) == 0 || strlen(city) == 0)
        return 0;
    return 1;
}
