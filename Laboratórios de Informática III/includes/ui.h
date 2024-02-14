#ifndef UI_H
#define UI_H

#include "util.h"

void print_menu();
void print_subMenu();
char* get_query_IO();
int get_opt();
char* choose_path();
void print_curr_page(int curr_page, int length);
void print_division();
void print_optionsTotal();
void print_optionsInit();
void print_optionsFinal();
int advance_page();
void tests_UI();
void print_results (int test_option, double *time, int* compare);

#endif
