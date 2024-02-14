#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <glib.h>

#include "../includes/cat_drivers.h"

/**
 * \brief Drivers arrat - Catalog
 */
struct cat_drivers{
    DRIVER* driver;
    int length;
    int size;
};

/**
 * \brief Creates the drivers catalog
 */
DRIVERS create_drivers(){
    DRIVERS drivers = calloc(1, sizeof(*drivers));
    drivers->length = 0;
    drivers->size = 100;
    drivers->driver = calloc(drivers->size, sizeof(drivers->driver));
    return drivers;
}

/**
 * \brief Adds driver to the drivers catalog
 */
void add_driver(DRIVER driver, DRIVERS drivers){
    if(drivers->size == drivers->length){                                                                              
        drivers->size *= 2;                                                                                                           
        drivers->driver = realloc(drivers->driver, drivers->size*sizeof(drivers->driver));
    }
    drivers->driver[drivers->length++] = driver;
}

/**
 * \brief Removes the drivers catalog
 */
void destroy_drivers(DRIVERS drivers){
    for(int i=0; i<drivers->length; i++){
        destroy_driver(drivers->driver[i]);
    }  

    free(drivers->driver);
    free(drivers);
}

/**
 * \brief Returns the length of the drivers catalog
 */
int get_length_drivers(DRIVERS drivers){
    return drivers->length;
}

/**
 * \brief Returns the id of the driver located at index "i" of the catalog
 */
char* get_drivers_driver_id(DRIVERS drivers, int i) {
    return get_driver_id(drivers->driver[i]);
}

/**
 * \brief Returns the name of the driver located at index "i" of the catalog
 */
char* get_drivers_driver_name(DRIVERS drivers, int i) {
    return get_driver_name(drivers->driver[i]);
}

/**
 * \brief Returns the birthday of the driver located at index "i" of the catalog
 */
char* get_drivers_birthday(DRIVERS drivers, int i) {
    return get_birthday(drivers->driver[i]);
}

/**
 * \brief Returns the gender of the driver located at index "i" of the catalog
 */
char* get_drivers_driver_gender(DRIVERS drivers, int i) {
    return get_driver_gender(drivers->driver[i]);
}

/**
 * \brief Returns the car class of the driver located at index "i" of the catalog
 */
char* get_drivers_car_class(DRIVERS drivers, int i) {
    return get_car_class(drivers->driver[i]);
}

/**
 * \brief Returns the license plate of the driver located at index "i" of the catalog
 */
char* get_drivers_license_plate(DRIVERS drivers, int i) {
    return get_license_plate(drivers->driver[i]);
}

/**
 * \brief Returns the city of the driver located at index "i" of the catalog
 */
char* get_drivers_driver_city(DRIVERS drivers, int i) {
    return get_driver_city(drivers->driver[i]);
}

/**
 * \brief Returns the Account Creation of the driver located at index "i" of the catalog
 */
char* get_drivers_account_creation(DRIVERS drivers, int i) {
    return get_driver_account_creation(drivers->driver[i]);
}

/**
 * \brief Returns the Account Status of the driver located at index "i" of the catalog
 */
char* get_drivers_driver_account_status(DRIVERS drivers, int i) {
    return get_driver_account_status(drivers->driver[i]);
}

/**
 * \brief Parsing the drivers.csv file into a drivers catalogue
 */
DRIVERS read_drivers(char* path, STATS stats) {
    char* file = str_connect(path,"/drivers.csv");
    FILE* data_file = fopen(file,"r");
    free(file);

    if(data_file == NULL){
        printf("»»» Error opening DRIVERS dataset «««\n");
        fclose(data_file);
        exit(1);
    }

    else{
        char* line = NULL;
        size_t size = 0;
        DRIVERS drivers = create_drivers();
        getline(&line,&size, data_file);
        while (getline(&line,&size, data_file) != -1){
            DRIVER driver = create_driver(line);
            if(driver_valid(driver)){
                add_driver(driver,drivers);
                add_person_index(stats, get_driver_id(driver), drivers->length-1, "driver");
            }
            else
                destroy_driver(driver);
        }
        free(line);

        printf("»»» DRIVERS dataset loaded «««\n");
        fclose(data_file);

        return drivers;
    } 
}
