
import sys

# Define a constant for modulo operations
mod = 1000000007

def main():
    # Read the length of the string and the number of queries
    n, q = map(int, input().split())

    # Read the string as a character array
    c = input()

    # Read the ranges for the queries and store them in a 2D array
    range = [list(map(int, input().split())) for _ in range(q)]

    # Initialize arrays to count "AC" fragments and store cumulative sums
    frag = [0] * (n + 1)
    rui = [0] * (n + 1)

    # Process the string to find "AC" fragments
    for i in range(2, n + 1):
        if c[i - 2:i] == 'AC':
            # Increment the count of "AC" fragments at position i
            frag[i] += 1
        # Update the cumulative sum array
        rui[i] = rui[i - 1] + frag[i]

    # Process the queries
    for i in range(q):
        left, right = range[i]
        # Calculate the number of "AC" fragments in the given range
        print(rui[right] - rui[left])

if __name__ == "__main__":
    main()

