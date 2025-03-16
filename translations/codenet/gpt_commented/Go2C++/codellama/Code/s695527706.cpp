#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string s;

	// Read input values for n and s from the standard input
	cin >> n >> s;

	// Count and print the number of occurrences of the substring "ABC" in the string s
	cout << count(s.begin(), s.end(), 'A') << endl;

	return 0;
}

