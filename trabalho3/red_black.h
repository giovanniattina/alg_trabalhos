

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//estutura para cada no
typedef struct nodo nodo;

struct nodo{
   int i;
   nodo *direita, *esquerda, *p;
   unsigned char cor;
};

//estutura de raiz, salvando o nodo raiz
typedef struct raiz{
  nodo *n;
}raiz;
/**
 * [analiza_op recebe uma operacao e avalia se tem que receber mais um item ou executar a operacao]
 * @param op [operacao recebi]
 * @param n  [ponteiro para a raiz da arvore]
 */

void analiza_op(int op, nodo **n);
/**
 * [insere insere um item na arvore de acordo com as regras de uma arvore binaria]
 * @param n    [ponteiro para a raiz da arvore onde o item sera inseiro]
 * @param item [item que sera inserido]
 */

void insere(nodo **n, int item);
/**
 * [arruma_insercao balanceia a arvore de acordo com os 3 casos de balanceamento da arvore vermelho e preto]
 * @param n [ponteiro para a raiz da arvore]
 * @param z [item novo que foi inserido]
 */
void arruma_insercao(nodo **n, nodo *z);

/**
 * [rotacao_esquerda recebe um nodo da arvore e faz a rotacao para esquerda]
 * @param n [raiz da arvore]
 * @param x [nodo para rotacionar]
 */

void rotacao_esquerda(nodo **n, nodo*x);

/**
 * [rotacao_direita recebe um nodo da arvore e faz a rotacao para direita]
 * @param n [raiz da arvore]
 * @param x [nodo para rotacionar]
 */
void rotacao_direita(nodo **n, nodo*x);

/**
 * [posOrdem imprime os nodos da arvore em pos ordem]
 * @param n [raiz da arvore]
 */
void posOrdem(nodo *n);

/**
 * [inOrdem imprime os nodos da arvore em in ordem]
 * @param n [raiz da arvore]
 */
void inOrdem(nodo *n);

/**
 * [preOrdem imprime os nodos da arvore em pre ordem]
 * @param n [raiz da arvore]
 */
void preOrdem(nodo *n);

/**
 * [minimo acha o melhor valor inserido na arvore]
 * @param n [raiz da arvore]
 */
void minimo(nodo *n);

/**
 * [maximo acha o maior valor inserido na arvore]
 * @param n [raiz da arvore]
 */
void maximo(nodo *n);

/**
 * [precessor acha o item precessor ao item buscado, o item de maior valor antes dele]
 * @param n [raiz da arvore]
 * @param i [item buscando o precessor]
 */
void precessor(nodo *n, int i);

/**
 * [sucessor acha o item precessor ao item buscado, o item de maior valor antes dele]
 * @param n [raiz da arvore]
 * @param i [item buscando o precessor]
 */
void sucessor(nodo *n, int i);


/**
 * [libera_arvore libera a memoria alocada para a arvore]
 * @param n [raiz da avore]
 */
void libera_arvore(nodo *n);
