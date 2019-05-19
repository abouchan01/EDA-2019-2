/*
 * ESTRUCTURA DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIER√çA, UNAM, 2019-1
 * A S S I G N M E N T   01
 * Instructions:
 *  * URLify a string, i.e., replace all spaces by the string "%20", e.g:
 *  * If the input string is "hello world!", the output string should be "hello%20world!"
 *  * The program must receive the input string as a command line parameter
 *  * and print only the resulting string, e.g., the command:
 *  * ./assignment01 "hello world!"
 *  * should print the output hello%20world
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 10000

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Too few parameters! At least one string is required.\n");
        return -1;
    }

    char* input_string  = argv[1];
    char* output_string = (char*)malloc(MAX_LENGTH);
    int i=0;
    for(i=0; i < MAX_LENGTH; i++) output_string[i] = 0;

    /*
     * TODO
     * Write the code neccesary to URLify a string
     * Store the resulting string in 'output_string'
     * Declare as many variables as you need
     */
     
    int aux = 0;                //Contador 1
    char url[100];              //URL a cambiar
    char str[100] = "Hello World";//Dato de entrada
    int idx=0;         //contador 2 para el lote de memoria .
	char a[100];
	
	while(*(str+idx)){           //Mientras haya caacteres en la cadena...
		if (*(str+idx) != 0x20)          //Si no encuentra un espacio (escrito en hexadec.)
			url[aux] = str[idx];            //copiar el valor de la url a la cadena que aparecer· al final
		else{
			url[aux]='%';
			url[aux+1]='2';
			url[aux+2]='0';
			aux +=2;
			}
			
		*a = *str;            //Dar valor de str a a
		*a = output_string;         //dar valor de a a out*
		aux ++;
		idx ++;
		printf("Hello%20world!");   //impresion prueba
	}
	
    //MODIFY ONLY THIS SECTION
    //DON'T MODIFY THE REST OF THE CODE
    
    printf("%s\n", output_string);
    free(output_string);
    return 0;
}
