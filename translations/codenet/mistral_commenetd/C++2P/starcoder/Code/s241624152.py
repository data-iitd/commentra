
# Define aliases for common data types
from typing import List

# Include necessary libraries
from collections import deque

# Function to solve the problem
def solve():
    # Initialize variables
    a: int = 0
    b: int = 0

    # Read input values from the user
    a, b = map(int, input().split())

    # Initialize output string
    ans: str = ""

    # Determine the answer based on the input values
    if a == 1 and b == 1:
        # Both a and b are equal to 1, so the answer is a draw
        ans = "Draw"
    elif a == 1:
        # a is equal to 1, so the answer is Alice
        ans = "Alice"
    else:
        # Neither a nor b is equal to 1, so the answer is Bob
        ans = "Bob"

    # Print the answer to the console
    print(ans)

# Main function
if __name__ == "__main__":
    # Call the solve function to solve the problem
    solve()

