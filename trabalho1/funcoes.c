
#include "funcoes.h"

int precedence(double c){

	/*
		Recive a operand and return the precedence of the operand
		In:
			-c: operand to check the precedence
		Out:
			2:  - or +
			3: / *
			4: ^
	*/

	switch((int)c){
		case -1:
		case -2:
			return 2.0;
			break;
		case -4:
		case -3:
			return 3.0;
			break;
		case -5:
			return 4.0;
			break;		
	}

	return 0;
}

char *receive_eq(){
	/*	
		Function to recive the line of equation
		Out:
			eq: pointer with the info
	*/
	char *eq = malloc(sizeof(char)*1001);

	fgets(eq, 1001, stdin);

	if(eq[strlen(eq) - 3] == ';'){
		eq[strlen(eq) - 2] = '\0';
	}

	return eq;
}

double char_to_double(char c){
	/*
		Recive a char, a operator, and change it in double to be able to save in the stack
		In:
			c: operator
		Out:
			+: -1
			-: -2
			*: -3
			/: -4
			^: -5
			(: -6
			): -7
	*/
	switch(c){
		case '+':
		 	return -1.0;
		 	break;
		case '-':
			return -2.0;
			break;
		case '*':
			return -3.0;
			break;
		case '/':
			return -4.0;
			break;
		case '^':
			return -5.0;
			break;
		case '(':
			return -6.0;
			break;
		case ')':
			return -7.0;
			break; 
	}
	return 0;
}


double ope(double num1, double op, double num2){
	/*
		Function recive a two number and um operand and eval the equation

		In: 
			num1, num2: numbers
			op: operand
		Out:
			if operand -1:	make sum
			-2:	make subtraction
			-3:	times
			-4: divison
			-5:	pow
	*/

	switch((int)op){
		case -1:
			return num1 + num2;
		case -2:
			return num1 - num2;
		case -3:
			return num1 * num2;
		case -4:
			return num1 / num2;
		case -5:
			return pow(num1, num2);
	}
	return 0;
}

void make_equation(stack *eqPos){
	/*
		Function recive a equation in posfix notation and eval the equation

		IN: 
			eqPos: equation in posfix notation
	*/
	double aux, operand, operand_1;
	stack res;	
	
	//eval eqaution
	if(empty(eqPos) != 1){
		while(empty(eqPos) != 1){//check if has a equation
			aux = remove_p(eqPos, 0);//to check

			if(aux < 0){//if is a operetor

				//make two operand
				operand = pop(&res);
				operand_1 = pop(&res);
				if(operand == 0 && aux == -4){//check if is not doing zero division
					printf("Expressao incorreta\n");
					clean_stack(&res);
					break;
				}
				push(&res, ope(operand_1, aux, operand));
			}else{//if is operand
				push(&res, aux);
			}
		}
	}else{//if hasn't a result
		printf("Expressao incorreta\n");
	}
	if(empty(&res) != 1){//print
		printf("%.2lf\n", pop(&res));
	}
}