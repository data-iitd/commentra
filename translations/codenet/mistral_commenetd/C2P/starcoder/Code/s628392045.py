# Include necessary header files
import sys

# Declare and initialize variables
n = 0
i = 0
h = []
max = -1
flag = 0

# Read the number of test cases
n = int(sys.stdin.readline())

# Read and process input
for i in range(n):
    # Read the next integer from standard input and store it in the array h
    h.append(int(sys.stdin.readline()))

    # Update the maximum height if the current height is greater
    if(max < h[i]): max = h[i]

    # Check if the difference between the current height and maximum height is greater than or equal to 2
    if(max - h[i] >= 2): flag = 1

# Check the value of the flag and print the appropriate message to the standard output
if(flag == 1): print("No")

else: print("Yes")

# Return 0 to indicate successful execution
return 0

