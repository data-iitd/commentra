# Define a function to calculate the number of cells that can be filled
def get_num_cells(H, W):
  # Check if either height or width is 1
  if H == 1 or W == 1:
    return 1 # If either dimension is 1, the answer is 1
  else:
    m = H * W # Calculate the total number of cells (H * W)
    # Check if the total number of cells is even or odd
    if m % 2 == 0:
      return m / 2 # If even, half of the cells can be filled
    else:
      return m / 2 + 1 # If odd, half plus one cell can be filled

# Read the height and width from the user
H, W = map(int, input().split())

# Get the number of cells that can be filled
ans = get_num_cells(H, W)

# Output the final answer
print(ans)

