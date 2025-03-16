
#include <stdio.h>

# Declare variables
n = 0
m = 0

# Initialize variables
n = int(input())
m = n

# Decrement n by 1
n -= 1

# Loop through n-1 times to calculate the factorial
for i in range(n-1):
    # Multiply m with current value of n
    m *= n

# Print the result
print(m)

# Return 0 to indicate successful execution
return 0

