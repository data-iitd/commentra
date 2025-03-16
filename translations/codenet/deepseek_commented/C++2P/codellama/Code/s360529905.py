#include <cstdio> // Include the standard input-output library for scanf and printf
#include <algorithm> // Include the standard library for the sort function
using std::sort; // Use the sort function from the standard library

int main(void)
{
	int *a, *b, i, N; // Declare pointers to integers, a loop variable, and the number of elements
	int frontHalf, backHalf; // Declare two integers to hold the two halves

	scanf("%d", &N); // Read the number of elements from the user
	a = new int[N]; // Dynamically allocate memory for array a
	b = new int[N]; // Dynamically allocate memory for array b

	for (i = 0; i < N; i++) // Loop to read elements into array a and copy them to array b
	{
		scanf("%d", a + i); // Read an element into array a
		b[i] = a[i]; // Copy the element from array a to array b
	}

	sort(b, b + N); // Sort array b

	frontHalf = b[N / 2 - 1]; // Calculate the first half's middle value
	backHalf = b[N / 2]; // Calculate the second half's middle value

	delete[] b; // Free the dynamically allocated memory for array b

	for (i = 0; i < N; i++) // Loop to compare each element of array a
	{
		if (a[i] < backHalf) // Check if the element is less than the second middle value
			printf("%d\n", backHalf); // Print the second middle value
		else
			printf("%d\n", frontHalf); // Print the first middle value
	}

	delete[] a; // Free the dynamically allocated memory for array a
	return 0; // Return 0 to indicate successful execution
}

