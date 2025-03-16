import sys
from math import gcd

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of integers
    ans = int(sys.stdin.readline().strip())  # Read the first integer and initialize 'ans' with it

    # Loop through the remaining integers to compute the GCD
    for _ in range(1, n):
        a = int(sys.stdin.readline().strip())  # Read the current integer from input
        ans = gcd(ans, a)  # Update 'ans' with the GCD of 'ans' and 'a'

    # Output the final GCD result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
