#include <stdio.h>

#define N 10000

int main()
{
    double sum = 0.0;
    int i;

    for(i=1; i<=N; i++)
        sum += 0.1;

    printf("sum = %15.10f\n", sum);
}
