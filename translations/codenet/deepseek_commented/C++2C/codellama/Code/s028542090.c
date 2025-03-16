#include <stdio.h>

int main(void)
{
	int k; // Declare an integer variable to store the number of elements
	unsigned long min, max; // Declare variables to store the minimum and maximum values
	scanf("%d", &k); // Read the number of elements from the standard input

	unsigned long a[100100]; // Declare an array to store up to 100100 elements

	for (int i = 0; i < k; i++)
		scanf("%ld", &a[i]); // Read the elements of the array from the standard input

	max = 3, min = 2; // Initialize the maximum and minimum values

	if (a[k - 1] != 2) { // Check if the last element of the array is not 2
		printf("%ld\n", -1); // Output -1 and terminate the program
		return 0;
	}

	for (int i = k - 2; i >= 0; i--) { // Iterate through the array in reverse order
		if (a[i] > max) { // Check if the current element is greater than the current maximum
			printf("%ld\n", -1); // Output -1 and terminate the program
			return 0;
		} else {
			max = ((max / a[i]) + 1) * a[i] - 1; // Update the maximum value
			if (min % a[i] != 0) { // Check if min is not a multiple of the current element
				min = ((min / a[i]) + 1) * a[i]; // Update the minimum value
			}
		}

		if (max <= min) { // Check if the maximum value is not greater than the minimum value
			printf("%ld\n", -1); // Output -1 and terminate the program
			return 0;
		}
	}

	printf("%ld %ld\n", min, max); // Output the minimum and maximum values

    return 0;
}

