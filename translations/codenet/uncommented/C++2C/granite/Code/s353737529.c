
/*
これを入れて実行
gcc code.c
./a.out
 */

#include <stdio.h>

int main(void){
	int n;

	scanf("%d", &n);

	char s[100000];

	if(n == 0){
		printf("0\n");
		return 0;
	}
	

	int i = 1;
	while(n!= 0){
		if(n % 2 == 0){
			s[i] = '0';
		} else {
			s[i] = '1';
		}

		n -= abs(n % 2);

		n /= -2;

		i++;
	}

	for(int j = i - 1; j >= 1; j--){
		printf("%c", s[j]);
	}

	printf("\n");


}

