#ifndef CAT_USERS_H
#define CAT_USERS_H

#include "user.h"
#include "stats.h"

typedef struct cat_users *USERS;

USERS create_users();
void add_user (USER user, USERS users);
void destroy_users (USERS users);

int get_length_users (USERS users);

char* get_users_username(USERS users, int i);
char* get_users_user_name (USERS users, int i);
char* get_users_user_gender (USERS users, int i);
char* get_users_birth_date (USERS users, int i);
char* get_users_account_creation (USERS users, int i);
char* get_users_pay_method (USERS users, int i);
char* get_users_user_account_status (USERS users, int i);

USERS read_users(char* path, STATS stats);

#endif
