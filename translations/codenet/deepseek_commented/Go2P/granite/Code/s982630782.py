

import sys

def main():
    # Create a dictionary to store the counts of integers
    d = {}
    
    # Read the number of initial elements (N) and the number of operations (M)
    N, M = map(int, input().split())
    
    # Read N integers and store their counts in the dictionary
    for _ in range(N):
        i = int(input())
        d[i] = d.get(i, 0) + 1
    
    # Perform M operations to update the dictionary with new integers and their counts
    for _ in range(M):
        B, C = map(int, input().split())
        d[C] = d.get(C, 0) + B
    
    # Create a list of integers from the dictionary keys
    ints = list(d.keys())
    
    # Sort the list of integers in descending order
    ints.sort(reverse=True)
    
    # Initialize variables to keep track of the remaining elements and the sum
    rest = N
    sum = 0
    
    # Iterate through the sorted integers and calculate the sum based on the conditions
    for i in ints:
        num = d[i]
        if num >= rest:
            sum += rest * i
            break
        sum += num * i
        rest -= num
    
    # Print the calculated sum
    print(sum)

if __name__ == '__main__':
    main()

