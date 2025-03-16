#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; // Declaring an integer variable to store the number of inputs
	string s; // Declaring a string variable to store the input string
	cin >> n >> s; // Reading input from the user and storing it in n and s
	cout << count(s.begin(), s.end(), 'A') << endl; // Counting the occurrences of 'A' in s and printing the result
	return 0;
}

