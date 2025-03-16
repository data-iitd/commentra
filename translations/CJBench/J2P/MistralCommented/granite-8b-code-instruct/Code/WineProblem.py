
import sys

def main():
    n = int(input("Enter the number of elements in the array: "))

    if n <= 0:
        print("Invalid input. Please enter a positive integer.")
        sys.exit(1)

    arr = [int(input(f"Enter element {i+1}: ")) for i in range(n)]

    result = wpbu(arr)
    print(f"Maximum profit: {result}")

def wpbu(arr):
    if arr is None or len(arr) == 0:
        raise ValueError("Input array cannot be null or empty.")

    n = len(arr)

    if n == 1:
        return arr[0] * (n + 1)

    strg = [[0 for _ in range(n)] for _ in range(n)]

    for slide in range(n):
        for si in range(n - slide):
            ei = si + slide
            year = n - (ei - si) + 1

            if si == ei:
                strg[si][ei] = arr[si] * year
            else:
                start = strg[si + 1][ei] + arr[si] * year
                end = strg[si][ei - 1] + arr[ei] * year
                strg[si][ei] = max(start, end)

    return strg[0][n - 1]

if __name__ == "__main__":
    main()

