#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    int i, x, sum;

    srand( (unsigned)time(NULL) );
    for(i=0; i<N; i++){
        x = (int)( rand() / (double)RAND_MAX * N );
        sum += x;
        printf("%d\n", x);
    }

    printf("----average----\n%d\n", sum/N);

    return 0;
}
