
#include<iostream> // Standard Input/Output library
#include<cstdlib> // Standard Library for memory allocation and other functions
#include<climits> // Library for working with maximum and minimum values
#include<cmath> // Library for mathematical functions

using namespace std;

int main(){
	// Declare variables
	int i,j,k,n;

	cout << "Enter the value of n: ";
	cin >> n; // Read an integer value from the user and store it in variable n

	// Calculate and print the result
	cout << "The result is: " << 24 + (24-n) << endl;

	return 0; // Indicate successful execution of the program
}

