import math

def main():
    n, m = map(int, input().split())
    gcd = math.gcd(n, m)
    s = input()
    t = input()
    
    for k in range(gcd):
        if s[k * n // gcd] != t[k * m // gcd]:
            print(-1)
            return
            
    result = (n * m) // gcd
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
