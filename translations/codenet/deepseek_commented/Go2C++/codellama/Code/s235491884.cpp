#include <iostream>
#include <string>

using namespace std;

int main() {
	string s; // Declaring a string variable to store user input
	cin >> s; // Reading input from the user and storing it in the variable s

	int n = count(s.begin(), s.end(), 'o'); // Counting the number of occurrences of "o" in the string s and storing the result in n
	cout << 700 + n*100 << endl; // Printing the final score based on the count of "o" characters

	return 0;
}

