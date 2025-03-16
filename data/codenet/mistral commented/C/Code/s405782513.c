
#include <stdio.h>

int main(void)
{
	// Declare an integer array 'c' of size 3 to store the input values
	int c[3];

	// Start an infinite loop to read input values until EOF is reached
	while (scanf("%d %d %d", &c[0], &c[1], &c[2]) != EOF){
		// Declare and initialize a character array 'card' of size 10 with all elements set to zero
		char card[10] = {0};
		int i;
		int count = 0;
		int sum = c[0] + c[1]; // Initialize sum with the sum of the first two input values

		// Loop through the array 'c' to mark the corresponding index in 'card' array
		for (i = 0; i < 3; i++){
			card[c[i] - 1] = 1; // Set the index in 'card' array to 1 if the corresponding value in 'c' is read
		}

		// Loop through the array 'card' to check if there are at least 4 distinct numbers in the input
		for (i = 0; i < 10; i++){
			// If the index in 'card' array is not set to 1 and the sum of input values, index and 1 is less than or equal to 20
			if (card[i] == 0 && sum + i + 1 <= 20){
				count++; // Increment the count if the condition is true
			}
		}

		// Check if the count is greater than or equal to 4 and print "YES" if true, otherwise print "NO"
		if (count >= 4){
			puts("YES");
		}
		else {
			puts("NO");
		}
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}

I hope these comments help make the code more readable and understandable. Let me know if you have any questions or need further clarification.