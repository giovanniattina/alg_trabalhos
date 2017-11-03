// arquivo com as definicoes e escopo das funcoes para utilizar a skip list
#ifndef	SKIP_LIST_H
#define SKIP_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

#define MAX 100

typedef struct{
	char *chave;
	char *conteudo;
}t_data;

typedef struct t_item t_item;

struct t_item{

	t_data *data;
	t_item **p;
};


typedef struct {

	int qnt_item, nivel;
	t_item *lista;
}t_lista;


/**
 * [cria Aloca espaco para o comeco da lista e seta todos os ponteiros para 'zzz']
 * @return [lista que sera' iniciada]
 */
t_lista *cria();

/**
 * [level_aleatorio Pega o nivel maximo de lista e retorna um level aleatorio]
 * @return [numero aleatorio para ver o novo numero de listas]
 */
int level_aleatorio();

/**
 * [insere adiciona um item novo no lista, andando por todos os niveis e salvando os ponteiros para o item que sera o item
 * anterior do novo que sera inserido e faz ele aportar para o novo item e os itens antigos que ele apontavam o novo item aponta
 * para eles]
 * @param  t    [lista que vai inserir o item]
 * @param  novo [item que sera inserido]
 * @return      [1 se ja nao tiver um item na lista com a mesma chave ou 0 se ja tiver]
 */
int insere(t_lista *t, t_data *novo);


/**
 * [free_item libera espaco alocado para um t_item]
 * @param del [item a ser desalocado]
 */
void free_item(t_item *del);


/**
 * [deleta deleta um item que tiver a mesma chave da lista em todos os nivels e analiza se precisa diminuir o nivel da lista]
 * @param  t    [lista que o item sera removida]
 * @param  data [item que sera removido]
 * @return      [1 se o item nao tiver na lista e 0 se o item tiver na lista]
 */
int deleta(t_lista *t, t_data *data);


/**
 * [busca busca um item na lista pela a chave]
 * @param  t     [lista para busca o item com a chave]
 * @param  busca [chave a ser buscado]
 * @return       [ 0 se tiver um item com a chave na lista e 1 se nao tiver]
 */
int busca(t_lista *t, char *busca);

/**
 * [busca_letra description]
 * @param  t     [description]
 * @param  letra [description]
 * @return       [description]
 */
int busca_letra(t_lista *t, char *letra);

int altera_conteudo(t_lista *t, t_data *data);

void print_lista(t_lista *t);
#endif
