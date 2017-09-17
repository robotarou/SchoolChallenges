#include <stdio.h>
#include <math.h> 

int main()
{
	int n = 0, i = 0;
	double suuti[100], x = 0, a = 0, sum;
	char end = 'y', suusiki[100];

	while(end == 'y'){
		printf("数式を入力してください(半角):\n");
		scanf("%s", suusiki);
		printf("1,%c\n", suusiki[0]);

		while(suusiki[n] != '\0'){
			if(suusiki[n] == '+' || suusiki[n] == '-' || suusiki[n] == '*' || suusiki[n] == '/'){
				x = 0;
				i++;
			}else{
				suuti[n] = suusiki[n];
				printf("%c\n", suusiki[n]);
				printf("%lf\n", suuti[i]);	
			}
			n++;
		}
		
		printf("%lf, %lf, %lf\n", suuti[0], suuti[1], suuti[2]);

		printf("続行しますか？[y/n]:");
		scanf("%s", &end);

		if(end == 'y' || end == 'n'){
		}else{
			printf("error: [y/n]のどちらかを入力してください。\n");
			return 0;
		}
	}

	return 0;
}