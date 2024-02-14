#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "../includes/execution.h"

/**
 * \brief Query 1 time
 */
double query1_time (char* file, STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line){
    clock_t start, end;
    start = clock();

    query1 (file, stats, users, drivers, rides, line);

    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

/**
 * \brief Query 2 time
 */
double query2_time (char* file, STATS stats, DRIVERS drivers, RIDES rides, char* line){
    clock_t start, end;
    start = clock();

    query2 (file, stats, drivers, rides, line); 

    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

/**
 * \brief Query 3 time
 */
double query3_time (char* file, STATS stats, USERS users, RIDES rides, char* line){
    clock_t start, end;
    start = clock();

    query3 (file, stats, users, rides, line); 

    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

/**
 * \brief Query 4 time
 */
double query4_time (char* file, STATS stats, CITY_STATS city_stats, RIDES rides, DRIVERS drivers, char* line){
    clock_t start, end;
    start = clock();

    query4 (file, stats, city_stats, rides, drivers, line);

    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

/**
 * \brief Query 5 time
 */
double query5_time (char* file, STATS stats, RIDES rides, DRIVERS drivers, char* line){
    clock_t start, end;
    start = clock();

    query5 (file, stats, rides, drivers, line);

    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

/**
 * \brief Query 6 time
 */
double query6_time (char* file, CITY_STATS city_stats, RIDES rides, char* line){
    clock_t start, end;
    start = clock();

    query6 (file, city_stats, rides, line);

    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

/**
 * \brief Query 7 time
 */
double query7_time (char* file, STATS stats, DRIVERS drivers, RIDES rides, char* line){
    clock_t start, end;
    start = clock();

    query7 (file, stats, drivers, rides, line);

    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

/**
 * \brief Query 8 time
 */
double query8_time (char* file, STATS stats, USERS users, DRIVERS drivers, RIDES rides, char* line){
    clock_t start, end;
    start = clock();

    query8 (file, stats, users, drivers, rides, line);

    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

/**
 * \brief Query 9 time
 */
double query9_time (char* file, STATS stats, RIDES rides, char* line){
    clock_t start, end;
    start = clock();

    query9 (file, stats, rides, line);

    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

/**
 * \brief Chooses te query to execute
 */
double choose_execution(int query_id, STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides) {
    double result;
    char* query;
    switch(query_id) {
        case 1: result = query1_time("Resultados/command1_output.txt",stats,users,drivers,rides,query = strdup("1 AfoCastro81")); break;
        case 2: result = query2_time("Resultados/command2_output.txt",stats,drivers,rides,query = strdup("2 100")); break;
        case 3: result = query3_time("Resultados/command3_output.txt",stats,users,rides,query = strdup("3 0")); break;
        case 4: result = query4_time("Resultados/command4_output.txt",stats,city_stats,rides,drivers,query = strdup("4 Braga")); break;
        case 5: result = query5_time("Resultados/command5_output.txt",stats,rides,drivers,query = strdup("5 19/03/2015 16/01/2016")); break;
        case 6: result = query6_time("Resultados/command6_output.txt",city_stats,rides,query = strdup("6 Braga 25/07/2015 08/01/2016")); break;
        case 7: result = query7_time("Resultados/command7_output.txt",stats,drivers,rides,query = strdup("7 100 NoSuchCity")); break;
        case 8: result = query8_time("Resultados/command8_output.txt",stats,users,drivers,rides,query = strdup("8 F 12")); break;
        case 9: result = query9_time("Resultados/command9_output.txt",stats,rides,query = strdup("9 13/10/2021 13/10/2021")); break;
        case 11: result = query1_time("Resultados/command1_output.txt",stats,users,drivers,rides,query = strdup("1 000000003412")); break;
        case 12: result = query2_time("Resultados/command2_output.txt",stats,drivers,rides,query = strdup("2 30")); break;
        case 13: result = query3_time("Resultados/command3_output.txt",stats,users,rides,query = strdup("3 30")); break;
        case 14: result = query4_time("Resultados/command4_output.txt",stats,city_stats,rides,drivers,query = strdup("4 Setúbal")); break;
        case 15: result = query5_time("Resultados/command5_output.txt",stats,rides,drivers,query = strdup("5 29/08/2007 13/09/2008")); break;
        case 16: result = query6_time("Resultados/command6_output.txt",city_stats,rides,query = strdup("6 NoSuchCity 25/07/2015 08/01/2016")); break;
        case 17: result = query7_time("Resultados/command7_output.txt",stats,drivers,rides,query = strdup("7 100 Porto")); break;
        case 18: result = query8_time("Resultados/command8_output.txt",stats,users,drivers,rides,query = strdup("8 M 12")); break;
        case 19: result = query9_time("Resultados/command9_output.txt",stats,rides,query = strdup("9 13/10/2025 13/10/2026")); break;
        default: break;
    }

    free(query);
    return result;
}

/**
 * \brief Fills the times array
 */
double* fill_times(STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, int flag){
    double* result = malloc(9*sizeof(double));
    if (flag == 1) {
        for (int i=0; i<9; i++) {
            result[i] = choose_execution(i+1,stats,city_stats,users,drivers,rides);
        }
    }

    else {
        for (int i=0; i<9; i++) {
            result[i] = choose_execution(i+11,stats,city_stats,users,drivers,rides);
        }
    }


    return result;
}

/**
 * \brief Fills the comparing array
 */
int* fill_compare(int flag) {
    int* compare = malloc(9*sizeof(int));
    for (int i=0; i<9; i++)
        compare[i] = compare_files(flag,i+1);

    return compare;
}

/**
 * \brief Compares two files
 */
int compare_files(int option, int query){
    char expected[64];
    snprintf(expected, 64, "testes/op %d/command%d_output.txt", option, query);
    char result[64];
    snprintf(result, 64, "Resultados/command%d_output.txt", query);
    FILE *exp = fopen(expected, "r");
    FILE *res = fopen(result, "r");
    char ch1 = getc(exp);
    char ch2 = getc(res);
    while(ch1 != EOF && ch2 != EOF){
        if(ch1 != ch2) {
            fclose(exp);
            fclose(res);
            return 0;
        }
        ch1 = getc(exp);
        ch2 = getc(res);
    }

    fclose(exp);
    fclose(res);
    
    if(ch1 != EOF || ch2 != EOF) 
        return 0;
    return 1;
}

/**
 * \brief Makes and prints the results
 */
void start_tests(STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, int flag){
    double* time = fill_times(stats,city_stats,users,drivers,rides,flag);
    int* compare = fill_compare(flag);

    print_results(flag,time,compare);
    free(time);
    free(compare);
}

/**
 * \brief Loads the datasets
 */
void load_it(char* path, int flag){
    clear();
    clock_t startU, startD, startR, endU, endD, endR;

    STATS stats = create_stats();
    CITY_STATS city_stats = create_city_stats();

    startU = clock();
    USERS users = read_users(path, stats);
    endU = clock();
    printf("Users dataset load time: %f seconds\n\n", (double) (endU - startU) / CLOCKS_PER_SEC);

    startD = clock();
    DRIVERS drivers = read_drivers(path, stats);
    endD = clock();
    printf("Drivers dataset load time: %f seconds\n\n", (double) (endD - startD) / CLOCKS_PER_SEC);

    startR = clock();
    RIDES rides = read_rides(path, stats, city_stats);
    endR = clock();
    printf("Rides dataset load time: %f seconds\n", (double) (endR - startR) / CLOCKS_PER_SEC);

    start_tests(stats,city_stats,users,drivers,rides,flag);

    destroy_stats(stats);
    destroy_city_stats(city_stats);
    destroy_users(users);
    destroy_drivers(drivers);
    destroy_rides(rides);
}

/**
 * \brief Inits the proccess
 */
void init_tests(){
    tests_UI();
    int option = get_opt();
    while(option < 1 || option > 2){
        printf("Opção inválida! ");
        option = get_opt();
    }

    switch(option){
        case 1: load_it("dataset/data-regular",option); break;
        case 2: load_it("dataset/data-regular-errors",option); break;
        default: break;
    }
}