import math

def wpbu(arr):
    if arr is None or len(arr) == 0:
        raise ValueError("Input array cannot be null or empty.")

    n = len(arr)

    if n == 1:
        return arr[0] * (n + 1)

    strg = [[0 for _ in range(n)] for _ in range(n)]

    for slide in range(0, n - 1):
        for si in range(0, n - slide - 1):
            ei = si + slide
            year = n - (ei - si) + 1

            if si == ei:
                strg[si][ei] = arr[si] * year
            else:
                start = strg[si + 1][ei] + arr[si] * year
                end = strg[si][ei - 1] + arr[ei] * year
                strg[si][ei] = max(start, end)

    return strg[0][n - 1]


def main():
    scanner = Scanner(System.in)

    n = scanner.nextInt()

    if n <= 0:
        print("Invalid input. Please enter a positive integer.")
        scanner.close()
        return

    arr = [0 for _ in range(n)]

    for i in range(n):
        arr[i] = scanner.nextInt()

    result = wpbu(arr)

    print("Maximum profit: " + str(result))

    scanner.close()


if __name__ == "__main__":
    main()

