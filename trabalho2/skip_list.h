// arquivo com as definicoes e escopo das funcoes para utilizar a skip list

#define MAX 5;

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

	int qnt_iten;
	t_item **lista;
}t_lista;


void cria(t_lista *t);