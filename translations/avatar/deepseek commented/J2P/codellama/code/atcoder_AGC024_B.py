import sys

def main():
    N = int(sys.stdin.readline().strip())
    P = [int(x) - 1 for x in sys.stdin.readline().strip().split()]

    # Create a dictionary to map each value in P to its index
    map = {}
    for i in range(N):
        map[P[i]] = i

    # Create a list to store indices of elements that are out of order
    nglist = []
    for i in range(N - 1):
        if map[i] > map[i + 1]:
            nglist.append(i)

    # If nglist is empty, the array P is already sorted
    if not nglist:
        print(0)
        return

    # Calculate the minimum number of swaps required to sort the array P
    ans = min(N - nglist[0] - 1, nglist[-1] + 1)
    for i in range(len(nglist) - 1):
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)

    # Print the minimum number of swaps required
    print(ans)


if __name__ == "__main__":
    main()
