
#include <stdio.h>
# Declare an integer array 'v' of size 10 and an integer variable 'sum' to store the sum of array elements.
int main(void)
{
	int v[10];	# Declare an integer array 'v' of size 10.
	int sum=0;	# Declare an integer variable 'sum' and initialize it to zero.
	int i;		# Declare an integer variable 'i' to use as a counter in for loops.

	# Read 10 integers from the user and store them in the array 'v'.
	for(i=0;i<10;i++)
	{
		printf("Enter the value for index %d: ", i);
		scanf("%d",&v[i]);
		# Read an integer value from the user and store it in the current index of the array 'v'.
	}

	# Calculate the sum of all elements in the array 'v'.
	for(i=0;i<10;i++)
	{
		sum+=v[i];
		# Add the value of the current element in the array 'v' to the variable 'sum'.
	}

	# Print the sum of all elements in the array 'v'.
	printf("%d\n",sum);
	# Display the sum of all elements in the array 'v'.

	return 0;
	# Indicate successful termination of the program.
}

