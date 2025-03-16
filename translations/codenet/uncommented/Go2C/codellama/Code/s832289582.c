#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

int checkSubNumbers(int N, int P, char *S) {
	int answer = 0;
	int n;
	for (int i = N - 1; i >= 0; i--) {
		n = S[i] - '0';
		if (n % P == 0) {
			answer += i + 1;
		}
	}
	return answer;
}

int checkTwoOrFive(int N, int P, char *S) {
	int answer = 0;
	int n;
	for (int i = N - 1; i >= 0; i--) {
		n = S[i] - '0';
		if (n % P == 0) {
			answer += i + 1;
		}
	}
	return answer;
}

int checkNotTwoNorFive(int N, int P, char *S) {
	int multiplier = 1; // 10^i % P
	int answer = 0;
	int remainderLookup[P];
	int prevRemaider = -1;
	int digit, remainder, count;
	for (int i = N - 1; i >= 0; i--) {
		digit = S[i] - '0';
		if (prevRemaider == -1) { // first digit
			remainder = digit % P;
		} else {
			remainder = (((multiplier * digit) % P) + prevRemaider) % P;
		}
		if (remainder == 0) {
			answer++;
		}
		count = remainderLookup[remainder];
		answer += count;
		count++;
		remainderLookup[remainder] = count;
		prevRemaider = remainder;
		multiplier = (multiplier * 10) % P;
	}
	return answer;
}

int main() {
	int N, P;
	char S[MAX_INPUT_SIZE];
	scanf("%d %d %s", &N, &P, S);
	int answer = checkSubNumbers(N, P, S);
	printf("%d\n", answer);
	return 0;
}

