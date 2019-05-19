/*
 * ESTRUCTURAS DE DATOS Y ALGORITMOS I
 * FACULTAD DE INGENIER√?A, UNAM, 2019-1
 * P R √? C T I C A   8
 * LISTA DE REPRODUCCI√?N USANDO UNA LISTA DOBLEMENTE LIGADA CIRCULAR
 * 
 * Instrucciones:
 * Implementar las operaciones de inserci√≥n, b√∫squeda y eliminaci√≥n en una lista doblemente ligada circular.
 * El programa implementar√° las opciones de "next", "prev", "add" y "remove"
 * y estas operaciones deber√°n imitar las funciones de una lista de reproducci√≥n.
 * Si se elige 'next' estando en el √∫ltimo elemento, el nodo actual debe apuntar al primero, 
 * y un funcionamiento similar se debe mostrar para la opci√≥n 'prev'
 * 
 * Restricciones.
 * SOLO SE PERMITE EL USO DE BIBLIOTECAS EST√?NDAR
 * NO CAMBIAR LA FUNCI√?N MAIN.
 * S√?LO MODIFICAR LAS FUNCIONES INDICADAS
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
    char* data;
    struct _Node* next;
    struct _Node* prev;
    
}Node;

typedef struct _CircularDoubleLinkedList
{
    Node* head;
}CircularDoubleLinkedList;

Node* node_initialize(char* data)
{
    Node* n = (Node*)malloc(sizeof(Node));
    int len = strlen(data);
    n->data = (char*)malloc(len+1);
    char* ptr = n->data;
    memcpy(ptr, data, len);
    ptr += len;
    *ptr = 0;
    n->next = 0;
    n->prev = 0;
    return n;
}

CircularDoubleLinkedList circular_double_linked_list_initialize()
{
    CircularDoubleLinkedList L;
    L.head = 0;
    return L;
}

Node* circular_double_linked_list_search(CircularDoubleLinkedList* L, char* k)
{
   
     int p=0;
     Node* x=L->head; 
   	 while(p!=2){ 
			if(strcmp(k, x->data)==0){ 
        	    return x; 
        }
      		if(x==L->head || x->next==L->head){
        		p++;
        	}
	    x=x->next; 
    } return 0;
}

void circular_double_linked_list_insert(CircularDoubleLinkedList* L, char* k)
{
    Node* x = node_initialize(k);
   
            if(L->head==NULL)
     	L->head = x;
     else{			
     	x->next=L->head; 	
     	L->head->prev=x;
     	L->head=x;	
     }
}

void circular_double_linked_list_delete(CircularDoubleLinkedList* L, char* k)
{
   
   
      Node* x=circular_double_linked_list_search( L, k); 
  if(x!=L->head && x!=NULL){
        x->next->prev=x->prev;
        x->prev->next=x->next;
    	}
		if(x==L->head && x!=NULL){	 
        L->head->prev->next=L->head->next;
		L->head=L->head->next;		
        }
}

void print_current_node(CircularDoubleLinkedList* L, Node* current)
{
    
    
      Node* x = L->head;
    printf("\nYOUR PLAYLIST:\n");
    
    while(x != 0)
    {
        if(x == current)
            printf("-> ");
        else
            printf("   ");
        printf("%s\n", x->data);
        x = x->next;
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    CircularDoubleLinkedList L = circular_double_linked_list_initialize();
    circular_double_linked_list_insert(&L, "Bohemian_Rapsody");
    circular_double_linked_list_insert(&L, "Imagine");
    circular_double_linked_list_insert(&L, "Another_brick_in_the_wall");
    Node* current = L.head;
    print_current_node(&L, current);

    char cmd[1000];
    int valid_cmd = 0;
    printf("Type command: ");
    scanf("%s", cmd);
    while(strcmp(cmd, "exit") != 0)
    {
        valid_cmd = 1;
        if(strcmp(cmd, "prev") == 0 && current->prev != 0)
            current = current->prev;
        else if(strcmp(cmd, "next") == 0 && current->next != 0)
            current = current->next;
        else if(strcmp(cmd, "insert") == 0)
        {
            printf("Enter title to insert: ");
            scanf("%s", cmd);
            circular_double_linked_list_insert(&L, cmd);
        }
        else if(strcmp(cmd, "del") == 0)
        {
            printf("Enter title to delete: ");
            scanf("%s", cmd);
            circular_double_linked_list_delete(&L, cmd);
        }
        else
        {
            printf("Invalid command\n");
            valid_cmd = 0;
        }

        if(valid_cmd)
            print_current_node(&L, current);
        printf("Type command: ");
        scanf("%s", cmd);
    }
    
    
    return 0;
}
