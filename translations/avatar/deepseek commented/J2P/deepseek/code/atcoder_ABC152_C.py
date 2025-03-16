import heapq
import sys

def solve():
    # Read the integer N from the input
    N = int(sys.stdin.readline().strip())
    
    # Read N integers from the input and store them in the array
    arr = list(map(int, sys.stdin.readline().strip().split()))
    
    # Initialize a sum variable to 0
    sum_ = 0
    
    # Create a priority queue to store the integers in ascending order
    q = []
    
    # Iterate through the array and add each element to the priority queue
    for i in range(N):
        heapq.heappush(q, arr[i])
        
        # Check if the current element is less than or equal to the smallest element in the priority queue
        if arr[i] <= q[0]:
            sum_ += 1
    
    # Return the sum
    return sum_

# Read the input and print the result
if __name__ == "__main__":
    print(solve())
