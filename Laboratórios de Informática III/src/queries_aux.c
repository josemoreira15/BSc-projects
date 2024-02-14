#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <glib.h>

#include "../includes/queries_aux.h"

/**
 * \brief Struct that keeps the rides ids in an array
 */
struct all_rides {
    int* rides_ids;
    int rides_length;
    int rides_size;
};

/**
 * \brief Creates ALL_RIDES
 */
ALL_RIDES create_all_rides(){
    ALL_RIDES all_rides = (ALL_RIDES) malloc(sizeof(*all_rides));

    all_rides->rides_size = 100;
    all_rides->rides_length = 0;
    all_rides->rides_ids = calloc(all_rides->rides_size,sizeof(all_rides->rides_ids));

    return all_rides;
}

/**
 * \brief Destroys ALL_RIDES
 */
void destroy_all_rides(ALL_RIDES all_rides) {
    free(all_rides->rides_ids);

    free(all_rides);
}

/**
 * \brief Adds a ride to ALL_RIDES
 */
void add_all_rides_ride(ALL_RIDES all_rides, int ride_id){
    if(all_rides->rides_size == all_rides->rides_length){
        all_rides->rides_size *= 2;
        all_rides->rides_ids = realloc(all_rides->rides_ids,all_rides->rides_size*sizeof(all_rides->rides_ids));
    }
    all_rides->rides_ids[all_rides->rides_length++] = ride_id;
}

/**
 * \brief Prints the query8 result in a file
 */
void print_all_rides_gender(STATS stats, PARAM param, DRIVERS drivers, RIDES rides, char* file){
    FILE* final = fopen(file,"w");

    if (param != NULL) {
        char** ids = get_param_ids(param);
        char** names = get_param_names(param);

        for(int i=0;i<get_param_arrays_size(param); i++){
            int index = get_ride_index(stats,ids[i]);
            char* id_driver = get_rides_ride_driver_id(rides,index);
        
            int driver_index = get_person_index(stats,id_driver,"driver");
            char* name_driver = get_drivers_driver_name(drivers,driver_index);

            char* id_user = get_rides_user(rides,index);

            fprintf(final,"%s;",id_driver);
            fprintf(final,"%s;",name_driver);
            fprintf(final,"%s;",id_user);
            fprintf(final,"%s\n",names[i]);

            free(id_driver);
            free(name_driver);
            free(id_user);
        }
    }

    fclose(final);
}

/**
 * \brief Prints the query9 result in a file
 */
void print_all_rides(STATS stats, PARAM param, RIDES rides, char* file) {
    FILE* final = fopen(file,"w");
    if (param != NULL) {
        char** ids = get_param_ids(param);
        double* values = get_param_values(param);
        char** names = get_param_names(param);

        for(int i=0;i<get_param_arrays_size(param); i++) {
            int index = get_ride_index(stats,ids[i]);
            double tip = get_rides_tip(rides, index);
            char* date = get_rides_date(rides,index);
            fprintf(final,"%s;",ids[i]);
            fprintf(final,"%s;",date);
            fprintf(final,"%d;",(int)values[i]);
            fprintf(final,"%s;",names[i]);
            fprintf(final,"%.3f\n",tip);

            free(date);
        }
    }

    fclose(final);
}

/**
 * \brief Struct that keeps the result for Query 1
 */
struct result {
    int index;
    int age;
    double av;
    int nr;
    double money;
    char* type;
};

/**
 * \brief Creates the RESULT struct
 */
RESULT create_result(int index, int age, double av, int nr, double money, char* type){
    RESULT result = (RESULT) malloc(sizeof(*result));

    result->index = index;
    result->age = age;
    result->av = av;
    result->nr = nr;
    result->money = money;
    result->type = type;

    return result;
}

/**
 * \brief Destroys the RESULT struct
 */
void destroy_result(RESULT result) {
    free(result);
}

/**
 * \brief Prints the struct RESULT elements
 */
