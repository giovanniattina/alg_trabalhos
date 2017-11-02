
/*
 *	Nome: Giovanni Attina do Nascimento NºUSP: 9286614
 *
 *	Trabalho implementado utilizando as informações dadas no arquivo de PDF presente no RunCodes
*/
#include "skip_list.h"


t_data *recebe_analiza(char *linha){
	int r, pos, bytes, item;
	char palavra[100];
	t_data *retorno = (t_data*)malloc(sizeof(t_data));
	/*
	 *	item 0 -> operacao a ser feito na lista
	 *	item 1 -> chave na lista

	 */
	pos = 0; item = 0;
	while((r = sscanf(&linha[pos], "%s %n", palavra, &bytes)) != EOF){
		if (r == 1) {
			printf("%s\n", palavra);
			switch (item) {
				case 0:
					item++;
				case 1:
					add_item(retorno->chave, palavra);
			}

		}
		pos += bytes;

	}

	return retorno;
}

int main(){

	char linha[1001];
	t_data *res;


	do {
		 fgets(linha, 1001, stdin);
		 //trata \n
		 if(linha[strlen(linha)-1] == '\n') linha[strlen(linha)-1] = '\0';
		 res = recebe_analiza(linha);
	}while(!feof(stdin));


	return 0;
}
