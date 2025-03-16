

#include <stdio.h>
#include <math.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int x = m*1900 + (n-m)*100;
	printf("%d\n", x * pow(2, m));
}

