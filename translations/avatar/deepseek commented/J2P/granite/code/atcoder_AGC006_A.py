

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
    cnt = 0
    b = []
    for i in range(n):
        b.append(str[i])
    for i in range(n):
        b.append(s1[i])
    f = getFail(b, 2 * n)
    len = min(f[2 * n], n)
    print(2 * n - len)

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "