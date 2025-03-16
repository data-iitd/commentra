import sys

def power(x, n):
    # Base case: x^0 = 1
    if n == 0:
        return 1

    # Define a modulus value for calculations
    mod = 1000000007

    # Recursively calculate power
    val = power(x, n / 2)

    # Square the result and take modulus
    val = val * val % mod

    # If n is odd, multiply by x and take modulus
    if n % 2 == 1:
        val = val * x % mod

    # Return the final result
    return val

def main():
    # Read the first line of input and split it into an array of strings
    sa = sys.stdin.readline().split(" ")

    # Parse the first element as an integer 'n'
    n = int(sa[0])

    # Read the second line of input and split it into an array of strings
    sa = sys.stdin.readline().split(" ")

    # Initialize an integer array 'c' of size 'n'
    c = [0] * n

    # Populate the array 'c' with integers from the input
    for i in range(n):
        c[i] = int(sa[i])

    # Sort the array 'c' in parallel
    c.sort()

    # Calculate powers of 2 for later use
    b = power(2, n)
    a = power(2, n - 2)

    # Initialize the answer variable
    ans = 0

    # Calculate the final answer using a loop
    for i in range(2, n + 1):
        # Calculate the value for the current iteration
        val = a * i % mod
        val *= c[n + 1 - i]
        val %= mod

        # Accumulate the result
        ans += val
        ans %= mod

    # Multiply the accumulated answer by 'b' and take modulus
    ans *= b
    ans %= mod

    # Print the final result
    print(ans)

if __name__ == "__main__":
    main()

