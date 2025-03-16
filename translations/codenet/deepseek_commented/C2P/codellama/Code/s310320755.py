#include<stdio.h>

# Infinite loop to keep the program running until n is 0
while True:
    n = int(input("Enter the size of the magic square: "))
    if n == 0:
        break

    # Initialize the starting position and the counter
    flag = 1
    r = (n + 1) // 2 + 1
    c = (n + 1) // 2
    arr = [[0 for i in range(n + 1)] for j in range(n + 1)]
    arr[r][c] = cnt = 1

    # Loop to fill the magic square
    while cnt != n * n + 1:
        cnt += 1
        if flag:
            r += 1
            c += 1
            if c > n:
                c = 1
            if r > n:
                r = 1
            if arr[r][c]:
                flag = 0
                cnt -= 1
            else:
                arr[r][c] = cnt
        else:
            r += 1
            c -= 1
            if c < 1:
                c = n
            if r > n:
                r = 1
            if arr[r][c]:
                flag = 0
            else:
                arr[r][c] = cnt
                flag = 1

    # Print the generated magic square
    for r in range(1, n + 1):
        for c in range(1, n + 1):
            print(arr[r][c], end=" ")
        print()

# 