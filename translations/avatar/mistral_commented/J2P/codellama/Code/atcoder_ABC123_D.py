
import math
import sys

def main():
    # Reading the size of the array x from the standard input stream
    x = [int(i) for i in sys.stdin.readline().split()]
    max = 0

    # Finding the maximum element of the array x
    for i in range(len(x)):
        max = max if max > x[i] else x[i]

    # Reading the integer k from the standard input stream
    k = int(sys.stdin.readline())

    # Declaring and initializing an array a of size 3, where each element is a list of Longs
    a = [[], [], []]

    # Reading the elements of each sub-list a[i] of size x[i] from the standard input stream and sorting it in ascending order
    for i in range(len(x)):
        for j in range(x[i]):
            a[i].append(int(sys.stdin.readline()))
        a[i].sort()

    # Finding all such sums and adding them to the list ans
    ans = []
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if (i + 1) * (j + 1) * (m + 1) <= k:
                    tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1]
                    ans.append(tmp)

    # Sorting the list ans in ascending order
    ans.sort()

    # Printing the i-th element of the list ans, where i is the index of the element to be printed, starting from the last one
    for i in range(k):
        print(ans[len(ans) - i - 1])

if __name__ == "__main__":
    main()

