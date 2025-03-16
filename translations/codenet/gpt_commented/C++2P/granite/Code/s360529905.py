
import sys
from typing import List

def main():
    # Read the number of elements
    N = int(input())

    # Read elements into list 'a' and copy them to list 'b'
    a = [int(x) for x in sys.stdin.read().split()]
    b = a[:]

    # Sort the list 'b' to find the median values
    b.sort()

    # Determine the two middle values (for even-sized arrays)
    frontHalf = b[N // 2 - 1]  # Value just before the median
    backHalf = b[N // 2]       # Median value

    # Output the appropriate value based on the original list 'a'
    for i in range(N):
        # If the current element is less than the backHalf (median), print backHalf
        if a[i] < backHalf:
            print(backHalf)
        # Otherwise, print frontHalf
        else:
            print(frontHalf)

if __name__ == "__main__":
    main()

