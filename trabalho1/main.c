
/*
	Nome: Giovanni Attina do Nascimento
	NºUSP: 9286614

	O trabalho foi considerado com as informacoes presentes no PDF no run codes

*/


#include "funcoes.h"
#include "pilha.h"


int main(){
	char *eq;
	stack eqPos;
    char aux;//to save the last char before free the memory allocated
	do{//recive a equation while , is not digited
		eq = receive_eq();//recive in char
		eqPos = to_posfix(eq);//pass to posfix
        aux = eq[strlen(eq)-1];
		make_equation(&eqPos);//resolve the equation

		free(eq);
	}while(aux != ',');

	return 0;
}
