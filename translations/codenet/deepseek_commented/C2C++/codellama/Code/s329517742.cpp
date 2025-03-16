#include<iostream> // Step 1: Include the standard input/output library.
using namespace std; // Step 2: Use the standard namespace.
int main() // Step 3: Define the main function.
{
	int a,b; // Step 4: Declare two integer variables a and b.
	cin>>a>>b; // Step 5: Read two integers from the user input.
	if(500*a>=b) cout<<"Yes\n"; // Step 6: Check if the product of 500 and a is greater than or equal to b.
	else cout<<"No\n"; // Step 7: Print "Yes" if the condition is true, otherwise print "No".
	return 0; // Step 8: End the main function and return 0.
}
