

n = int(input())
arr = [int(x) for x in input().split()]
m = int(input())
q = [int(x) for x in input().split()]

def fun(arr, q, n, m):
    res = 0
    i = 0
    j = n
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

for k in range(m):
    print(fun(arr, q[k], n, m) + 1)

