def duplicate_patterns(elems, k):
    return dupli_rec([], elems, k)

def dupli_rec(pattern, elems, k):
    if len(pattern) == k:
        return [pattern]

    res = []
    for e in elems:
        new_pattern = pattern + [e]
        sub_patterns = dupli_rec(new_pattern, elems, k)
        res.extend(sub_patterns)

    return res

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
        break
else:
    # If all patterns are checked and no satisfying pattern is found, print "No"
    print("No")

# <END-OF-CODE>
