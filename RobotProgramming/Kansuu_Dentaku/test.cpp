#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	double sum, i, suuji; 
	char end = 'y', kigou;
	char kansuu[100], s[] = "sin", c[] = "cos", t[] = "tan";

	while(end == 'y'){
		printf("入力してください\n");
		scanf(" %c%lf", &kigou, &suuji);
		
		printf("%c\n", kigou);
		printf("%lf\n", suuji);

		printf("続行しますか？[y/n]: ");
		scanf("%s", &end);
	}
}
