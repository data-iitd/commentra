// Package main is the entry point of our Go program
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declare and initialize two variables: n of type int and s of type string
	int n;
	string s;

	// Use the cin object to read input from the standard input
	cin >> n;
	cin >> s;

	// Use the std::string and std::count functions to compute and print the result
	cout << count(s.begin(), s.end(), 'A') << endl;

	return 0;
}

