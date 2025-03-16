n = int(input())  # 1. Read an integer `n` from the standard input

as_ = list(map(int, input().split()))  # 2. Initialize list `as_` with values from the standard input
bs = list(map(int, input().split()))  # 3. Initialize list `bs` with values from the standard input

sum_ = 0  # 4. Initialize a variable `sum_` to store the result

for i in range(n):  # 5. Iterate through the elements of `as_` and `bs`
    a = as_[i]
    b = bs[i]
    if a <= b:  # 6. Check if `a` is less than or equal to `b`
        sum_ += a  # 7. Add `a` to `sum_`
        b -= a  # 8. Subtract `a` from `b`
        if i+1 < n:  # 9. Check if the next index is within bounds
            an = as_[i+1]
            if an <= b:  # 10. Check if the next element in `as_` is less than or equal to the remaining `b`
                sum_ += an  # 11. Add the next element in `as_` to `sum_`
                as_[i+1] = 0  # 12. Set the next element in `as_` to 0
            else:
                sum_ += b  # 13. Add the remaining `b` to `sum_`
                as_[i+1] -= b  # 14. Subtract the remaining `b` from the next element in `as_`
    else:  # 15. If `a` is greater than `b`
        sum_ += b  # 16. Add `b` to `sum_`

print(sum_)  # 17. Print the value of `sum_`
