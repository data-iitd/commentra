

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define REP(i,n) for(int i=0;i<(n);++i) // Define a macro for repetition
#define ALL(v) (v).begin,(v).end() // Define a macro for getting the iterator range of a vector
#define INF 1e9 // Define a constant for large number
#define MOD 1e9+7 // Define a constant for modulo operation
typedef long long llong; // Define a type alias for long long

int main(){
	int n; // Declare an integer variable 'n' to store the number of strings
	scanf("%d", &n); // Read the number of strings from the standard input

	// Declare two vectors: 'cnt' to store the count of each character and's' to store the strings
	int cnt[26] = {1}; // Initialize the count vector with all elements set to 1
	char s[n]; // Declare a character array to store the strings

	// Read the strings from the standard input and update the count vector accordingly
	REP(i, n){
		scanf(" %c", &s[i]); // Read a character from the standard input and store it in the's' array
		cnt[s[i] - 'a']++; // Increment the count of the character in the 'cnt' vector
	}

	// Calculate the answer using the count vector
	long long ans = 1; // Initialize the answer to 1
	for(int i = 0; i < 26; ++i){ // Iterate through all the characters from 'a' to 'z'
		ans *= cnt[i]; // Multiply the answer with the count of the current character
	}

	// Calculate the final answer by subtracting 1 from the initial answer
	ans--;

	// Print the final answer to the standard output
	printf("%lld\n", ans); // Print the final answer to the standard output

	return 0; // Indicate the successful termination of the program
}

