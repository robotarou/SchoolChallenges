#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main()
{
  int moudo;
  double answer, suuji;
  char end = 'y', kigou,  kansuu;

  while(end == 'y'){
    moudo = 0;
    answer = '\0';
    kigou = '\0';
    while(kigou != '='){
      kigou = '\0';
      printf("モードを選択してください\n");
      printf("【四則演算モード】: 0  【関数電卓モード】：１\n");
      printf(">> ");
      scanf(" %d", &moudo);
      if(answer == '\0'){
	printf("モード選択に戻るには[f]を入力\n");
	printf("答えを出すには[=]を入力\n");
      }      

      while(kigou != 'f' && kigou != '='){
	switch(moudo){
	case 0:
	  printf("【四則演算モード】\n");
	  printf("入力例：+3\n");
	  printf(">> ");
	  scanf(" %c", &kigou);
	  if(kigou != 'f' && kigou != '='){
	    scanf(" %lf", &suuji);
	  }
	  break;
	case 1:
	  printf("【関数電卓モード】\n");
	  printf("入力例：+s30\n");
	  printf(">> ");
	  scanf(" %c", &kigou);
	  if(kigou != 'f' && kigou != '='){
	    scanf(" %c%lf", &kansuu, &suuji);
	  }

	  switch(kansuu){
	  case 's':
	    suuji = sin(suuji*PI/180);
	    break;
	  case 'c':
	    suuji = cos(suuji*PI/180);
	    break;
	  case 't':
	    if(suuji == 90 || suuji == 270){
	      printf("error: 計算エラー\n");
	      kigou = 'e';
	      suuji = 0;
	    }else{
	      suuji = tan(suuji*PI/180);
	    }
	    break;
	  default:
	    printf("error: 入力エラー\n");
	    kigou = '=';
	  }
	  break;
	default:
	  printf("error: 入力エラー\n");
	  kigou = '=';
	}

	switch(kigou){
	case '+':
	  answer += suuji;
	  break;
	case '-':
	  answer -= suuji;
	  break;
	case '*':
	  answer *= suuji;
	  break;
	case '/':
	  answer /= suuji;
	  break;
	case 'f':
	case '=':
	case 'e':
	  break;
	default:
	  printf("error: 入力エラー\n");
	  kigou = '=';
	}
      }
    }
    printf("答え：%lf\n", answer);
    printf("続行しますか？[y/n]:");
    scanf("  %c", &end);
    switch(end){
    case 'y':
    case 'n':
      break;
    default:
      printf("error: 入力エラー\n");
      end = 'n';
    }
  }
  return 0;
}
