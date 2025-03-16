# Include the standard input-output library for scanf and printf
# Include the standard library for the sort function
from __future__ import print_function
import sys

# Declare pointers to integers, a loop variable, and the number of elements
a = None
b = None
i = 0
N = 0

# Read the number of elements from the user
N = int(raw_input())

# Dynamically allocate memory for array a
a = [0] * N

# Dynamically allocate memory for array b
b = [0] * N

# Loop to read elements into array a and copy them to array b
for i in range(0, N):
	a[i] = int(raw_input())
	b[i] = a[i]

# Sort array b
b.sort()

# Calculate the first half's middle value
frontHalf = b[N / 2 - 1]

# Calculate the second half's middle value
backHalf = b[N / 2]

# Loop to compare each element of array a
for i in range(0, N):
	if (a[i] < backHalf):
		# Print the second middle value
		print(backHalf)
	else:
		# Print the first middle value
		print(frontHalf)

# Free the dynamically allocated memory for array b
del b

# Free the dynamically allocated memory for array a
del a

# Return 0 to indicate successful execution
sys.exit(0)

