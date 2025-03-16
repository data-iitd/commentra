
#include <stdio.h>

int main(void)
{
	// Step 2: Declare the necessary variables.
	a = int(input("Enter the value of a: "))
	b = int(input("Enter the value of b: "))
	c = int(input("Enter the value of c: "))
	i = 0
	count = 0
	
	// Step 3: Start a for loop from a to b.
	for i in range(a, b+1):
		# Step 6: Check if c is divisible by i.
		if c % i == 0:
			# Step 7: Increment the count if the condition is true.
			count += 1
	
	# Step 8: Print the count.
	print(count)
	
	# Step 9: Return 0 to indicate successful execution.
	return 0
}

