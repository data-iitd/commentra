
import sys

def main():
    # Read three integers and the number of patterns
    a, b, c, k = map(int, sys.stdin.readline().split())

    # Generate all possible patterns of length k from the set {0, 1, 2, 3}
    patterns = duplicate_patterns([0, 1, 2, 3], k)

    # Iterate through each generated pattern
    for P in patterns:
        r, g, b = a, b, c # Initialize color values for each pattern
        # Apply the pattern to modify the color values
        for i in range(len(P)):
            if P[i] == 0:
                continue # Skip if the pattern element is 0
            elif P[i] == 1:
                r *= 2 # Double the red value
            elif P[i] == 2:
                g *= 2 # Double the green value
            elif P[i] == 3:
                b *= 2 # Double the blue value

        # Check if the modified values satisfy the condition
        if g > r and b > g:
            print("Yes") # Print "Yes" if the condition is met
            return # Return from the function

    print("No") # Print "No" if no pattern satisfies the condition

# Function to generate all patterns of length k from the given elements
def duplicate_patterns(elems, k):
    if k == 0:
        return [[]] # Return the empty pattern

    res = [] # Slice to hold the results
    # Iterate through each element to build patterns
    for e in elems:
        for P in duplicate_patterns(elems, k - 1):
            res.append([e] + P) # Append the new element to the pattern

    return res # Return all generated patterns

if __name__ == "__main__":
    main()

