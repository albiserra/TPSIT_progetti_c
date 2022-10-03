#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16601
#define LUNG 20

typedef struct dati {
    int rank;
    char* name;
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float NA_sales;
    float EU_sales;
    float JP_sales;
    float other_sales;
    float global_sales;

} dati;

int main() {
    FILE *fp;
    char riga[MAX];
    dati info[MAX];
    int cont = 0;
    dati *pi = info;

    fp = fopen("vgsales.csv", "r");
    if(fp == NULL) {
        printf("Errore nell'apertura del file\n");
        return 0;
    } else {
        printf("Entrato\n");
    }
    while(!feof(fp) && cont<=MAX) {
        fgets(riga, MAX, fp);
        pi->rank = atoi(strtok(riga, ","));
        pi->name=strtok(NULL, ",");
        pi->platform = strtok(NULL, ",");
        pi->year = atoi(strtok(NULL, ","));
        pi->genre = strtok(NULL, ",");
        pi->publisher = strtok(NULL, ",");
        pi->NA_sales = atof(strtok(NULL, ","));
        pi->EU_sales = atof(strtok(NULL, ","));
        pi->JP_sales = atof(strtok(NULL, ","));
        pi->other_sales = atof(strtok(NULL, ","));
        pi->global_sales = atof(strtok(NULL, ","));
        printf("%d\t", pi->rank);
        printf("%s\t", pi->name);
        printf("%s\t", pi->platform);
        printf("%d\t", pi->year);
        printf("%s\t", pi->genre);
        printf("%s\t", pi->publisher);
        printf("%f\t", pi->NA_sales);
        printf("%f\t", pi->EU_sales);
        printf("%f\t", pi->JP_sales);
        printf("%f\t", pi->other_sales);
        printf("%f\n", pi->global_sales);
        cont++;
        *pi++;
    }

    fclose(fp);
    return 0;
}
