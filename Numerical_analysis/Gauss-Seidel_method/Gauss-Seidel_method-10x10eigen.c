#include <stdio.h>
#include <math.h>
#define EPS (1e-20)         //計算誤差の許容値

int main(void){
    double a[100][100], b[100], x[100];
    double err=1, absx=1, sum, new_x;
    int i, n, m, N;

    //入力部
    printf("行列の大きさを入力してください\nm= n= ");
    scanf("%d", &N);

    printf("係数行列を入力してください\n");
    printf("| a11 a12 … a1m | \n| a21 a22 … a2m | \n"
           "| …             | \n| an1 an2 … anm | \n\n");
    for(n=1; n<=N; n++){
        for(m=1; m<=N; m++){
            printf("a%d%d= ", n, m);
            scanf("%lf", &a[n][m]);
        }
    }

    printf("同次項を入力してください\n");
    printf("| b1 | \n| b2 | \n| …  | \n| bn | \n\n");
    for(n=1; n<=N; n++){
        printf("b%d= ", n);
        scanf("%lf", &b[n]);
    }

    printf("近似解の初期値\n");
    printf("| x1 | \n| x2 | \n| …  | \n| xn | \n\n");
    for(n=1; n<=N; n++){
        printf("x%d= ", n);
        scanf("%lf", &x[n]);
    }

    //収束判定
    for(n=1; n<=N; n++){
        sum=0.0;
        for(m=1; m<=N; m++){
            if(n!=m){
                sum += fabs(a[n][m]);
            }
        }
        if(fabs(a[n][n]) < sum){
            printf("発散しました\n");
            return false;
        }
    }

    //反復計算のループ
    i = 0;
    while(err/absx > EPS){
        err  = 0.0;
        absx = 0.0;

        for(n=1; n<=N; n++){
            sum=0.0;
            for(m=1; m<=N; m++){
                if(n != m){
                    sum+=a[n][m]*x[m];
                }
            }

            new_x  = 1.0/a[n][n]*(b[n]-sum);
            err   += fabs(new_x-x[n]);
            absx  += fabs(new_x);
            x[n]   = new_x;
        }

        //収束判定
        if(i > 100 || isnan(x[n]) != 0 || isinf(x[n]) != 0){
            printf("inf&nan\n");
            printf("発散しました\n");
            return false;
        }
        i++;
    }

    printf("\n------answer------\n");
    printf("Loop= %d\n", i);

    for(n=1; n<=N; n++){
        printf("x%d=%25.20f\n", n, x[n]);
    }

    return 0;
}
