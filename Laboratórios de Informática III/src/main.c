#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/parsing.h"
#include "../includes/interface.h"

/**
 * \brief Main function
 */
int main(int argc, char* argv[]){
	if(argc == 1){
		printf("[>> Entering interactive mode <<]\n\n");
		start_interface();
	}
	else
		parsing(argv[1], argv[2]);

	return 0;
}
