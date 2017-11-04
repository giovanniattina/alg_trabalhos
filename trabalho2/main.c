
/*
 *	Nome: Giovanni Attina do Nascimento NºUSP: 9286614
 *
 *	Trabalho implementado utilizando as informações dadas no arquivo de PDF presente no RunCodes
*/
#include "skip_list.h"
#include "funcoes.h"


int main(){

	char linha[1001], *acao;
	char *linhaAntiga = (char*)calloc(1001, sizeof(char));
	int para;
	t_data *res;
	t_lista *l;
	l = cria();
	//srand(time(NULL));

	do {
			para = 0;


		 if(linhaAntiga != 0){
			 strcpy(linha, linhaAntiga);

		 }
		 recebe_linha(linha);
		 //printf("%s\n", linha);
		 if(strcmp(linha, linhaAntiga) == 0){
			 break;
		 }
		 acao = acao_lista(linha, &para);
		 res = recebe_analiza(&(linha[para]));


		 lista(l ,acao, res);


	}while(!feof(stdin));

	//free_lista(l);
	return 0;
}
