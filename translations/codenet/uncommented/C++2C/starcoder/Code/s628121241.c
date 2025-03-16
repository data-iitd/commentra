#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main() {
	int R;
	scanf("%d", &R);
	if (R < 1200)printf("ABC\n");
	else if (R >= 2800)printf("AGC\n");
	else printf("ARC\n");
}

