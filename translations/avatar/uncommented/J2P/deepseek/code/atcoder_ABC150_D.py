import sys

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def main():
    input_line = sys.stdin.readline().strip()
    n, m = map(int, input_line.split())
    a = list(map(int, sys.stdin.readline().strip().split()))
    
    for i in range(n):
        a[i] //= 2
    
    lcd = 1
    for i in range(n):
        gcd_val = gcd(lcd, a[i])
        lcd = lcd * a[i] // gcd_val
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
