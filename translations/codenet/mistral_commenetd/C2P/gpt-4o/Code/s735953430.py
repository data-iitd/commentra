# Import necessary modules
import sys

# The main function is the entry point of the program
def main():
    # Read input values X and N from the user
    X, N = map(int, input().split())

    # Check if N is zero, if yes, print X and exit the program
    if N == 0:
        print(X)
        sys.exit(0)

    # Initialize two lists plus and minus of size 256
    plus = list(range(256))
    minus = [-i for i in range(256)]

    # Subtract the given numbers from the plus list
    for _ in range(N):
        j = int(input())
        # Set the corresponding index in the plus list to zero
        plus[j] = 0

    # Initialize variables i_min and min with initial values
    i_min = 0
    min_diff = 1000

    # Find the minimum number in the plus list that is not zero and can form the difference X
    for i in range(255, -1, -1):
        # Skip the iteration if the current number in the plus list is zero and it is not the first element
        if plus[i] == 0 and i > 0:
            continue
        # Calculate the difference between X and the current number in the plus list
        k = X - plus[i]
        # If the difference is negative, make it positive
        if k < 0:
            k *= -1
        # Update min_diff and i_min if the current difference is smaller than the previous minimum
        if k <= min_diff:
            min_diff = k
            i_min = i

    # Print the index of the minimum number
    print(i_min)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
