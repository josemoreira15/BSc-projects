#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <glib.h>

#include "../includes/param_queries.h"

/**
 * \brief PARAM struct
 **/
struct param {
	char** ids;
	double* values;
	char** dates;
	char** names;

	int arrays_size;
	int arrays_length;
};

/**
 * \Creates PARAM struct
 **/
PARAM create_param(int size){
	PARAM param = (PARAM) malloc(sizeof(*param));

	param->arrays_size = size;
	param->arrays_length = 0;
	param->ids = calloc(param->arrays_size,sizeof(param->ids));
	param->values = calloc(param->arrays_size,sizeof(param->values));
	param->dates = calloc(param->arrays_size,sizeof(param->values));
	param->names = calloc(param->arrays_size,sizeof(param->values));

	return param;
}

/**
 * \Destroys/Frees PARAM struc
 **/
void destroy_param(PARAM param){
	for(int i=0;i<param->arrays_size;i++)
		free(param->ids[i]);
	free(param->ids);

	free(param->values);
	
	for(int i=0;i<param->arrays_size;i++)
		free(param->dates[i]);
	free(param->dates);

	for(int i=0;i<param->arrays_size;i++)
		free(param->names[i]);
	free(param->names);

	free(param);
}

/**
 * \Returns the ids of the PARAM struct
 **/
char** get_param_ids(PARAM param){
	return param->ids;
}

/**
 * \Returns the values of the PARAM struct
 **/
double* get_param_values(PARAM param){
	return param->values;
}

/**
 * \Returns the dates of the PARAM struct
 **/
char** get_param_dates(PARAM param){
	return param->dates;
}

/**
 * \Returns the names of the PARAM struct
 **/
char** get_param_names(PARAM param){
	return param->names;
}

/**
 * \Returns the size of the PARAM struct arrays
 **/
int get_param_arrays_size(PARAM param) {
	return param->arrays_size;
}

/**
 * \Returns the length of the PARAM struct arrays
 **/
int get_param_arrays_length(PARAM param) {
	return param->arrays_length;
}

/**
 * \Finds the min element in a PARAM struct
 **/
int find_min_values(double* values, char** dates, char** ids, int length, int flag){
    int min_index = 0;
    for (int i = 1; i<length; i++){
        if (values[i] < values[min_index])
            min_index = i;
        else if(values[i] == values[min_index]){
        	if(strcmp(dates[i],dates[min_index]) < 0)
            	min_index = i;
        	else if (!strcmp(dates[i],dates[min_index])){
        		if(strcmp(ids[i],ids[min_index]) > 0 && flag == 0)
            		min_index = i;
            	else if(strcmp(ids[i],ids[min_index]) < 0 && flag == 1)
            		min_index = i;
            }
        }
    }

    return min_index;
}

/**
 * \Sorts all PARAM struct arrays
 **/
void insertionSort(double* values, char** dates, char** ids, char** names, int N, int flag) {
	int i,j;
	double value;
	char* date;
	char* id;
	char* name;

	for (i = 1; i < N; i++) {
		value = values[i];
		date = dates[i];
		id = ids[i];
		name = names[i];

		j = i - 1;

		if (flag == 0) {
			while (j >= 0 && (values[j] < value || (values[j] == value && strcmp(dates[j],date) < 0) || (values[j] == value && !strcmp(dates[j],date) && strcmp(ids[j],id) > 0))){
				values[j + 1] = values[j];
				dates[j+1] = dates[j];
				ids[j+1] = ids[j];
				names[j+1] = names[j];
				j--;
			}
		}

		else {
			while (j >= 0 && (values[j] < value || (values[j] == value && strcmp(dates[j],date) < 0) || (values[j] == value && !strcmp(dates[j],date) && strcmp(ids[j],id) < 0))){
				values[j + 1] = values[j];
				dates[j+1] = dates[j];
				ids[j+1] = ids[j];
				names[j+1] = names[j];
				j--;
			}
		}
		values[j + 1] = value;
		dates[j + 1] = date;
		ids[j + 1] = id;
		names[j + 1] = name;
	}
}

/**
 * \Inserts a new element in each PARAM struct array
 **/
void insert_all_params(PARAM param, char* id, double value, char* date, char* name, int index){
	param->values[index] = value;
	free(param->ids[index]);
	param->ids[index] = id;
	free(param->dates[index]);
	param->dates[index] = date;
	free(param->names[index]);
	param->names[index] = name;
}

/**
 * \Compares the given values with the PARAM struct arrays' values to decide if the given values will be inserted
 **/
void insert_param(PARAM param, char* id, double value, char* date, char* name, int flag){
	int insert = 0;
	if(param->arrays_size == param->arrays_length){
		int min = find_min_values(param->values,param->dates, param->names, param->arrays_length, flag);
		if (value > param->values[min]){
			insert_all_params(param,id,value,date,name,min);
			insert = 1;
		}
		else if(param->values[min] == value){
			if(strcmp(date,param->dates[min]) > 0){
				insert_all_params(param,id,value,date,name,min);
				insert = 1;
			}
			else if (!strcmp(date,param->dates[min])){
				if (flag == 0 && strcmp(id,param->ids[min]) < 0){
					insert_all_params(param,id,value,date,name,min);
					insert = 1;
				}
				else if (flag == 1 && strcmp(id,param->ids[min]) > 0){
					insert_all_params(param,id,value,date,name,min);
					insert = 1;
				}
			}
		}	
	}

	else{
		insert_all_params(param,id,value,date,name,param->arrays_length);
		param->arrays_length++;
		insert = 1;
	}

	if (insert == 0){
		free(id);
		free(date);
		free(name);
	}
}

/**
 * \Calls the sort function
 **/
void sort_param(PARAM param, int flag) {
	insertionSort(param->values, param->dates, param->ids, param->names, param->arrays_length, flag);
}

/**
 * \Prints the PARAM struct arrays' elements
 **/
void print_param_queries(PARAM param, char* file, int flag) {
	FILE* final = fopen(file, "w");
	
	if (param != NULL){
		if (flag == 0){
			for(int i=0;i<param->arrays_size; i++){
				fprintf(final,"%s;",param->ids[i]);
				fprintf(final,"%s;",param->names[i]);
				fprintf(final,"%.3f\n",param->values[i]);
			}
		}
		else {
			for(int i=0;i<param->arrays_size; i++){
				fprintf(final,"%s;",param->ids[i]);
				fprintf(final,"%s;",param->names[i]);
				fprintf(final,"%d\n",(int)param->values[i]);
			}
		}
	}

	fclose(final);
}
