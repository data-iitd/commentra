#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declare a variable S to hold the input string
	string S;
	
	// Read the input string from the standard input
	cin >> S;
	
	// Iterate over even lengths of the string from 2 to the length of S
	for (int i = 2; i <= S.length(); i = i + 2) {
		// Check if the first half of the string (up to the current length minus i)
		// is equal to the second half of the string (from the middle to the current length minus i)
		if (S.substr(0, S.length() - i) == S.substr(S.length() - i, S.length() - i)) {
			// If they are equal, print the length of the string minus i
			// This gives the length of the string that is not part of the repeated pattern
			cout << S.length() - i << endl;
			// Exit the loop after finding the first match
			break;
		}
	}
}

