def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    m = int(data[1])

    ans = []

    for i in range(n):
        row = input().strip()
        temp = ""
        for j in range(m):
            if row[j] == '-':
                temp += "-"
            else:
                if (i + j) % 2 == 1:
                    temp += "W"
                else:
                    temp += "B"
        ans.append(temp)

    for row in ans:
        print(row)


if __name__ == "__main__":
    main()