void print_result(RESULT result, char* file, USERS users, DRIVERS drivers, int flag) {
    if (flag == 0) {
        FILE* final = fopen(file,"w");
        if (strcmp(result->type,"")) {
            char* name;
            char* gender;
            int index = result->index;

            if (!strcmp(result->type,"user")){
                name = get_users_user_name(users,index);
                gender = get_users_user_gender(users,index);
            }

            else {
                name = get_drivers_driver_name(drivers,index);
                gender = get_drivers_driver_gender(drivers,index);
            }
        
            fprintf(final,"%s;",name);
            fprintf(final,"%s;",gender);
            fprintf(final,"%d;",result->age);
            fprintf(final,"%.3f;",result->av);
            fprintf(final,"%d;",result->nr);
            fprintf(final,"%.3f\n",result->money);

            free(name);
            free(gender);
        }

        fclose(final);
    }

    else {

        if (!strcmp(result->type,""))
            printf("\n»»»»»»»»»»»»» Conta não encontrada! «««««««««««««\n");

        else {
            char* name;
            char* gender;
            int index = result->index;

            if (!strcmp(result->type,"user")){
                name = get_users_user_name(users,index);
                gender = get_users_user_gender(users,index);
            }

            else {
                name = get_drivers_driver_name(drivers,index);
                gender = get_drivers_driver_gender(drivers,index);
            }
            
            printf("»»»»»»»»»»»»» Perfil «««««««««««««\n");
            printf("\n» Nome: %s\n",name);
            printf("» Género: %s\n",gender);
            printf("» Idade: %d\n",result->age);
            printf("» Avaliação média: %.3f\n",result->av);
            printf("» Número de viagens: %d\n",result->nr);
            printf("» Dinheiro gasto/recebido: %.3f €\n",result->money);

            free(name);
            free(gender);
        }
    }
}

/**
 * \brief Checks, by his username, if a user is active
 */
int is_user_active(USERS users, int index){
    char* status = get_users_user_account_status(users,index);

    if (status[0] == 'a' || status[0] == 'A'){
        free(status);
    	return 1;
    }
    
    free(status);
    return 0;
}

/**
 * \brief Checks, by his id, if a driver is active
 */
int is_driver_active(DRIVERS drivers, int index){
    char* status = get_drivers_driver_account_status(drivers,index);

    if (status[0] == 'a' || status[0] == 'A'){
        free(status);
        return 1;
    }
    
    free(status);
    return 0;
}

/**
 *  \brief Returns the total distance of an user
 */
double total_distance(STATS stats, void* rides_ids, RIDES rides){
    GSList* iterator = NULL;
    int distance = 0;

    for (iterator = rides_ids; iterator; iterator = iterator->next){
        int ride_id = get_ride_index(stats, iterator->data);
        distance += get_rides_distance(rides,ride_id);
    }

    return (double)distance;
}

/**
 *  \brief Auxiliar function that calculates the price of a ride
 */
double tariff(char* type, int dist){

    double value = 0;
    
    if(type[0] == 'b' || type[0] == 'B')
        value = 3.25 + 0.62 * (double) dist;
    else if(type[0] == 'g' || type[0] == 'G')
        value = 4.00 + 0.79 * (double) dist;
    else
        value = 5.20 + 0.94 * (double) dist;
    

    return value;
}

/**
 * \brief Returns the last ride's date of a driver
 */
char* last_ride_date(STATS stats, void* rides_ids, RIDES rides){
    GSList* iterator = NULL;
    char* date_changed = NULL;
    int freeIt = 1;

    for (iterator = rides_ids; iterator; iterator = iterator->next){
        int index = get_ride_index(stats,iterator->data);
        char* curr_date = get_rides_date(rides,index);
        char* curr_date_changed = change_date_format(curr_date);
        free(curr_date);

        if (date_changed == NULL || !is_before(curr_date_changed,date_changed)){
            free(date_changed);
            date_changed = curr_date_changed;
            freeIt = 0;
        }
        else
            freeIt = 1;

        if (freeIt == 1)
            free(curr_date_changed);
    }

    return date_changed;
}

/**
 * \brief Calculates the average of a driver score
 */
double media_av(STATS stats, void* rides_ids, RIDES rides){
    GSList* iterator = NULL;
    int nr_rides = 0;

    int total_av = 0;
    for (iterator = rides_ids; iterator; iterator = iterator->next){
        nr_rides++;
        int index = get_ride_index(stats,iterator->data);
        total_av += get_rides_score_driver(rides,index);

    }

    return (double)total_av/(double)nr_rides;
}

/**
 * \brief Calculates the average of a driver score in a given city
 */
