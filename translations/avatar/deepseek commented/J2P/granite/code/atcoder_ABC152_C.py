

import sys

def solve():
    # Read the integer N from the input
    N = int(input())

    # Initialize an array of size N to store the integers
    arr = list(map(int, input().split()))

    # Initialize a sum variable to 0
    sum = 0

    # Create a priority queue to store the integers in ascending order
    q = []

    # Iterate through the array and add each element to the priority queue
    for i in range(N):
        q.append(arr[i])
        q.sort()
        if arr[i] <= q[0]:
            sum += 1

    # Return the sum
    return sum

if __name__ == "__main__":
    print(solve())

