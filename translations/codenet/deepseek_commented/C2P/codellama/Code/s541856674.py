#include <stdio.h> # Step 1: Include necessary headers

int main() { # Step 2: Define the main function
	int N = 0 # Step 3: Declare variables
	int R = 0

	scanf("%d %d", &N, &R) # Step 4: Read input values

	if(N >= 10): # Step 5: Implement conditional logic
		print(R) # If true, print the value of R
	else:
		print(R + 100*(10-N)) # Otherwise, calculate and print the adjusted value of R

	return 0 # Step 6: Return statement
}
