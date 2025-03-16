def print_island(n, count):
    a = (n + 1) // 2
    b = n // 2
    max_islands = a * a + b * b

    if count > max_islands:
        print("NO")
        return

    print("YES")

    for i in range(n):
        row = ""
        for j in range(n):
            if (i + j) % 2 == 0 and count > 0:
                row += 'L'
                count -= 1
            else:
                row += 'S'
        print(row)


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    count = int(data[1])
    print_island(n, count)


main()
