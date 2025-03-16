
#include <stdio.h>

int main(void) {
	int n, sum;
	
	# Step 4: Read input from the user
	scanf("%d", &n);
	
	# Step 5: Calculate the sum of the first n natural numbers
	sum = (n * (n + 1)) / 2;
	
	# Step 6: Print the result
	printf("%d\n", sum);
	
	# Step 7: Return from the main function
	return 0;
}
