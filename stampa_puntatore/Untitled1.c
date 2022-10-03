#include <stdio.h>

int main(){
    int *p;
    int i=10;

    p=&i;

    *p=20;

    printf("%d", i);
}
