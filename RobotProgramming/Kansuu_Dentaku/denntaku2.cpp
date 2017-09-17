#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.1415926

int main()
{
	int n;
	double sum, suuji, i; 
	char end = 'y', kigou;
	char kansuu[100], s[] = "sin", c[] = "cos", t[] = "tan";

	while(end == 'y'){
		kigou = '\n';
		sum = '\0';
		n = '\0';
		while(kigou != '='){
			printf("kigou-> ");
			if(n == '\0'){
				scanf("%c", &kigou); 
				switch(kigou){
					case '\n':
								kigou = '+';
								break;
					case 'f':
								n = 1;
								break;
					case 'a':
								n = 0;
								break;
				}
			}else{
				if(n == 0){
					scanf("%*c%c", &kigou);
					if(kigou == '=')
						break;
					if(kigou == 'f'){
						n = 1;
					}else{
						if(kigou == 'a')
							n = 0;
					}
				}
			}

			if(n == 1){
				printf("kigou-> ");
				scanf("%*c%c", &kigou);
				if(kigou == '\n')
					kigou = '+';
				if(kigou == '=')
					break;
				if(kigou == 'a')
					n = 0;

				printf("kansuu->");
				scanf("%s", kansuu);

				if(strcmp(kansuu, s) == 0){
					printf("suuji-> ");
					scanf("%lf", &suuji);
					if(suuji == '\n'){
						printf("error: 入力エラー\n");
						break;
					}
					suuji = sin(suuji*PI/180);
				}

				if(strcmp(kansuu, c) == 0){
					printf("suuji-> ");
					scanf("%lf", &suuji);
					if(suuji == '\n'){
						printf("error: 入力エラー\n");
						break;
					}
					suuji = cos(suuji*PI/180);
				}

				if(strcmp(kansuu, t) == 0){
					printf("suuji-> ");
					scanf("%lf", &suuji);
					if(suuji == '\n'){
						printf("error: 入力エラー\n");
						break;
					}
					suuji = tan(suuji*PI/180);
				}
			}

			if(n != 1){
				printf("suuji-> ");
				scanf("%lf", &suuji);
				if(suuji == '\n'){
					printf("error: 入力エラー\n");
					break;
				}
			}

			switch(kigou){
				case '+':
						sum += suuji;
						break;
				case '-':
						sum -= suuji;
						break;
				case '*':
						sum *= suuji;
						break;
				case '/':
						sum /= suuji;
						break;
			}
		}

		printf("sum = %lf\n", sum);

		printf("続行しますか？[y/n]: ");
		scanf("%*c%c", &end);
	}

	return 0;
}