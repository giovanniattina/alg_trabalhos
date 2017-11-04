#include "skip_list.h"




char *add_item(char *antigo, char *novo, int sobescreve){

	int tam_antigo, tam_novo;

	tam_novo = strlen(novo);

	char *retorno  = (char*)malloc(sizeof(char)* 1000);
	if(antigo != 0 && sobescreve == 1){
		//subescreve antigo no retorno
		tam_antigo = 0;

		while(antigo[tam_antigo] != '\0'){
			retorno[tam_antigo] = antigo[tam_antigo];
			tam_antigo++;
		}

		retorno[tam_antigo] = ' ';
		//passa o novo para o antigo
		for (int i = tam_antigo+1, j = 0; i <= tam_antigo+tam_novo; i++, j++)
			retorno[i] = novo[j];
	}else{
		for(int i = 0; i < tam_novo; i++) retorno[i] = novo[i];
	}




	return retorno;
}

t_data *recebe_analiza(char *linha){
	int r, pos, bytes, item, sobre;
	char *palavra = (char*)malloc(sizeof(300));
	t_data *retorno = (t_data*)calloc(1 ,sizeof(t_data));

	/*
	 *	item 0 -> chave
	 *	item 1 -> conteudo
	 */
  sobre = 0;
	pos = 0; item = 0;
	while((r = sscanf(&linha[pos], "%s %n", palavra, &bytes)) != EOF){
		if (r == 1) {
			switch (item) {
				case 0:
					retorno->chave =  add_item(retorno->chave, palavra, 0);
					item++;
					break;
				case 1:
					retorno->conteudo =  add_item(retorno->conteudo, palavra, sobre);
          sobre = 1;
					break;
			}

		}
		pos += bytes;

	}

	return retorno;
}

char *acao_lista(char *analiza, int *final){
	//int controle = *final;
	//
	char *acao = (char*)malloc(sizeof(char) * 20);
	int r, bytes;
	while((r = sscanf(&analiza[*final], "%s %n", acao, &bytes)) != EOF){
		if (r == 1) {
			*final = *final + bytes;
				return acao;
		}



	}

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
