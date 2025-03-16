

import math

def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    gcd = 1
    lcm = 1
    for i in range(n):
        gcd = math.gcd(gcd, a[i] // 2)
        lcm = (lcm * a[i]) // gcd
        if lcm > m:
            print(0)
            return
        if (lcm // a[i]) % 2 == 0:
            print(0)
            return
    print((m // lcm + 1) // 2)

if __name__ == "__main__":
    main()

