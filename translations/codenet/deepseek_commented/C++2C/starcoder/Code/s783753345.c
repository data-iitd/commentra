#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b;
	char S;
	
	while (true) {
		scanf("%d %c %d", &a, &S, &b);
		
		if (S == '+') printf("%d\n", a + b);
		if (S == '-') printf("%d\n", a - b);
		if (S == '*') printf("%d\n", a * b);
		if (S == '/') printf("%d\n", a / b);
		
		if (S == '?') break;
	}
}
