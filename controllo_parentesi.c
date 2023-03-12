#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <stdbool.h>

typedef struct stack_node{
    char p;
    struct stack_node* next;
}Stack_node;

void push(Stack_node **head, Stack_node *element) {
    printf("push\n");
    if(head == NULL) {
        *head = element;
        element->next = NULL;
    }
    else {
        element->next = *head;
        *head = element;
    }
}

Stack_node *pop(Stack_node **head){
    printf("pop\n");
    Stack_node *ret = *head;
    if(head == NULL){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

bool controllo(char str[1024], Stack_node **head){
    int k=0;
    while(str[k]!='\0'){
        if(str[k]=='(' || str[k]=='[' || str[k]=='{'){
            Stack_node* elemento;
            elemento=(Stack_node*)malloc(sizeof(Stack_node));
            elemento->p=str[k];
            push(head, elemento);
        }

        if(str[k]==')'){
            if(*head->p=='('){
                *head = pop(head);
            }
        }else if(str[k]==']'){
            if(str[k]=='['){
                *head = pop(head);
            }
        }else if(str[k]=='}'){
            if(str[k]=='{'){
                *head = pop(head);
            }
        }
        k++;
    }
    if(*head == NULL){
        return true;
    }else{
        return false;
    }
}

int main(){
    char str[1024];
    printf("Inserire la stringa: ");
    fflush(stdin);
    gets(str);
    printf("%s", str);

    Stack_node* pila;
    pila=(Stack_node*)malloc(sizeof(Stack_node));
    if(controllo(str, &pila)){
        printf("Le parentesi sono state chiuse correttamente\n");
    }else{
        printf("Le parentesi non sono state chiuse correttamente\n");
    }
}