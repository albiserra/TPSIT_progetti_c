#include <stdlib.h>
#include <stdio.h>

int main(){

int a[3]={1,2,3};
int i;
int *p;
p=a;

for(p=a; p<a+3; p++) printf("%d", *p);
}