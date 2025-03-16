LEN = 300
TRUE = 1
FALSE = -1

def solve(i, m):
    global flag
    if i >= n:
        return FALSE
    elif m < 0:
        return FALSE
    elif m == 0 or m - A[i + 1] == 0:
        flag = TRUE
        return TRUE
    else:
        # not use A[i]
        solve(i + 1, m)
        # use A[i]
        solve(i + 1, m - A[i])

n = int(input())
A = list(map(int, input().split()))

q = int(input())
for _ in range(q):
    M = int(input())
    flag = FALSE

    solve(-1, M)
    if flag == TRUE:
        print("yes")
    else:
        print("no")

# <END-OF-CODE>
