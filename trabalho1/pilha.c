#include "pilha.h"
#include "funcoes.h"


void cria(stack *p){
	/*
		Creat one stack if zero elements
	*/

	p->qnt = 0;
}

void push(stack *p, double item){
	/*
		Add a item in the final of the stack
		In:	
			p: stack to add the item
			item: double to the added
	*/

	if(p->qnt == MAX -1){
		printf("cheira\n");
		exit(0);
	}
	t_item add;
	add.itemD = item;
	p->itens[p->qnt++] = add;
}
	
double remove_p(stack *p, int pos){
	/*
		This function remove a item in the pos passed thourgh the values
		In:remove_p
			p: struct to be uses
			pos: pos to be remove
	*/
	double ret = p->itens[pos].itemD;
	for(int i =  pos; i < p->qnt - 1; i++){
		p->itens[i] = p->itens[i+1];
	}
	p->qnt--;
	return ret;
}

double pop(stack *p){
	/*	
		Return the last element to enter in the stack
		In:
			p: stack to return element
		Out:
			return a double
	*/


	if(p->qnt <= 0){//check if is no empety
		return 0;
	}
	double aux;
	aux = p->itens[p->qnt-1].itemD; //element to be returned
	p->qnt--;
	return aux;

}



int empty(stack *p){
	/*
		Recive a stack and check if is empyte
		in:
			p> stack to be check
		out:
			0: has a member
			1:	not has a member
	*/

	if(p->qnt == 0){
		return 1;
	}else{
		return 0;
	}
}


stack to_posfix(char *eq){
	/*
		Function recive a math expression and pass to infix notaion
		Out:
			output: the equation in infix notation
	*/

	char op;

	double num, opI, aux;
	int r, pos, c, bracket;
	stack output, operand;
	/*
	 	num: to recive num
	 	opI: to transform the operand from char to int
	 	aux: one auxiliary
	 	r: check the return of sscanf
	 	pos: save where in the pointer
	 	c: recive how many bytes read
		bracket: count the ( and  )
		output: save the final equation
		operand: stack to save the operands
	*/


	bracket = 0;
	cria(&output); cria(&operand);
	pos = 0;
	while ((r = sscanf(&eq[pos], "%lf%n", &num, &c)) != EOF){//read all the line
	 // printf("%d %f %d\n", r, num, c);
		if (r == 1){//if is a digit


	    	push(&output, num);
	        pos += c;
	    }
	    if (r == 0){//if is not a digit
	        
	        r = sscanf(&eq[pos], " %c%n", &op, &c);
			
	        if(op == ';' || op == ',') break;

		    opI = char_to_double(op);

	        if((opI != -6) && (opI != -7) ){ //if is no a bracket
		        
		        if(empty(&operand) == 1){ //if the stack operand is null
		        	push(&operand, opI);
		        }else{//if is not null check the stack 
		        	aux = pop(&operand);
		        	if(precedence(opI) <= precedence(aux)){//if the operand in the stack has a higher precedence pop in the output
		        		push(&output, aux);
		        	}else{//if not return the operand to the stack
		        		push(&operand, aux);
		        	}
		        	push(&operand, opI);
		        }

	        }else if(opI == -6){ // if is a (
	        	bracket++;
	        	push(&operand, opI);

	        }else{//if is a )
	        	bracket--;
	        	do{//while not found the ( in the stack 
		       		if(empty(&operand) == 1){//if the stack in empty and not find the ( the expression is wrong
	       				break;
	       			}
	       			aux = pop(&operand);

	   				if(aux != -6) push(&output, aux);// if is not a ) put in the stack the operand
	        	
	      		}while( aux != -6);

	    	}
	    	pos += c;
	       
	    }
	}
	if(bracket != 0){//if the bracket is not equal
	  	clean_stack(&output);
	}else{//if is equal
		while(empty(&operand) != 1){// if the stack of operand  is not null, pop the itens and push in the output
		  	push(&output, pop(&operand));
		}
	}
	return output;		
}


void clean_stack(stack *p){
	/*
		Recive the stack strcut and change the qnt to zero
		In: 
			p: stack to be clean
	*/
	p->qnt = 0;
}
