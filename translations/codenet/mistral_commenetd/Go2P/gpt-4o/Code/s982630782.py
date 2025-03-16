import sys
from collections import defaultdict

def read_int():
    return int(sys.stdin.readline().strip())

def main():
    # Initialize an empty dictionary to store the frequency of each number
    m = defaultdict(int)

    # Read the number of test cases N
    N = read_int()
    # Read the N integers and store their frequencies in the dictionary
    for _ in range(N):
        num = read_int()
        m[num] += 1

    # Read the number of queries M
    M = read_int()
    # For each query, read the number B and the index C, and update the frequency of the number at index C in the dictionary
    for _ in range(M):
        B, C = map(int, sys.stdin.readline().strip().split())
        m[C] += B

    # Create a list of integers from the dictionary keys
    ints = list(m.keys())

    # Sort the list in descending order
    ints.sort(reverse=True)

    # Initialize variables for calculating the sum
    rest = N
    total_sum = 0
    # Iterate through the sorted list of integers
    for i in ints:
        num = m[i]
        # If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
        if num >= rest:
            total_sum += rest * i
            break
        # Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
        total_sum += num * i
        rest -= num

    # Print the result
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
