#include <stdlib.h>
#include <stdio.h>

void stampaVet(int vet[], int dim) {
    printf("vettore:");
    for(int j=0; j<dim; j++) {
        printf("%d\t", vet[j]);
    }
    printf("\n");
}

int main() {
    int vet[5];
    int dim = 5;
    int *pi = vet;
    *(pi+1) = 2;
    *(pi+2) = 3;
    *(pi+3) = 4;
    *(pi+4) = 5;
    stampaVet(vet, dim);
    while((pi-vet) < dim) {
        *(pi++) = 2;
    }
    stampaVet(vet, dim);
}
