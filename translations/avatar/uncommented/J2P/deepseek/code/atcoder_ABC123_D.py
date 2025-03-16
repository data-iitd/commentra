import sys

def main():
    x = [0] * 3
    max_val = 0
    n = 3
    x = list(map(int, sys.stdin.readline().split()))
    max_val = max(x)
    k = int(sys.stdin.readline())
    
    a = [[] for _ in range(3)]
    for i in range(3):
        a[i] = list(map(int, sys.stdin.readline().split()))
        a[i].sort(reverse=True)
    
    ans = []
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if (i + 1) * (j + 1) * (m + 1) <= k:
                    tmp = a[0][i] + a[1][j] + a[2][m]
                    ans.append(tmp)
    
    ans.sort(reverse=True)
    for i in range(k):
        print(ans[i])

if __name__ == "__main__":
    main()
