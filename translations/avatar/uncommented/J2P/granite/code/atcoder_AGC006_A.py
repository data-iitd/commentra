
import sys
def getFail(b, m):
    j = 0
    f = [0] * (m + 1)
    for i in range(2, m + 1):
        while j > 0 and b[j + 1]!= b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j
    return f

def main():
    n = int(input())
    s1 = input()
    str = input()
    b = []
    cnt = 0
    for i in range(n):
        b.append(str[i])
    for i in range(n):
        b.append(s1[i])
    cnt = 2 * n
    f = getFail(b, cnt)
    len = min(f[cnt], min(n, n))
    print(2 * n - len)

if __name__ == "__main__":
    main()

