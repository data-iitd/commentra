import sys

def main():
    # Read the integer N from standard input
    N = int(sys.stdin.readline().strip())

    # Initialize a list v of size N to hold counts of occurrences
    v = [0] * N

    # Loop through the range from 1 to N-1 to read N-1 integers
    for _ in range(1, N):
        # Read the next integer from input
        a = int(sys.stdin.readline().strip())
        # Increment the count at the index corresponding to the value read (adjusted for 0-based index)
        v[a - 1] += 1

    # Print the counts of occurrences
    for e in v:
        print(e)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
