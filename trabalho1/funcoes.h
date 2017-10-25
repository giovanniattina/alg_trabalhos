#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilha.h"


int precedence(double c);
char *receive_eq();
double char_to_double(char c);
double ope(double num1, double op, double num2);
void make_equation(stack *eqPos);


#endif