double media_av_city(STATS stats, void* rides_ids, RIDES rides, char* city){
    GSList* iterator = NULL;
    int total_av = 0;
    int total_rides = 0;

    for (iterator = rides_ids; iterator; iterator = iterator->next){
        int index = get_ride_index(stats,iterator->data);
        char* this_city = get_rides_city(rides,index);
        if (!strcmp(this_city,city)){
            total_av += get_rides_score_driver(rides,index);
            total_rides++;
        }
        free(this_city);
    }

    return total_rides > 0 ? (double)total_av/(double)total_rides : 0;

}

/**
 * \brief Auxiliar to query 1
 */
RESULT query1_aux(STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line){
    strsep(&line, " ");

    char* id = change_char(strsep(&line, " "));
    char* name;
    char* gender;
    GSList* iterator = NULL;
    void* list_ids;
    char* date;
    char* flag;

    int total_av = 0, index, distance, ride_id, rides_nr = 0, age;

    double av_media, money_s = 0, ride_spent;

    if (isdigit(id[0])) {
        flag = "driver";
        index = get_person_index(stats, id, "driver");

        list_ids = get_name_hash(stats,id,"driver");
        if (list_ids == NULL)
            return create_result(0,0,0,0,0,"");

        if(!is_driver_active(drivers,index))
            return create_result(0,0,0,0,0,"");

        name = get_drivers_driver_name(drivers,index);
        gender = get_drivers_driver_gender(drivers,index);
        char* car_class = get_drivers_car_class(drivers,index);
        date = get_drivers_birthday(drivers,index);

        for (iterator = list_ids; iterator; iterator = iterator->next) {
            rides_nr++;
            ride_id = get_ride_index(stats,iterator->data);
            distance = 0;
            
            total_av += get_rides_score_driver(rides,ride_id);
            distance += get_rides_distance(rides,ride_id);

            ride_spent = get_rides_tip(rides,ride_id) + tariff(car_class,distance);
            money_s += ride_spent;
        }

        free(car_class);
    }


    else {
        flag = "user";
        index = get_person_index(stats,id,"user");

        list_ids = get_name_hash(stats,id,"user");
        if (list_ids == NULL)
            return create_result(0,0,0,0,0,"");

        if(!is_user_active(users,index))
            return create_result(0,0,0,0,0,"");

        name = get_users_user_name(users,index);
        gender = get_users_user_gender(users,index);
        date = get_users_birth_date(users,index);

        for (iterator = list_ids; iterator; iterator = iterator->next) {
            rides_nr++;

            char* this_driver;

            distance = 0;
            ride_id = get_ride_index(stats,iterator->data);
            this_driver = get_rides_ride_driver_id(rides,ride_id);
            char* driver_car_class = get_drivers_car_class(drivers,get_person_index(stats,this_driver,"driver"));

            total_av += get_rides_score_user(rides,ride_id);
            distance += get_rides_distance(rides,ride_id);

            ride_spent = get_rides_tip(rides,ride_id) + tariff(driver_car_class,distance);
            money_s += ride_spent;

            free(this_driver);
            free(driver_car_class);
        }

    }
        age = find_age(date);
        av_media = (double)total_av / (double)rides_nr;

        RESULT result = create_result(index,age,av_media,rides_nr,money_s,flag);

        free(name); 
        free(gender); 
        free(date);

        return result;
}

/**
 * \brief Auxiliar to query 2
 */
PARAM query2_aux(STATS stats, DRIVERS drivers, RIDES rides, char* line){
    strsep(&line, " ");

    int size = atoi(strsep(&line, " "));
    if (size <= 0)
        return NULL;
    PARAM param = create_param(size);

    for(int i=0; i<get_length_drivers(drivers); i++){
        if (is_driver_active(drivers,i)){
            char* driver_id = get_drivers_driver_id(drivers,i);
            char* name = get_drivers_driver_name(drivers,i);
            void* ids = get_name_hash(stats,driver_id,"driver");
            char* date = last_ride_date(stats,ids,rides);
            double value = media_av(stats,ids,rides); 
        
            insert_param(param,driver_id,value,date,name,0);
        }
    }

    sort_param(param,0);

    return param;
}

/**
 * \brief Auxiliar to query 3
 */
