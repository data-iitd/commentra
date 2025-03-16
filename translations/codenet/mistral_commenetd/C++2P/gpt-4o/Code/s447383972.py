# Including necessary libraries
import sys
from collections import defaultdict

# Function to read input
def read():
    return int(sys.stdin.readline().strip())

# Function to write output
def writeln(x):
    print(x)

# Constants
N = 200010
a = [0] * N
q = [0] * N
tot = 0

# Main function
def main():
    global tot

    # Reading input
    n = read()

    # Reading array 'a'
    for i in range(1, n + 1):
        a[i] = read()

    # Sorting array 'a' in ascending order
    a[1:n + 1] = sorted(a[1:n + 1])

    # Finding duplicate elements and storing them in 'q'
    i = 1
    while i <= n:
        if a[i] == a[i + 1]:  # Checking if current element is same as next element
            q[tot + 1] = a[i]  # If yes, storing it in 'q'
            tot += 1  # Incrementing total count
            i += 1  # Incrementing index 'i'
        i += 1

    # Outputting the result
    if tot >= 2:
        writeln(q[tot] * q[tot - 1])
    else:
        writeln(0)  # If there are not enough duplicates

# End of main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
