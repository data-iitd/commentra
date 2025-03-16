#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// N: [1, 2e5]
// len(S) = N
// P: [2, 10000], prime
int main() {
	int N, P;
	scanf("%d %d", &N, &P);
	char S[N + 1];
	scanf("%s", S);
	int answer = checkSubNumbers(N, P, S);
	printf("%d", answer);
}

int checkSubNumbers(int N, int P, char S[]) {
	switch (P) {
	case 2:
	case 5:
		return checkTwoOrFive(N, P, S);
	default:
		return checkNotTwoNorFive(N, P, S);
	}
}

int checkTwoOrFive(int N, int P, char S[]) {
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

int checkNotTwoNorFive(int N, int P, char S[]) {
	int multiplier = 1; // 10^i % P
	int answer = 0;
	int remainderLookup[P];
	memset(remainderLookup, 0, sizeof(remainderLookup));
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

