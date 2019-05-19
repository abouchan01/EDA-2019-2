/*
 * ESTRUCTURA DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIERÍA, UNAM, 2019-1
 * A S S I G N M E N T   03
 * Instructions:
 * Write a program to determine if a string is a permutation of another one.
 * A string S1 is said to be a permutation of another string S2 if the
 * total number of each different character in S1 is the same than string S2.
 * The program must receive as command line arguments the two strings two be analized.
 * The output of the program must be only 1, if S1 is permutation of S2, and 0, otherwise.
 * THE USE OF EXTRA LIBRARIES IS NOT ALLOWED
 * MODIFY ONLY THE is_permutation FUNCTION
 */

#include<stdio.h>

int is_permutation(char* str1, char* str2)
{
    /*
     * TODO:
     * Implement an algorithm to check if str1 is a permutation of str2
     * You can follow these steps:
     * Declare two 256-sized arrays of ints, one for each string.
     * Initialize both arrays with zeros
     * Loop over the string 1 and count the total number of each character. Store in array1
     * Loop over the string 2 and count the total number of each character. Store in array2
     * Compare the i-th value of array1 with the i-th value of array2.
     * If a difference is found, return false, otherwise, return true.
     * ONLY MODIFY THIS FUNCTION. 
     */
	char  c;
	int count1[256], count2[256], i, true, false;
	true = 1;
	false = 0;
	for (i = 0; i < 256; i++)     //inicializamos todo en cero
	{
		count1[i] = 0;
		count2[i] = 0;
	};
	for(;*str1;str1++)  //recorremos el arreglo y le damos una variable a cada letra que suma uno cada vezz que lo encuentra
	{
		c = *str1;
		count1[c]++;
	};
		for(;*str2;str2++)  //recorremos el arreglo y le damos una variable a cada letra que suma uno cada vezz que lo encuentra pero en str2
	{
		c = *str2;
		count2[c]++;
	};
    for (i=0; i<= 256; i++)
    {
    	if (count1[i] != count2[i] || count2[i]!=count1[i]){     //Se detiene si encuentra un error o diferencia y regresa 0
			return 0 ;//False                                      
    		
		}
		
    	else {
		return true;
		}
    };
    
    
    
    
}

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        printf("Too few parameters! Two strings are required.\n");
        return -1;
    }

    printf("%d\n", is_permutation(argv[1], argv[2]));
    return 0;
}
