#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/interface.h"

/**
 * \brief Returns Gives the options that allow to return to the Menu or leave the exec
 */
void retry(STATS stats,CITY_STATS city_stats,USERS users,DRIVERS drivers,RIDES rides){
	printf("\n");
	print_subMenu();
	int opt = get_opt();
	if(opt == 1){
		clear();
		start_query(stats,city_stats,users,drivers,rides);
	}

	else {
		destroy_stats(stats);
    	destroy_city_stats(city_stats);
    	destroy_users(users);
    	destroy_drivers(drivers);
    	destroy_rides(rides);
	}
			
}

/**
 * \brief Starts the pagination of the chosen query
 */
void query_pages(PAGES pages){
	clear();
	print_division();
	pages_controller(pages);
}

/**
 * \brief Query 1 interactive mode
 */
void query1_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, char* query_param){
	RESULT result = query1_aux(stats,users,drivers,rides,query_param);
	free(query_param);
	clear();
	print_result(result,"",users,drivers,1);
	free(result);
	retry(stats,city_stats,users,drivers,rides);
}

/**
 * \brief Query 2 interactive mode
 */
void query2_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, char* query_param){
	PARAM result = query2_aux(stats,drivers,rides,query_param);
	free(query_param);
	if (result == NULL) {
		clear();
		printf("\n»»»»»»»»»»»»» Não há condutores para o top N indicado! «««««««««««««\n");
	}
	else {
		PAGES pages = param_to_pages(result,0);
		query_pages(pages);
		destroy_pages(pages);
		destroy_param(result);
	}
	retry(stats,city_stats,users,drivers,rides);
}

/**
 * \brief Query 3 interactive mode
 */
void query3_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, char* query_param){
	PARAM result = query3_aux(stats,users,rides,query_param);
	free(query_param);
	if (result == NULL){
		clear();
		printf("\n»»»»»»»»»»»»» Não há utilizadores para o top N indicado! «««««««««««««\n");
	}
	else {
		PAGES pages = param_to_pages(result,1);
		query_pages(pages);
		destroy_pages(pages);
		destroy_param(result);
	}
	retry(stats,city_stats,users,drivers,rides);
}	

/**
 * \brief Query 4 interactive mode
 */
void query4_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param){
	double result = query4_aux(stats,city_stats,rides,drivers,query_param);
	free(query_param);
	clear();
	if (result == 0)
		printf("\n»»»»»»»»»»»»» Não há viagens na cidade indicada! «««««««««««««\n");
	else
		printf("\nPreço médio das viagens: %.3f €\n",result);
	retry(stats,city_stats,users,drivers,rides);
}

/**
 * \brief Query 5 interactive mode
 */
void query5_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param){
	double result = query5_aux(stats,rides, drivers, query_param);
	free(query_param);
	clear();
	if (result == 0)
		printf("\n»»»»»»»»»»»»» Não há viagens entre as datas indicadas! «««««««««««««\n");
	else
		printf("\nPreço médio das viagens: %.3f €\n",result);
	retry(stats,city_stats,users,drivers,rides);
}

/**
 * \brief Query 6 interactive mode
 */
void query6_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param){
	double result = query6_aux(city_stats, rides, query_param);
	free(query_param);
	clear();
	if (result == 0)
		printf("\n»»»»»»»»»»»»» Não há viagens na cidade indicada, entre as datas fornecidas! «««««««««««««\n");
	else
		printf("\nDistãncia média percorrida: %.3f km\n",result);
	retry(stats,city_stats,users,drivers,rides);
}

/**
 * \brief Query 7 interactive mode
 */
void query7_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param){
	PARAM result = query7_aux(stats,drivers,rides,query_param);
	free(query_param);
	if (result == NULL) {
		clear();
		printf("\n»»»»»»»»»»»»» Não há condutores para o top N indicado, para a cidade fornecida! «««««««««««««\n");
	}
	else {
		PAGES pages = param_to_pages(result,0);
		query_pages(pages);
		destroy_pages(pages);
		destroy_param(result);
	}
	retry(stats,city_stats,users,drivers,rides);
}

/**
 * \brief Query 8 interactive mode
 */
void query8_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, char* query_param){
	PARAM result = query8_aux(stats,users,drivers,rides,query_param);
	free(query_param);
	if (result == NULL) {
		clear();
		printf("\n»»»»»»»»»»»»» Não há viagens para o género indicado, com idade de conta fornecida! «««««««««««««\n");
	}
	else {
		PAGES pages = param_gender_to_pages(stats, result, drivers, rides);
		query_pages(pages);
		destroy_pages(pages);
		destroy_param(result);
	}
	retry(stats,city_stats,users,drivers,rides);
}

/**
 * \brief Query 9 interactive mode
 */
void query9_output(STATS stats,CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides,char* query_param){
	PARAM result = query9_aux (rides,query_param);
	free(query_param);
	if (result == NULL) {
		clear();
		printf("\n»»»»»»»»»»»»» Não há viagens com gorjeta associada, entre as datas fornecidas! «««««««««««««\n");
	}
	else {
		PAGES pages = param_tip_to_pages(stats, result, rides);
		query_pages(pages);
		destroy_pages(pages);
		destroy_param(result);
	}
	retry(stats,city_stats,users,drivers,rides);
}

/**
 * \brief Redirects to the query function depending on the input
 */
void choose_queryIO(int query_id, STATS stats, CITY_STATS city_stats, USERS users, DRIVERS drivers, RIDES rides, char* query_param){
    switch(query_id){
        case 1: query1_output(stats,city_stats,users,drivers,rides,query_param); break;
        case 2: query2_output(stats,city_stats,users,drivers,rides,query_param); break;
        case 3: query3_output(stats,city_stats,users,drivers,rides,query_param); break;
   		case 4: query4_output(stats,city_stats,users,drivers,rides,query_param); break;
        case 5: query5_output(stats,city_stats,users,drivers,rides,query_param); break;
        case 6: query6_output(stats,city_stats,users,drivers,rides,query_param); break;
        case 7: query7_output(stats,city_stats,users,drivers,rides,query_param); break;
        case 8: query8_output(stats,city_stats,users,drivers,rides,query_param); break;
        case 9: query9_output(stats,city_stats,users,drivers,rides,query_param); break;
        default: free(query_param);destroy_stats(stats); destroy_city_stats(city_stats); destroy_users(users); destroy_drivers(drivers); destroy_rides(rides); break;
    }    
}

/**
 * \brief Query choice
 */
void start_query(STATS stats,CITY_STATS city_stats,USERS users,DRIVERS drivers,RIDES rides){
	printf("\n");
	print_menu();
	char* query_param = get_query_IO();
	int query = atoi(query_param);
	while(query < 1 || query > 10){
		free(query_param);
		printf("Opção inválida! \n");
		query_param = get_query_IO();
		query = atoi(query_param);
	}
	choose_queryIO(query,stats,city_stats,users,drivers,rides,query_param);
}

/**
 * \brief Starts the interface
 */
void start_interface(){
	char* path = choose_path();

	STATS stats = create_stats();
    CITY_STATS city_stats = create_city_stats();
    USERS users = read_users(path, stats);
    DRIVERS drivers = read_drivers(path, stats);
    RIDES rides = read_rides(path, stats, city_stats);
    free(path);

    start_query(stats,city_stats,users,drivers,rides);
}
