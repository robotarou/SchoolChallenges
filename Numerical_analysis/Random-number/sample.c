#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int i, x;

    srand( (unsigned)time(NULL) );
    for(i=0; i<N; i++){
        x = (int)( rand() / (double)RAND_MAX * N );
        printf("%d\n", x);
    }

    return 0;
}
