#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	// Count the occurrences of the letter 'o' in the input string's'
	int n = count(s.begin(), s.end(), 'o');

	// Calculate the result based on the count of 'o' and print it
	// The formula adds 700 to 100 times the count of 'o'
	cout << 700 + n*100 << endl;
}

