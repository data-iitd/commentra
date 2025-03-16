import sys
import bisect

def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())  # Reading two integers, N and M.

    L = [0] * 100000  # Initializing a list L with a size of 100,000.
    for i in range(N):
        L[i] = int(input())  # Reading N integers and populating the list L.

    L.sort()  # Sorting the list L in ascending order.

    for _ in range(M):  # Performing M operations.
        max_L = L[-1]  # Finding the largest element in the list.
        if max_L == 0:
            break  # If the largest element is 0, break the loop.

        max_L //= 2  # Halving the largest element.
        bisect.insort(L, max_L)  # Inserting the halved value back into the list.
        L.pop()  # Removing the largest element from the list.

    ans = sum(L)  # Calculating the sum of all elements in the list L.

    print(ans)  # Printing the result.

if __name__ == "__main__":
    main()
