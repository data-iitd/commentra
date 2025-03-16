
import sys

def main():
    # Read the input.
    a, b, c = map(int, input().split())
    k = int(input())

    # Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3.
    patterns = generate_patterns([0, 1, 2, 3], k)

    # Iterate through each pattern to check the condition.
    for P in patterns:
        r, g, b = a, b, c # Initialize r, g, and b with a, b, and c respectively.
        for i in range(len(P)):
            if P[i] == 0:
                continue # If the operation is 0, do nothing.
            elif P[i] == 1:
                r *= 2 # Double the value of r.
            elif P[i] == 2:
                g *= 2 # Double the value of g.
            elif P[i] == 3:
                b *= 2 # Double the value of b.

        # Check if the condition b > a and c > b is met.
        if g > r and b > g:
            print("Yes") # Print "Yes" if the condition is met.
            return

    print("No") # Print "No" if no pattern meets the condition.

def generate_patterns(elems, k):
    if k == 0:
        return [[]]

    res = []
    for e in elems:
        for P in generate_patterns(elems, k - 1):
            res.append([e] + P)

    return res

if __name__ == "__main__":
    main()

