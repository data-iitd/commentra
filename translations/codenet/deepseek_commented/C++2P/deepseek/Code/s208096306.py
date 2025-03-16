def gcd(a, b):
    if a < b:
        a, b = b, a
    while (r := a % b) > 0:
        a, b = b, r
    return b

# Define gcd function: This function computes the greatest common divisor
# of two integers using the Euclidean algorithm.

def main():
    n = int(input())

    # Read the number of integers.

    ans = int(input())

    # Read the first integer and initialize the answer.

    for _ in range(1, n):
        a = int(input())
        ans = gcd(ans, a)

    # Read the remaining integers, compute their GCD with the current answer,
    # and update the answer accordingly.

    print(ans)

    # Print the final result, which is the GCD of all the input integers.

# Call the main function.
main()

