#include <iostream>
#include <cmath>

using namespace std;

#define EPS 1e-7

double formula1(double ans)
{
    return (ans-(pow(ans,3.0)+ans+1.0)/(3.0*pow(ans,2.0)+1.0));
}

double formula2(double ans)
{
    return (ans-(3*pow(ans,3.0)-6*pow(ans,2.0)-3*ans+6)/(9*pow(ans,2.0)-12*ans-3));
}

double formula3(double ans)
{
    return (ans-(2*sin(ans)-ans)/(2*cos(ans)-1));
}

double formula4(double ans)
{
    return (ans-(cos(ans)-pow(ans,2.0))/(-sin(ans)-2*ans));
}

double formula5(double ans)
{
    return (ans-(exp(ans)+ans)/(exp(ans)+1)); 
}

//double divergence(double ans){


int main(void)
{
    int n=0, select, num_values=0, discrimination;
    double ans, ans_new, ans_old[200];

    for(int i=0; i<200; i++) ans_old[i] = 1e-6;

    cout << "以下の式のうちニュートン法で近似するのはどれにしますか？" << endl;
    cout << "1: x^3+x+1" << endl;
    cout << "2: 3*x^3-6*x^2-3*x-6" << endl;
    cout << "3: 2*sin(x)-x" << endl;
    cout << "4: cos(x)-x^2" << endl;
    cout << "5: e^x + x" << endl;
    cout << "6: ALL" << endl;
    cin >> select;

    switch(select){
        case 1:
            cout << "ans= " << endl;
            for(n=0; n<2000; n++){
                ans = -10.0 + n * 0.01;
                ans_new = formula1(ans);
                while(fabs(ans-ans_new) > EPS){
                    ans_new = ans;
                    ans = formula1(ans_new);
                }
                                    
                for(int i=0; i<=num_values; i++){
                    if(fabs(ans-ans_old[i]) > EPS){
                        discrimination = 1;
                    } else {
                        discrimination = 0;
                        break;
                    }
                }

                if(discrimination == 1){
                    ans_old[num_values] = ans;
                    num_values++;
                    cout << ans << endl;
                }
            }
            break;
        case 2:
            cout << "ans= " << endl;
            for(n=0; n<2000; n++){
                ans = -10.0 + n * 0.01;
                ans_new = formula2(ans);
                while(fabs(ans-ans_new) > EPS){
                    ans_new = ans;
                    ans = formula2(ans_new);
                }
                                    
                for(int i=0; i<=num_values; i++){
                    if(fabs(ans-ans_old[i]) > EPS){
                        discrimination = 1;
                    } else {
                        discrimination = 0;
                        break;
                    }
                }

                if(discrimination == 1){
                    ans_old[num_values] = ans;
                    num_values++;
                    cout << ans << endl;
                }
            }
            break;
        case 3:
            cout << "ans= " << endl;
            for(n=0; n<2000; n++){
                ans = -10.0 + n * 0.01;
                ans_new = formula3(ans);
                while(fabs(ans-ans_new) > EPS){
                    ans_new = ans;
                    ans = formula3(ans_new);
                }
                                    
                for(int i=0; i<=num_values; i++){
                    if(fabs(ans-ans_old[i]) > EPS){
                        discrimination = 1;
                    } else {
                        discrimination = 0;
                        break;
                    }
                }

                if(discrimination == 1){
                    ans_old[num_values] = ans;
                    num_values++;
                    cout << ans << endl;
                }
            }
            break;
        case 4:
            cout << "ans= " << endl;
            for(n=0; n<2000; n++){
                ans = -10.0 + n * 0.01;
                ans_new = formula4(ans);
                while(fabs(ans-ans_new) > EPS){
                    ans_new = ans;
                    ans = formula4(ans_new);
                }
                                    
                for(int i=0; i<=num_values; i++){
                    if(fabs(ans-ans_old[i]) > EPS){
                        discrimination = 1;
                    } else {
                        discrimination = 0;
                        break;
                    }
                }

                if(discrimination == 1){
                    ans_old[num_values] = ans;
                    num_values++;
                    cout << ans << endl;
                }
            }
            break;
        case 5:
            cout << "ans= " << endl;
            for(n=0; n<2000; n++){
                ans = -10.0 + n * 0.01;
                ans_new = formula5(ans);
                while(fabs(ans-ans_new) > EPS){
                    ans_new = ans;
                    ans = formula5(ans_new);
                }
                                    
                for(int i=0; i<=num_values; i++){
                    if(fabs(ans-ans_old[i]) > EPS){
                        discrimination = 1;
                    } else {
                        discrimination = 0;
                        break;
                    }
                }

                if(discrimination == 1){
                    ans_old[num_values] = ans;
                    num_values++;
                    cout << ans << endl;
                }
            }
            break;
        case 6:

            break;
        default:
            break;
    }
}