PARAM query3_aux(STATS stats, USERS users, RIDES rides, char* line){
    strsep(&line, " ");

    int size = atoi(strsep(&line, " "));
    if (size <= 0)
        return NULL;
    PARAM param = create_param(size);

    for(int i=0; i<get_length_users(users); i++){
        if (is_user_active(users,i)){
            char* username = get_users_username(users,i);
            char* name = get_users_user_name(users,i);
            void* ids = get_name_hash(stats,username,"user");
            char* date = last_ride_date(stats,ids, rides);
            double value = total_distance(stats,ids,rides);
        
            insert_param(param,username,value,date,name,0);
        }
    }

    sort_param(param, 0);

    return param;
}

/**
 * \brief Auxiliar to query 4
 */
double query4_aux(STATS stats, CITY_STATS city_stats, RIDES rides, DRIVERS drivers, char* line){
    strsep(&line, " ");

    char* city = change_char(strsep(&line, " "));

    double price = 0;

    int nr = 0;

    CITY this_city = get_city_stats(city_stats,city);
    if (this_city == NULL)
        return 0;
    int* rides_ids = get_city_rides_ids(this_city);

    for(int i = 0; i<get_city_rides_length(this_city); i++){
        int index = rides_ids[i];
        int distance = get_rides_distance(rides,index);
        char* driver_id = get_rides_ride_driver_id(rides,index);
        int driver_index = get_person_index(stats,driver_id,"driver");
        char* car_class = get_drivers_car_class(drivers,driver_index);
        price += tariff(car_class,distance);
        nr++;

        free(car_class);
        free(driver_id);
    }

    return nr > 0 ? (price / (double)nr) : 0;
}

/**
 * \brief Auxiliar to query 5
 */
double query5_aux(STATS stats, RIDES rides, DRIVERS drivers, char* line){
    strsep(&line, " ");
    char* date1 = change_date_format(strsep(&line, " "));
    char* date2 = change_date_format(change_char(strsep(&line, " ")));

    double price = 0;
    int nr = 0;
    int id;
    int distance;

     for(int i = 0; i<get_length_rides(rides); i++){
        char* this_date = get_rides_date(rides,i);
        char* this_date_changed = change_date_format(this_date);
        if(is_between_dates(this_date_changed,date1,date2)){
            distance = get_rides_distance(rides,i);
            char* driver_id = get_rides_ride_driver_id(rides,i);
            id = get_person_index(stats,driver_id,"driver");
            char* car_class = get_drivers_car_class(drivers,id);
            price += tariff(car_class,distance);
            nr++;
            free(driver_id);
            free(car_class);
        }
        free(this_date);
        free(this_date_changed);
    }
    free(date1);
    free(date2);

    return nr > 0 ? (price / (double)nr) : 0;
}

/**
 * \brief Auxiliar to query 6
 */
double query6_aux(CITY_STATS city_stats, RIDES rides, char* line){
    strsep(&line, " ");
    char* city = strsep(&line, " ");
    char* date1 = change_date_format(strsep(&line, " "));
    char* date2 = change_date_format(change_char(strsep(&line, " ")));

    int distance = 0;
    int nr = 0;

    CITY this_city = get_city_stats(city_stats,city);
    if (this_city == NULL){
        free(date1);
        free(date2);
        return 0;
    }

    int* rides_ids = get_city_rides_ids(this_city);

    for(int i = 0; i<get_city_rides_length(this_city); i++){
        int index = rides_ids[i];
        char* date = get_rides_date(rides,index);
        char* date_changed = change_date_format(date);
        if(is_between_dates(date_changed,date1,date2)){
            nr++;
            distance += get_rides_distance(rides,index);
        }
        free(date);
        free(date_changed);
    }

    free(date1);
    free(date2);

    return nr > 0 ? ((double)distance / (double)nr) : 0;
}

/**
 * \brief Auxiliar to query 7
 */
PARAM query7_aux(STATS stats, DRIVERS drivers, RIDES rides, char* line){
    strsep(&line, " ");
    int size = atoi(strsep(&line," "));
    if (size == 0)
        return NULL;
    char* city = change_char(strsep(&line," "));

    PARAM param = create_param(size);
    
    for(int i=0; i<get_length_drivers(drivers); i++){
        if (is_driver_active(drivers,i)){
            char* driver_id = get_drivers_driver_id(drivers,i);
            char* name = get_drivers_driver_name(drivers,i);
            
            void* ids = get_name_hash(stats,driver_id,"driver");

            double value = media_av_city(stats,ids,rides,city);

            if (value > 0)
                insert_param(param,driver_id,value,strdup(driver_id),name,1);

            else {
                free(driver_id);
                free(name);
            }
        }
    }

    int length = get_param_arrays_length(param);
    if (length == 0) {
        destroy_param(param);
        return NULL;
    }

    sort_param(param,1);

    return param;
}

