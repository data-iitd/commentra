
n = int(input())  # Taking an integer input `n` which represents the number of iterations.
for i in range(n):  # Looping `n` times.
    a = int(input())  # Taking an integer input `a` for each iteration.
    if a < 2:  # Checking if `a` is less than 2.
        print(0)  # Printing 0 if `a` is less than 2.
    else:  # If `a` is not less than 2.
        print(a - 2)  # Printing the result of `a - 2`.

