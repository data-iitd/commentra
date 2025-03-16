# Step 1: Include necessary libraries and declare variables
# We include the iostream library for input and output operations.
# We declare two integer variables, N and A, to store user input.

import sys

N = int(input())
A = int(input())

# Step 2: Perform the required operation
# We check if the remainder of N divided by 500 is less than or equal to A.
# If the condition is true, we print "Yes"; otherwise, we print "No".
print("Yes" if N % 500 <= A else "No")

# Step 3: Return from the main function
# We return 0 to indicate successful execution of the program.
sys.exit(0)

