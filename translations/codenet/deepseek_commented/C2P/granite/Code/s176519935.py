
import heapq

# Read the number of elements and the number of operations
n, m = map(int, input().split())

# Read the elements into a list
a = list(map(int, input().split()))

# Initialize a min-heap with the elements
heapq.heapify(a)

# Perform the operations
for _ in range(m):
    # Pop the maximum element and halve it
    tm = heapq.heappop(a) // 2
    # Push the halved element back into the heap
    heapq.heappush(a, tm)

# Calculate the sum of the heap elements
ans = sum(a)

# Print the result
print(ans)

