#include <stdio.h>

int main(void) {
	int n; // Step 3: Declare an integer variable n
	unsigned long long int m; // Step 3: Declare an unsigned long long integer variable m
	scanf("%d",&n); // Step 4: Read an integer input from the user and store it in n
	m=n; // Step 5: Copy the value of n to m
	n-=1; // Step 6: Decrement the value of n by 1
	for(;n>1;n-=1) { // Step 7: Start a for loop that runs while n is greater than 1
		m*=n; // Inside the loop, multiply m by n and decrement n by 1
	}
	print(m); // Step 8: Print the value of m, which represents the factorial of the input number
	return 0; // Step 9: Return 0 to indicate successful execution
}
