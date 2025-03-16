LEN = 300
TRUE = 1
FALSE = -1

def solve(i, m, A, n, flag):
    if i >= n:
        return FALSE
    elif m < 0:
        return FALSE
    elif m == 0:
        flag[0] = TRUE
        return TRUE
    else:
        # not use A[i]
        solve(i + 1, m, A, n, flag)
        # use A[i]
        solve(i + 1, m - A[i], A, n, flag)

def main():
    n = int(input())
    A = list(map(int, input().split()))
    q = int(input())

    for _ in range(q):
        M = int(input())
        flag = [FALSE]
        solve(-1, M, A, n, flag)
        if flag[0] == TRUE:
            print("yes")
        else:
            print("no")

if __name__ == "__main__":
    main()
