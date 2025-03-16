def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read the number of elements in the array P
    P = [int(data[i]) - 1 for i in range(1, N + 1)]  # Read each element and adjust to 0-based index

    # Create a dictionary to map each value in P to its index
    index_map = {P[i]: i for i in range(N)}

    # Create a list to store indices of elements that are out of order
    nglist = []
    for i in range(N - 1):
        if index_map[i] > index_map[i + 1]:
            nglist.append(i)  # Add the index to nglist if the current element is greater than the next element

    # If nglist is empty, the array P is already sorted
    if not nglist:
        print(0)  # Print 0 and return as the array is sorted
        return

    # Calculate the minimum number of swaps required to sort the array P
    ans = min(N - nglist[0] - 1, nglist[-1] + 1)
    for i in range(len(nglist) - 1):
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)

    # Print the minimum number of swaps required
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
