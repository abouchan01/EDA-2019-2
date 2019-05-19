/*
 * ESTRUCTURAS DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIERÍA, UNAM, 2019-1
 * P R A C T I C E   04
 * Instrucciones:
 *  * Multiplicar tres matrices cuyos órdenes están dados por: a0Xa1, a1Xa2, a2Xa3
 *  * Las tres matrices se deben llenar con números enteros aleatorios en [0,99] 
 *  * Imprimir las tres matrices y la matriz resultante.
 *  * Los valores a0, a1, a2 y a3 se pasan como argumentos por línea de comandos.
 * ES OBLIGATORIO USAR LA FUNCIÓN MALLOC PARA RESERVAR EL ESPACIO 
 * NECESARIO PARA ALMACENAR LOS VALORES DE LAS MATRICES.
 */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char** argv)
{
    if(argc < 5)
	return -1;
    int a0 = atoi(*(argv + 1));
    int a1 = atoi(*(argv + 2));
    int a2 = atoi(*(argv + 3));
    int a3 = atoi(*(argv + 4));
    if(a0 <= 0 || a1 <= 0 || a2 <= 0 || a3 <= 0)
	return -1;
    //
    //CÓDIGO POR ESCRIBIR:
    //Reservar suficiente memoria para multiplicar las matrices
    //con órdenes a0Xa1, a1Xa2, a2Xa3.
    //Los datos en las matrices serán números enteros
    //

    //Ejemplo:
    unsigned int* m1   = (int*)malloc(sizeof(int)*a0*a1);
    unsigned int* m2   = (int*)malloc(sizeof(int)*a1*a2);
    unsigned int* m3   = (int*)malloc(sizeof(int)*a2*a3);
    //
    //CÓDIGO POR ESCRIBIR:
    //Llenar las matrices con números enteros aleatorios entre 0 y 99
    //

    //Ejemplo:
    srand(time(NULL));
    int i,j;
    for(i=0; i < a0*a1; i++)
	*(m1 + i) = rand()%100;

    for(i=0; i < a1*a2; i++)
	*(m2 + i) = rand()%100;
    
    for(i=0; i < a2*a3; i++)
	*(m3 + i) = rand()%100;

    //CÓDIGO POR ESCRIBIR:
    //Imprimir las tres matrices:
    //

    //Ejemplo:
    printf("\nMatriz 1:\n"); //Siempre que haya filas y columnas debe haber for para llenar
    for(i = 0; i < a0; i++)
    {
	printf("\n");
	for(j = 0; j < a1; j++)
	    printf("%d\t", m1[i*a1 + j]);
    };
    printf("\n");
    
    printf("\nMatriz 2:\n");
    for(i = 0; i < a1; i++)
    {
	printf("\n");
	for(j = 0; j < a2; j++)
	    printf("%d\t", m2[i*a2 + j]);
    };
    printf("\n");
    
    printf("\nMatriz 3:\n");
    for(i = 0; i < a2; i++)
    {
	printf("\n");
	for(j = 0; j < a3; j++)
	    printf("%d\t", m3[i*a3 + j]);
    };
    printf("\n");
    
    //
    //CÓDIGO POR ESCRIBIR:
    //Multiplicar las tres matrices.
    //
    int k;
    int* mr   = (int*)malloc(sizeof(int)*a0*a2);
	for(i=0; i< a0; i++){
		for(j=0; j< a2; j++){
			 mr[i*a2+j]=0; 
			for(k = 0; k<a1; k++){
				mr[i*a2+j]+= m1[i*a1+k]*m2[k+a2+j]; //Multiplicacion de ambas matrices
			}
		}
	}
    
    int* mr2   = (int*)malloc(sizeof(int)*a1*a3);
	for(i=0; i<a1; i++){
		for(j=0; j< a3; j++){
			mr2[i*a3+j] = 0;
			for(k = 0; k<a2; k++){
				mr2[i*a3+j] += mr[i*a2+k]*m3[k*a3+j]; //Ultima multiplicacion de las matrices
			}
		}
	}
    //
    //CÓDIGO POR ESCRIBIR:
    //Imprimir el resultado
    //
	 printf("\nMatriz resultado:\n"); //Siempre que haya impresiones de matrices hay ciclos 
    for(i = 0; i < a0; i++)
    {
	printf("\n");
	for(j = 0; j < a3; j++)
	    printf("%d\t", mr2[i*a3 + j]);
    };
    printf("\n");
    //
    //CÓDIGO POR ESCRIBIR:
    //Liberar toda la memoria reservada.
    //

    //Ejemplo:
	free(m1);
    free(m2);
    free(m3);
    free(mr);
    free(mr2);
    
    
    return 0;
}

