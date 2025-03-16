
import heapq # Importing heapq module
import sys # Importing sys module

def solve():
    # Reading the number of elements in the array from the input
    N = int(input())

    # Creating an empty list to store the array elements
    arr = []

    # Using for loop to read and store elements in the array
    for i in range(N):
        arr.append(int(input())) # Reading an integer and appending it to the array

    sum = 0 # Initializing sum variable to 0
    q = [] # Creating an empty list to store the elements of the queue

    # Using for loop to iterate through the array
    for i in range(len(arr)):
        heapq.heappush(q, arr[i]) # Adding the current element to the queue

        # Checking if the current element is smaller than or equal to the top element of the queue
        if arr[i] <= q[0]:
            sum += 1 # Incrementing sum if the condition is true

    # Returning the sum as the solution
    return sum

# Main method is the entry point of the Python application
if __name__ == "__main__":
    # Printing the solution
    print(solve()) # Calling solve method to get the solution and print it

