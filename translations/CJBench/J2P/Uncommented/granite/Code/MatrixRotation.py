
import sys
def rotate(matrix, r):
    m = len(matrix)
    n = len(matrix[0])
    while m >= 1 and n >= 1:
        count = 2 * (m + n) - 4
        tmp = [0] * count
        curr = 0
        for i in range(n):
            tmp[curr] = matrix[0][i]
            curr += 1
        for i in range(1, m - 1):
            tmp[curr] = matrix[i][n - 1]
            curr += 1
        for i in range(n - 1, -1, -1):
            tmp[curr] = matrix[m - 1][i]
            curr += 1
        for i in range(m - 2, 1, -1):
            tmp[curr] = matrix[i][0]
            curr += 1
        curr = r % count
        if curr < 0:
            curr += count
        for i in range(n):
            matrix[0][i] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        for i in range(1, m - 1):
            matrix[i][n - 1] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        for i in range(n - 1, -1, -1):
            matrix[m - 1][i] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        for i in range(m - 2, 1, -1):
            matrix[i][0] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        m -= 2
        n -= 2
        for i in range(m):
            for j in range(n):
                matrix[i][j] = tmp[curr]
                curr += 1
                if curr >= count:
                    curr -= count
def main():
    rows, cols = map(int, sys.stdin.readline().split())
    matrix = []
    for _ in range(rows):
        matrix.append(list(map(int, sys.stdin.readline().split())))
    rotations = int(sys.stdin.readline())
    rotate(matrix, rotations)
    for row in matrix:
        print(" ".join(map(str, row)))
if __name__ == "__main__":
    main()
