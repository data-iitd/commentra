#include<iostream>
#include<string>
using namespace std;

#include<iostream>
#include<string>
using namespace std;

// Main function where the program execution begins
int main() {
	// Declare variables to store integers and a character
	int a, b;
	char S;
	
	// Infinite loop to continuously take input and perform operations
	while (true):
		// Take input in the format a S b
		cin >> a >> S >> b;
		
		// Perform operations based on the value of S
		if (S == '+'):
			cout << a + b << endl;
		if (S == '-'):
			cout << a - b << endl;
		if (S == '*'):
			cout << a * b << endl;
		if (S == '/'):
			cout << a / b << endl;
		
		// Break the loop if S is '?'
		if (S == '?'):
			break;
}

