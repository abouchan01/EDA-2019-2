/*
 * ESTRUCTURAS DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIER√çA, UNAM, 2019-1
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
	float x;
	float y;
	float z;
};

Vector3 Vector3_init(float x, float y, float z)
{
    /*Bouchan Ramirez Abraham
     * TODO:
     * Initialize all components in zero and return the Vector3
     */
    
     Vector3 vector;
     vector.x = 0.0;
     vector.y = 0.0;
     vector.z = 0.0;
     return vector;
}

Vector3 add(Vector3 a, Vector3 b)
{
		//En el metodo de suma solamente necesitamos sumar componentes iguales
    Vector3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
     
}

Vector3 substract(Vector3 a, Vector3 b)
{
    /*
     * TODO:
     * Implement the substraction of vectors a - b and return the result
     */
     //Por el contrario en la sustraccion solamente debemos restar elemento por elemento
     Vector3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

Vector3 cross_product(Vector3 a, Vector3 b)
{
    /*
     * TODO:
     * Implement the cross product and return the result
     */
     Vector3 result;
    result.x = (a.y*b.z) - (b.y*a.z);
    result.y =-((a.x*b.z)-(b.x*a.z));
    result.z =(a.x*b.y) - (b.x*a.y);
    return result;
     //Fue utilizado el mÈtodo por determinantes
}

float dot_product(Vector3 a, Vector3 b)
{    
    /*
     * TODO:
     * Implement the dot product and return the result
     */
    float result;
	Vector3 prod;
	prod.x = a.x*b.x;
	//Primero se multiplican mismos terminos 
	prod.y = a.y*b.y;
	prod.z = a.z*b.z;
	result = prod.x + prod.y + prod.z;
	//luego se suman los productos anteriores
	return result;
}

float norm2(Vector3 a)
{
    /*
     * TODO:
     * Calculate the magnitud of vector a and return the result
     */
     float result;
     float cuad;
     cuad = pow(a.x,2) + pow(a.y,2) + pow(a.z,2);   //Se elevan al cuadrado los tÈrminos y se suman
     result = pow(cuad,(1/2));  //Se le saca la raiz cuadrada
     return result;
}

Vector3 unitary(Vector3 a)
{
    /*
     * TODO:
     * Calculate the unitary vector of 'a' and return the result
     */
     Vector3 result;
     float mag; //Magnitud del vector
	 float cuad;//Cuadrados de A
     cuad = pow(a.x,2) + pow(a.y,2) + pow(a.z,2); //Se elevan al cuadrado tods los terminos
     mag = pow(cuad,(1/2)); //Se elevan a un medio para sacar la raÌz
     result.x = a.x/mag;
     result.y = a.y/mag;
     result.z = a.z/mag;
     //Se acomodan en la estructura.
     return result;
}

float angle_ab(Vector3 a, Vector3 b)
{
    /*
     * TODO:
     * Calculate the angle between vectors 'a' and 'b' and return the result in radians
     */
    float result;
    float dot,cuadA,cuadB,resultA, resultB;   //dot es el resultado de producto punto, mag la magnitud del vector, cuadA la suma de los cuadrados de A y cuadB la suma de los cuadrados de B
    //resultA es la raiz de los cuadrados de A, en cambio resultB la de B 
	Vector3 prod;
	prod.x = a.x*b.x;
	prod.y = a.y*b.y;
	prod.z = a.z*b.z;
	dot = prod.x + prod.y + prod.z;
    cuadA = pow(a.x,2) + pow(a.y,2) + pow(a.z,2);
    resultA = pow(cuadA,(1/2));
	cuadB = pow(b.x,2) + pow(b.y,2) + pow(b.z,2);
    resultB = pow(cuadB,(1/2));
    double x; //Aqui vamos a guardar la ecuacion 
    x = ((dot)/(resultA*resultB));
    result = acos(x); 
    //Acos nos ayuda a sacar el arco coseno de X
	//Bouchan Ramirez Abraham
	
	return result; 
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
