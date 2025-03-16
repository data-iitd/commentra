
#include <iostream>
#include <string>

using namespace std;

// Declare empty strings s1, s2, and s3 for user input
string s1, s2, s3;

int main() {
	// Read user input for strings s1, s2, and s3
	cin >> s1 >> s2 >> s3;

	// Declare slices s1s, s2s, and s3s to store individual characters of strings s1, s2, and s3 respectively
	string s1s[s1.length()];
	string s2s[s2.length()];
	string s3s[s3.length()];

	// Print the concatenated uppercase first character of each string
	cout << toupper(s1s[0]) << toupper(s2s[0]) << toupper(s3s[0]) << endl;
}

