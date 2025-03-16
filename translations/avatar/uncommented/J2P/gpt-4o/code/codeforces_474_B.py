import sys

def main():
    n = int(sys.stdin.readline().strip())
    arr = [0] * n
    arr[0] = int(sys.stdin.readline().strip())
    
    for i in range(1, n):
        x = int(sys.stdin.readline().strip())
        arr[i] = x + arr[i - 1]
    
    m = int(sys.stdin.readline().strip())
    q = [int(sys.stdin.readline().strip()) for _ in range(m)]
    
    for k in range(m):
        print(fun(arr, q[k], n, m) + 1)

def fun(arr, q, n, m):
    res = 0
    i, j = 0, n - 1
    while i <= j:
        md = i + (j - i) // 2
        if arr[md] == q:
            return md
        elif arr[md] > q:
            res = md
            j = md - 1
        else:
            i = md + 1
    return res

if __name__ == "__main__":
    main()

# <END-OF-CODE>
