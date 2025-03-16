
import sys

def rotate(matrix, r):
    m = len(matrix)
    n = len(matrix[0])
    left = 0
    up = 0
    while m >= 1 and n >= 1:
        count = 2 * (m + n) - 4
        tmp = [0] * count
        curr = 0
        for i in range(n):
            tmp[curr] = matrix[up][left + i]
            curr += 1
        for i in range(1, m - 1):
            tmp[curr] = matrix[up + i][left + n - 1]
            curr += 1
        for i in range(n - 1, -1, -1):
            tmp[curr] = matrix[up + m - 1][left + i]
            curr += 1
        for i in range(m - 2, 1, -1):
            tmp[curr] = matrix[up + i][left]
            curr += 1
        curr = r % count
        if curr < 0:
            curr += count
        for i in range(n):
            matrix[up][left + i] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        for i in range(1, m - 1):
            matrix[up + i][left + n - 1] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        for i in range(n - 1, -1, -1):
            matrix[up + m - 1][left + i] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        for i in range(m - 2, 1, -1):
            matrix[up + i][left] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        m -= 2
        n -= 2
        left += 1
        up += 1

if __name__ == "__main__":
    rows, cols = map(int, input().split())
    matrix = []
    for _ in range(rows):
        matrix.append(list(map(int, input().split())))
    r = int(input())
    rotate(matrix, r)
    for row in matrix:
        print(*row)

