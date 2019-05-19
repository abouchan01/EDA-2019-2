/*
 * ESTRUCTURAS DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIERÍA, UNAM, 2019-1
 * P R A C T I C E   2 
 * Instructions:
 * Write a program to implement the Caesar Cipher
 * The program must receive as command line arguments, the number
 * of positions to shift, and the string to be ciphered.
 * Only the characters in a-z and A-Z must be shifted and
 * all the other chars must remain the same.
 
 * ONLY MODIFY THE FUNCTION caesar_cipher
 * USE OF POINTERS IS MANDATORY
 * THE ARRAY NOTATION [] IS NOT ALLOWED
 */

#include <stdio.h>
#include <stdlib.h>

char* caesar_cipher(char* str, int n)
{
    //Bouchan Ramirez Abraham
    //Por el momento solo sirve el cifrado con un maximo de recorrido de 26 
	char* aux = str;
	for(;*str;str++)
		{
		if ((*str>=65 && *str<= 90)||(*str>=97 && *str<= 122))
			{
			*str += n;
			
			if(*str > 90 && *str < 121)
				while(*str > 90 && *str < 94)
					{
					*str=((*str+n)-90)+65;         //Lo que se hace aqui es imprimir solo la diferencia de posiciones
					}
				*str -= 26;
				if(*str > 122)
				{
				while(*str > 122)
					{
					*str=((*str+n)-122)+96;    //Debemos hacer lo mismo tanto en mayusculas como minusculas
					}
				*str -= 26;
				}
			}
		}
	return aux;   //debemos poner otra variable, ya que str ya tiene otros valores
}

int main(int argc, char** argv)
{
    int i, n;
    if(argc < 3)
    {
        printf("Too few parameters! Usage:\n");
        printf("./Practice_02 n string\n");
	return -1;
    }
    n = atoi(argv[1]);
    for(i=2; i < argc; i++)
        printf("%s\n", caesar_cipher(*(argv + i), n));
    
    return 0;    
}
