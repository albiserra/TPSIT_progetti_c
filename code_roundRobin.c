#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define LENGHT 20
#define MAX_RAND 4
#define MIN_RAND 1
#define MIN_TEMP 50
#define MAX_TEMP 200
#define T_CPU 30

typedef struct process{
    int pid;
    char stato[LENGHT];
    int time;
    struct process *next;
}Process;

bool is_empty(Process* head){//controllo se la coda e' vuota
    if(head == NULL) return true;
    else return false;
}

//stampa coda
void stampaCoda(Process *pr){
    while(pr != NULL){
       printf("%d, %s, %d\n", pr->pid, pr->stato, pr->time);
        pr = pr->next;
    }
}


//funzione per iserire i valori
void enqueue(struct process **head, struct process **tail, struct process *element){
    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next = element;
    }
    *tail = element;
    element->next=NULL;
}

//funzione per estrarre i valori
struct process * dequeue(struct process **head, struct process **tail){
    struct process *ret = *head;
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


int main(){
    //head e tail del nuovo processo
    Process* NL_h = NULL;
    Process* NL_t = NULL;
    
    //head e tail del processo pronto
    Process* RL_h = NULL;
    Process* RL_t = NULL;

    //head e tail del processo termnato 
    Process* TL_h = NULL;
    Process* TL_t = NULL;

    //creo il processo
    Process *process;

    //variabile per il tempo random assegnato al processo
    int tmp=0;

    //variabile per assegnare il nuovo tempo in caso di tempo insufficente nella cpu
    int new_tmp=0;

    srand(time(NULL));

    //creo il numero di processi random
    int n_process;
    n_process=rand()%MAX_RAND+MIN_RAND;
    printf("Numero di processi: %d \n", n_process);

    //ciclo per allocare i processi
    for(int k=0; k<n_process; k++){
        tmp=0;//assegno 0 al tempo
        
        //alloco il processo
        process=(Process*)malloc(sizeof(Process));

        //assegno all'identificatore il valore di k 
        process->pid=k;

        //assegno lo stato
        strcpy(process->stato, "NUOVO");

        //assegno un tempo random al processo necessario alla sua esecuzione
        tmp=rand()%MAX_TEMP+MIN_TEMP;
        process->time=tmp;

        //aggiungo il processo
        enqueue(&NL_h, &NL_t, process);
    }
    printf("Il caricamento e' stato eseguito\n");
    stampaCoda(NL_h);
    printf("\n");



    //passaggio da stato nuovo a pronto
    for(int i=0; i<n_process; i++){

        //estraggo dalla coda dei nuovi processi
        Process *process= dequeue(&NL_h, &NL_t);

        //cambio lo stato
        strcpy(process->stato, "pronto");

        //inserimento del processo nella coda dei pronti
        enqueue(&RL_h, &RL_t, process);
    }
    printf("Caricamento nella lista ready eseguito\n");
    stampaCoda(RL_h);
    printf("\n");

    //ciclo per eseguire i processi(entro solo se la coda ne ha almeno 1)
    while(RL_h!=NULL){

        //tolgo il processo dalla coda ready
        process = dequeue(&RL_h, &RL_t);

        //controllo che il tempo a disposizione dalla cpu sia sufficiente
        if(process->time+T_CPU>MAX_TEMP){
            //assegno al tempo del processo il restante da eseguire
            new_tmp=(process->time+T_CPU)-MAX_TEMP;
            process->time=new_tmp;

            //lo inserisco di nuovo nella ready 
            enqueue(&RL_h, &RL_t, process);

            //messaggio di segnalazione
            printf("\n TEMPO INSUFFICIENTE : processo numero %d \n", process->pid);

        }else{//se il tempo è sufficente lo eseguo e lo termino
            //cambio lo stato
            strcpy(process->stato, "eseguibile");

            //aggiungo ai terminati
            enqueue(&TL_h, &TL_t, process);
        } 
    }

    //stampo la coda dei processi terminati per vedere se è andato a buon fine
    printf("termine esecuzione\n");
    stampaCoda(TL_h);

}