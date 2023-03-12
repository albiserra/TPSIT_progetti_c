#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

typedef struct  node{
    int  valore;
    char nome[20];
    struct  node* next;//indirizzo del nodo successivo
}Node;

void inserimento(Node **tail, Node **head, Node *element){
    Node *curr=*tail;
    Node *prev = NULL;

    if (curr == NULL){
        *tail = element;
        *head = element;
    }else {
        curr->next = element;
    }

    *tail = element;
}

void stampa(Node *l){
    
    int k=0;
    //printf("STAMPA CON PROC: \n");
    while (l!=NULL && k<5)//puntatore alla lista diversa da NULL
    {
        printf("\n%s - %d \n",l->nome, l->valore);
        l=l->next;                                          //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
        k++;
    }
}

int  main()
{
    int n;
    char nom[20];
    Node* coda;                                            //tipo a puntatore a node
    coda = NULL;
    Node* lista;
    lista = NULL;
    Node* l;
    int k=0;
    
    do
    {
        printf("Inserisci il valore del viodeogioco o -1 per  terminare\n");
        scanf("%d",&n);

        if (n!=-1){
            printf("Inserisci il nome: \n");
            fflush(stdin);
            gets(nom);
        }

        if (n!=-1){
            Node *elem;
            elem = (Node*)malloc(sizeof(Node));
        
            elem->valore=n;
            strcpy(elem->nome,nom);
            elem->next=NULL;

            inserimento(&coda, elem, &lista);
        }
        
    } while (n>=0);

    stampa(coda);
    
    return  0;
}