#include <stdio.h>
#include <stdlib.h>

#define LUNG 1024

typedef struct node{
    char nome[LUNG];
    struct node *next;
}Node;

int main() {
    Node *lista = (Node*)malloc(sizeof(Node));
    Node *temp = (Node*)malloc(sizeof(Node));
    printf("Inserisici il nome: ");
    gets(lista->nome);
    lista->next = NULL;
    printf("Nome 1: %s", lista->nome);

    printf("\nInserisci un nome: ");
    gets(temp->nome);
    temp->next = NULL;
    lista->next = temp;
    printf("nome 2: %s", lista->next->nome);

    printf("\nInserisci un nome: ");
    gets(temp->nome);
    temp->next = NULL;

    lista->next->next = temp;
    printf("nome 3: %s", lista->next->next->nome);

    do{
        printf("\nInserisci un nome: ");
        gets(temp->nome);
        temp->next = NULL;
        lista->next = temp;
        printf("nome 2: %s", lista->next->nome);
    }while(strcmp(tmp->nome, "0")==1);

    return 0;
}