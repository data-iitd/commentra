# Import the sys module for standard input
import sys

# Read two integers A and B from standard input
A, B = map(int, sys.stdin.readline().split())

# Initialize the variable ans to store the result of our calculation
ans = 0

# Check the value of A
if 6 <= A <= 12:
    # If A is between 6 and 12 (inclusive), calculate the answer as the integer division of B by 2
    ans = B // 2
elif A > 12:
    # If A is greater than 12, assign the value of B directly to the ans variable
    ans = B

# Print the value of ans
print(ans)

# End of code
# <END-OF-CODE>
