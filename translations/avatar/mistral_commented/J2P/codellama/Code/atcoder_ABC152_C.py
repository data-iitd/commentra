import sys
import heapq

def solve():
    # Reading the number of elements in the array
    N = int(sys.stdin.readline().strip())

    # Creating an empty list to store the elements
    arr = []

    # Using for loop to read and store elements in the list
    for i in range(N):
        arr.append(int(sys.stdin.readline().strip()))

    # Initializing sum variable to 0
    sum = 0

    # Creating an empty heap
    q = []

    # Using for loop to iterate through the list
    for i in range(len(arr)):
        # Adding the current element to the heap
        heapq.heappush(q, arr[i])

        # Checking if the current element is smaller than or equal to the top element of the heap
        if arr[i] <= q[0]:
            sum += 1 # Incrementing sum if the condition is true

    # Returning the sum as the solution
    return sum

# Main method to call the solve method and print the solution
if __name__ == "__main__":
    print(solve()) # Calling solve method to get the solution and print it

