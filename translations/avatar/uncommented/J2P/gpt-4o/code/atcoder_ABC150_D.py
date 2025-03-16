import sys
from math import gcd
from functools import reduce

def main():
    n = int(input())
    m = int(input())
    a = [int(input()) // 2 for _ in range(n)]
    
    lcd = 1
    for i in range(n):
        current_gcd = gcd(lcd, a[i])
        lcd = lcd * a[i] // current_gcd
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

# <END-OF-CODE>
