/*
 * ESTRUCTURAS DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIERÍA, UNAM, 2019-1
 * T A R E A   6
 * NOTACIÓN POLACA (PREFIX).
 * 
 * Instrucciones:
 * Implementar el algoritmo para evaluar una expresión aritmética en notación polaca (prefix).
 * La expresión se pasa como argumento donde cada caracter representa ya sea un operando o un operador
 * Considere que la cadena a evaluar sólo contiene los caracteres 0-9, '+', '-', '*' y '/'.
 * Para implementar la pila, utilice el archivo Stack.h y las funciones ya definidas en él.
 * No es necesario validar la sintaxis de la expresión, es decir, puede suponer que la expresión
 * es sintácticamente correcta.
 * Para la manipulación de datos en la pila, sólo se permite el uso de las funciones
 * stack_float_push y stack_float_pop, ya definidas en el archivo Stack.h
 * Además del archivo Stack.h, SÓLO SE PERMITE EL USO DE BIBLIOTECAS ESTÁNDARES.
 */

#include <stdio.h>
#include "Stack.h"

int main(int argc, char** argv)
{
    if(argc < 2)
	return -1;

    char* expression = argv[1];
    StackFloat S = stack_float_initialize();
    float result = 0;

    //
    //CÓDIGO POR ESCRIBIR:
    //Algoritmo para la evaluación de una expresión aritmética en notación polaca (prefix).
    //La cadena a evaluar es 'expression'
    //El resultado se debe almacenar en la variable 'result'
    //
    //Recuerde primero calcular la longitud de la cadena y recorrer la expresión de derecha a izquierda. 
    //
    int longitud = strlen(&*expression);
    //Debemos de sacar el valor de la cadena al total, para poder sumarlo al contador y que vaya decrementando.
    char* x = expression+=longitud;
    int i;
    for(*expression = longitud-1;*expression>=0;*expression--) //Se pone -1 en la longitud porque tenemos que evitar el caracter nulo, de no ser as�, el programa no ejecutaria nada
	{	
		char c = *expression;
		
		//Declaramos como char porque va a leer caracter por caracter 
		if(c>= '0' && c<='9')
			stack_float_push(&S, c-0x30);
		//En este caso declaramos los operandos para convertirlos de su caracter ASCII a un n�mero
		/*A partir de aqu� la suma, resta y multiplicaci�n son iguales: Sacamos dos elementos de la pila ,
		se los asignamos a una variable y los operamos*/
		else if(c == '+')
		{
			int op2= stack_float_pop(&S);
			int op1= stack_float_pop(&S);
			stack_float_push(&S, op1+op2);
			
		}
		else if(c == '*')
		{
			int op2= stack_float_pop(&S);
			int op1= stack_float_pop(&S);
			stack_float_push(&S, op1*op2);
			
		}
		
		else if(c == '-')
		{
			int op2= stack_float_pop(&S);
			int op1= stack_float_pop(&S);
			stack_float_push(&S, op1-op2);	
		}
		else if(c == '/')
		{
			int op2= stack_float_pop(&S);
			int op1= stack_float_pop(&S);
			stack_float_push(&S, op1/op2); 
			 //En esta peracion no debemos cambiar el orden de los factores para no alterar el producto
		}
	}
    //Asignamos el valor final de la operacion a la variable que vamos a imprimir.
    result = stack_float_pop(&S);
    
    printf("%f\n", result);
    return 0;
}
