import sys
import math

def main():
    # Initialize minimum value of array A to a large number
    minA = math.pow(10, 9) + 1
    num = 0
    f = -1  # Initialize f to an invalid value

    # Read number of elements and time t from the standard input
    n, t = map(int, sys.stdin.readline().split())

    # Create a list A to store the input elements
    A = list(map(int, sys.stdin.readline().split()))

    # Read each element of list A
    for i in range(n):
        # Check if the current element is smaller than the minimum value
        if minA > A[i]:
            # Update the minimum value of array A
            minA = A[i]
        else:
            # Calculate the difference between the current element and the minimum value
            diff = A[i] - minA

            # If the difference is equal to the previous difference, increment the count of similar differences
            if f == diff:
                num += 1
            # If the difference is greater than the previous difference, reset the count to 1 and update the previous difference
            elif f < diff:
                num = 1
                f = diff

    # Print the count of similar differences on the standard output
    print(num)

if __name__ == "__main__":
    main()
# <END-OF-CODE>
