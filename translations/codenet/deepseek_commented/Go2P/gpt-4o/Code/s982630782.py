import sys
from collections import defaultdict

def main():
    # Create a dictionary to store the counts of integers
    m = defaultdict(int)
    
    # Read the number of initial elements (N) and the number of operations (M)
    N, M = map(int, sys.stdin.readline().split())
    
    # Read N integers and store their counts in the dictionary
    for _ in range(N):
        m[int(sys.stdin.readline().strip())] += 1
    
    # Perform M operations to update the dictionary with new integers and their counts
    for _ in range(M):
        B, C = map(int, sys.stdin.readline().split())
        m[C] += B
    
    # Create a list of integers from the dictionary keys
    ints = list(m.keys())
    
    # Sort the list of integers in descending order
    ints.sort(reverse=True)
    
    # Initialize variables to keep track of the remaining elements and the sum
    rest = N
    total_sum = 0
    
    # Iterate through the sorted integers and calculate the sum based on the conditions
    for i in ints:
        num = m[i]
        if num >= rest:
            total_sum += rest * i
            break
        total_sum += num * i
        rest -= num
    
    # Print the calculated sum
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
