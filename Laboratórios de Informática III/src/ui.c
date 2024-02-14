#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/ui.h"

/**
 * \brief Prints the main MENU
 */
void print_menu(){
	printf("===============================================================================================================================\n");		
	printf("||                                              [    MENU    ]                                                               ||\n");
	printf("===============================================================================================================================\n");	
	printf("|| 1  || Resumo de um perfil registado no serviço através do seu identificador   [ID/Username]                               ||\n");
	printf("===============================================================================================================================\n");	
	printf("|| 2  || Top N condutores com maior avaliação média   [N]                                                                    ||\n");
	printf("===============================================================================================================================\n");	
	printf("|| 3  || Top N utilizadores com maior distância viajada   [N]                                                                ||\n");
	printf("===============================================================================================================================\n");	
	printf("|| 4  || Preço médio das viagens numa determinada cidade   [Cidade]                                                          ||\n");
	printf("===============================================================================================================================\n");	
	printf("|| 5  || Preço médio das viagens num dado intervalo de tempo   [dd/mm/aaaa dd/mm/aaaa]                                       ||\n");
	printf("===============================================================================================================================\n");
	printf("|| 6  || Distância média percorrida, numa determinada cidade, num dado intervalo de tempo   [Cidade dd/mm/aaaa dd/mm/aaaa]   ||\n");
	printf("===============================================================================================================================\n");
	printf("|| 7  || Top N condutores numa determinada cidade, com maior avaliação média   [N Cidade]                                    ||\n");
	printf("===============================================================================================================================\n");
	printf("|| 8  || Viagens em que o utilizador e o condutor são de um determinado género e têm perfis com X ou mais anos   [Género X]  ||\n");
	printf("===============================================================================================================================\n");
	printf("|| 9  || Viagens nas quais o passageiro deu gorjeta, num dado intervalo de tempo   [dd/mm/aaaa dd/mm/aaaa]                   ||\n");
	printf("===============================================================================================================================\n");
	printf("|| 10 || Sair                                                                                                                ||\n");
	printf("===============================================================================================================================\n");
	printf("\n");
}

/**
 * \brief Prints the secondary MENU
 */
void print_subMenu(){
	printf("===============================================================================================================================\n");	
	printf("||   1   || Voltar ao MENU                                                                                                   ||\n");
	printf("===============================================================================================================================\n");
	printf("|| Outro || Sair                                                                                                             ||\n");
	printf("===============================================================================================================================\n");
}

/**
 * \brief Reads the input used to execute a query
 */
char* get_query_IO(){
	char* query_param = malloc(32);
	printf("Insira a opção: ");
	scanf(" %[^\n]s",query_param);
	printf("\n");

	return query_param;
}

/**
 * \brief Reads an int option
 */
int get_opt(){
	int opt;
	printf("Selecione a opção pretendida: ");
	scanf("%d",&opt);

	return opt;
}

/**
 * \brief Reads the path to be used in the dataset opening
 */
char* choose_path(){
	clear();

	char* path = malloc(32);
	printf("Indique a path para os datasets: ");
	scanf("%s",path);

	return path;
}

/**
 * \brief Prints the number of the current page in a total number of pages
 */
void print_curr_page(int curr_page, int length){
	printf("\n================================================ PÁGINA %d DE %d ================================================\n",curr_page,length);
}

/**
 * \brief Prints a "division" string
 */
void print_division(){
	printf("\n================================================================================================================\n");
}

/**
 * \brief Prints the options on the pagination window
 */
void print_optionsTotal(){
	printf("\n   [1] - Página anterior   [2] - Próxima página   [3] - Avançar para a página ...   [4] - Voltar\n\n\n");
}

/**
 * \brief Prints the init option on the pagination shell
 */
void print_optionsInit(){
	printf("\n   [1] - Próxima página   [2] - Avançar para a página ...   [4] - Voltar\n\n\n");
}

/**
 * \brief Prints the final option on the pagination shell
 */
void print_optionsFinal(){
	printf("\n   [1] - Página anterior   [2] - Avançar para a página ...   [4] - Voltar\n\n\n");
}

/**
 * \brief Reads the "for what page do you wanna go?" answer
 */
int advance_page(){
	int final_page;

	printf("Para que página deseja avançar? ");
	scanf("%d",&final_page);

	return final_page;
}

/**
 * \brief Prints the available options for the tests
 */
void tests_UI(){
	clear();
    printf("\n                                »»» Opções de teste disponíveis «««\n\n"
         "     » 1ª Opção - regular dataset «                               » 2ª Opção - regular dataset w/ errors «\n\n"
         "   | 1 AfoCastro81                                               | 1 000000003412\n"
         "   | 2 100                                                       | 2 30\n"
         "   | 3 0                                                         | 3 30\n"
         "   | 4 Braga                                                     | 4 Setúbal\n"
         "   | 5 19/03/2015 16/01/2016                                     | 5 29/08/2007 13/09/2008\n"
         "   | 6 Braga 25/07/2015 08/01/2016                               | 6 NoSuchCity 25/07/2015 08/01/2016\n"
         "   | 7 100 NoSuchCity                                            | 7 100 Porto\n"
         "   | 8 F 12                                                      | 8 M 12\n"
         "   | 9 13/10/2021 13/10/2021                                     | 9 13/10/2025 13/10/2026\n\n\n");
}

/**
 * Prints the table with all test results
 */
void print_results (int test_option, double *time, int* compare){
    printf("\n\n\n                »»» Módulo de Testes (Opção %d) - Resultados «««\n\n\n", test_option);
    printf("                  +-------------------+------------------+---------------+\n"
           "       +----------|      Tempo de     |  Comparação dos  |  Execução em  |\n"
           "       | Query ID |      execução     |    resultados    |  tempo útil*  |\n"
           "       +----------+-------------------+------------------+---------------+\n");
    for(int i=0; i<9; i++) { 
    printf("       |     %d    | %f segundos |     %s    |      %s      |\n", i+1, time[i], compare[i] == 0 ? "Incorreto" : " Correto ", time[i] > 10 ? "Não" : "Sim");
    printf("       +----------+-------------------+------------------+---------------+\n" );
    }
    printf("                                                           *(<10 segundos)\n\n\n");
}
