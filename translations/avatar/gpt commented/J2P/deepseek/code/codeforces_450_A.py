from collections import deque
import sys

# Read the number of elements (n) and the threshold value (m)
n, m = map(int, sys.stdin.readline().split())

# Initialize two queues: one for the values and one for their original indices
q1 = deque()
q2 = deque()

# Populate the queues with input values and their corresponding indices
for i in range(1, n + 1):
    value = int(sys.stdin.readline())
    q1.append(value)  # Add the value to the first queue
    q2.append(i)  # Add the index to the second queue

# Variable to store the final answer (the index of the last processed element)
ans = 0

# Process the elements in the queue until it is empty
while q1:
    # Check if the front element of q1 is less than or equal to m
    if q1[0] <= m:
        # If yes, remove it from q1 and update the answer with the corresponding index from q2
        ans = q2.popleft()
        q1.popleft()
    # If the front element is greater than m
    else:
        # Remove the element, reduce it by m, and add it back to q1
        x = q1.popleft()
        val = x - m
        q1.append(val)
        
        # Remove the index from q2 and add it back to maintain the order
        val2 = q2.popleft()
        q2.append(val2)

# Output the final answer
print(ans)
