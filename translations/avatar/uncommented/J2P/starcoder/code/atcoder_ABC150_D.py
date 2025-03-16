
import sys

def getGCD(a, b):
    if b == 0:
        return a
    else:
        return getGCD(b, a % b)

def main():
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    a = [0] * n
    for i in range(n):
        a[i] = int(sys.stdin.readline()) / 2
    lcd = 1
    for i in range(n):
        gcd = getGCD(lcd, a[i])
        lcd = lcd * a[i] / gcd
        if lcd > m:
            print(0)
            return
    for i in range(n):
        if (lcd / a[i]) % 2 == 0:
            print(0)
            return
    print((m / lcd + 1) / 2)

if __name__ == "__main__":
    main()

# 