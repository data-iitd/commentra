
import sys

def wpbu(arr):
    if arr is None or len(arr) == 0:
        raise ValueError("Input array cannot be null or empty.")
    n = len(arr)
    strg = [[0 for _ in range(n)] for _ in range(n)]
    for slide in range(n):
        for si in range(n - slide):
            ei = si + slide
            year = (n - (ei - si + 1)) + 1
            if si == ei:
                strg[si][ei] = arr[si] * year
            else:
                start = strg[si + 1][ei] + arr[si] * year
                end = strg[si][ei - 1] + arr[ei] * year
                strg[si][ei] = max(start, end)
    return strg[0][n - 1]

if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    arr = [int(x) for x in input("Enter the elements of the array: ").split()]
    result = wpbu(arr)
    print("Maximum profit:", result)

