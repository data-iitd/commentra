import sys
from collections import defaultdict

# Main function is the entry point of the program
def main():
    # Read the number of elements from the standard input
    N = int(sys.stdin.readline().strip())

    # Initialize a dictionary to store the frequency of each element
    v = [0] * N

    # Iterate through the input elements and update the frequency in the list 'v'
    for _ in range(N - 1):
        # Read the next element from the standard input
        a = int(sys.stdin.readline().strip())
        # Update the frequency of the element 'a-1' in the list 'v'
        v[a - 1] += 1

    # Print each element to the standard output
    for e in v:
        print(e)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
