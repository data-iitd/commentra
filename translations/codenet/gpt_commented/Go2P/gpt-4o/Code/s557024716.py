import sys
from itertools import product

def main():
    # Read three integers and the number of patterns
    a, b, c = map(int, sys.stdin.readline().split())
    k = int(sys.stdin.readline().strip())

    # Generate all possible patterns of length k from the set {0, 1, 2, 3}
    patterns = product([0, 1, 2, 3], repeat=k)

    # Iterate through each generated pattern
    for P in patterns:
        r, g, b = a, b, c  # Initialize color values for each pattern
        # Apply the pattern to modify the color values
        for i in range(len(P)):
            if P[i] == 0:
                continue  # Skip if the pattern element is 0
            elif P[i] == 1:
                r *= 2  # Double the red value
            elif P[i] == 2:
                g *= 2  # Double the green value
            elif P[i] == 3:
                b *= 2  # Double the blue value

        # Check if the modified values satisfy the condition
        if g > r and b > g:
            print("Yes")  # Print "Yes" if the condition is met
            return

    print("No")  # Print "No" if no pattern satisfies the condition

if __name__ == "__main__":
    main()

# <END-OF-CODE>
