

import sys

def reverse(n):
    if n < 10:
        return n * 10
    r = 0
    while n > 0:
        r = (r * 10) + (n % 10)
        n = n // 10
    return r

def main():
    n = int(input())
    m = int(input())
    t = reverse(m)
    print(t + n)

if __name__ == "__main__":
    main()

