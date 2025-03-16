
#include <bits/stdc++.h>

using namespace std;

// N: [1, 2e5] // We define N as an integer variable with the range [1, 2e5]
// len(S) = N   // The length of string S is equal to N
// P: [2, 10000], prime // We define P as an integer variable with the range [2, 10000] and prime
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, P;
	string S;
	cin >> N >> P >> S;
	cout << checkSubNumbers(N, P, S);
}

// checkSubNumbers function checks if any subnumber of given string S is divisible by prime number P
int checkSubNumbers(int N, int P, string S) {
	// Switch statement to check if P is equal to 2 or 5
	switch (P) {
	case 2, 5:
		return checkTwoOrFive(N, P, S); // If P is equal to 2 or 5, we call checkTwoOrFive function
	default:
		return checkNotTwoNorFive(N, P, S); // If P is not equal to 2 or 5, we call checkNotTwoNorFive function
	}
}

// checkTwoOrFive function checks if any subnumber of given string S is divisible by prime number P equal to 2 or 5
int checkTwoOrFive(int N, int P, string S) {
	int answer = 0; // We initialize answer variable as 0
	int n; // We define an integer variable n
	// We iterate through the string S from the last character to the first character
	for (int i = N - 1; i >= 0; i--) {
		// We convert the substring from i to i+1 to an integer n
		n = stoi(S.substr(i, 1));
		// If n is divisible by P, we add its index to the answer variable
		if (n % P == 0) {
			answer += i + 1;
		}
	}
	return answer;
}

// checkNotTwoNorFive function checks if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
int checkNotTwoNorFive(int N, int P, string S) {
	int multiplier = 1; // We initialize multiplier variable as 1
	int answer = 0;     // We initialize answer variable as 0
	// We create a slice of length P for storing the count of remainders
	vector<int> remainderLookup(P);
	int prevRemaider = -1; // We initialize prevRemaider variable as -1
	// We iterate through the string S from the last character to the first character
	for (int i = N - 1; i >= 0; i--) {
		// We get the digit from the string S at the current index i
		int digit = S[i] - '0';
		// If prevRemaider is equal to -1, we get the remainder of the first digit by dividing it by P
		if (prevRemaider == -1) {
			int remainder = digit % P;
		} else {
			// Otherwise, we get the remainder of the current digit multiplied by multiplier and added to the previous remainder, then we get the remainder of the result by dividing it by P
			int remainder = (((multiplier * digit) % P) + prevRemaider) % P;
		}
		// If the remainder is equal to 0, we add 1 to the answer variable
		if (remainder == 0) {
			answer++;
		}
		// We get the count of the current remainder from the slice remainderLookup
		int count = remainderLookup[remainder];
		// We add the count to the answer variable
		answer += count;
		// We update the slice remainderLookup with the new count of the current remainder
		count++;
		remainderLookup[remainder] = count;
		// We update the multiplier variable as multiplier * 10 % P
		prevRemaider = remainder;
		multiplier = (multiplier * 10) % P;
	}
	return answer;
}

