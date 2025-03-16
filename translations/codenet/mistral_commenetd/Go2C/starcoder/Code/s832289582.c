
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// N: [1, 2e5] // We define N as an integer variable with the range [1, 2e5]
// len(S) = N   // The length of string S is equal to N
// P: [2, 10000], prime // We define P as an integer variable with the range [2, 10000] and prime

int main() {
	int N, P;
	char S[256];
	scanf("%d %d %s", &N, &P, S); // We read N, P, and S from the standard input
	int answer = checkSubNumbers(N, P, S); // We call checkSubNumbers function with N, P, and S as arguments and store the result in answer variable
	printf("%d", answer); // We print the answer using printf
}

// checkSubNumbers function checks if any subnumber of given string S is divisible by prime number P
int checkSubNumbers(int N, int P, char S[]) {
	// Switch statement to check if P is equal to 2 or 5
	switch (P) {
	case 2:
	case 5:
		return checkTwoOrFive(N, P, S); // If P is equal to 2 or 5, we call checkTwoOrFive function
	default:
		return checkNotTwoNorFive(N, P, S); // If P is not equal to 2 or 5, we call checkNotTwoNorFive function
	}
}

// checkTwoOrFive function checks if any subnumber of given string S is divisible by prime number P equal to 2 or 5
int checkTwoOrFive(int N, int P, char S[]) {
	int answer = 0; // We initialize answer variable as 0
	int n; // We define an integer variable n
	for (int i = N - 1; i >= 0; i--) { // We iterate through the string S from the last character to the first character
		n = atoi(S + i); // We convert the substring from i to i+1 to an integer n
		if (n % P == 0) { // If n is divisible by P, we add its index to the answer variable
			answer += i + 1;
		}
	}
	return answer;
}

// checkNotTwoNorFive function checks if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
int checkNotTwoNorFive(int N, int P, char S[]) {
	int multiplier = 1; // We initialize multiplier variable as 1
	int answer = 0;     // We initialize answer variable as 0
	int remainderLookup[P]; // We create a lookup table for storing the count of remainders
	int prevRemaider = -1; // We initialize prevRemaider variable as -1
	for (int i = N - 1; i >= 0; i--) { // We iterate through the string S from the last character to the first character
		int digit = S[i] - '0'; // We get the digit from the string S at the current index i
		if (prevRemaider == -1) { // If prevRemaider is equal to -1, we get the remainder of the first digit by dividing it by P
			int remainder = digit % P;
		} else { // Otherwise, we get the remainder of the current digit multiplied by multiplier and added to the previous remainder, then we get the remainder of the result by dividing it by P
			int remainder = (((multiplier * digit) % P) + prevRemaider) % P;
		}
		if (remainder == 0) { // If the remainder is equal to 0, we add 1 to the answer variable
			answer++;
		}
		int count = remainderLookup[remainder]; // We get the count of the current remainder from the lookup table
		answer += count; // We add the count to the answer variable
		count++; // We update the lookup table with the new count of the current remainder
		remainderLookup[remainder] = count; // We update the lookup table with the new count of the current remainder
		prevRemaider = remainder; // We update the prevRemaider variable as remainder
		multiplier = (multiplier * 10) % P; // We update the multiplier variable as multiplier * 10 % P
	}
	return answer;
}

