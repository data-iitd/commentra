import sys

def main():
    # Initialize a map to count occurrences of integers
    m = {}

    # Read the number of initial integers (N) and the number of operations (M)
    N, M = read_int(), read_int()

    # Read N integers and count their occurrences in the map
    for i in range(N):
        m[read_int()] = m.get(read_int(), 0) + 1

    # Process M operations, where each operation adds B occurrences of integer C
    for i in range(M):
        B, C = read_int(), read_int()
        m[C] = m.get(C, 0) + B

    # Create a slice to hold the unique integers from the map
    ints = []
    for i in m:
        ints.append(i)

    # Sort the integers in descending order
    ints.sort(reverse=True)

    # Initialize variables to keep track of remaining integers and the total sum
    rest = N
    sum = 0

    # Calculate the maximum sum based on the sorted integers
    for i in ints:
        num = m[i]
        # If the number of occurrences is greater than or equal to the remaining count
        if num >= rest:
            sum += rest * i # Add the product of remaining count and the integer
            break # Exit the loop as we have used all remaining integers
        sum += num * i # Add the product of occurrences and the integer to the sum
        rest -= num # Decrease the remaining count by the number of occurrences

    # Output the final calculated sum
    print(sum)

# Initialize a buffered reader for input
reader = sys.stdin

# Scan reads input and handles any errors
def read_int():
    return int(reader.readline())

# ReadInt reads an integer from input and returns it
def read_int():
    return int(input())

# 