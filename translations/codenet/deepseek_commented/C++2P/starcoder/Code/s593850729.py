# Include necessary headers for input and output operations
import sys

# The main function is the entry point of the program
def main():
    # Read the values of A, B, C, and X from the standard input
    A, B, C, X = map(int, sys.stdin.readline().split())

    # Initialize a counter to count the number of combinations
    cnt = 0

    # Iterate over the possible values of a (0 to A)
    for a in range(A+1):
        # Iterate over the possible values of b (0 to B)
        for b in range(B+1):
            # Iterate over the possible values of c (0 to C)
            for c in range(C+1):
                # Calculate the total value of the coins
                total = 500*a + 100*b + 50*c
                # If the total equals X, increment the counter
                if total == X:
                    cnt += 1

    # Output the number of combinations that sum up to X
    print(cnt)

# The entry point of the program
if __name__ == "__main__":
    main()

