def rotate(matrix, r):
    left = 0
    up = 0
    m = len(matrix)
    n = len(matrix[0])
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
        for i in range(m - 2, 0, -1):
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
        for i in range(m - 2, 0, -1):
            matrix[up + i][left] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        m -= 2
        n -= 2
        left += 1
        up += 1


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    rows = int(data[0])
    cols = int(data[1])
    matrix = []
    index = 2
    for i in range(rows):
        matrix.append([])
        for j in range(cols):
            matrix[i].append(int(data[index]))
            index += 1
    rotations = int(data[index])
    rotate(matrix, rotations)
    for i in range(rows):
        for j in range(cols):
            print(matrix[i][j], end=' ')
        print()


main()
