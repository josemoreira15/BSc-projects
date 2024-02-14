#ifndef USER_H
#define USER_H

#include "validation.h"

typedef struct user *USER;

USER create_user (char* info);
void destroy_user (USER user);

char* get_username (USER user);
char* get_user_name (USER user);
char* get_user_gender (USER user);
char* get_birth_date (USER user);
char* get_user_account_creation (USER user);
char* get_pay_method (USER user);
char* get_user_account_status (USER user);

int user_valid(USER user);

#endif
