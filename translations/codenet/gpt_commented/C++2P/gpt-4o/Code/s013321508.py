import sys
import bisect

def main():
    # Read the number of elements (N) and the number of operations (M)
    N, M = map(int, sys.stdin.readline().split())

    # Initialize a list to hold the elements
    L = []

    # Read N integers from input and store them in the list L
    for _ in range(N):
        l = int(sys.stdin.readline().strip())
        L.append(l)

    # Sort the list L in ascending order
    L.sort()

    # Perform M operations to modify the list L
    for _ in range(M):
        # Get the maximum element from the end of the sorted list
        max_L = L[-1]

        # If the maximum element is 0, break the loop as no further operations are needed
        if max_L == 0:
            break

        # Halve the maximum element
        max_L //= 2

        # Find the position to insert the halved value in the sorted list
        bisect.insort(L, max_L)

        # Remove the last element (the original maximum) from the list
        L.pop()

    # Calculate the sum of all elements in the list L
    ans = sum(L)

    # Output the final sum
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
