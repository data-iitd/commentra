def main():
    n = int(input())
    s = input().encode()  # Read the input string and encode it to bytes
    ns = [0] * n
    for i in range(n):
        if s[i] == b'R'[0]:
            ns[i] = 0
        elif s[i] == b'G'[0]:
            ns[i] = 1
        elif s[i] == b'B'[0]:
            ns[i] = 2

    rgb = [[0] * 3 for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(3):
            rgb[i][j] = rgb[i - 1][j]
        rgb[i][ns[i - 1]] += 1

    total_sum = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            if ns[i] != ns[j]:
                tn = 3 - ns[i] - ns[j]
                total_sum += rgb[n][tn] - rgb[j + 1][tn]
                k = 2 * j - i
                if k < n and ns[k] == tn:
                    total_sum -= 1

    print(total_sum)

if __name__ == "__main__":
    main()
# <END-OF-CODE>
