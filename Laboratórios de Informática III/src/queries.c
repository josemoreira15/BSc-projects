#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "../includes/queries.h"

/**
 * \brief Query 1
 */
void query1 (char* file, STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line){
    RESULT result = query1_aux(stats,users,drivers,rides,line);
    print_result(result,file,users,drivers,0);
    destroy_result(result);
}

/**
 * \brief Query 2
 */
void query2 (char* file, STATS stats, DRIVERS drivers, RIDES rides, char* line){
    PARAM param = query2_aux(stats,drivers,rides,line);
    print_param_queries(param, file, 0);
    if (param != NULL)
        destroy_param(param); 
}

/**
 * \brief Query 3
 */
void query3 (char* file, STATS stats, USERS users, RIDES rides, char* line){
    PARAM param = query3_aux(stats,users,rides,line);
    print_param_queries(param, file, 1);
    if (param != NULL)
        destroy_param(param); 
}

/**
 * \brief Query 4
 */
void query4 (char* file, STATS stats, CITY_STATS city_stats, RIDES rides, DRIVERS drivers, char* line){
    float result = query4_aux(stats,city_stats,rides,drivers,line);
    FILE* final = fopen(file, "w");
    if (result != 0)
        fprintf(final,"%.3f\n",result);
    fclose(final);
}

/**
 * \brief Query 5
 */
void query5 (char* file, STATS stats, RIDES rides, DRIVERS drivers, char* line){
    float result = query5_aux(stats,rides,drivers,line);
    FILE* final = fopen(file, "w");
    if (result != 0)
        fprintf(final,"%.3f\n",result);
    fclose(final);
}

/**
 * \brief Query 6
 */
void query6 (char* file, CITY_STATS city_stats, RIDES rides, char* line){
    float result = query6_aux(city_stats,rides,line);
    FILE* final = fopen(file, "w");
    if (result != 0)
        fprintf(final,"%.3f\n",result);
    fclose(final);
}

/**
 * \brief Query 7
 */
void query7 (char* file, STATS stats, DRIVERS drivers, RIDES rides, char* line){
    PARAM param = query7_aux(stats,drivers,rides,line);
    print_param_queries(param, file, 0);
    if (param != NULL)
        destroy_param(param);
}

/**
 * \brief Query 8
 */
void query8 (char* file, STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line){
    PARAM param = query8_aux(stats,users,drivers,rides,line);
    print_all_rides_gender(stats,param, drivers, rides, file);
    if (param != NULL)
        destroy_param(param);
}

/**
 * \brief Query 9
 */
void query9 (char* file, STATS stats, RIDES rides, char* line){
    PARAM param = query9_aux(rides,line);
    print_all_rides(stats, param, rides, file);
    if (param != NULL)
        destroy_param(param);
}

/**
 * \brief Choosing the query by its number
 */
void choose_query(int indice, char* line, STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides){
    int id; 
    char file[50];
    id = line[0] - 48;
    snprintf(file, 50, "Resultados/command%d_output.txt", indice);
    switch(id){
        case 1: query1(file,stats,users,drivers,rides,line); break;
        case 2: query2(file,stats,drivers,rides,line); break;
        case 3: query3(file,stats,users,rides,line); break;
        case 4: query4(file,stats,city_stats,rides,drivers,line); break;
        case 5: query5(file,stats,rides,drivers,line); break;
        case 6: query6(file,city_stats,rides,line); break;
        case 7: query7(file,stats,drivers,rides,line); break;
        case 8: query8(file,stats,users,drivers,rides,line); break;
        case 9: query9(file,stats,rides,line); break;
        default: printf("ERROR: INVALID QUERY\n");
    }    
}

/**
 * \brief Parsing input file, "sending" it to the function that will make the right query
 */
void queries(STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, char* commands){
    char* line = NULL;
    int i=1;
    size_t len = 0;
    FILE *commands_file = fopen(commands, "r");
    while(getline(&line, &len, commands_file) != -1){
        choose_query(i, line, stats, city_stats, users, drivers, rides);
        i++;   
    }
    free(line);
    fclose(commands_file);
}
