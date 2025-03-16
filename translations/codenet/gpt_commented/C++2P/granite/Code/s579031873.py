
import sys

# Read the number of items (N) and the total amount (X)
N, X = map(int, input().split())

# Initialize the answer and minimum value variables
ans = 0 # Counter for the number of items processed
min = sys.maxsize # Initialize min to a large value

# Process each item
for i in range(N):
    tmp = int(input()) # Read the current item's value
    X -= tmp # Subtract the item's value from total amount X
    ans += 1 # Increment the count of items processed
    if tmp < min: min = tmp # Update min if the current item is smaller

# Calculate how many more items can be added using the remaining amount
ans += X // min # Add the number of additional items that can be bought

# Output the final answer
print(ans)

