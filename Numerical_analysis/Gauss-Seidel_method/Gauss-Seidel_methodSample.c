#include <stdio.h>
#include <math.h>
#define N (3)               // 連立方程式の大きさ
#define EPS (1e-15)         // 計算誤差の許容値

int main(void){
    double a[N+1][N+1], x[N+1], b[N+1];
    double dx, absx, sum, new;
    int i,j;

    a[1][1]=3.0;  a[1][2]=2.0;  a[1][3]=1.0;  // 係数行列
    a[2][1]=1.0;  a[2][2]=4.0;  a[2][3]=1.0;
    a[3][1]=2.0;  a[3][2]=2.0;  a[3][3]=5.0;

    b[1]=10.0;                         // 同次項
    b[2]=12.0;
    b[3]=21.0;

    x[1]=0.0;                          // 近似解の初期値
    x[2]=0.0;
    x[3]=0.0;

    do{                                // 反復計算のループ
        dx=0.0;
        absx=0.0;

        for(i=1;i<=N;i++){
            sum=0;
            for(j=1;j<=N;j++){
                if(i != j){
                    sum+=a[i][j]*x[j];
                }
            }

            new=1.0/a[i][i]*(b[i]-sum);   // 反復計算後の近似解
            dx+=fabs(new-x[i]);           // 近似解の変化量を加算
            absx+=fabs(new);              // 近似解の総和計算
            x[i]=new;                     // 新しい近似解を代入
        }
                                                 
    }while(dx/absx > EPS);            // 計算終了条件
                               
    for(i=1;i<=N;i++){
        printf("x[%d]=%25.20f\n",i,x[i]);
    }

    return 0;
}

