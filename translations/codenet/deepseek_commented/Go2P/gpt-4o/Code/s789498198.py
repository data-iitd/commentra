import sys

# Main function of the program
def main():
    # Read two integers A and B from standard input
    A, B = map(int, sys.stdin.readline().strip().split())

    # Check if the sum of A and B is even
    if (A + B) % 2 == 0:
        # If even, print the average of A and B
        print((A + B) // 2)
    else:
        # If not even, print "IMPOSSIBLE"
        print("IMPOSSIBLE")

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
