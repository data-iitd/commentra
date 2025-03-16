
# Include necessary headers: These headers provide essential functionalities
# such as input/output operations, containers like vectors and deques,
# and algorithms.

from math import gcd

# Define gcd function: This function computes the greatest common divisor
# of two integers using the Euclidean algorithm.

if __name__ == '__main__':
    n = int(input())

    # Read the number of integers.

    ans = int(input())

    # Read the first integer and initialize the answer.

    for i in range(1, n):
        a = int(input())
        ans = gcd(ans, a)

    # Read the remaining integers, compute their GCD with the current answer,
    # and update the answer accordingly.

    print(ans)

    # Print the final result, which is the GCD of all the input integers.

