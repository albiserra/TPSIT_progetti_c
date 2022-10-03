#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
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
    fp = fopen("vgsales.csv", "r");
    if(fp == NULL) {
        printf("Errore nell'apertura del file\n");
        return 0;
    } else {
        printf("Entrato\n");
    }
    while(!feof(fp)) {
        fgets(riga, MAX, fp);
        info[cont].rank = atoi(strtok(riga, ","));
        info[cont].name=strtok(NULL, ",");
        info[cont].platform = strtok(NULL, ",");
        info[cont].year = atoi(strtok(NULL, ","));
        info[cont].genre = strtok(NULL, ",");
        info[cont].publisher = strtok(NULL, ",");
        info[cont].NA_sales = atof(strtok(NULL, ","));
        info[cont].EU_sales = atof(strtok(NULL, ","));
        info[cont].JP_sales = atof(strtok(NULL, ","));
        info[cont].other_sales = atof(strtok(NULL, ","));
        info[cont].global_sales = atof(strtok(NULL, ","));
        printf("%d\t", info[cont].rank);
        printf("%s\t", info[cont].name);
        printf("%s\t", info[cont].platform);
        printf("%d\t", info[cont].year);
        printf("%s\t", info[cont].genre);
        printf("%s\t", info[cont].publisher);
        printf("%f\t", info[cont].NA_sales);
        printf("%f\t", info[cont].EU_sales);
        printf("%f\t", info[cont].JP_sales);
        printf("%f\t", info[cont].other_sales);
        printf("%f\n", info[cont].global_sales);
        cont++;
    }

    fclose(fp);
    return 0;
}
