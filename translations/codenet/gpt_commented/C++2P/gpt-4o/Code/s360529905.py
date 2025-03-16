# Import necessary modules
import sys

def main():
    # Read the number of elements
    N = int(sys.stdin.readline().strip())

    # Dynamically allocate memory for two arrays
    a = [0] * N
    b = [0] * N

    # Read elements into array 'a' and copy them to array 'b'
    for i in range(N):
        a[i] = int(sys.stdin.readline().strip())  # Read element into array 'a'
        b[i] = a[i]                               # Copy element from 'a' to 'b'

    # Sort the array 'b' to find the median values
    b.sort()

    # Determine the two middle values (for even-sized arrays)
    frontHalf = b[N // 2 - 1]  # Value just before the median
    backHalf = b[N // 2]       # Median value

    # Output the appropriate value based on the original array 'a'
    for i in range(N):
        # If the current element is less than the backHalf (median), print backHalf
        if a[i] < backHalf:
            print(backHalf)
        # Otherwise, print frontHalf
        else:
            print(frontHalf)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
