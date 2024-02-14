#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "../includes/dates.h"

#define data "09/10/2022"

/**
 * \brief Checks if a date is before another date
 */
int is_before(char* date1, char*date2) {
	if(strcmp(date1,date2) <= 0)
		return 1;
    return 0;
}

/**
 * \Converts a date into a reversed date with no bars : dd/mm/yyyy -> yyyymmdd
 */
char* change_date_format(char* date){
    int index = 0;
    char* result = malloc(11);
    for(int i = 0; i<11;i++){
        if(date[i] != '/'){
            result[index] = date[i];
            index++; 
        }
    }
    result[index] = '\0';

    for(int i = 0; i<4;i++)
        swap(&result[i],&result[i+4]);
    for(int i = 4; i<6;i++)
    swap(&result[i],&result[i+2]);
    
    return result;
}

/**
 * \brief Checks if a date is between other two
 */
int is_between_dates(char* date, char* date1, char* date2){
    if(is_before(date,date2) && is_before(date1,date))
        return 1;
    return 0;
}

/**
 * \brief Calculates the age from the birth date
 */
int find_age(char* date){

    char day[3];
    char month[3];
    char year[5];
    char curr_day[3];
    char curr_month[3];
    char curr_year[5];
    int age, i = 0, m = 0, y = 0;
    
    while(date[i] != '/'){
        day[i] = date[i];
        curr_day[i] = data[i];
        i++;
    }
    day[i] = '\0';
    curr_day[i] = '\0';

    i++;
    while(date[i] != '/'){
        month[m] = date[i];
        curr_month[m] = data[i];
        m++;
        i++;
    }
    month[m] = '\0';
    curr_month[m] = '\0';

    i++;
    while(date[i] != '\0'){
        year[y] = date[i];
        curr_year[y] = data[i];
        y++;
        i++;
    }
    year[y] = '\0';
    curr_year[y] = '\0';
    
    age = atoi(curr_year)-atoi(year);

    int curr_month_int = atoi(curr_month);
    int month_int = atoi(month);

    if(curr_month_int < month_int)
        age--;
    else if(curr_month_int == month_int){
        int curr_day_int = atoi(curr_day);
        int day_int = atoi(day);

        if(curr_day_int < day_int)
            age--;
    }

    return age;
}
