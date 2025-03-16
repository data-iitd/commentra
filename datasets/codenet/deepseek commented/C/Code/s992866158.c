#include <stdio.h> // Include necessary headers

int main() {
	int n, k, cnt; // Declare necessary variables

	scanf("%d%d", &n, &k); // Read input values
	cnt = 0; // Initialize the count variable
	while (n--) { // Use a while loop to read each height
		int h;

		scanf("%d", &h); // Read each height
		if (h >= k) // Check if the height is suitable
			cnt++; // Increment the count if the height is greater than or equal to k
	}
	printf("%d\n", cnt); // Print the final count
	return 0; // Return 0 to indicate successful execution
}
