def wpbu(arr):
    if arr is None or len(arr) == 0:
        raise ValueError("Input array cannot be None or empty.")

    n = len(arr)

    if n == 1:
        return arr[0] * (n + 1)

    strg = [[0] * n for _ in range(n)]

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


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])

    if n <= 0:
        print("Invalid input. Please enter a positive integer.")
        return

    arr = []
    for i in range(1, n + 1):
        arr.append(int(data[i]))

    result = wpbu(arr)
    print("Maximum profit:", result)


if __name__ == "__main__":
    main()
