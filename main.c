#include <stdio.h>
#include <stdio.h>

int main()
{
    int vet[10] = {8, 5, 4, 3, 7, 2, 1, 9, 6, 0};
    int *pi = vet;
    int tmp;

    for(int i = 0; i < 9; i++)
    {
        for(int k = 0; k < 9 - i; k++)
        {
            if(*pi > *(pi + 1))
            {
                tmp = *pi;
                *pi = *(pi+1);
                *(pi+1) = tmp;
            }
            pi = pi + 1;
        }
        pi = vet;
    }
    
    printf("Ordinamento: ");

    pi = vet;

    for(int j = 0; j < 10; j++)
    {
        printf("%d ", *pi);
        pi = pi + 1;
    }

}