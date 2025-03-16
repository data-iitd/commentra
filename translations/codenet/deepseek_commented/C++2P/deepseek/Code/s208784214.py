# Step 1: Include necessary libraries and declare variables
# We include the sys library for input operations.
# We declare two integer variables, N and A, to store user input.

import sys

# Step 2: Read input values
# We read two integer values from the standard input and store them in variables N and A.
N, A = map(int, sys.stdin.readline().split())

# Step 3: Perform the required operation
# We check if the remainder of N divided by 500 is less than or equal to A.
# If the condition is true, we print "Yes"; otherwise, we print "No".
print("Yes" if N % 500 <= A else "No")

# Step 4: Return from the main function
# We do not need to return anything in Python as the function implicitly returns None.

