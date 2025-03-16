
# 1. Read an integer `n` from the standard input
n = int(input())

# 2. Initialize a list `as` with length `n+1`
as = [0] * (n+1)

# 3. Initialize a list `bs` with length `n`
bs = [0] * n

# 4. Read values into `as` from the standard input
for i in range(n+1):
    as[i] = int(input())

# 5. Read values into `bs` from the standard input
for i in range(n):
    bs[i] = int(input())

# 6. Initialize a variable `sum` to store the result
sum = 0

# 7. Iterate through the elements of `as` and `bs`
for i in range(n):
    a = as[i]
    b = bs[i]

    # 8. Check if `a` is less than or equal to `b`
    if a <= b:
        sum += a # 9. Add `a` to `sum`
        b -= a   # 10. Subtract `a` from `b`

        # 11. Check if the next index is within bounds
        if i+1 <= n:
            an = as[i+1]

            # 12. Check if the next element in `as` is less than or equal to the remaining `b`
            if an <= b:
                sum += an # 13. Add the next element in `as` to `sum`
                as[i+1] = 0 # 14. Set the next element in `as` to 0
            else:
                sum += b # 15. Add the remaining `b` to `sum`
                as[i+1] -= b # 16. Subtract the remaining `b` from the next element in `as`

    # 17. If `a` is greater than `b`
    else:
        sum += b # 18. Add `b` to `sum`

# 19. Print the value of `sum`
print(sum)

