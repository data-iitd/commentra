def print_magic_square(n):
    if n == 0:
        return

    # Initialize a nxn array to store the magic square, filled with zeros
    arr = [[0] * n for _ in range(n)]

    # Initialize flag and starting position for the first number
    flag = 1
    r = (n + 1) // 2
    c = (n - 1) // 2
    arr[r][c] = 1
    cnt = 2

    # Loop to fill the magic square until all numbers are placed
    while cnt <= n * n:
        if flag:
            r = (r - 1) % n
            c = (c + 1) % n
            if arr[r][c]:
                flag = 0
                cnt -= 1
            else:
                arr[r][c] = cnt
                flag = 1
        else:
            r = (r + 1) % n
            c = (c - 1) % n
            if arr[r][c]:
                flag = 1
            else:
                arr[r][c] = cnt
                flag = 1
        cnt += 1

    # Print the completed magic square
    for r in range(n):
        for c in range(n):
            print(f"{arr[r][c]:4}", end="")
        print()

# Infinite loop to continuously accept input until a zero is entered
while True:
    n = int(input())
    if n == 0:
        break
    print_magic_square(n)
