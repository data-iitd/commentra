
import sys

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def main():
    n = int(input())

    if n == 0:
        print('0')
        sys.exit(0)

    s = ''
    while n!= 0:
        if n % 2 == 0:
            s += '0'
        else:
            s += '1'

        n -= abs(n % 2)
        n //= -2

    s = s[::-1]
    print(s)

if __name__ == '__main__':
    main()

