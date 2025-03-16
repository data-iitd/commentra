import heapq

# Initialize the heap and size
heap = []
sz = 0

def push(x):
    global sz
    sz += 1
    heapq.heappush(heap, -x)  # Use negative values to simulate a max-heap

def pop():
    global sz
    ret = heapq.heappop(heap)
    sz -= 1
    return -ret  # Convert back to positive value

# Read input
n, m = map(int, input().split())
a = list(map(int, input().split()))

# Push all elements into the heap
for x in a:
    push(x)

# Perform m operations
for _ in range(m):
    x = pop()
    x //= 2
    push(x)

# Calculate the sum of the heap elements
ans = sum(heap)

# Output the result
print(ans)
