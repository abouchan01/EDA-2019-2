/*
 * ESTRUCTURAS DE DATOS Y ALGORITMOS I, FI, UNAM, 2019-1
 * PRÁCTICA 05
 * IMPLEMENTACIÓN DE UNA COLA (DE ENTEROS) USANDO DOS PILAS Y UNA PILA (DE ENTEROS), USANDO DOS COLAS
 *
 * LINEAMIENTOS:
 * 1. No se deben modificar los archivos Queue.h ni Stack.h
 * 2. No se permite el acceso directo a los datos de las Pilas y Colas,
 *    Para manipular las estructuras de datos, sólo se permite el uso de las funciones:
 *    stack_int_push
 *    stack_int_pop
 *    stack_int_is_full
 *    stack_int_is_empty
 *    queue_int_enqueue
 *    queue_int_dequeue
 *    queue_int_is_full
 *    queue_int_is_empty
 *    Estas funciones vienen implementadas en los archivos Stack.h y Queue.h
 * 3. SOLO SE DEBEN MODIFICAR LAS FUNCIONES CON EL COMENTARIO "CÓDIGO POR ESCRIBIR"
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

//Declaración de pilas y colas auxiliares.
//Bouchan Ramirez Abraham
StackInt S1;
StackInt S2;
QueueInt Q1;
QueueInt Q2;

void enqueue(int k)
{
    //
    //CÓDIGO POR ESCRIBIR:
    //Implementar la función ENQUEUE utilizando las pilas S1 y S2
    //(No es neceario pasar por argumento la cola en la que se quiere insertar el dato
    // puesto que no hay una cola en sí, sino que se deben utilizar las pilas S1 y S2)
    //
	
	//Bouchan Ramirez Abraham
	stack_int_push(&S1, k);   //Se mete k en la primera stack

}

int dequeue()
{
    //
    //CÓDIGO POR ESCRIBIR:
    //Implementar la función DEQUEUE utilizando las pilas S1 y S2
    //(No es neceario pasar por argumento la cola de la que se quiere eliminar el dato
    // puesto que no hay una cola en sí, sino que se deben utilizar las pilas S1 y S2)
    //

	while(!stack_int_is_empty(&S1)) stack_int_push(&S2, stack_int_pop(&S1));     
	//Mientras stack 1 no est� vac�o vamos a meter en stack 2 lo que vayamos sacando de la primera

	int x = stack_int_pop(&S2);
	//Vamos guardando el ultimo valor que saquemos en x para que sea lo que devuelve.

	while(!stack_int_is_empty(&S2)) stack_int_push(&S1, stack_int_pop(&S2)); 
	//Visceversa de lo de arriba.
	
	
	return x;

}

void push(int k)
{
    //
    //CÓDIGO POR ESCRIBIR:
    //Implementar la función PUSH utilizando las colas Q1 y Q2
    //(No es neceario pasar por argumento la pila en la que se quiere insertar el dato
    // puesto que no hay una pila en sí, sino que se deben utilizar las colas Q1 y Q2)
    //

	queue_int_enqueue(&Q1, k);
	//Encolar k en q1
	
}

int pop()
{
    //
    //CÓDIGO POR ESCRIBIR:
    //Implementar la función POP utilizando las colas Q1 y Q2
    //(No es neceario pasar por argumento la pila de la que se quiere eliminar el dato
    // puesto que no hay una pila en sí, sino que se deben utilizar las colas Q1 y Q2)
    //


	int x = queue_int_dequeue(&Q1);
	//Damos a x lo que squemos de desencolar en q1

	while(!queue_int_is_empty(&Q1)){
	//Mientras q1 no est� vac�a...
	
	queue_int_enqueue(&Q2,x);
	//Encolar  a q2 lo que est� en x
	
	
	x = queue_int_dequeue(&Q1);
	//Damos a x lo que squemos de desencolar en q1

	}


	while(!queue_int_is_empty(&Q2)) queue_int_enqueue(&Q1, queue_int_dequeue(&Q2));
	//mientras q2 no est� vac�a encolar en q1 lo que desencolemos en q2

	return x;



}

int main(int argc, char** argv)
{
    if(argc < 3)
	return -1;
    
    S1 = stack_int_initialize();
    S2 = stack_int_initialize();
    Q1 = queue_int_initialize();
    Q2 = queue_int_initialize();

    int i=0;
    int value;
    while(++i < argc)
    {
	if(!strcmp(argv[i], "push"))
	    push(atoi(argv[++i]));
	else if(!strcmp(argv[i], "pop"))
	    pop();
	else if(!strcmp(argv[i], "enq"))
	    enqueue(atoi(argv[++i]));
	else if(!strcmp(argv[i], "deq"))
	    dequeue();
    }

    if(!queue_int_is_empty(&Q1))
	printf("Peek: %d\n", queue_int_tail(&Q1));
    if(!stack_int_is_empty(&S1))
    {
	printf("Tail: %d\n", stack_int_peek(&S1));
	printf("Head: %d\n", stack_int_bottom(&S1));
    }
    return 0;
}
