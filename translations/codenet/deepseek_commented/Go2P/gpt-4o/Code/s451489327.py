def main():
    n = int(input())  # 1. Read an integer `n` from the standard input

    as_ = [0] * (n + 1)  # 2. Initialize list `as_` with length `n+1`
    bs = [0] * n        # 3. Initialize list `bs` with length `n`

    for i in range(n + 1):  # 4. Read values into `as_` from the standard input
        as_[i] = int(input())

    for i in range(n):  # 5. Read values into `bs` from the standard input
        bs[i] = int(input())

    sum_ = 0  # 6. Initialize a variable `sum_` to store the result
    for i in range(n):  # 7. Iterate through the elements of `as_` and `bs`
        a = as_[i]
        b = bs[i]
        if a <= b:  # 8. Check if `a` is less than or equal to `b`
            sum_ += a  # 9. Add `a` to `sum_`
            b -= a  # 10. Subtract `a` from `b`
            if i + 1 < n:  # 11. Check if the next index is within bounds
                an = as_[i + 1]
                if an <= b:  # 12. Check if the next element in `as_` is less than or equal to the remaining `b`
                    sum_ += an  # 13. Add the next element in `as_` to `sum_`
                    as_[i + 1] = 0  # 14. Set the next element in `as_` to 0
                else:
                    sum_ += b  # 15. Add the remaining `b` to `sum_`
                    as_[i + 1] -= b  # 16. Subtract the remaining `b` from the next element in `as_`
        else:  # 17. If `a` is greater than `b`
            sum_ += b  # 18. Add `b` to `sum_`
    
    print(sum_)  # 19. Print the value of `sum_`

if __name__ == "__main__":
    main()

# <END-OF-CODE>
