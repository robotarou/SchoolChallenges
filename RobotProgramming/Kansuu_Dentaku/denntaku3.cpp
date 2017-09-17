#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	double sum, i; 
	char end = 'y', kigou, suuji[100];
	char kansuu[100], s[] = "sin", c[] = "cos", t[] = "tan";

	while(end == 'y'){
		printf("入力してください\n");
		scanf("%s", suuji);

		while(suuji[n] != '\0'){
			printf("%c\n", suuji[n++]);
		}

		sum = suuji[1] + suuji[3];

		if(suuji[0] == '+')
			printf("+bbbbbbbb+\n");

		printf("\n");
		printf("%lf\n", sum);

		printf("続行しますか？[y/n]: ");
		scanf("%s", &end);
	}
}