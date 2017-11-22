#include "red_black.h"




void analiza_op(int op, nodo **n){
  int num;
  switch (op) {//realiza a operacao nescessaria para tirar o no

    case 1:
      scanf("%d ", &num);
      insere(n, num);
      break;

    case 2:
      scanf("%d ", &num);
      sucessor(*n, num);
      break;

    case 3:
      scanf("%d ", &num);
      precessor(*n, num);
      break;

    case 4:
      maximo(*n);
      break;

    case 5:
      minimo(*n);
      break;

    case 6:
      preOrdem(*n);
      printf("\n");
      break;

    case 7:
      inOrdem(*n);
      printf("\n");

      break;

    case 8:
      posOrdem(*n);
      printf("\n");

      break;
  }
}


nodo *cria_nodo(int item, nodo *p){

  nodo *n;

  n = (nodo*)malloc(sizeof(nodo));

  n->direita = NULL;
  n->esquerda = NULL;
  n->cor = 'R';
  n->p = p;
  n->i = item;

  return n;
}

void insere(nodo **n, int item){
  nodo *y = NULL;
  nodo *x = *n;

  while(x != NULL){//procura a possicao do nó
    y = x;
    if(item < x->i) x = x->esquerda;
    else x = x->direita;
  }

  nodo *novo = cria_nodo(item, y);
  if(y == NULL){
    *n = novo;
  }else if(novo->i < y->i) y->esquerda = novo; //se o no tem q ir para a esquerda
  else y->direita = novo;//se o no tem q ir para a direita

  arruma_insercao(n, novo);//chama a funcao para balancear a arvore
}
void rotacao_direita(nodo **n, nodo*x){
  /*
   *  Para uma melhor explicação com figuras das rotacao acessar o site: http://www.geeksforgeeks.org/red-black-tree-set-2-insert/
   * e vizualar a rotacao right left case
  */
  nodo *y = x->esquerda;
  x->esquerda = y->direita;

  if(y->direita != NULL) y->direita->p = x;

  y->p = x->p;

  if(x->p == NULL) *n = y;
  else if(x == x->p->direita) x->p->direita = y;
  else x->p->esquerda = y;

  y->direita = x;
  x->p = y;
}

void rotacao_esquerda(nodo **n, nodo*x){
  /*
   *  Para uma melhor explicação com figuras das rotacao acessar o site: http://www.geeksforgeeks.org/red-black-tree-set-2-insert/
   * e vizualar a rotacao left right case
  */
  nodo *y = x->direita;
  x->direita = y->esquerda;
  if(y->esquerda != NULL){
    y->esquerda->p = x;
  }
  y->p = x->p;
  if(x->p == NULL){
    *n = y;
  }else if(x == x->p->esquerda){
    x->p->esquerda = y;
  }else{
    x->p->direita = y;
  }
  y->esquerda = x;
  x->p = y;
}

void arruma_insercao(nodo **n, nodo *z){
  /**
   * Ele executa ate chegar no nodo raiz
   * A teoria dos 3 possiveis casos podem ser encontrado no Livro: Introduction to Algorithms, Cormen T.H, Rivest R., Leiserson E. C, pag 312 edição 3
   */
  nodo *y;
  while(z->p != NULL && z->p->cor == 'R'){
    if(z->p ==  z->p->p->esquerda){//faz a verificacao para esquerda
      y = z->p->p->direita; //pega o tio de z
      if(y != NULL && y->cor == 'R'){ //se o tio for vermelho
        //muda a cor do pai e' e do tio para preto e o avo^ para vermelho
        z->p->cor = 'P';
        y->cor = 'P';
        z->p->p->cor = 'R';
        z = z->p->p;
      }else{//se o tio e' preto
        if(z == z->p->direita){
          z = z->p; //aponto para o pai
          rotacao_esquerda(n, z); //faço a rotocao para a esquerda
        }
        z->p->cor = 'P'; // mudo a cor do novo pai para preto
        z->p->p->cor = 'R';//mudo a cor do avo^ para vermelho
        rotacao_direita(n,z->p->p); //faço rotação para a direita
      }
    }else{//faz a verificacao para direita e repete as mesmas operacaos do codigo das linhas 136 a 150
      y = z->p->p->esquerda;
      if(y != NULL && y->cor == 'R'){
        z->p->cor = 'P';
        y->cor = 'P';
        z->p->p->cor = 'R';
        z = z->p->p;
      }else{
        if(z == z->p->esquerda){
          z = z->p;
          rotacao_direita(n, z);
        }
        z->p->cor = 'P';
        z->p->p->cor = 'R';
        rotacao_esquerda(n, z->p->p);
      }
    }
  }
  (*n)->cor = 'P';

}

void precessor(nodo *n, int i){
  if(n == NULL){
    printf("ERRO\n");
  }
  nodo *x = n;
  nodo *y;
  //acha item i na arvore
  while(x != NULL && x->i != i){
    if(x->i > i)  x = x->esquerda;
    else x = x->direita;
  }
  if(x->esquerda != NULL){//se a esquerda na~o for nulo o sucessor e o valor minimo do filho a direita

    maximo(x->esquerda);
  }else{
    y = x->p;
    while(y != NULL && x == y->esquerda){//se não ele vai voltando para os pais ate achar o sucessor
      x = y;
      y = y->p;
    }

    if(y == NULL){//se chego no topo na arvore e na~o acho da erro
      printf("erro\n");
    }else{
      printf("%d\n", y->i);
    }
  }

}

void sucessor(nodo *n, int i){
  if(n == NULL){
    printf("ERRO\n");
  }
  nodo *x = n;
  nodo *y;
  //acha item i
  while(x != NULL && x->i != i){
    if(x->i > i)  x = x->esquerda;
    else x = x->direita;
  }
  if(x->direita != NULL){//se a direita na~o for nulo o sucessor e o valor minimo do filho a direita
    minimo(x->direita);
  }else{
    y = x->p;
    while(y != NULL && x == y->direita){//se não ele vai voltando para os pais ate achar o sucessor
      x = y;
      y = y->p;
    }

    if(y == NULL){//se chegou no topo da arvore e nao acho da erro
      printf("erro\n");
    }else{
      printf("%d\n", y->i);
    }
  }
}

void minimo(nodo *n){
  //vai sempre para o nodo da esquerda ate chegar no NULL
  if(n->esquerda == NULL) printf("%d\n", n->i);
  else minimo (n->esquerda);
}

void maximo(nodo *n){
  //vai sempre no nodo da direita ate achar o NULL
  if(n->direita == NULL) printf("%d\n", n->i);
  else maximo (n->direita);
}

void preOrdem(nodo *n){
  if(n == NULL){
      return;
  }
  printf("%d ", n->i);
  preOrdem(n->esquerda);
  preOrdem(n->direita);

}

void inOrdem(nodo *n){
  if(n == NULL){
    return;
  }
  inOrdem(n->esquerda);
  printf("%d ", n->i);
  inOrdem(n->direita);
}

void posOrdem(nodo *n){
  if(n == NULL){
    return;
  }
  posOrdem(n->esquerda);
  posOrdem(n->direita);
  printf("%d ", n->i);

}

void libera_arvore(nodo *n){
  if(n != NULL){
    libera_arvore(n->esquerda);
    libera_arvore(n->direita);
    free(n);
  }
}
