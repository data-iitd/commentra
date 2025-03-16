import sys
from bisect import insort, bisect_left

def main():
    N, M = map(int, sys.stdin.readline().split())  # Reading two integers, N and M.

    L = []  # Initializing a list L.
    for _ in range(N):
        l = int(sys.stdin.readline().strip())  # Reading N integers and populating the list L.
        L.append(l)

    L.sort()  # Sorting the list L in ascending order.

    for _ in range(M):  # Performing M operations.
        max_L = L[-1]  # Finding the largest element in the list.
        if max_L == 0:
            break  # If the largest element is 0, break the loop.

        max_L //= 2  # Halving the largest element.
        itr = bisect_left(L, max_L)  # Finding the position to insert the halved value.
        insort(L, max_L)  # Inserting the halved value back into the list.
        L.pop()  # Removing the largest element from the list.

    ans = sum(L)  # Calculating the sum of all elements in the list L.

    print(ans)  # Printing the result.

if __name__ == "__main__":
    main()

# <END-OF-CODE>
