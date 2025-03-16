
import heapq

def solve():
    # Read the number of elements in the array
    N = int(input())

    # Populate the array with user input
    arr = list(map(int, input().split()))

    # Initialize a variable to keep track of the count of elements
    sum = 0

    # Create a priority queue to manage the elements
    q = []

    # Iterate through the array to process each element
    for i in range(N):
        # Add the current element to the priority queue
        heapq.heappush(q, arr[i])

        # Check if the current element is less than or equal to the smallest element in the queue
        if arr[i] <= q[0]:
            # Increment the count if the condition is met
            sum += 1

    # Return the final count of elements that met the condition
    return sum

# Call the solve method and print the result
print(solve())

