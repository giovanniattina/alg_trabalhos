#include "skip_list.h"


void cria(t_list **t){
	*t = malloc(sizeof(t_list));
	*t->qnt_item = 0;
	*t->lista = malloc(sizeof(*t_item)*MAX);
}