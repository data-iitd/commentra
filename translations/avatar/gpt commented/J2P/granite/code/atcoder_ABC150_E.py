
import sys

def main():
    # Read input from the console
    n, *c = map(int, sys.stdin.read().split())

    # Define a modulus value for calculations
    mod = 1000000007

    # If there is only one element, calculate and print the result directly
    if n == 1:
        print((c[0] * 2) % mod)
        return

    # Sort the array 'c' in parallel
    c.sort()

    # Calculate powers of 2 for later use
    b = pow(2, n, mod)
    a = pow(2, n - 2, mod)

    # Initialize the answer variable
    ans = 0

    # Calculate the final answer using a loop
    for i in range(2, n + 2):
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

