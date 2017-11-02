#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>


#define MAX 1001



typedef union{
	double itemD;
}t_item;


typedef struct {
	int qnt;
	t_item itens[MAX];
}stack;


void cria(stack *p);
void push(stack *p, double item);
//void push_char(stack *p, char item);
double pop(stack *p);
double remove_p(stack *p, int pos);
//char pop_char(stack *p);
int empty(stack *p);
void print_stack(stack *p);
stack to_posfix(char *c);
stack inverse_stack(stack *p);
void clean_stack(stack *p);
#endif