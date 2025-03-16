def main():
    import sys
    from collections import defaultdict

    # Read the number of elements
    N = int(sys.stdin.readline().strip())

    # Initialize a list to store the elements, adjusting for zero-based indexing
    P = [int(x) - 1 for x in sys.stdin.readline().strip().split()]

    # Create a map to store the index of each element for quick lookup
    map_indices = {P[i]: i for i in range(N)}

    # List to store indices where the order is not increasing
    nglist = []
    for i in range(N - 1):
        # Check if the current index is greater than the next index in the map
        if map_indices[i] > map_indices[i + 1]:
            nglist.append(i)  # Add the index to the nglist if the order is violated

    # If there are no indices in nglist, print 0 and exit
    if not nglist:
        print(0)
        return

    # Calculate the minimum number of moves required to fix the order
    ans = min(N - nglist[0] - 1, nglist[-1] + 1)
    for i in range(len(nglist) - 1):
        # Update ans with the minimum moves needed between consecutive indices in nglist
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)

    # Print the result which is the minimum number of moves
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
