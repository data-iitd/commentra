# Import necessary libraries
import sys
from bisect import bisect_left

# Main function starts here
def main():
    # Read input from user
    N, M = map(int, input().split())

    # Initialize a list of integers with size N
    L = list(map(int, input().split()))

    # Sort the list in ascending order
    L.sort()

    # Perform the required operations for M times
    for _ in range(M):
        max_L = L[-1]  # Get the last element of the list

        # If the last element is 0, break the loop
        if max_L == 0:
            break

        # Divide the last element by 2
        max_L //= 2

        # Find the position of the element greater than or equal to max_L using bisect
        pos = bisect_left(L, max_L)

        # Insert max_L before the found position and remove the last element
        L.insert(pos, max_L)
        L.pop()  # Remove the last element

    # Calculate the answer and print it
    ans = sum(L)
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
