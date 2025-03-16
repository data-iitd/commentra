
t = int(input())  # Read the number of test cases

def solve(n):
    # Calculate the sum of the first n natural numbers
    s = (1 + n) * n // 2
    # Initialize t to 1
    t = 1
    # Subtract twice the sum of powers of 2 up to n from s
    while t <= n:
        s -= 2 * t
        t *= 2
    return s

# Main loop to iterate over the number of test cases
for _ in range(t):
    n = int(input())  # Read each n for the test case
    print(solve(n))  # Print the result of the solve function for the current n


