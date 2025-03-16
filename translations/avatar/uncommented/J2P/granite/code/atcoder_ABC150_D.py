
import sys

def gcd(a, b):
    while b!= 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(n):
        a[i] //= 2
    l = 1
    for i in range(n):
        l = lcm(l, a[i])
        if l > m:
            print(0)
            sys.exit()
    for i in range(n):
        if (l // a[i]) % 2 == 0:
            print(0)
            sys.exit()
    print((m // l + 1) // 2)

if __name__ == '__main__':
    main()

