
/*
 *	Nome: Giovanni Attina do Nascimento NºUSP: 9286614
 *
 *	Trabalho implementado utilizando as informações dadas no arquivo de PDF presente no RunCodes
*/
#include "skip_list.h"

char *add_item(char *antigo, char *novo){

	int tam_antigo, tam_novo;

	tam_novo = strlen(novo);
	if(antigo == NULL){
		tam_antigo = 0;
	}
	else tam_antigo = strlen(antigo);

	char *retorno  = (char*)malloc(sizeof(char)* 1000);
	if(tam_antigo > 0){// se ja tiver alguma coisa no antigo

		//subescreve antigo no retorno
		for(int i = 0; i < tam_antigo; i++) {
			retorno[i] = antigo[i];
		}

		retorno[tam_antigo] = ' ';
		//passa o novo para o antigo
		for (int i = tam_antigo+1, j = 0; i <= tam_antigo+tam_novo; i++, j++) {
			retorno[i] = novo[j];
		}
	}else{//se nao tiver nada em antigo

		for(int i = 0; i < tam_novo; i++) retorno[i] = novo[i];
	}


	return retorno;
}

t_data *recebe_analiza(char *linha){
	int r, pos, bytes, item;
	char *palavra = (char*)malloc(sizeof(300));
	t_data *retorno = (t_data*)calloc(1 ,sizeof(t_data));


	/*
	 *	item 0 -> chave
	 *	item 1 -> conteudo
	 */
	pos = 0; item = 0;
	while((r = sscanf(&linha[pos], "%s %n", palavra, &bytes)) != EOF){
		if (r == 1) {
			switch (item) {
				case 0:
					retorno->chave =  add_item(retorno->chave, palavra);
					item++;
					break;
				case 1:
					retorno->conteudo =  add_item(retorno->conteudo, palavra);
					break;
			}

		}
		pos += bytes;

	}

	return retorno;
}

char *acao_lista(char *analiza, int *final){
	int controle = *final;
	char *acao = (char*)malloc(sizeof(char) * 20);

	while(analiza[controle] != 32){
		acao[controle] = analiza[controle];
		controle++;
	}
	*final = controle;
	return acao;
}

void lista(t_lista *t, char *operacao, t_data *dado){

	int aux;

	if(strcmp(operacao, "insercao") == 0){
		//printf("INSERE\n");
		aux = insere(t, dado);
		if(aux != 0){
			printf("OPERACAO INVALIDA\n");
		}

	}else if(strcmp(operacao, "remocao") == 0){
		//printf("DELETA\n");
		aux = deleta(t, dado);
		if(aux != 0){
			printf("OPERACAO INVALIDA\n");
		}

	}else if(strcmp(operacao, "busca") == 0){
		//printf("BUSCA\n");
		aux = busca(t, dado);
		if(aux != 0){
			printf("OPERACAO INVALIDA\n");
		}
	}else if(strcmp(operacao, "alteracao") == 0){
		//printf("ALTERA\n");
		aux = altera_conteudo(t, dado);
		if(aux != 0){
			printf("OPERACAO INVALIDA\n");

		}
	}else if(strcmp(operacao, "impressao") == 0){
		aux = busca_letra(t, dado->chave);
		if(aux != 0){
			printf("OPERACAO INVALIDA\n");

		}
	}
}


#define recebe_linha(linha) {\
 fgets(linha, 1001, stdin);\
 if(linha[strlen(linha) -1] == '\n') linha[strlen(linha) -2] = '\0';\
 }


int main(){

	char linha[1001], *acao;
	int para;
	t_data *res;
	t_lista *l;
	l = cria();
	do {
			para = 0;

		 recebe_linha(linha);
		 printf("%s\n", linha);
		 acao = acao_lista(linha, &para);
		 res = recebe_analiza(&(linha[para]));
		 //printf("chave %s\n", res->chave);
		 //printf("conteudo %s\n", res->conteudo);

		 lista(l ,acao, res);
		 /*printf("------------------\n");
		 printf("MINHA LISTA\n");
		 print_lista(l);
		 printf("-----------------\n");
		 printf("\n \n");*/

	}while(!feof(stdin) && linha[0] != '\n');


	return 0;
}
