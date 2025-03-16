import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    
    pre = [0] * (n + 1)
    last = [0] * (n + 1)
    
    sumpre = 0
    for i in range(1, n):
        sumpre += a[i - 1]
        pre[i] = sumpre
    
    sumlast = 0
    for i in range(n, 1, -1):
        sumlast += a[i - 1]
        last[i] = sumlast
    
    d = 1 << 60
    for i in range(1, n):
        d = min(d, abs(pre[i] - last[i + 1]))
    
    print(d)

if __name__ == "__main__":
    main()
