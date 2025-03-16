#include <iostream>

using namespace std;

int main(){
	// Declare a string variable to store the input
	string s;
	
	// Read a string input from the user and store it in `s`
	cin >> s;
	
	// Iterate over each character in the string `s` and print 'x' for each character
	for(int i = 0 ; i < s.length() ; i++){
		cout << "x";
	}
	
	// Print a newline character to move to the next line
	cout << endl;
}

