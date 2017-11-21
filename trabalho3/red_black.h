

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct t_item{
  int i;
}t_item;


typedef struct nodo nodo;

struct nodo{
  t_item i;
   nodo *direita, *esquerda, *p;
   unsigned char color;
};


void analiza_op(int op);
