#include <stdio.h>
#include <math.h>
#define N (3)               // $BO"N)J}Dx<0$NBg$-$5(B
#define EPS (1e-15)         // $B7W;;8m:9$N5vMFCM(B

int main(void){
    double a[N+1][N+1], x[N+1], b[N+1];
    double dx, absx, sum, new;
    int i,j;

    a[1][1]=3.0;  a[1][2]=2.0;  a[1][3]=1.0;  // $B78?t9TNs(B
    a[2][1]=1.0;  a[2][2]=4.0;  a[2][3]=1.0;
    a[3][1]=2.0;  a[3][2]=2.0;  a[3][3]=5.0;

    b[1]=10.0;                         // $BF1<!9`(B
    b[2]=12.0;
    b[3]=21.0;

    x[1]=0.0;                          // $B6a;w2r$N=i4|CM(B
    x[2]=0.0;
    x[3]=0.0;

    do{                                // $BH?I|7W;;$N%k!<%W(B
        dx=0.0;
        absx=0.0;

        for(i=1;i<=N;i++){
            sum=0;
            for(j=1;j<=N;j++){
                if(i != j){
                    sum+=a[i][j]*x[j];
                }
            }

            new=1.0/a[i][i]*(b[i]-sum);   // $BH?I|7W;;8e$N6a;w2r(B
            dx+=fabs(new-x[i]);           // $B6a;w2r$NJQ2=NL$r2C;;(B
            absx+=fabs(new);              // $B6a;w2r$NAmOB7W;;(B
            x[i]=new;                     // $B?7$7$$6a;w2r$rBeF~(B
        }
                                                 
    }while(dx/absx > EPS);            // $B7W;;=*N;>r7o(B
                               
    for(i=1;i<=N;i++){
        printf("x[%d]=%25.20f\n",i,x[i]);
    }

    return 0;
}

