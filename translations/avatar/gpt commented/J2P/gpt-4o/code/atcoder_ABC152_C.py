import heapq

def solve():
    # Create a list to hold the input values
    arr = list(map(int, input().split()))
    
    # Initialize a variable to keep track of the count of elements
    sum_count = 0
    
    # Create a priority queue (min-heap) to manage the elements
    q = []
    
    # Iterate through the array to process each element
    for num in arr:
        # Add the current element to the priority queue
        heapq.heappush(q, num)
        
        # Check if the current element is less than or equal to the smallest element in the queue
        if num <= q[0]:  # q[0] is the smallest element in the min-heap
            # Increment the count if the condition is met
            sum_count += 1
            
    # Return the final count of elements that met the condition
    return sum_count

# Call the solve function and print the result
print(solve())

# <END-OF-CODE>
