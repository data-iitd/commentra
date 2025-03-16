
# Step 1: Include necessary libraries and declare variables
# We import the sys library to access system functions.
# We declare two integer variables, N and A, to store user input.

import sys
N = int(sys.stdin.readline())
A = int(sys.stdin.readline())

# Step 2: Read input values
# We read two integer values from the standard input and store them in variables N and A.

# Step 3: Perform the required operation
# We check if the remainder of N divided by 500 is less than or equal to A.
# If the condition is true, we print "Yes"; otherwise, we print "No".

if N % 500 <= A:
    print("Yes")
else:
    print("No")

# Step 4: Return from the main function
# We use the sys.exit() function to exit the program with a status code of 0.

sys.exit(0)

