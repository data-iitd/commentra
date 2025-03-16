
n = int(input())  # Take an integer input from the user and store it in the variable `n`.
for i in range(n, 0, -1):  # Iterate from `n` down to 1, decrementing by 1 in each iteration.
    if n % i == 0:  # Check if `n` is divisible by `i`.
        n = i  # Update `n` to `i` if `n` is divisible by `i`.
        print(i, end=' ')  # Print the value of `i` followed by a space.

