import sys
from collections import Counter

def read_int():
    return int(sys.stdin.readline().strip())

def main():
    # Read the number of initial elements (N) and the number of operations (M)
    N, M = map(int, sys.stdin.readline().strip().split())
    
    # Read N integers and store their counts in the map
    counts = list(map(int, sys.stdin.readline().strip().split()))
    counter = Counter(counts)
    
    # Perform M operations to update the map with new integers and their counts
    for _ in range(M):
        B, C = map(int, sys.stdin.readline().strip().split())
        counter[C] += B
    
    # Create a list of integers from the map keys
    ints = list(counter.keys())
    
    # Sort the list of integers in descending order
    ints.sort(reverse=True)
    
    # Initialize variables to keep track of the remaining elements and the sum
    rest = N
    sum_ = 0
    
    # Iterate through the sorted integers and calculate the sum based on the conditions
    for i in ints:
        num = counter[i]
        if num >= rest:
            sum_ += rest * i
            break
        sum_ += num * i
        rest -= num
    
    # Print the calculated sum
    print(sum_)

if __name__ == "__main__":
    main()

