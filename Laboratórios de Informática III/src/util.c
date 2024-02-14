#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "../includes/util.h"


/**
 * \brief Connects two strings
 */
char* str_connect(char* path, char* file){
	char* all = malloc(64);
	strcpy(all,path);
	strcat(all,file);

	return all;
}

/**
 * \brief Changes the positions of two elements in an array from their given pointers
 */
void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * \brief Removes "\n" from a string
 */
char* change_char(char* word){
    int i;
    for (i=0; word[i] != '\n' && i<(int)strlen(word) ; i++);
    word[i] = '\0';

    return word;
}

/**
 * \brief Returns the "upper" word
 */
char* toUpper_string(char* word) {
    int i = 0;

    char* result = malloc(strlen(word)+1);

    while (word[i]){
        result [i] = toupper(word[i]);
        i++;
    }
    result[i] = '\0';

    return result;
}

/**
 * \brief Converts an int into its string
 */
char* int_to_string(int num){

    int length = snprintf(NULL,0,"%d",num);
    char* str = malloc(length + 1);
    snprintf(str,length + 1,"%d",num);

    return str;
}

/**
 * \brief Clears the shell window
 */
void clear(){
    system("clear");
}
