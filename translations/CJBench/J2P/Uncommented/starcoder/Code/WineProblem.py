
import sys

def wpbu(arr):
    if arr == None or len(arr) == 0:
        raise Exception("Input array cannot be null or empty.")
    n = len(arr)
    strg = [[0 for x in range(n)] for x in range(n)]
    for slide in range(0, n):
        for si in range(0, n - slide):
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
    n = int(sys.stdin.readline().strip())
    arr = [int(sys.stdin.readline().strip()) for x in range(n)]
    result = wpbu(arr)
    print("Maximum profit: " + str(result))

