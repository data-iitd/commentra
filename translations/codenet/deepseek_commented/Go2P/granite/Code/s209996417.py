

n, k = map(int, input().split())

# Read two integers, n and k, from standard input.
# These represent the number to be converted and the base of the number system, respectively.

x = 0
while True:
    under = k ** x
    upper = k ** (x + 1)

    if under <= n and n < upper:
        print(x + 1)
        break
    x += 1

