#include "skip_list.h"

char *add_item(char *antigo, char *novo, int sobescreve){

	size_t tam_antigo, tam_novo, i, j;
	tam_novo = strlen(novo);

	char *retorno = NULL;
	retorno  = (char*)malloc(sizeof(char)* (200));
	if(antigo != NULL && sobescreve == 1){

		tam_antigo = strlen(antigo);

		//subescreve antigo no retorno
		strcpy(retorno, antigo);
		free(antigo);
		retorno[tam_antigo] = ' ';
		//passa o novo para o antigo
		for (i = tam_antigo+1, j = 0; i <= tam_antigo+tam_novo; i++, j++)
			strcpy(&(retorno[i]), &(novo[j]));

	}else{

		for(i = 0; i < tam_novo; i++) strcpy( &(retorno[i]) , &(novo[i]));
	}
	retorno[i] = '\0';

	return retorno;
}

t_data *recebe_analiza(char *linha){
	int r, pos, bytes, item, sobre;
	char *palavra = (char*)malloc(sizeof(char)*300);
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
	free(palavra);
	return retorno;
}

char *acao_lista(char *analiza, int *final){

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
