


#include "red_black.h"


int main(){

  int qnt, i, op;
  scanf("%d", &qnt);
  i  = 0;

  while(i< qnt){
    //recebe operacao
    scanf("%d", &op);
    analiza_op(op);

    i++;
  }
  return 0;
}
