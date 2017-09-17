#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
  char name[100],
    address[100],
    phone[100];
}Person;

int main()
{
  int n, i;
  char kensaku[100], i1[100];
  FILE *fp;
  Person student[1000];

  while(1){
    char close = 'y';
    printf("===========================================\n");
    printf(" 0: 登録  1: 検索  2: 消去  3: 一覧 4: 終了\n");
    printf("===========================================\n");
    printf("選択してください\n>>");
    scanf("%d", &n);

    if(n == 4)
      break;     //stop
    
    switch(n){
    case 0:
      while(close == 'y'){
	fp = fopen("datafile.txt", "a");
	
	printf("登録する名前と電話番号とメールアドレスを入力してください\n");
	printf("名前\n>>");
	scanf("%s", student[0].name);
	printf("電話番号\n>>");
	scanf("%s", student[0].phone);
	printf("メールアドレス\n>>");
	scanf("%s", student[0].address);
	fprintf(fp, "%s %s %s\n", student[0].name, student[0].phone, student[0].address);

	printf("このまま、登録を続けますか？[y/n]:");
	scanf(" %c", &close);

	fclose(fp);
      }
      break;
    case 1:
      while(close == 'y'){
	char erasure = 'n';
	fp = fopen("datafile.txt", "r+");
	
	printf("検索したい項目を選んでください\n");
	printf("=============================================\n");
	printf(" 0: 名前  1: 電話番号  2: メールアドレス\n");
	printf("=============================================\n>>");
	scanf("%d", &i);

	switch(i){
	case 0:
	  printf("検索したい名前を入力してくだい\n>>");
	  scanf("%s", kensaku);

	  i=0;
	  while(fscanf(fp, "%s%s%s", student[i].name, student[i].phone, student[i].address) != EOF){
	    if(strcmp(kensaku, student[i].name) == 0){
	      printf("%s %s %s\n", student[i].name, student[i].phone, student[i].address);
	    }
	    i++;
	  }
	  
	  break;
	case 1:
	  printf("検索したい電話番号を入力してくだい\n>>");
	  scanf("%s", kensaku);

	  i=0;
	  while(fscanf(fp, "%s%s%s", student[i].name, student[i].phone, student[i].address) != EOF){
	    if(strcmp(kensaku, student[i].phone) == 0){
	      printf("%s %s %s\n", student[i].name, student[i].phone, student[i].address);
	    }
	    i++;
	  }

	  break;
	case 2:
	  printf("検索したいメールアドレスを入力してくだい\n>>");
	  scanf("%s", kensaku);

	  i=0;
	  while(fscanf(fp, "%s%s%s", student[i].name, student[i].phone, student[i].address) != EOF){
	    if(strcmp(kensaku, student[i].address) == 0){
	      printf("%s %s %s\n", student[i].name, student[i].phone, student[i].address);
	    }
	    i++;
	  }
	  
	  break;
	default:
	  break;
	}

	fclose(fp);
	
	printf("このまま、検索を続けますか？[y/n]:");
	scanf(" %c", &close);
      }
      
      break;
    case 2:
      while(close == 'y'){
	char erasure = 'n';
	fp = fopen("datafile.txt", "r+");
	
	printf("消去したい項目を選んでください\n");
	printf("=============================================\n");
	printf(" 0: 名前  1: 電話番号  2: メールアドレス\n");
	printf("=============================================\n>>");
	scanf("%d", &i);

	switch(i){
	case 0:
	  printf("消去したい名前を入力してくだい\n>>");
	  scanf("%s", kensaku);

	  i=0;
	  while(fscanf(fp, "%s%s%s", student[i].name, student[i].phone, student[i].address) != EOF){
	    if(strcmp(kensaku, student[i].name) == 0){
	      printf("%s %s %s\n", student[i].name, student[i].phone, student[i].address);
	      i1[n++] = i;
	    }
	    i++;
	  }

	  n = i;
	  fclose(fp);
	  
	  printf("消去しますか？(名前以外も含む）[y/n]:");
	  scanf(" %c", &erasure);
	  if(erasure == 'y'){
	    i = 0;
	    fp = fopen("datafile.txt", "w");
	    while(n > i){
	      if(i[i] == i) {
	      }else{
		fprintf(fp, "%s %s %s\n", student[i].name, student[i].phone, student[i].address);
	      }
	      i++;
	    }
	    fclose(fp);
	  }
	  
	  break;
	case 1:
	  printf("消去したい電話番号を入力してくだい\n>>");
	  scanf("%s", kensaku);

	  i=0;
	  while(fscanf(fp, "%s%s%s", student[i].name, student[i].phone, student[i].address) != EOF){
	    if(strcmp(kensaku, student[i].phone) == 0){
	      printf("%s %s %s\n", student[i].name, student[i].phone, student[i].address);
	      n = i;
	    }
	    i++;
	  }

	  i1 = i;
	  fclose(fp);
	  
	  printf("消去しますか？(電話番号以外も含む）[y/n]:");
	  scanf(" %c", &erasure);
	  if(erasure == 'y'){
	    i = 0;
	    fp = fopen("datafile.txt", "w");
	    while(i1 > i){
	      if(n == i) {
	      }else{
		fprintf(fp, "%s %s %s\n", student[i].name, student[i].phone, student[i].address);
	      }
	      i++;
	    }
	    fclose(fp);
	  }
	  
	  break;
	case 2:
	  printf("消去したいメールアドレスを入力してくだい\n>>");
	  scanf("%s", kensaku);

	  i=0;
	  while(fscanf(fp, "%s%s%s", student[i].name, student[i].phone, student[i].address) != EOF){
	    if(strcmp(kensaku, student[i].address) == 0){
	      printf("%s %s %s\n", student[i].name, student[i].phone, student[i].address);
	      n = i;
	    }
	    i++;
	  }

	  i1 = i;
	  fclose(fp);
	  
	  printf("消去しますか？(メールアドレス以外も含む）[y/n]:");
	  scanf(" %c", &erasure);
	  if(erasure == 'y'){
	    i = 0;
	    fp = fopen("datafile.txt", "w");
	    while(i1 > i){
	      if(n == i) {
	      }else{
		fprintf(fp, "%s %s %s\n", student[i].name, student[i].phone, student[i].address);
	      }
	      i++;
	    }
	    fclose(fp);
	  }
	  
	  break;
	default:
	  break;
	}
	
	printf("このまま、検索を続けますか？[y/n]:");
	scanf(" %c", &close);
      }
      break;
    case 3:
      printf("===================================\n");
      printf("   一覧\n");
      printf("===================================\n");
      printf(" \t名前 \t| \t電話番号 \t| \t電子メールアドレス \t|\n");
      printf("\t-------------------------------------------------------\n");

      fp = fopen("datafile.txt", "r");
      i=0;
      while(fscanf(fp, "%s%s%s", student[i].name, student[i].phone, student[i].address) != EOF){
	printf(" \t%s \t| \t%s \t| \t%s \t|\n", student[i].name, student[i].phone, student[i].address);
	i++;
      }
      printf("現在 %d人のデータがあります\n", i);
      
      break;
    default:
      break;
    }
  }
}
