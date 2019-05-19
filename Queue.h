/*
 * Implementación de varias colas para varios tipos de datos
 */

#define QUEUE_CAPACITY 1000
#include <stdlib.h>

typedef struct _QueueInt{
    int data[QUEUE_CAPACITY];
    int head;
    int tail;
    int size;
}QueueInt;

typedef struct _QueueChar{
    char data[QUEUE_CAPACITY];
    int head;
    int tail;
    int size;
}QueueChar;

typedef struct _QueueFloat{
    float data[QUEUE_CAPACITY];
    int head;
    int tail;
    int size;
}QueueFloat;

typedef struct _QueueString{
    char* data[QUEUE_CAPACITY];
    int head;
    int tail;
    int size;
}QueueString;

QueueInt queue_int_initialize()
{
    QueueInt Q;
    Q.head = 0;
    Q.tail = -1;
    Q.size = 0;
    return Q;
}

QueueChar queue_char_initialize()
{
    QueueChar Q;
    Q.head = 0;
    Q.tail = -1;
    Q.size = 0;
    return Q;
}

QueueFloat queue_float_initialize()
{
    QueueFloat Q;
    Q.head = 0;
    Q.tail = -1;
    Q.size = 0;
    return Q;
}

QueueString queue_string_initialize()
{
    QueueString Q;
    Q.head = 0;
    Q.tail = -1;
    Q.size = 0;
    return Q;
}

int queue_int_is_full(QueueInt* Q)
{
    return Q->size == QUEUE_CAPACITY;
}

int queue_char_is_full(QueueChar* Q)
{
    return Q->size == QUEUE_CAPACITY;
}

int queue_float_is_full(QueueFloat* Q)
{
    return Q->size == QUEUE_CAPACITY;
}

int queue_string_is_full(QueueString* Q)
{
    return Q->size == QUEUE_CAPACITY;
}

int queue_int_is_empty(QueueInt* Q)
{
    return Q->size == 0;
}

int queue_char_is_empty(QueueChar* Q)
{
    return Q->size == 0;
}

int queue_float_is_empty(QueueFloat* Q)
{
    return Q->size == 0;
}

int queue_string_is_empty(QueueString* Q)
{
    return Q->size == 0;
}

void queue_int_enqueue(QueueInt* Q, int k)
{
    if(queue_int_is_full(Q))
	exit(-1);
    Q->tail = (Q->tail + 1) % QUEUE_CAPACITY;
    Q->data[Q->tail] = k;
    Q->size++;
}

void queue_char_enqueue(QueueChar* Q, char k)
{
    if(queue_char_is_full(Q))
	exit(-1);
    Q->tail = (Q->tail + 1) % QUEUE_CAPACITY;
    Q->data[Q->tail] = k;
    Q->size++;
}

void queue_float_enqueue(QueueFloat* Q, float k)
{
    if(queue_float_is_full(Q))
	exit(-1);
    Q->tail = (Q->tail + 1) % QUEUE_CAPACITY;
    Q->data[Q->tail] = k;
    Q->size++;
}

void queue_string_enqueue(QueueString* Q, char* k)
{
    if(queue_string_is_full(Q))
	exit(-1);
    Q->tail = (Q->tail + 1) % QUEUE_CAPACITY;
    Q->data[Q->tail] = k;
    Q->size++;
}

int queue_int_dequeue(QueueInt* Q)
{
    if(queue_int_is_empty(Q))
	exit(-1);
    int t = Q->data[Q->head];
    Q->head = (Q->head + 1) % QUEUE_CAPACITY;
    Q->size--;
    return t;
}

char queue_char_dequeue(QueueChar* Q)
{
    if(queue_char_is_empty(Q))
	exit(-1);
    char t = Q->data[Q->head];
    Q->head = (Q->head + 1) % QUEUE_CAPACITY;
    Q->size--;
    return t;
}

float queue_float_dequeue(QueueFloat* Q)
{
    if(queue_float_is_empty(Q))
	exit(-1);
    float t = Q->data[Q->head];
    Q->head = (Q->head + 1) % QUEUE_CAPACITY;
    Q->size--;
    return t;
}

char* queue_string_dequeue(QueueString* Q)
{
    if(queue_string_is_empty(Q))
	exit(-1);
    char* t = Q->data[Q->head];
    Q->head = (Q->head + 1) % QUEUE_CAPACITY;
    Q->size--;
    return t;
}

int queue_int_head(QueueInt* Q)
{
    if(queue_int_is_empty(Q))
	exit(-1);
    return Q->data[Q->head];
}

char queue_char_head(QueueChar* Q)
{
    if(queue_char_is_empty(Q))
	exit(-1);
    return Q->data[Q->head];
}

float queue_float_head(QueueFloat* Q)
{
    if(queue_float_is_empty(Q))
	exit(-1);
    return Q->data[Q->head];
}

char* queue_string_head(QueueString* Q)
{
    if(queue_string_is_empty(Q))
	exit(-1);
    return Q->data[Q->head];
}

int queue_int_tail(QueueInt* Q)
{
    if(queue_int_is_empty(Q))
	exit(-1);
    return Q->data[Q->tail];
}

char queue_char_tail(QueueChar* Q)
{
    if(queue_char_is_empty(Q))
	exit(-1);
    return Q->data[Q->tail];
}

float queue_float_tail(QueueFloat* Q)
{
    if(queue_float_is_empty(Q))
	exit(-1);
    return Q->data[Q->tail];
}

char* queue_string_tail(QueueString* Q)
{
    if(queue_string_is_empty(Q))
	exit(-1);
    return Q->data[Q->tail];
}

