def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])
    
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a
    
    g = gcd(n, m)
    
    s = data[2]
    t = data[3]
    
    result = 0
    for k in range(g):
        if s[k * n // g] != t[k * m // g]:
            result = -1
            break
    else:
        result = (n * m) // g
    
    print(result)

main()
