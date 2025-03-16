
n = int(input())  # Read an integer input `n`

# Start a loop from 1 to 10^5
for i in range(1, 10 ** 5):
    # Check if the square of the current number `i` is greater than `n`
    if i * i > n:
        # Print the square of the previous number `(i-1)` and exit the program
        print((i-1) * (i-1))
        exit()

