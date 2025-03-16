
import sys

# Define a constant for array or list size
NUM = int(1e5 + 2)

# Read the number of elements
N = int(input())

# Initialize a HashMap to store value and its index
map = {}

# Initialize a PriorityQueue to store numbers
nums = []

# Read each number, add it to the PriorityQueue, and store its value and index in the HashMap
for i in range(N):
    tmp = int(input())
    nums.append(tmp)
    map[tmp] = i

# Initialize variables to keep track of the current index and the count of differences
bin = 0
diff = 0

# Loop until the PriorityQueue is empty
while len(nums) > 0:
    # Retrieve the next number and its index from the PriorityQueue and HashMap
    num = nums.pop(0)
    idx = map[num]

    # If the current index is not even when bin is even (or vice versa), increment the diff counter
    if (bin % 2)!= (idx % 2):
        diff += 1

    # Update bin and take modulo 2 to keep it within 0 or 1
    bin += 1
    bin %= 2

# Calculate the answer by dividing diff by 2
ans = diff // 2

# Print the result
print(ans)

# 