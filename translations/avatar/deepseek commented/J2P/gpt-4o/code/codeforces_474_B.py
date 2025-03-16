import sys

def main():
    n = int(input())  # Read the size of the array
    arr = [0] * n
    arr[0] = int(input())  # Initialize the first element of the array

    # Read the rest of the elements and calculate the prefix sum
    for i in range(1, n):
        x = int(input())
        arr[i] = x + arr[i - 1]

    m = int(input())  # Read the number of queries
    q = [0] * m

    # Read the queries
    for i in range(m):
        q[i] = int(input())

    # Perform binary search for each query and print the result adjusted by +1
    for k in range(m):
        print(fun(arr, q[k], n) + 1)

# Binary search function to find the position of q in arr
def fun(arr, q, n):
    res = 0
    i, j = 0, n - 1
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

# <END-OF-CODE>
