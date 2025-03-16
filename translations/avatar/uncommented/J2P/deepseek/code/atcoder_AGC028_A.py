import sys
import math

def main():
    n, m = map(int, input().split())
    s = input()
    t = input()
    
    gcd = math.gcd(n, m)
    
    result = 0
    for k in range(gcd):
        if s[n * k // gcd] != t[m * k // gcd]:
            result = -1
            break
    else:
        result = (n * m) // gcd
    
    print(result)

if __name__ == "__main__":
    main()
