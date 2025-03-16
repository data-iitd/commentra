
import sys

def main():
    n = int(input())
    s = input()
    ns = [0] * n
    for i in range(n):
        if s[i] == 'R':
            ns[i] = 0
        elif s[i] == 'G':
            ns[i] = 1
        else:
            ns[i] = 2
    rgb = [[0] * 3 for _ in range(n + 1)]
    for i in range(n):
        for j in range(3):
            rgb[i + 1][j] = rgb[i][j]
        rgb[i + 1][ns[i]] += 1
    sum = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            if ns[i]!= ns[j]:
                tn = 3 - ns[i] - ns[j]
                sum += rgb[n][tn] - rgb[j + 1][tn]
                k = 2 * j - i
                if k < n and ns[k] == tn:
                    sum -= 1
    print(sum)

if __name__ == "__main__":
    main()

