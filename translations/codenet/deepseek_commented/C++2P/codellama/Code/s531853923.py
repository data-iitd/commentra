#include<iostream> 
#include<string> 
#include<vector> 
#include<algorithm> 
using namespace std; 

// Main function to execute the program
int main()
{
	// Declare four integer variables to store user input
	int a, b, c, d; 
	
	// Read four integers from the standard input
	cin >> a >> b >> c >> d; 
	
	// Check if the product of a and b is odd and if the sum of c and d is also odd
	if (a*b%2==1 and (c+d)%2==1):
		# If both conditions are true, print "No"
		print("No")
	else:
		# Otherwise, print "Yes"
		print("Yes")
}

