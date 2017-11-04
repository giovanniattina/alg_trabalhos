#include "skip_list.h"


t_lista *cria(){
	t_lista *t;
	t = (t_lista*)malloc(sizeof(t_lista));

	t->lista = (t_item*)malloc(sizeof(t_item));
	t->lista->p = (t_item**)calloc(MAX+1 , sizeof(t_item*));


	t->nivel = 1;
	t->qnt_item = 0;
	return t;
}

int level_aleatorio(){
	int nivel = 1;
	while (rand() < RAND_MAX/2 && nivel< MAX) nivel ++;
	return nivel;
}

int insere(t_lista *t, t_data *novo){
	t_item **atualizar = (t_item**)malloc(sizeof(t_item)*MAX+1);//salvar ponteiro para item anterior em todos niveis da lista
	t_item *aux = t->lista;//aponta para o primeiro item
	for(int i = t->nivel; i >= 1; i--){//anda por todos os niveis
			while ( aux->p[i] != NULL  && strcmp(aux->p[i]->data->chave, novo->chave) < 0) {//ate acha um item maior ou igual que quero inserir
				printf("%s\n",aux->p[i]->data->chave );
					aux = aux->p[i];
			}
			atualizar[i] = aux;

	}
	aux = aux->p[1]; // item com nivel mais baixo que quero inserir

	if(aux != NULL && strcmp(aux->data->chave, novo->chave) == 0){// se tiver item com a mesma chave que quero inserir da erro

		return 1; //erro
	}else{//se não tiver
		int nivel = level_aleatorio();
		if(nivel > t->nivel){
			for(int i = t->nivel+1; i <= nivel; i++){

				atualizar[i] = t->lista;
			}
			t->nivel = nivel;
		}

		//aloca espaco para o novo item
		aux = (t_item*)malloc(sizeof(t_item));
		aux->data = novo;
		aux->p = (t_item**)calloc(MAX+1, sizeof(t_item*));
		printf("%d\n", nivel);
		for(int i = 1; i <= nivel; i++){//anda por todos os niveis e vai adicionando o novo 	item
			aux->p[i] = atualizar[i]->p[i];
			atualizar[i]->p[i] = aux;
		}

	}
	return 0;//se nao acho um item iguaç e nao teve erro

}

void free_item(t_item *del){
	if(del != NULL){
		free(del->p);
		free(del);
	}
}

int deleta(t_lista *t, t_data *data){

	t_item *atualizar[MAX+1];//salvar ponteiro para item anterior em todos niveis da lista
	t_item *aux = t->lista;//aponta para o primeiro item

	for(int i = t->nivel; i >= 1; i--){//anda por todos os niveis
			while (aux->p[i] != 0 && strcmp(aux->p[i]->data->chave, data->chave) < 0) {//ate acha um item maior ou igual que quero deletar
					aux = aux->p[i];
			}
			atualizar[i] = aux;
	}

	aux = aux->p[1]; // item com nivel mais baixo que quero deletar
	if(aux != NULL && strcmp(aux->data->chave, data->chave) == 0){//se o item que eu estiver for igual ao item que quero remover

		for(int i = 1; i <= t->nivel; i++){ //anda por todos o niveis
			if(atualizar[i]->p[i] != aux) break;

			atualizar[i]->p[i] = aux->p[i];//faz todos os ponteiros aportar para o item proximo do que sera excluido
		}
		free_item(aux);//libera memoria alocada apra o item
		while (t->nivel > 1 && strcmp(t->lista->p[t->nivel]->data->chave, "zzz") == 0)  t->nivel--; //anda por todos os niveis e vai vendo se algum nivel ficou vazio, se sim diminiu o tamanho total de lsita

		return 0;

	}
	return 1;
}

int busca(t_lista *t, t_data *data){
	t_item *aux = t->lista;
	for(int i = t->nivel; i > 0; i--){//anda por todos os niveis
		while (aux->p[i] && strncmp(aux->p[i]->data->chave, data->chave, strlen(data->chave)+1) <= 0) {//ate acha um item maior ou igual que quero inserir
			aux = aux->p[i];
		}
	}

	//aux = aux->p[1];

	if(aux && strcmp(aux->data->chave, data->chave) == 0){
		printf("%s %s\n", aux->data->chave, aux->data->conteudo);
		return 0;
	}

	return 1;
}

int altera_conteudo(t_lista *t, t_data *data){
	t_item *aux = t->lista;//aponta para o primeiro item

	for(int i = t->nivel; i > 0; i--){//anda por todos os niveis
			while (aux->p[i] && strcmp(aux->p[i]->data->chave, data->chave) < 0) {//ate acha um item maior ou igual que quero inserir
					aux = aux->p[i];
			}
	}


	aux = aux->p[1]; // item com nivel mais baixo que quero inserir
	if(strcmp(aux->data->chave, data->chave) == 0){
		aux->data->conteudo = data->conteudo;
		return 0;
	}
	return 1;
}

int  busca_letra(t_lista *t, char *letra){
	t_item *aux = t->lista;//aponta para o primeiro item
	for(int i = t->nivel; i > 0; i--){//anda por todos os niveis

			while (aux->p[i] && strncmp(aux->p[i]->data->chave, letra, 1) < 0) {//ate acha um item maior ou igual que quero inserir
					aux = aux->p[i];
			}
	}

	aux = aux->p[1];
	//ve se o proximo comeca comeca com a mesma letra
	if(strncmp(aux->data->chave, letra, 1) == 0){
		while (strncmp(aux->data->chave, letra, 1) == 0) {
			printf("%s %s\n", aux->data->chave, aux->data->conteudo);
			aux = aux->p[1];
		}
		return 0;
	}

	return 1;
}

void print_lista(t_lista *t){
	t_item *aux = t->lista;


	for(int i = 1; i <= t->nivel; i ++){
		printf("-------------------\n");
		printf("%d NIVEL\n", i);
		printf("-------------------\n");
		aux = t->lista->p[i];
		while(aux->p[i] && strcmp(aux->data->chave, "zzz") != 0 ){
			printf("chave %s conteudo %s\n", aux->data->chave, aux->data->conteudo);
			aux = aux->p[i];
		}
		printf(" chave %s conteudo %s\n", aux->data->chave, aux->data->conteudo);
	}







}
