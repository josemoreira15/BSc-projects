#ifndef PARAM_QUERIES_H
#define PARAM_QUERIES_H

#include "cat_users.h"
#include "cat_drivers.h"
#include "cat_rides.h"
#include "dates.h"

typedef struct param *PARAM;

PARAM create_param(int size);
void destroy_param(PARAM param);
char** get_param_ids(PARAM param);
double* get_param_values(PARAM param);
char** get_param_dates(PARAM param);
char** get_param_names(PARAM param);
int get_param_arrays_size(PARAM param);
int get_param_arrays_length(PARAM param);

int find_min_values(double* values, char** dates, char** ids, int length, int flag);
void insertionSort(double* values, char** dates, char** ids, char** names, int N, int flag);
void insert_all_params(PARAM param, char* id, double value, char* date, char* name, int index);
void insert_param(PARAM param, char* id, double value, char* date, char* name, int flag);
void sort_param(PARAM param, int flag);
void print_param_queries(PARAM param, char* file, int flag);

#endif
