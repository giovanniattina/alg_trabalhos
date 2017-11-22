/*
  * Nome: Giovanni Attina do Nascimento Nº USP 9286614
  * Implementaca~o feita atraves dos requisitos dados no PDF prensente no RunCodes.
 */


#include "red_black.h"


int main(){
  int qnt, i, op;
  /*
   * qnt -> qnt de operacoes que recebera na entrada
   * i -> interador para contar quantas operacoes ja foi feita
   * op-> recebe a operacao que sera executada
   */
  raiz *r = (raiz*)calloc(1,sizeof(raiz));

  scanf("%d", &qnt);
  i  = 0;

  while(i< qnt){
    //recebe operacao
    scanf("%d", &op);
    analiza_op(op, &(r->n));
    i++;
  }
  //libera memoria alocada na heap
  libera_arvore(r->n);
  free(r);
  return 0;
}
