#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <glib.h>

#include "../includes/cat_users.h"

/**
 * \brief Users array - catalog
 */
struct cat_users {
    USER* user;
    int length;
    int size;
};

/**
 * \brief Creats the users catalog
 */
USERS create_users(){
    USERS users = calloc(1, sizeof(*users));
    users->length = 0;
    users->size = 1000;
    users->user = calloc(users->size, sizeof(users->user));
    return users;
}

/**
 * \brief Adds an user to the users catalog
 */
void add_user(USER user, USERS users){
    if(users->size == users->length){
        users->size *= 2;
        users->user = realloc(users->user, users->size*sizeof(users->user));
    }
    users->user[users->length++] = user;
}

/**
 * \brief "Frees" the memory space of the users catalog
 */
void destroy_users(USERS users){
    for(int i=0; i<users->length; i++){
        destroy_user(users->user[i]);
    } 

    free(users->user);
    free(users);
}

/**
 * \brief Returns the length of the users catalog (number of users in the catalog)
 */
int get_length_users(USERS users){
    return users->length;
}

/**
 * \brief Returns the username of the user in index "i" of the catalog
 */
char* get_users_username(USERS users, int i){
    return get_username(users->user[i]);
}

/**
 * \brief Returns the name of the user in index "i" of the catalog
 */
char* get_users_user_name (USERS users, int i){
    return get_user_name(users->user[i]);
}

/**
 * \brief Returns the gender of the user in index "i" of the catalog
 */
char* get_users_user_gender (USERS users, int i){
    return get_user_gender(users->user[i]);
}

/**
 * \brief Returns the birth date of the user in index "i" of the catalog
 */
char* get_users_birth_date (USERS users, int i){
    return get_birth_date(users->user[i]);
}

/**
 * \brief Returns the account creation date of the user in index "i" of the catalog
 */
char* get_users_account_creation (USERS users, int i){
    return get_user_account_creation(users->user[i]);
}

/**
 * \brief Returns the pay method of the user in index "i" of the catalog
 */
char* get_users_pay_method (USERS users, int i){
    return get_pay_method(users->user[i]);
}

/**
 * \brief Returns the account status of the user in index "i" of the catalog
 */
char* get_users_user_account_status (USERS users, int i){
    return get_user_account_status (users->user[i]);
}

/**
 * \brief Parsing the users.csv file into a users catalogue
 */
USERS read_users(char* path, STATS stats) {
    char* file = str_connect(path,"/users.csv");
    FILE* data_file = fopen(file,"r");
    free(file);

    if(data_file == NULL){
        printf("»»» Error opening USERS dataset «««\n");
        fclose(data_file);
        exit(1);
    }

    else{
        char* line = NULL;
        size_t size = 0;
        USERS users = create_users();
        getline(&line,&size, data_file);
        while (getline(&line,&size, data_file) != -1){
            USER user = create_user(line);
            if(user_valid(user)){
                add_user(user,users);
                add_person_index(stats, get_username(user), users->length-1, "user");
            }
            else
                destroy_user(user);
        }
        free(line);

        printf("»»» USERS dataset loaded «««\n");
        fclose(data_file);

        return users;
    } 
}
