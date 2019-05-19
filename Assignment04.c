/*
 * ESTRUCTURA DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIERÍA, UNAM, 2019-1
 * A S S I G N M E N T   04
 * Instructions:
 * Write a program to determine if a string is one-edit away of another string..
 * A string S1 is said to be a one-edit of another string S2 if ONLY ONE of the following conditions is held:
 * a) S1 is obtained from S2 by chaging one character
 * b) S1 is obtained from S2 by deleting one character
 * c) S1 is obtained from S2 by inserting one character
 * Examples:
 * bear -> beer  = true
 * bear -> bar   = true
 * bear -> beard = true
 * bear -> ber   = false
 * The program must receive as command line arguments the two strings two be analized.
 * The output of the program must be 1, if S1 is one-edit away of S2, and 0, otherwise.
 * THE USE OF EXTRA LIBRARIES IS NOT ALLOWED
 * MODIFY ONLY THE INDICATED FUNCTIONS
 */

#include<stdio.h>

int string_length(char* str)
{
    /*
     * TODO:
     * Implement a function that return the lenght of the string
     */
     int len=0;
     for(;str[len]!=0;len++);
     return len;

}

int is_one_edit_replace(char* str1, char* str2)
{
    /*
     * TODO:
     * Implement a function to determine if a string str2 can be obtained
     * from string str1 by replacing only one character.
     */
    int diferentes=0;
    int posible=0;
    int iguales=0;
    int i=0;
    if(string_length(str1)==string_length(str2)){
    	for(;str1[i]!=0;i++){
    		if(str1[i]!=str2[i]){
    			diferentes++;
    			i++;
    			if(str1[i]==str2[i]){
    				posible++;
    				iguales++;
    			}else
    				diferentes++;
    		}
else
    			iguales++;
            }
	    }
	else
		return 0;

	if(diferentes==0){
		printf("It's the same string.");
	}

	if((diferentes+iguales)==string_length(str1) && posible==1){
		return 1;
	}
	else
		return 0;

}

int is_one_edit_insert(char* str1, char* str2)
{
    /*
     * TODO:
     * Implement a function to determine if a string str2 can be obtained
     * from string str1 by inserting only one character.
     */
     int diferente=0;
     int iguale=0;
     int posible=0;
     int o=0;
     int u=0;
     if(((string_length(str1))+1)==string_length(str2)){
     	for(;str1[o]!=0;o++){
		 		if(str1[o]!=str2[u]){
    				diferente++;
    				u++;
    				if(str1[o]==str2[u]){
    					posible++;
    					iguale++;
    				}
    				else
    					diferente++;
		 	   	 }
		 	   	 else
		 	   	 	iguale++;
     	 }
     }
     else{
     	return 0;
     }
    if((diferente+iguale)==string_length(str2) && posible==1){
    	return 1;
    }else
		return 0;
}

int is_one_edit(char* str1, char* str2)
{
    /*
     * TODO:
     * Implement a function to determine if a string str2 can be obtained
     * from string str1 by a one-edit process.
     * Use the previous functions.
     */
     if(string_length(str1)<string_length(str2))
	 	is_one_edit_insert(str1,str2);

	if(string_length(str1)==string_length(str2))
    	is_one_edit_replace(str1,str2);
}

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        printf("Too few parameters! Two strings are required.\n");
        return -1;
    }

    printf("%d\n", is_one_edit(argv[1], argv[2]));
    return 0;
}
