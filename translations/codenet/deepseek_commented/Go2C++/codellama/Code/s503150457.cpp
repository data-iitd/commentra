
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	// Declare three string variables to hold the input values
	string s1, s2, s3;
	
	// Read input values for s1, s2, and s3 from the standard input
	cin >> s1 >> s2 >> s3;

	// Split each input string into individual characters
	vector<string> s1s = split(s1);
	vector<string> s2s = split(s2);
	vector<string> s3s = split(s3);

	// Print the uppercase version of the first character of each input string
	cout << toUpper(s1s[0]) + toUpper(s2s[0]) + toUpper(s3s[0]) << endl;

	return 0;
}

string toUpper(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = s[i] - 32;
		}
	}
	return s;
}

vector<string> split(string s) {
	vector<string> v;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s.substr(i, 1));
	}
	return v;
}

