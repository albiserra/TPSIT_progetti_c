/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

typedef struct  node {
    int  valore;
    struct  node* next;
}Node;

void insertHead(Node** head, int newValore){
    Node* newTesta = (Node*)  malloc(sizeof(Node));

    

    newTesta->valore=newValore;
    newTesta->next=(*head);//il next punterà alla testa attuale

    (*head) = newTesta;
}

void insert_ordered(Node** head, Node* element){
    Node* curr=*head, *prev = NULL;

    while(curr != NULL){
        if(element->valore <= curr->valore){
            break;
        }
        prev=curr;
        curr=curr->next;

    }

    if(prev==NULL){
        *head = element;
    }else{
        prev->next = element;
    }
    element->next = curr;
}

void stampaLista(Node* l){
    while (l!=NULL)
    {
        printf("%d - %p \n",l->valore, l->next);
        l=l->next;
    }
    printf("\n");
}

void stampaListaRicorsiva(Node* l){

        printf("%d - %p \n",l->valore, l->next);
        if(l->next!=NULL){
            stampaListaRicorsiva(l->next);
        }
        printf("\n");
}

void contaElementi(Node* l){
    int cont=0;
    while (l!=NULL)
    {
        cont++;
        l=l->next;
    }
    printf("Numero elementi: %d", cont);
}



int contaElementiRicorsiva(Node* l, int cont){
        cont++;
        if(l->next!=NULL){
            cont = contaElementiRicorsiva(l->next, cont);
        }
    return cont;
}

void dealloca(Node *l){
    Node* tmp;
    if(l!=NULL)
    {
        tmp->next = l->next;
        free(*l);
        dealloca(tmp);
    }
}

int  main()
{
    int n;
    Node* lista;
    Node* l;
    lista=NULL;
    Node* tmp;


    int cont=0;
    
    /*do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d",&n);
        if (n>=0) 
        {
            if (lista==NULL) //prima  iterazione 
            {
                lista = (Node*)  malloc(sizeof(Node));
                l = lista;
            }
            else //iterazioni  successive
            {
                l->next = (Node*)  malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n>=0);*/
    lista=l;

    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d", n);
        if (n!=-1) 
        {
            Node* elemento;
            elemento=(*Node)malloc(sizeof(Node));
            elemento->element=n;
            insert_ordered(&l, elemento);
            l->next = NULL;
        }
    } while (n!=-1);
    
    l=lista;
    insertHead(&l, 8);
    printf("numeri  inseriti: \n");
    stampaListaRicorsiva(l);

    l=lista;
    cont=contaElementiRicorsiva(l, cont);
    printf("Numero elementi: %d", cont);
    return  0;
}