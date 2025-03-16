
import sys
import heapq

def solve():
    # Read the integer N from the input
    N = int(sys.stdin.readline().strip())

    # Initialize an array of size N to store the integers
    arr = [0] * N

    # Read N integers from the input and store them in the array
    for i in range(N):
        arr[i] = int(sys.stdin.readline().strip())

    # Initialize a sum variable to 0
    sum = 0

    # Create a priority queue to store the integers in ascending order
    q = []

    # Iterate through the array and add each element to the priority queue
    for i in range(len(arr)):
        heapq.heappush(q, arr[i])

        # Check if the current element is less than or equal to the smallest element in the priority queue
        if arr[i] <= q[0]:
            sum += 1

    # Return the sum
    return sum

# Call the solve function and print the result
print(solve())

# END-OF-CODE
