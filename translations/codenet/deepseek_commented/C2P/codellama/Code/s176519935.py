#include<stdio.h>

# Define the heap array and its size
heap = [0] * 100000
sz = 0

# Function to insert a new element into the heap
def push(x):
    i = sz # Increment the size of the heap and store the current index
    sz += 1
    # Bubble up the new element to its correct position
    while i > 0:
        p = (i - 1) // 2 # Calculate the parent index
        if heap[p] >= x: break # If the parent is greater or equal, break the loop
        heap[i] = heap[p] # Move the parent down
        i = p # Move to the parent index
    heap[i] = x # Insert the new element

# Function to remove and return the maximum element from the heap
def pop():
    ret = heap[0] # Store the root (maximum) element
    x = heap[sz - 1] # Get the last element and decrement the size of the heap
    sz -= 1
    i = 0 # Start from the root
    # Bubble down the new root to its correct position
    while i * 2 + 1 < sz:
        a = i * 2 + 1
        b = i * 2 + 2
        # Calculate the children indices
        if b < sz and heap[b] > heap[a]: a = b # Choose the larger child
        if heap[a] <= x: break # If the children are less than or equal to the element, break the loop
        heap[i] = heap[a] # Move the child up
        i = a # Move to the child index
    heap[i] = x # Insert the element
    return ret # Return the removed element

n, m = map(int, input().split()) # Read the number of elements and the number of operations
a = list(map(int, input().split())) # Read the elements into the array
for i in range(n): push(a[i]) # Push each element into the heap
for i in range(m):
    tm = pop() # Pop the maximum element
    tm //= 2 # Halve the element
    push(tm) # Push the halved element back into the heap
ans = 0
for i in range(n): ans += heap[i] # Calculate the sum of the heap elements
print(ans) # Print the result

