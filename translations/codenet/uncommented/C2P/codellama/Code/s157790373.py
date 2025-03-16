#include<stdio.h>
#define LEN 300
#define TRUE 1
#define FALSE -1

def solve(i, m):
    if i > n:
        return FALSE
    elif m < 0:
        return FALSE
    elif m == 0 or m - A[i+1] == 0:
        flag = TRUE
        return TRUE
    else:
        #not use A[i]
        solve(i+1, m)
        #use A[i]
        solve(i+1, m-A[i])

n = 0
A = []
flag = FALSE

def main():
    global n, A, flag
    q = 0
    M = 0
    i = 0
    j = 0
    k = 0

    scanf("%d", &n)
    for i in range(0, n):
        scanf("%d", &A[i])

    scanf("%d", &q)
    for i in range(0, q):
        scanf("%d", &M)
        flag = FALSE

        solve(-1, M)
        if flag == TRUE:
            printf("yes\n")
        else:
            printf("no\n")


if __name__ == "__main__":
    main()

