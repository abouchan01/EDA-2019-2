/*
 * ESTRUCTURAS DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIERÍA, UNAM, 2019-1
 * P R A C T I C E   3
 * Instructions:
 * Write a program to implement the addition, substraction, cross product,
 * dot product, norm2, unitary vector and angle between vectors in R3.
 * The program must receive as command line arguments the operation code followed
 * by the values of the vectors to operate.
 * Operation codes are 'add', 'sub', 'cross', 'dot', 'mag', 'unit' o 'ang'
 * Example: the command
 * ./Practice_03 cross 1 0 0  0 1 0
 * should print the output
 * $ 0.00000,0.00000,1.00000
 * MODIFY ONLY THE INDICATED FUNCTIONS
 */

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct _Vector3 Vector3;

struct _Vector3
{
    /*
     * TODO:
     * Declare the necessary members to represent a vector in R3
     */
};

Vector3 Vector3_init(float x, float y, float z)
{
    /*
     * TODO:
     * Initialize all components in zero and return the Vector3
     */
}

Vector3 add(Vector3 a, Vector3 b)
{
    /*
     * TODO:
     * Implemente the addition of two vectors in R3 and return the result
     */
}

Vector3 substract(Vector3 a, Vector3 b)
{
    /*
     * TODO:
     * Implement the substraction of vectors a - b and return the result
     */
}

Vector3 cross_product(Vector3 a, Vector3 b)
{
    /*
     * TODO:
     * Implement the cross product and return the result
     */
}

float dot_product(Vector3 a, Vector3 b)
{    
    /*
     * TODO:
     * Implement the dot product and return the result
     */
}

float norm2(Vector3 a)
{
    /*
     * TODO:
     * Calculate the magnitud of vector a and return the result
     */
}

Vector3 unitary(Vector3 a)
{
    /*
     * TODO:
     * Calculate the unitary vector of 'a' and return the result
     */
}

float angle_ab(Vector3 a, Vector3 b)
{
    /*
     * TODO:
     * Calculate the angle between vectors 'a' and 'b' and return the result in radians
     */
}

void print_vector(Vector3 v)
{
    printf("%.7f,%.7f,%.7f\n", v.x, v.y, v.z);
}

int main(int argc, char** argv)
{
    if(argc < 2)
	return -1;

    Vector3 a,b;
    if(argc >= 5)
	a = Vector3_init(atof(argv[2]), atof(argv[3]), atof(argv[4]));
    if(argc >= 8)
	b = Vector3_init(atof(argv[5]), atof(argv[6]), atof(argv[7]));

    if(!strcmp(argv[1],"add") && argc >= 8)
	print_vector(add(a,b));
    else if(!strcmp(argv[1],"sub") && argc >= 8)
	print_vector(substract(a,b));
    else if(!strcmp(argv[1],"dot") && argc >= 8)
	printf("%f\n",dot_product(a,b));
    else if(!strcmp(argv[1],"cross") && argc >= 8)
	print_vector(cross_product(a,b));
    else if(!strcmp(argv[1],"ang") && argc >= 8)
	printf("%f\n", angle_ab(a,b));
    else if(!strcmp(argv[1],"mag") && argc >= 5)
	printf("%f\n", norm2(a));
    else if(!strcmp(argv[1],"unit") && argc >= 5)
	print_vector(unitary(a));
    
    return 0;
}
