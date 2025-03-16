#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int n = nextInt();
	int rt = (int)sqrt(n);
	int minf = 100;
	for (int i = 1; i < rt+1; i++) {
		if (n%i == 0) {
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			minf = min(minf, ndigit);
		}
	}
	printf("%d\n", minf);
}

const int size = 1000000;

char buffer[size];
int position = 0;

char nextChar() {
	if (position == size) {
		position = 0;
		fgets(buffer, size, stdin);
	}
	return buffer[position++];
}

int nextInt() {
	int result = 0;
	char c = nextChar();
	for (c =='' || c == '\n' || c == '\r' || c == '\t') {
		c = nextChar();
	}
	if (c == '-') {
		result = -1;
		c = nextChar();
	}
	for (c >= '0' && c <= '9') {
		result = result * 10 + c - '0';
		c = nextChar();
	}
	return result;
}

int min(int i, int j) {
	if (i > j) {
		return j;
	}
	return i;
}

