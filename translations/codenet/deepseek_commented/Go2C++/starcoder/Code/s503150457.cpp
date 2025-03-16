#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declare three string variables to hold the input values
	string s1, s2, s3;
	
	// Read input values for s1, s2, and s3 from the standard input
	cin >> s1 >> s2 >> s3;

	// Split each input string into individual characters
	string s1s[s1.length()];
	string s2s[s2.length()];
	string s3s[s3.length()];

	for (int i = 0; i < s1.length(); i++) {
		s1s[i] = s1[i];
	}

	for (int i = 0; i < s2.length(); i++) {
		s2s[i] = s2[i];
	}

	for (int i = 0; i < s3.length(); i++) {
		s3s[i] = s3[i];
	}

	// Print the uppercase version of the first character of each input string
	cout << toupper(s1s[0]) << toupper(s2s[0]) << toupper(s3s[0]) << endl;
}

