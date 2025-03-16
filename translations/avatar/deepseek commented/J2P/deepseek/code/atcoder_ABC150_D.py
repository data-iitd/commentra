import sys

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def main():
    n = int(input().split()[0])
    m = int(input().split()[1])
    a = [int(x) // 2 for x in input().split()]
    
    lcd = 1
    
    for i in range(n):
        g = gcd(lcd, a[i])
        lcd = lcd * a[i] // g
        if lcd > m:
            print(0)
            return
    
    for i in range(n):
        if (lcd // a[i]) % 2 == 0:
            print(0)
            return
    
    print((m // lcd + 1) // 2)

if __name__ == "__main__":
    main()

