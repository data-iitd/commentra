
import sys

MOD = 10000000000 + 7
# MOD          = 998244353
ALPHABET_NUM = 26
INF_INT64    = 10 ** 18
INF_BIT60    = 1 << 60
INF_INT32    = 10 ** 9
INF_BIT30    = 1 << 30
NIL          = -1

# Read input values
a, b, c = map(int, input().split())
k = int(input())

# Generate all possible patterns of length k from the given array [0, 1, 2, 3]
patterns = DuplicatePatterns([0, 1, 2, 3], k)

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
        sys.exit()

# If all patterns are checked and no satisfying pattern is found, print "No"
print("No")

# DuplicatePatterns function
def DuplicatePatterns(elems, k):
    return dupliRec([], elems, k)

# DFS function for DuplicatePatterns
def dupliRec(pattern, elems, k):
    if len(pattern) == k:
        # Return the generated pattern as a list
        return [pattern]

    res = []
    for e in elems:
        # Create a new pattern by appending the current element to the current pattern
        newPattern = pattern + [e]

        # Recursively call the function with the new pattern and the remaining elements
        subPatterns = dupliRec(newPattern, elems, k)

        # Append the sub-patterns to the result
        res += subPatterns
    return res

