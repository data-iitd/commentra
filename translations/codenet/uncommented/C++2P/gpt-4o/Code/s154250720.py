import sys

maxn = 200000 + 10
INF = int(1e8)

def main():
    n = int(sys.stdin.readline().strip())
    maps = [0] * maxn
    num = [0] * maxn
    
    for i in range(1, n + 1):
        maps[i] = int(sys.stdin.readline().strip())
        num[i] = maps[i]
    
    maps[1:n + 1] = sorted(maps[1:n + 1])
    m = n // 2
    
    for i in range(1, n + 1):
        if num[i] <= maps[m]:
            print(maps[m + 1])
        else:
            print(maps[m])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
