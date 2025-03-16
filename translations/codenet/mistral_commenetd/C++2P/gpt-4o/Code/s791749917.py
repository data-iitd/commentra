# Import necessary libraries
H, W = map(int, input().split())  # Read input values for H and W

# Initialize answer variable
ans = 0

# Check if the grid has only one cell
if H == 1 or W == 1:
    ans = 1  # The answer is 1 in this case
else:
    # Calculate the total number of cells in the grid
    m = H * W

    # Check if the total number of cells is even
    if m % 2 == 0:
        ans = m // 2  # The answer is half of the total number of cells if it's even
    else:
        ans = m // 2 + 1  # The answer is half of the total number of cells plus one if it's odd

# Output the answer
print(ans)

# End of code
# <END-OF-CODE>
