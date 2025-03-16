def power(x, n, mod):
    if n == 0:
        return 1
    val = power(x, n // 2, mod)
    val = (val * val) % mod
    if n % 2 == 1:
        val = (val * x) % mod
    return val

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    c = list(map(int, data[1].split()))
    
    mod = 1000000007
    
    if n == 1:
        print(c[0] * 2 % mod)
        return
    
    c.sort()
    
    b = power(2, n, mod)
    a = power(2, n - 2, mod)
    ans = 0
    
    for i in range(2, n + 2):
        val = (a * i) % mod
        val = (val * c[n + 1 - i]) % mod
        ans = (ans + val) % mod
    
    ans = (ans * b) % mod
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
