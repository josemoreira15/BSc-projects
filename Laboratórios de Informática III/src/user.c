#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/user.h"

/**
 * \brief User structure
 */
struct user {
	char* username;
	char* name;
	char* gender;
	char* birth_date;
	char* account_creation;
	char* pay_method;
	char* account_status;
};

/**
 * \brief Creates user
 */
USER create_user (char* info) {
	USER user = (USER) malloc(sizeof(*user));

	user->username = strdup(strsep (&info, ";"));
	user->name = strdup(strsep (&info, ";"));
	user->gender = strdup(strsep (&info, ";"));
	user->birth_date = strdup(strsep (&info, ";"));
	user->account_creation = strdup(strsep (&info, ";"));
	user->pay_method = strdup(strsep (&info, ";"));
	user->account_status = strdup(strsep (&info, ";"));

	return user;
}

/**
 * \brief Removes user
 */
void destroy_user(USER user) {
	free(user->username);
	free(user->name);
	free(user->gender);
	free(user->birth_date);
	free(user->account_creation);
	free(user->pay_method);
	free(user->account_status);

	free(user);
}

/**
 * \brief Returns the username of the user
 */
char* get_username (USER user){
	return strdup(user->username);
}

/**
 * \brief Returns the name of the user
 */
char* get_user_name (USER user){
	return strdup(user->name);
}

/**
 * \brief Returns the gender of the user
 */
char* get_user_gender (USER user){
	return strdup(user->gender);
}

/**
 * \brief Returns the birth date of the user
 */
char* get_birth_date (USER user){
	return strdup(user->birth_date);
}

/**
 * \brief Returns the account creation of the user
 */
char* get_user_account_creation (USER user){
	return strdup(user->account_creation);
}

/**
 * \brief Returns the pay method of the user
 */
char* get_pay_method (USER user){
	return strdup(user->pay_method);
}

/**
 * \brief Returns the account status of the user
 */
char* get_user_account_status (USER user){
	return strdup(user->account_status);
}

/**
 * \brief Validates an user
 */
int user_valid(USER user){

	if (verify_user_fields(user->username,user->name,user->gender,user->pay_method) &&
	   (verify_date(user->birth_date)) &&
	   (verify_date(user->account_creation)) &&
	   (verify_account_status(user->account_status)))
            
    	return 1;
		
	return 0;
}
