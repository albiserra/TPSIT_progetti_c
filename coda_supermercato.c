#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 4
#define MIN 1
#define MINTOT 100

typedef struct cliente{
    int tmpArrivo;
    int tmpServito;
    struct cliente *next;
}Cliente;

bool is_empty(Cliente* head){//controllo se la coda e' vuota
    if(head == NULL) return true;
    else return false;
}

//stampa coda
void stampaCoda(Cliente *cl){
    while(cl != NULL){
       printf("%d, %d\n", cl->tmpArrivo, cl->tmpServito);
        cl = cl->next;
    }
}

//funzione per stampare il cliente
void stampaCliente(Cliente *cl){
    printf("%d, %d\n", cl->tmpArrivo, cl->tmpServito);
}

//funzione per iserire i valori
void enqueue(struct cliente **head, struct cliente **tail, struct cliente *element){
    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next = element;
    }
    *tail = element;
    element->next=NULL;
}

//funzione per estrarre i valori
struct cliente * dequeue(struct cliente **head, struct cliente **tail){
    struct cliente *ret = *head;
     if(is_empty(*head)){
         return NULL;
     }else{
         *head = ret->next;
     }

     if(*head == NULL){
         *tail = NULL;
     }
     return ret;
}

void dealloc(Cliente* cl){
    free(cl);
}

int main(){

    //head e tail della coda
    Cliente* head = NULL;
    Cliente* tail = NULL;

    //cliente da aggiungere alla coda
    Cliente* cl;

    Cliente* clServito;

    srand(time(NULL));

    int tmpArrivo;
    int tmpServ = 0;

    cl = (Cliente*)malloc(sizeof(Cliente));
    cl->tmpArrivo = rand()%MAX+MIN;
    printf("%d\n", cl->tmpArrivo);
    cl->tmpServito = cl->tmpArrivo + rand()%MAX+MIN;

    for(int k = 0; k < MINTOT; k++){
        
        if(cl->tmpArrivo == k){
            printf("arrivo");
            
            enqueue(&head, &tail, cl);
            stampaCoda(head);
            cl = (Cliente*)malloc(sizeof(Cliente));
            cl->tmpArrivo = k + rand()%MAX+MIN;
            if(!is_empty(head)){
                cl->tmpServito = cl->tmpArrivo + rand()%MAX+MIN;
            }/*else{
                cl->tmpServito = tail->tmpServito + rand()%MAX+MIN;
            }*/
        }

        if(head != NULL && head->tmpServito == k){
            clServito = dequeue(&head, &tail);
            printf("fatto");
            stampaCliente(clServito);
            free(clServito);
            head->tmpServito = k + rand()%MAX+MIN;
        }
    }
}