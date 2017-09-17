#include <stdio.h>

double get_x1(double x2, double x3)
{
    return ((10 - x2 - x3)/5);
}
double get_x2(double x1, double x3)
{
    return ((12 - x1 - x3)/4);
}
double get_x3(double x1, double x2)
{
    return ((13 - 2*x1 -x2)/3);
}

int main()
{
    int i;
    double x1, x2, x3;

    printf("初期値入力(x1=x2=x3）\n");
    scanf("%lf", &x3);

    x1=x2=x3;

    printf("round:  0 (%12.10f, %12.10f, %12.10f)\n", x1, x2, x3);
    for(i = 1; i<20; i++){
        x1 = get_x1(x2, x3);
        x2 = get_x2(x1, x3);
        x3 = get_x3(x1, x2);

        printf("round: %2d (%12.10f, %12.10f, %12.10f)\n", i+1, x1,x2, x3);
    }
}
