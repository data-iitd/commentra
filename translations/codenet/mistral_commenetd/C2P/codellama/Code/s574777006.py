
#include <stdio.h>

# Declare variables
n, i, j, q, x, y, sum = 0

# Read the number of elements in the array x
scanf("%d", &n)

# Allocate memory for array x
for i in range(0, n):
    # Read each element of array x
    scanf("%d", &x[i])

# Read the number of queries
scanf("%d", &q)

# Allocate memory for array y
for i in range(0, q):
    # Read each element of array y
    scanf("%d", &y[i])

# Initialize sum to zero
sum = 0

# Check if each element of array y is present in array x and increment sum if found
for i in range(0, q):
    for j in range(0, n):
        # Check if current element of y is equal to current element of x
        if y[i]==x[j]:
            # Increment sum if found
            sum = sum + 1
            # Break out of inner loop as soon as a match is found
            break

# Print the value of sum
printf("%d\n", sum)

# Return 0 to indicate successful execution
return 0

