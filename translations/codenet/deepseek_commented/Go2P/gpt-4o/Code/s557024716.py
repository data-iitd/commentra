import sys
from itertools import product

def main():
    a, b, c = map(int, sys.stdin.readline().split())
    k = int(sys.stdin.readline().strip())

    # Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3.
    patterns = product([0, 1, 2, 3], repeat=k)

    # Iterate through each pattern to check the condition.
    for P in patterns:
        r, g, _ = a, b, c  # Initialize r, g, and b with a, b, and c respectively.
        for operation in P:
            if operation == 0:
                continue  # If the operation is 0, do nothing.
            elif operation == 1:
                r *= 2  # Double the value of r.
            elif operation == 2:
                g *= 2  # Double the value of g.
            elif operation == 3:
                c *= 2  # Double the value of c.

        # Check if the condition b > a and c > b is met.
        if g > r and c > g:
            print("Yes")  # Print "Yes" if the condition is met.
            return

    print("No")  # Print "No" if no pattern meets the condition.

if __name__ == "__main__":
    main()

# <END-OF-CODE>
