# Step 1: Import the necessary libraries.
import sys

# Step 2: Declare the necessary variables.
a = 0
b = 0
c = 0
i = 0
count = 0

# Step 3: Read the input values for a, b, and c.
a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
c = int(sys.stdin.readline())

# Step 4: Initialize the count variable to zero.
count = 0

# Step 5: Start a for loop from a to b.
for i in range(a, b + 1):
	# Step 6: Check if c is divisible by i.
	if c % i == 0:
		# Step 7: Increment the count if the condition is true.
		count += 1

# Step 8: Print the count.
print(count)

# Step 9: Return 0 to indicate successful execution.
return 0

