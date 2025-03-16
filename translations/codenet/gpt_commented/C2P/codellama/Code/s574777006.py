#include <stdio.h>

int main() {
	
	# Declare variables
	n = 0
	i = 0
	j = 0
	q = 0
	x = []
	y = []
	sum = 0
	
	# Read the number of elements in array x
	scanf("%d", &n)
	
	# Read n elements into array x
	for i in range(n):
		scanf("%d", &x[i])
	
	# Read the number of queries
	scanf("%d", &q)
	
	# Read q elements into array y
	for i in range(q):
		scanf("%d", &y[i])
	
	# Initialize sum to count how many elements in y are found in x
	for i in range(q):
		# Check each element in y against all elements in x
		for j in range(n):
			# If a match is found, increment sum and break the inner loop
			if y[i] == x[j]:
				sum = sum + 1
				break
	
	# Output the total count of matches found
	printf("%d\n", sum)
	
	return 0
}

