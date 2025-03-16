import sys

inf = 10**14

def min(*args):
    return min(args)

def main():
    n = int(sys.stdin.readline().strip())
    x = int(sys.stdin.readline().strip())
    a = list(map(int, sys.stdin.readline().strip().split()))
    v = a[:]
    ans = inf
    
    for k in range(n):
        kans = 0
        for i in range(n):
            if i - k < 0:
                v[i] = min(v[i], a[n + i - k])
            else:
                v[i] = min(v[i], a[i - k])
            kans += v[i]
        ans = min(ans, kans + k * x)

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
