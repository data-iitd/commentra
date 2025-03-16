#include <iostream>  // Include standard input/output library
#include <cstring>  // Include standard library for string manipulation

using namespace std;  // Use the standard namespace

int main(){  // Beginning of the main function
	string S;  // Declare a string variable 'S'

	cin >> S;  // Read a string from the standard input and store it in the variable 'S'

	for(int i = 0; i < S.length() - 1; i++){  // Iterate through each character in the string 'S'
		if(S[i] == 'A' && S[i + 1] == 'C'){  // Check if the current character is 'A' and the next character is 'C'
			cout << "Yes" << endl;  // If so, print 'Yes' to the standard output
			return 0;  // And exit the program
		}
	}

	cout << "No" << endl;  // If no pair of 'AC' is found, print 'No' to the standard output
	return 0;  // End of the main function
}