/**
 * \brief Auxiliar to query 8
 */
PARAM query8_aux (STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line) {
    strsep(&line, " ");
    char* gender = strsep(&line, " ");
    int years = atoi(strsep(&line, " "));

    if (strcmp(gender,"M") && strcmp(gender,"F"))
        return NULL; 

    ALL_RIDES all_rides = create_all_rides();

    for(int i=0; i<get_length_rides(rides);i++){
        char* driver_id = get_rides_ride_driver_id(rides,i);
        char* user_id = get_rides_user(rides,i);

        int driver_index = get_person_index(stats, driver_id, "driver");
        int user_index = get_person_index(stats, user_id, "user");

        char* driver_gender = get_drivers_driver_gender(drivers, driver_index);
        char* user_gender = get_users_user_gender(users,user_index);

        char* driver_date = get_drivers_account_creation(drivers,driver_index);
        char* user_date = get_users_account_creation(users,user_index);

        if(is_driver_active(drivers,driver_index) && is_user_active(users,user_index))
            if(!strcmp(driver_gender,gender) && !strcmp(user_gender,gender) && find_age(driver_date) >= years && find_age(user_date) >= years)
                add_all_rides_ride(all_rides,i);

        free(driver_id);
        free(user_id);
        free(driver_gender);
        free(user_gender);
        free(driver_date);
        free(user_date);
    }

    if (all_rides->rides_length == 0) {
        destroy_all_rides(all_rides);
        return NULL;
    }

    PARAM param = create_param(all_rides->rides_length);

    for(int i=0; i<all_rides->rides_length;i++){
        int index = all_rides->rides_ids[i];

        char* driver_id = get_rides_ride_driver_id(rides,index);
        char* user_id = get_rides_user(rides,index);

        int driver_index = get_person_index(stats, driver_id, "driver");
        int user_index = get_person_index(stats, user_id, "user");

        char* ride_id = get_rides_ride_id(rides,index);
        char* driver_date = get_drivers_account_creation(drivers,driver_index);
        char* user_date = get_users_account_creation(users,user_index);
        char* user_name = get_users_user_name(users,user_index);

        char* user_date_changed = change_date_format(user_date);
        char* driver_date_changed = change_date_format(driver_date);

        char* longest_user = int_to_string(99999999 - atoi(user_date_changed));
        double longest_driver = (double)(99999999 - atoi(driver_date_changed));

        insert_param(param,ride_id,longest_driver,longest_user,user_name,0);

        free(driver_id);
        free(user_id);
        free(user_date);
        free(driver_date);
        free(user_date_changed);
        free(driver_date_changed);
    }

    sort_param(param,0);

    destroy_all_rides(all_rides);

    return param;
}

/**
 * \brief Auxiliar to query 9
 */
PARAM query9_aux (RIDES rides, char* line) {
    strsep(&line, " ");

    char* date1 = change_date_format(strsep(&line, " "));
    char* date2 = change_date_format(change_char(strsep(&line, " ")));

    ALL_RIDES all_rides = create_all_rides();

    for(int i=0; i<get_length_rides(rides);i++){
        char* this_date = get_rides_date(rides,i);
        char* this_date_changed = change_date_format(this_date);
        if(is_between_dates(this_date_changed,date1,date2)){
            double tip = get_rides_tip(rides,i);
            if (tip > 0)
                add_all_rides_ride(all_rides,i);
        }
        free(this_date);
        free(this_date_changed);
    }

    free(date1);
    free(date2);

    if (all_rides->rides_length == 0){

        destroy_all_rides(all_rides);
        return NULL;
    }

    PARAM param = create_param(all_rides->rides_length);

    for(int i=0; i<all_rides->rides_length;i++){
        int index = all_rides->rides_ids[i];

        char* ride_id = get_rides_ride_id(rides,index);
        char* city = get_rides_city(rides,index);
        char* date = get_rides_date(rides,index);
        char* date_changed = change_date_format(date);
        double dist = (double)get_rides_distance(rides,index);

        insert_param(param,ride_id,dist,date_changed,city,1);

        free(date);
    }

    sort_param(param,1);

    destroy_all_rides(all_rides);

    return param;
}
