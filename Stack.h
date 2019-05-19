/*
 * Implementación de varias pilas para varios tipos de datos
 */

#define STACK_CAPACITY 1000
#include <stdlib.h>

typedef struct _StackInt{
    int data[STACK_CAPACITY];
    int top;
}StackInt;

typedef struct _StackChar{
    char data[STACK_CAPACITY];
    int  top;
}StackChar;

typedef struct _StackFloat{
    float data[STACK_CAPACITY];
    int   top;
}StackFloat;

typedef struct _StackString{
    char* data[STACK_CAPACITY];
    int   top;
}StackString;

StackInt stack_int_initialize()
{
    StackInt S;
    S.top = -1;
    return S;
}

StackChar stack_char_initialize()
{
    StackChar S;
    S.top = -1;
    return S;
}

StackFloat stack_float_initialize()
{
    StackFloat S;
    S.top = -1;
    return S;
}

StackString stack_string_initialize()
{
    StackString S;
    S.top = -1;
    return S;
}

int stack_int_is_full(StackInt* S)
{
    return S->top == STACK_CAPACITY - 1;
}

int stack_char_is_full(StackChar* S)
{
    return S->top == STACK_CAPACITY - 1;
}

int stack_float_is_full(StackFloat* S)
{
    return S->top == STACK_CAPACITY - 1;
}

int stack_string_is_full(StackString* S)
{
    return S->top == STACK_CAPACITY - 1;
}

int stack_int_is_empty(StackInt* S)
{
    return S->top == -1;
}

int stack_char_is_empty(StackChar* S)
{
    return S->top ==  -1;
}

int stack_float_is_empty(StackFloat* S)
{
    return S->top ==  -1;
}

int stack_string_is_empty(StackString* S)
{
    return S->top ==  -1;
}

void stack_int_push(StackInt* S, int k)
{
    if(stack_int_is_full(S))
	exit(-1);
    S->top++;
    S->data[S->top] = k;
}

void stack_char_push(StackChar* S, char k)
{
    if(stack_char_is_full(S))
	exit(-1);
    S->top++;
    S->data[S->top] = k;
}

void stack_float_push(StackFloat* S, float k)
{
    if(stack_float_is_full(S))
	exit(-1);
    S->top++;
    S->data[S->top] = k;
}

void stack_string_push(StackString* S, char* k)
{
    if(stack_string_is_full(S))
	exit(-1);
    S->top++;
    S->data[S->top] = k;
}

int stack_int_pop(StackInt* S)
{
    if(stack_int_is_empty(S))
	exit(-1);
    S->top--;
    return S->data[S->top+1];
}

char stack_char_pop(StackChar* S)
{
    if(stack_char_is_empty(S))
	exit(-1);
    S->top--;
    return S->data[S->top+1];
}

float stack_float_pop(StackFloat* S)
{
    if(stack_float_is_empty(S))
	exit(-1);
    S->top--;
    return S->data[S->top+1];
}

char* stack_string_pop(StackString* S)
{
    if(stack_string_is_empty(S))
	exit(-1);
    S->top--;
    return S->data[S->top+1];
}

int stack_int_peek(StackInt* S)
{
    if(stack_int_is_empty(S))
	exit(-1);
    return S->data[S->top];
}

char stack_char_peek(StackChar* S)
{
    if(stack_char_is_empty(S))
	exit(-1);
    return S->data[S->top];
}

float stack_float_peek(StackFloat* S)
{
    if(stack_float_is_empty(S))
	exit(-1);
    return S->data[S->top];
}

char* stack_string_peek(StackString* S)
{
    if(stack_string_is_empty(S))
	exit(-1);
    return S->data[S->top];
}

int stack_int_bottom(StackInt* S)
{
    if(stack_int_is_empty(S))
	exit(-1);
    return S->data[0];
}

char stack_char_bottom(StackChar* S)
{
    if(stack_char_is_empty(S))
	exit(-1);
    return S->data[0];
}

float stack_float_bottom(StackFloat* S)
{
    if(stack_float_is_empty(S))
	exit(-1);
    return S->data[0];
}

char* stack_string_bottom(StackString* S)
{
    if(stack_string_is_empty(S))
	exit(-1);
    return S->data[0];
}
