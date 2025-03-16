import heapq  # Importing heapq for priority queue functionality
import sys  # Importing sys for reading input

def solve():
    input = sys.stdin.read  # Reading all input at once
    data = input().split()  # Splitting the input into a list of strings

    N = int(data[0])  # Reading the number of elements in the array
    arr = list(map(int, data[1:N+1]))  # Creating a list of integers from the input

    sum_count = 0  # Initializing sum variable to 0
    q = []  # Creating an empty list to use as a priority queue

    # Using for loop to iterate through the array
    for i in range(N):
        heapq.heappush(q, arr[i])  # Adding the current element to the priority queue

        # Checking if the current element is smaller than or equal to the top element of the queue
        if arr[i] <= q[0]:  # q[0] is the smallest element in the priority queue
            sum_count += 1  # Incrementing sum if the condition is true

    # Returning the sum as the solution
    return sum_count

if __name__ == "__main__":
    print(solve())  # Calling solve function to get the solution and print it

# <END-OF-CODE>
