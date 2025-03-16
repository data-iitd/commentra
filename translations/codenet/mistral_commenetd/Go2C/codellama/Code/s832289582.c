
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

// Package main is the entry point of the program
int main() {
	int N, P, answer; // We define N, P, and answer as integers
	char S[100000]; // We define S as a string with a maximum length of 100000
	scanf("%d %d %s", &N, &P, S); // We read N, P, and S from the standard input using scanf
	answer = checkSubNumbers(N, P, S); // We call checkSubNumbers function with N, P, and S as arguments and store the result in answer variable
	printf("%d\n", answer); // We print the answer using printf
	return 0; // We return 0 as the exit code
}

// checkSubNumbers function checks if any subnumber of given string S is divisible by prime number P
int checkSubNumbers(int N, int P, char S[]) {
	int i, n, answer = 0; // We define i, n, and answer as integers
	// Switch statement to check if P is equal to 2 or 5
	switch (P) {
	case 2:
	case 5:
		for (i = N - 1; i >= 0; i--) { // We iterate through the string S from the last character to the first character
			n = S[i] - '0'; // We get the digit from the string S at the current index i
			if (n % P == 0) { // If n is divisible by P, we add its index to the answer variable
				answer += i + 1;
			}
		}
		return answer; // If P is equal to 2 or 5, we return the answer
	default:
		int multiplier = 1, prevRemaider = -1, remainderLookup[10000], count; // We define multiplier, prevRemaider, remainderLookup, and count as integers
		for (i = N - 1; i >= 0; i--) { // We iterate through the string S from the last character to the first character
			int digit = S[i] - '0'; // We get the digit from the string S at the current index i
			int remainder; // We define remainder as an integer
			if (prevRemaider == -1) { // If prevRemaider is equal to -1, we get the remainder of the first digit by dividing it by P
				remainder = digit % P;
			} else { // Otherwise, we get the remainder of the current digit multiplied by multiplier and added to the previous remainder, then we get the remainder of the result by dividing it by P
				remainder = (((multiplier * digit) % P) + prevRemaider) % P;
			}
			if (remainder == 0) { // If the remainder is equal to 0, we add 1 to the answer variable
				answer++;
			}
			count = remainderLookup[remainder]; // We get the count of the current remainder from the slice remainderLookup
			answer += count; // We add the count to the answer variable
			remainderLookup[remainder] = count + 1; // We update the slice remainderLookup with the new count of the current remainder
			prevRemaider = remainder; // We update the multiplier variable as multiplier * 10 % P
			multiplier = (multiplier * 10) % P;
		}
		return answer; // If P is not equal to 2 or 5, we return the answer
	}
}

