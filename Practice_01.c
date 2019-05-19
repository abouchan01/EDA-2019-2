/*
 * ESTRUCTURA DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIER√çA, UNAM, 2019-1
 * P R A C T I C E   1
 * Instructions:
 *  * Calculate the transpose of a matrix using ONLY ONE-DIMENSIONAL ARRAYS, i.e., 
 *  * you CANNOT USE the double bracket [][] notation.
 *  * The program must receive the matrix order as command line parameters, e.g:
 *  * ./Prac_01 3 5 indicates a 3x5 matrix.
 *  * The program must fill the matrix with random integers in the interval [0,99].
 *  * The program must print both the original and the transposed matrix.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        printf("Too few parameters! At least two integers are required.\n");
        return -1;
    }
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    if(rows < 1 || cols < 1)
    {
        printf("Invalid columns or rows.");
        return -1;
    }

    /*
      TODO:
      Declare a one-dimensional array with enough space to store the matrix elements,
      Declare any other variables you may need.
     */
     int mat[rows*cols];    //En este paso hicimos la matriz unidimensional.
	 int trans[rows*cols]; //La matriz se transpone al cambiar de lugar filas por columnas
	 int esp;              //Ser· utilizado como numero random
	 int i = 0;
	 int j;                    //variables necesarias para contadores
	 srand(time(NULL));        //que el numero generado sea en funcion dl tiempo
	 
    /*
      TODO:
      Fill the matrix with random integers in the interval [0,99]
      Hint: use the functions rand(), srand() and time().		*/
	printf("The original matrix is:\n");
	while(i < rows){                  //checamos que el valor del argumento nos deje iterar
		j = 0;
		while(j < cols){
			esp	= rand() % 99;            //Damos a esp el valor random entre 0 y 99
			mat[(i*cols)+j] = esp;                    //damos a la matriz los valores random
			printf("%i\t",mat[(i*cols)+j]);     //Se imprime desde dentro para que salgan todos los numeros
			j++;
			}
		printf("\t");     //si usaramos aqui \n se verÌa la forma com˙n de la matriz
		i++;
		}
    /*
      TODO: 
      Print the matrix elements using the '\t' character as separator.
     */
     	
//En el apartado anterior fueron impresas las dos instrucciones para meterlas en el ciclo y hacer mas eficiente el codigo.
    
	printf("\n\nThe transposed matrix is:\n");
	/*
      TODO: 
      Print the transposed matrix elements using the '\t' character as separator.
     */
		i = 0;                  //se debe volver a inicializar para que nos muestre algun valor.
		while(i < rows){
			j = 0;                 
			while(j < cols){ 
				printf("%i\t",mat[(j*rows)+i]);      //Se cambia el orden entre filas y columnas para hacer la traspuesta.
				j++;
			}
			printf("\t");
			i++;
		}
			
    printf("\n");
    return 0;
}
