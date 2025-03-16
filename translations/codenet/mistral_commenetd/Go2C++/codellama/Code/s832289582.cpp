
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Package main is the entry point of the program
int main() {
	int N, P; // We define N and P as integers
	string S; // We define S as a string
	cin >> N >> P >> S; // We read N, P, and S from the standard input
	int answer = checkSubNumbers(N, P, S); // We call checkSubNumbers function with N, P, and S as arguments and store the result in answer variable
	cout << answer << endl; // We print the answer using cout
	return 0; // We return 0 as the exit code
}

// checkSubNumbers function checks if any subnumber of given string S is divisible by prime number P
int checkSubNumbers(int N, int P, string S) {
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

// 