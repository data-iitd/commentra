
# Python code to solve the problem

# Declare a max heap and a variable to track the size of the heap
heap = []
sz = 0

# Function to insert an element into the max heap
def push(x):
    global sz
    i = sz
    sz += 1
    while i > 0:
        p = (i - 1) // 2
        if heap[p] >= x: break
        heap[i] = heap[p]
        i = p
    heap[i] = x

# Function to remove and return the maximum element from the max heap
def pop():
    global sz
    ret = heap[0]
    x = heap[sz - 1]
    sz -= 1
    i = 0
    while i * 2 + 1 < sz:
        a = i * 2 + 1
        b = i * 2 + 2
        if b < sz and heap[b] > heap[a]: a = b
        if heap[a] <= x: break
        heap[i] = heap[a]
        i = a
    heap[i] = x
    return ret

# Read the number of elements and the number of operations
n, m = map(int, input().split())
# Read the elements into the array
a = list(map(int, input().split()))
# Insert all elements into the max heap
for i in range(n): push(a[i])
# Perform m operations of removing the max element and pushing back half of it
for i in range(m):
    tm = pop()
    tm //= 2
    push(tm)
# Calculate the sum of all elements remaining in the heap
ans = sum(heap)
# Print the final result
print(ans)

