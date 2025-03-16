
import sys

# Define a constant for the maximum number of elements
NUM = int(1e5 + 2)

# Read the number of elements
N = int(sys.stdin.readline().strip())

# Initialize a dictionary to store the index of each number
map = {}

# Initialize a priority queue to store the numbers in sorted order
nums = []

# Read N numbers from input
for i in range(N):
    tmp = int(sys.stdin.readline().strip()) # Read the next number
    nums.append(tmp) # Add the number to the priority queue
    map[tmp] = i # Store the index of the number in the dictionary

# Initialize variables to track the binary state and the difference count
bin = 0
diff = 0

# Process the numbers in sorted order
while len(nums) > 0:
    num = nums.pop(0) # Retrieve and remove the smallest number
    idx = map[num] # Get the original index of the number
    
    # Check if the parity of the current index and the binary state differ
    if (bin % 2) != (idx % 2):
        diff += 1 # Increment the difference count if they differ
    
    # Update the binary state
    bin += 1
    bin %= 2 # Toggle between 0 and 1

# Calculate the final answer as half of the difference count
ans = diff // 2

# Output the result
print(ans)

