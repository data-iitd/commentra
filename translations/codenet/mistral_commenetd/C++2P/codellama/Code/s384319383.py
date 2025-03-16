
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define REP(i,n) for(int i=0;i<(n);++i) // Define a macro for repetition
#define ALL(v) (v).begin,(v).end() // Define a macro for getting the iterator range of a vector
#define INF 1e9 // Define a constant for large number
#define MOD 1e9+7 // Define a constant for modulo operation
typedef long long llong; // Define a type alias for long long
using namespace std;

int main(){
	int n; // Declare an integer variable 'n' to store the number of strings
	cin >> n; // Read the number of strings from the standard input

	// Declare two vectors: 'cnt' to store the count of each character and 's' to store the strings
	vector<int> cnt(26, 1);
	vector<char> s(n);

	// Read the strings from the standard input and update the count vector accordingly
	REP(i, n){
		cin >> s[i]; // Read a character from the standard input and store it in the 's' vector
		cnt[s[i] - 'a']++; // Increment the count of the character in the 'cnt' vector
	}

	// Calculate the answer using the count vector
	llong ans = 1; // Initialize the answer to 1
	for(int i = 0; i < 26; ++i){ // Iterate through all the characters from 'a' to 'z'
		ans *= cnt[i]; // Multiply the answer with the count of the current character
	}

	// Calculate the final answer by subtracting 1 from the initial answer
	ans--;

	// Print the final answer to the standard output
	cout << ans << endl;

	return 0; // Indicate the successful termination of the program
}

