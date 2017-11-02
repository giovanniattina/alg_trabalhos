#include "skip_list.h"


t_lista *cria(){
	t_lista *t;
	t = (t_lista*)malloc(sizeof(t_lista));

	t->lista = (t_item*)malloc(sizeof(t_item)*MAX);
	t->lista->p = (t_item**)malloc(sizeof(t_item*)*MAX);

	//defina todos os proximo item com null
	for(int i = 0; i < MAX; i++)strcpy(t->lista->p[i]->data->chave, "zzz");

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

	t_item *atualizar[MAX];//salvar ponteiro para item anterior em todos niveis da lista
	t_item *aux = t->lista;//aponta para o primeiro item

	for(int i = t->nivel; i > 0; i--){//anda por todos os niveis
			while (strcmp(aux->p[i]->data->chave, novo->chave) <= 0) {//ate acha um item maior ou igual que quero inserir
					aux = aux->p[i];
			}
			atualizar[i] = aux;
	}

	aux = aux->p[0]; // item com nivel mais baixo que quero inserir

	if(strcmp(aux->data->chave, novo->chave) == 1){// se tiver item com a mesma chave que quero inserir da erro
		return 0; //erro
	}else{//se não tiver

		int nivel = level_aleatorio();

		if(nivel > t->nivel){
			for(int i = t->nivel; i <= nivel; i++){
				atualizar[i] = t->lista;
			}
			t->nivel = nivel;
		}

		//aloca espaco para o novo item
		aux = (t_item*)malloc(sizeof(t_item));
		aux->data = novo;
		aux->p = (t_item**)malloc(sizeof(t_item*)*MAX);

		for(int i = 0; i < nivel; i++){//anda por todos os niveis e vai adicionando o novo 	item
			aux->p[i] = atualizar[i]->p[i];
			atualizar[i]->p[i] = aux;
		}
	}
	return 1;//se nao acho um item iguaç e nao teve erro

}

void free_item(t_item *del){
	if(del != NULL){
		free(del->p);
		free(del);
	}
}

int deleta(t_lista *t, t_data *data){

	t_item *atualizar[MAX];//salvar ponteiro para item anterior em todos niveis da lista
	t_item *aux = t->lista;//aponta para o primeiro item

	for(int i = t->nivel; i > 0; i--){//anda por todos os niveis
			while (strcmp(aux->p[i]->data->chave, data->chave) == 0) {//ate acha um item maior ou igual que quero deletar
					aux = aux->p[i];
			}
			atualizar[i] = aux;
	}

	aux = aux->p[0]; // item com nivel mais baixo que quero deletar

	if(strcmp(aux->data->chave, data->chave) == 0){//se o item que eu estiver for igual ao item que quero remover
		for(int i = 0; i < t->nivel; i++){ //anda por todos o niveis
			if(atualizar[i]->p[i] != aux) break;

			atualizar[i]->p[0] = aux->p[i];//faz todos os ponteiros aportar para o item proximo do que sera excluido
		}
		free_item(aux);//libera memoria alocada apra o item

		while (t->nivel > 1 && t->lista->p[t->nivel] == t->lista)  t->nivel--; //anda por todos os niveis e vai vendo se algum nivel ficou vazio, se sim diminiu o tamanho total de lsita

		return 0;

	}
	return 1;
}

int busca(t_lista *t, char *data){

	t_item *aux = t->lista;
	for (int i = t->nivel; i >= 0; i++){
		while (strcmp(aux->p[i]->data->chave, data) == 0){
			aux = aux->p[i];
		}

		if(strcmp(aux->p[0]->data->chave, data) == 0){
			//printa
			return 0;
		}
	}
	return 1;
}

int altera(t_lista *t, t_data *data){
	t_item *atualizar[MAX];//salvar ponteiro para item anterior em todos niveis da lista
	t_item *aux = t->lista;//aponta para o primeiro item

	for(int i = t->nivel; i >= 0; i--){//anda por todos os niveis
			while (strcmp(aux->p[i]->data->chave, data->chave) < 0) {//ate acha um item maior ou igual que quero inserir
					aux = aux->p[i];
			}
			atualizar[i] = aux;
	}


	aux = aux->p[0]; // item com nivel mais baixo que quero inserir
	if(strcmp(aux->data->chave, data->chave) == 0){
		for(int i = 0; i <= t->nivel; i++){
			if(strcmp(atualizar[i]->data->chave, data->chave) == 0){
				atualizar[i]->data->conteudo = data->conteudo;
			}
		}
	}else{
		return 1;
	}
	return 0;
}

t_data **busca_letra(t_lista *t, char *letra){
	t_item *aux = t->lista;//aponta para o primeiro item

	t_data **final = (t_data**)malloc(sizeof(t_data*)*100);
	int conta_final = 0;

	for(int i = t->nivel; i >= 0; i--){//anda por todos os niveis
			while (strncmp(aux->p[i]->data->chave, letra, 1) == 0) {//ate acha um item maior ou igual que quero inserir
					aux = aux->p[i];
			}
	}


	aux = aux->p[0];
	//ve se o proximo comeca comeca com a mesma letra
	if(strncmp(aux->data->chave, letra, 1) == 0){
		while (strncmp(aux->data->chave, letra, 1) == 0) {
			final[conta_final++] = aux->data;
			aux = aux->p[0];
		}
	}else{
		//print error
	}

	return final;
}
