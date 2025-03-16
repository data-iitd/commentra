import sys
from collections import defaultdict

def main():
    # Reading the size of the array x
    x = [int(sys.stdin.readline().strip()) for _ in range(3)]
    max_value = 0  # Initializing max to 0

    # Finding the maximum element of the array x
    for value in x:
        max_value = max(max_value, value)

    k = int(sys.stdin.readline().strip())  # Reading the integer k

    a = [list() for _ in range(3)]  # Declaring an array a of size 3

    # Reading the elements of each sub-list a[i] and sorting it in ascending order
    for i in range(3):
        a[i] = [int(sys.stdin.readline().strip()) for _ in range(x[i])]
        a[i].sort()

    ans = []  # Declaring an empty list ans to store the sums

    # Finding all such sums and adding them to the list ans
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if (i + 1) * (j + 1) * (m + 1) <= k:  # Checking the product condition
                    tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1]  # Calculating the sum
                    ans.append(tmp)  # Adding the sum to the list ans

    ans.sort()  # Sorting the list ans in ascending order

    n = len(ans)  # Getting the size of the list ans

    # Printing the i-th element of the list ans, starting from the last one
    for i in range(min(k, n)):
        print(ans[n - i - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
