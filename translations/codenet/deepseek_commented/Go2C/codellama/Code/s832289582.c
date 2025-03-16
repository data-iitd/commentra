#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// N: [1, 2e5]
// len(S) = N
// P: [2, 10000], prime
int checkSubNumbers(int N, int P, char *S) {
	int answer = 0;
	switch (P) {
	case 2:
	case 5:
		for (int i = N - 1; i >= 0; i--) {
			if (S[i] % P == 0) {
				answer += i + 1;
			}
		}
		break;
	default:
		int multiplier = 1;
		int remainderLookup[P];
		int prevRemaider = -1;
		int digit, remainder, count;
		for (int i = N - 1; i >= 0; i--) {
			digit = S[i] - '0';
			if (prevRemaider == -1) {
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
		break;
	}
	return answer;
}

int main() {
	int N, P;
	char S[20000];
	scanf("%d %d %s", &N, &P, S);
	int answer = checkSubNumbers(N, P, S);
	printf("%d\n", answer);
	return 0;
}

