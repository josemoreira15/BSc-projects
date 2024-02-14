#ifndef PAGES_H
#define PAGES_H

#include "queries.h"
#include "ui.h"

typedef struct page *PAGE;
typedef struct pages *PAGES;

PAGE create_page(char* fst, double value, char* snd, char* trd, char* fth, int flag);
void destroy_page(PAGE page);
PAGES create_pages();
PAGES param_to_pages(PARAM param, int flag);
PAGES param_gender_to_pages(STATS stats, PARAM param, DRIVERS drivers, RIDES rides);
PAGES param_tip_to_pages(STATS stats, PARAM param, RIDES rides);
void insert_page(PAGES pages,PAGE page);
void destroy_pages(PAGES pages);
void print_page(PAGE page);
void control(PAGES pages, int curr);
void pages_controller(PAGES pages);

#endif
