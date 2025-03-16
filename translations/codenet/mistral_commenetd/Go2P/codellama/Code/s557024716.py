
import sys

def main():
    # Read input values
    a, b, c = map(int, input().split())
    k = int(input())

    # Generate all possible patterns of length k from the given array [0, 1, 2, 3]
    patterns = duplicate_patterns([0, 1, 2, 3], k)

    # Check each generated pattern
    for P in patterns:
        # Apply bitwise operation to RGB values of the given input
        r, g, b = a, b, c
        for i in range(len(P)):
            if P[i] == 0:
                continue
            elif P[i] == 1:
                r *= 2
            elif P[i] == 2:
                g *= 2
            elif P[i] == 3:
                b *= 2

        # Check if the result satisfies the condition g > r and b > g
        if g > r and b > g:
            print("Yes")
            return

    # If all patterns are checked and no satisfying pattern is found, print "No"
    print("No")

def duplicate_patterns(elems, k):
    return duplicate_patterns_rec([], elems, k)

def duplicate_patterns_rec(pattern, elems, k):
    if len(pattern) == k:
        # Return the generated pattern as a slice
        return [pattern]

    res = []
    for e in elems:
        # Create a new pattern by appending the current element to the current pattern
        new_pattern = pattern + [e]

        # Recursively call the function with the new pattern and the remaining elements
        sub_patterns = duplicate_patterns_rec(new_pattern, elems, k)

        # Append the sub-patterns to the result
        res += sub_patterns

    return res

if __name__ == "__main__":
    main()

