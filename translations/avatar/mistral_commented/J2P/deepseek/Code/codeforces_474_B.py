import sys

def main():
    # Reading the number of elements in the array from the input
    n = int(input().strip())
    arr = [0] * n
    arr[0] = int(input().strip())

    # Reading and storing the remaining elements of the array
    for i in range(1, n):
        x = int(input().strip())
        arr[i] = x + arr[i - 1]

    # Reading the number of queries from the input
    m = int(input().strip())
    q = [0] * m

    # Reading and storing the queries in the array q
    for i in range(m):
        q[i] = int(input().strip())

    # Processing each query and printing the result
    for k in range(m):
        print(fun(arr, q[k], n, m) + 1)

def fun(arr, q, n, m):
    res = 0
    i, j = 0, n

    # Performing a binary search on the array
    while i <= j:
        md = i + (j - i) // 2
        if arr[md] == q:
            return md
        elif arr[md] > q:
            res = md
            j = md - 1
        else:
            i = md + 1

    return res

if __name__ == "__main__":
    main()
