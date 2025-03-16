
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	// Declare three string variables to hold user input
	string s1, s2, s3;
	
	// Read three strings from standard input
	cin >> s1 >> s2 >> s3;

	// Split each string into a vector of individual characters
	vector<string> s1s = split(s1);
	vector<string> s2s = split(s2);
	vector<string> s3s = split(s3);

	// Convert the first character of each string to uppercase and concatenate them
	string result = toUpper(s1s[0]) + toUpper(s2s[0]) + toUpper(s3s[0]);
	
	// Print the concatenated result
	cout << result << endl;

	return 0;
}

string toUpper(string s) {
	return s[0] - 'a' + 'A';
}

vector<string> split(string s) {
	vector<string> result;
	for (int i = 0; i < s.length(); i++) {
		result.push_back(s[i]);
	}
	return result;
}

