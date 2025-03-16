# Declare a max heap and a variable to track the size of the heap
heap = []
sz = 0

# Function to insert an element into the max heap
def push(x):
    global sz
    i = sz  # Current index
    sz += 1  # Increment size
    heap.append(x)  # Add the new element to the end of the heap
    # Percolate up to maintain heap property
    while i > 0:
        p = (i - 1) // 2  # Calculate parent index
        if heap[p] >= x:
            break  # If parent is greater or equal, stop
        heap[i] = heap[p]  # Move parent down
        i = p  # Move index to parent
    heap[i] = x  # Place the new element in its correct position

# Function to remove and return the maximum element from the max heap
def pop():
    global sz
    ret = heap[0]  # Store the maximum element
    x = heap[sz - 1]  # Remove the last element
    sz -= 1  # Decrease size
    if sz > 0:
        heap[0] = x  # Move the last element to the root
        i = 0  # Start from the root of the heap
        # Percolate down to maintain heap property
        while i * 2 + 1 < sz:
            a = i * 2 + 1  # Left child index
            b = i * 2 + 2  # Right child index
            # Choose the larger child
            if b < sz and heap[b] > heap[a]:
                a = b
            if heap[a] <= x:
                break  # If the larger child is less than or equal to x, stop
            heap[i] = heap[a]  # Move the larger child up
            i = a  # Move index to the child
        heap[i] = x  # Place the removed element in its correct position
    return ret  # Return the maximum element

def main():
    global sz
    n, m = map(int, input().split())  # Read the number of elements and the number of operations
    a = list(map(int, input().split()))  # Read the elements into the array
    # Insert all elements into the max heap
    for i in range(n):
        push(a[i])
    # Perform m operations of removing the max element and pushing back half of it
    for i in range(m):
        tm = pop()  # Get the maximum element
        tm //= 2  # Halve the maximum element
        push(tm)  # Push the halved value back into the heap
    ans = sum(heap[:sz])  # Calculate the sum of all elements remaining in the heap
    # Print the final result
    print(ans)

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
