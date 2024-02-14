#ifndef DATES_H
#define DATES_H

#include "util.h"

int is_before(char* date1, char*date2);
char* change_date_format (char* date);
int is_between_dates(char* date, char* date1, char* date2);
int find_age(char* date);

#endif
