#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <glib.h>

#include "../includes/pages.h"

/**
 * \brief PAGE struct
 */
struct page {
	char* fst;
	double value;
	char* snd;
	char* trd;
	char* fth;
	int flag;
};

/**
 * \brief PAGES struct -> array of PAGE
 */
struct pages {
	PAGE *page;
	int size;
	int length;
};

/**
 * \brief Creates a PAGE through 5 given values
 */
PAGE create_page(char* fst, double value, char* snd, char* trd, char* fth, int flag){
	PAGE page = malloc(sizeof(*page));

	page->fst = fst;
	page->value = value;
	page->snd = snd;
	page->trd = trd;
	page->fth = fth;
	page->flag = flag;

	return page;
}

/**
 * \brief Destroys/Frees a PAGE
 */
void destroy_page(PAGE page){
	free(page->fst);
	free(page->snd);
	free(page->trd);
	free(page->fth);

	free(page);
}

/**
 * \brief Creates the struct PAGES
 */
PAGES create_pages(){
	PAGES pages = malloc(sizeof(*pages));

	pages->size = 2;
	pages->length = 0;
	pages->page = calloc(pages->size,sizeof(pages->page));

	return pages;
}

/**
 * \brief Creates the struct PAGES by a given PARAM struct - queries 2, 3 and 7
 */
PAGES param_to_pages(PARAM param, int flag){
	PAGES pages = create_pages();
	char** ids = get_param_ids(param);
	double* values = get_param_values(param);
	char** names = get_param_names(param);

	for(int i=0;i<get_param_arrays_size(param);i++){
		PAGE page = create_page(strdup(ids[i]),values[i],strdup(names[i]),NULL,NULL,flag);
		insert_page(pages,page);
	}
	return pages;	
}

/**
 * \brief Creates the struct PAGES by a given PARAM struct - query 8
 */
PAGES param_gender_to_pages(STATS stats, PARAM param, DRIVERS drivers, RIDES rides) {
	PAGES pages = create_pages();
	char** ids = get_param_ids(param);
	char** names = get_param_names(param);
	int index;

	for(int i=0;i<get_param_arrays_size(param);i++){
		index = get_ride_index(stats,ids[i]);
		char* id_driver = get_rides_ride_driver_id(rides,index);

		int driver_index = get_person_index(stats,id_driver,"driver");
        char* name_driver = get_drivers_driver_name(drivers,driver_index);

        char* id_user = get_rides_user(rides,index);
		PAGE page = create_page(id_driver,0,name_driver,id_user,strdup(names[i]),2);
		insert_page(pages,page);
	}

	return pages;
}

/**
 * \brief Creates the struct PAGES by a given PARAM struct - query 9
 */
PAGES param_tip_to_pages(STATS stats, PARAM param, RIDES rides) {
	PAGES pages = create_pages();
	char** ids = get_param_ids(param);
	double* values = get_param_values(param);
	char** names = get_param_names(param);

	for(int i=0;i<get_param_arrays_size(param);i++){
		int index = get_ride_index(stats,ids[i]);
		double tip = get_rides_tip(rides, index);
        char* date = get_rides_date(rides,index);

        PAGE page = create_page(strdup(ids[i]),tip,date,strdup(names[i]),int_to_string((int)values[i]),3);
        insert_page(pages,page);
    }

    return pages;
}

/**
 * \brief Inserts a PAGE in a struct PAGES
 */
void insert_page(PAGES pages,PAGE page){
	if(pages->size == pages->length){
		pages->size *= 2;
		pages->page = realloc(pages->page,pages->size*sizeof(pages->page));
	}
	pages->page[pages->length++] = page;
}

/**
 * \brief Destroys/Frees a PAGES struct
 */
void destroy_pages(PAGES pages){
	for(int i=0;i<pages->length;i++){
		destroy_page(pages->page[i]);
	}
	free(pages->page);
	free(pages);
}

/**
 * \brief Prints the parameters of the struct PAGE
 */
void print_page(PAGE page){
    if (page->flag < 2){
        printf("\n» ID/Username: %s\n",page->fst);
        printf("» Nome: %s\n",page->snd);
        if (page->flag == 0)
            printf("» Avaliação média: %.3f\n",page->value);
        else
            printf("» Distância total: %dkm\n",(int)page->value);
    }

    else if (page->flag == 2){
        printf("\n» ID do condutor: %s\n",page->fst);
        printf("» Nome do condutor: %s\n",page->snd);
        printf("» Username do utilizador: %s\n",page->trd);
        printf("» Nome do utilizador: %s\n",page->fth);
    }

    else {
    	printf("\n» ID da viagem: %s\n",page->fst);
        printf("» Data da viagem: %s\n",page->snd);
        printf("» Distancia: %s\n",page->fth);
        printf("» Cidade: %s\n",page->trd);
        printf("» Valor da gorjeta: %.3f €\n",page->value);
    }
}

/**
 * \brief Pagination control function
 */
void control(PAGES pages, int curr){ 
    print_division();
    print_page(pages->page[curr-1]);
    print_curr_page(curr,pages->length);
    if(curr == pages->length)
        print_optionsFinal();
    else if(curr == 1)
        print_optionsInit();
    else
        print_optionsTotal();
}

/**
 * \brief Pagination control complete function - iterates through the struct PAGES and prints the requested PAGE, allowing the "go back" option
 */
void pages_controller(PAGES pages){
	int curr = 1;

	print_page(pages->page[curr-1]);
	print_curr_page(curr,pages->length);
	print_optionsInit();
	int opt; 
	while((opt = get_opt())!= 4){
		if(curr == 1){	
			print_optionsInit();
				if(opt == 1){
					curr++;
					clear();
					control(pages,curr);
				}
				else if(opt == 2){
					clear();
					curr = advance_page();
					if (curr <= 0 || curr >= pages->length)
						curr = 1;
					control(pages,curr);
			}
				
		}
		else if(curr == pages->length){
			if(opt == 1){
				curr--;
				clear();
				control(pages,curr);
			}
			else if(opt == 2){
				clear();
				curr = advance_page();
				if (curr <= 0 || curr >= pages->length)
						curr = 1;
				control(pages,curr);
			}
		}
		else{
			if(opt == 1){
				curr--;
				clear();
				control(pages,curr);
			}
			else if(opt == 2){
				curr++;
				clear();
				control(pages,curr);
			}
			else if(opt == 3){
				clear();
				curr = advance_page();
				control(pages,curr);
			}
		}	
	}
}
