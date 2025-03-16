
#include<iostream> // Step 1: Include the standard input/output library.
using namespace std; // Step 8: Use the standard namespace.

int main() // Step 2: Define the main function.
{
	int a,b,h; // Step 3: Declare three integer variables a, b, and h.
	
	// Step 4: Read three integer values from the user and store them in a, b, and h.
	cin>>a>>b>>h; 
	
	// Step 5: Calculate the area of a trapezoid using the formula (a+b)*h/2.
	cout<<(a+b)*h/2<<endl; 
	
	// Step 7: End the main function and return 0.
	return 0; 
}

