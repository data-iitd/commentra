# Import necessary libraries
import sys

# Read height and width from input
H, W = map(int, sys.stdin.readline().split())

# Variable to store the final answer
if H == 1 or W == 1:
    ans = 1  # If either dimension is 1, the answer is 1
else:
    m = H * W  # Calculate the total number of cells (H * W)
    if m % 2 == 0:
        ans = m // 2  # If even, half of the cells can be filled
    else:
        ans = m // 2 + 1  # If odd, half plus one cell can be filled

# Output the final answer
print(ans)  # Print the final answer
# <END-OF-CODE>
