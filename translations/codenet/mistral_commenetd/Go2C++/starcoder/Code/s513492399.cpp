
#include <iostream>
using namespace std;

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b){
	// Base case: if b is 0, return a as the GCD
	if(b==0){
		return a;
	}
	// Recursive case: call gcd function with b and the remainder of a divided by b
	return gcd(b, a%b);
}

// Main function
int main(){
	// Initialize variables
	int k, a, b, c, ans=0;
	// Read an integer 'k' from the user input
	cin>>k;
	// Loop through all possible combinations of a, b and c from 1 to k
	for(a=1;a<=k;a++){
		// Inner loop to find the GCD of b and c
		for(b=1;b<=k;b++){
			// Inner most loop to find the GCD of a, b and c
			for(c=1;c<=k;c++){
				// Add the result of GCD(a, GCD(b, c)) to the answer
				ans+=gcd(a, gcd(b, c));
			}
		}
	}
	// Print the final answer
	cout<<"The sum of GCD of all combinations of three numbers from 1 to k is: "<<ans<<endl;
	// End of code

