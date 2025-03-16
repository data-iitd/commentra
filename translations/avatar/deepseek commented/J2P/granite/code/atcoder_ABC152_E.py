

import math
import sys

def main():
    N = int(input())
    A = list(map(int, input().split()))

    lcm = 1
    for a in A:
        lcm = lcm * a // math.gcd(lcm, a)

    mod = 1000000007
    modLcm = lcm % mod
    ans = 0
    for a in A:
        ans = (ans + modLcm * pow(a, mod - 2, mod)) % mod

    print(ans)

if __name__ == "__main__":
    main()

