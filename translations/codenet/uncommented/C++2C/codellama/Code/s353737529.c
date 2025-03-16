/*
これを入れて実行
gcc code.c
./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

//-----------------------ここから-----------


int main(void){
	int n;

	scanf("%d", &n);

	char s[1000000];

	if(n == 0){
		printf("0\n");
		return 0;
	}
	

	int i = 1;
	while(n != 0){
		if(n % 2 == 0){
			s[i] = '0';
		} else {
			s[i] = '1';
		}

		n -= abs(n % 2);

		n /= -2;
		i++;
	}

	for(int j = i - 1; j >= 0; j--){
		printf("%c", s[j]);
	}

	printf("\n");


}

