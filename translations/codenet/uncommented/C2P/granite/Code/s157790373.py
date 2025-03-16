
# -*- coding: utf-8 -*-

def solve(i, m):
    if i > n:
        return False
    elif m < 0:
        return False
    elif m == 0 or m - A[i + 1] == 0:
        global flag
        flag = True
        return True
    else:
        # not use A[i]
        solve(i + 1, m)
        # use A[i]
        solve(i + 1, m - A[i])

n = int(input())
A = list(map(int, input().split()))

q = int(input())
for i in range(q):
    m = int(input())
    flag = False

    solve(-1, m)
    if flag == True:
        print("yes")
    else:
        print("no")

# 