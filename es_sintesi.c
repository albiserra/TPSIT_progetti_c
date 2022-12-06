#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4
#define LUNG 40

typedef struct{
    char *cognome;
    char *nome;
    int data;
}Persona;

/*int main(){

    Persona *pi=(Persona*)malloc(MAX*sizeof(Persona));
    Persona* inizio=pi;
    Persona tmp;
    FILE* fp;
    char riga[LUNG];
    int cont=0;


    fp=fopen("nascita.csv", "r");

    if(fp!=NULL){
        printf("File aperto\n");
        while(!feof(fp) && cont<MAX){
            fgets(riga, LUNG, fp);
            pi->cognome=strtok(riga, ",");
            pi->nome=strtok(NULL, ",");
            pi->data=atoi(strtok(NULL, ","));
            printf("%s %s %d\n", pi->cognome, pi->nome, pi->data);
            pi++;
        }
        pi=inizio;

        printf("%s %s %d\n", pi->cognome, pi->nome, pi->data);

        for(int i = 0; i < MAX-1; i++)
        {
            for(int k = 0; k < MAX - i; k++)
            {
                if(pi->data > (pi + 1)->data)
                {
                    tmp=*pi;
                    *pi=*(pi+1);
                    *(pi+1)=tmp;
                    printf("1\n");
                    printf("%s %s %d\n", pi->cognome, pi->nome, pi->data);
                }
                pi++;
            }
            pi=inizio;
        }
        
        printf("%s %s %d\n", pi->cognome, pi->nome, pi->data);

        for(pi=inizio; pi<inizio+MAX; pi++){
            printf("%s %s %d\n", pi->cognome, pi->nome, pi->data);
        }
        
        free(pi);
    
    }else{
        printf("Il file non esiste\n");
        return(0);
    }
}*/

int contaRighe(){
    char riga[LUNG];
    int cont=0;

    FILE *fp;
    fp=fopen("nascita.csv", "r");

    while(fgets(riga, LUNG, fp)){
        cont++;
    }
    fclose(fp);
    return cont;
}

void caricaDati(Persona* pers){
    Persona* p= pers;
    char riga[LUNG];

    FILE *fp;
    fp=fopen("nascita.csv", "r");

    printf("Lettura file:\n");

    while(fgets(riga, LUNG, fp)){
        pers->cognome = strdup(strtok(riga, ","));
        pers->nome = strdup(strtok(NULL, ","));
        pers->data = atoi(strtok(NULL, ","));
        printf("%s %s %d\n", pers->cognome, pers->nome, pers->data);
        pers++;
    }
    pers=p;
    fclose(fp);
}

void ordinamento(Persona* pers){
    Persona* p=pers;
    Persona tmp;

    for(int i = MAX-1; i >0; i--)
        {
            for(int k = 0; k < i; k++)
            {
                if(pers->data > (pers + 1)->data)
                {
                    tmp=*pers;
                    *pers=*(pers+1);
                    *(pers+1)=tmp;
                }
                pers++;
            }
            pers=p;
        }
}

void stampaDati(Persona* pers){
    Persona* p= pers;
    printf("Classifica dal piu' vecchio al piu' giovane:\n");
    for(pers=p; pers<p+MAX; pers++){
        printf("%s %s %d\n", pers->cognome, pers->nome, pers->data);
    }
    pers=p;
}

int main(){

    Persona *pi;
    int n=0;

    n=contaRighe();
    pi=(Persona*)malloc(n*sizeof(Persona));
    caricaDati(pi);
    ordinamento(pi);
    stampaDati(pi);
    free(pi);
}