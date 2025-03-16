import sys

# Method to solve the problem
def solve():
    # Read input values
    x, t, a, b, da, db = map(int, sys.stdin.readline().split())

    first = a
    second = b
    ok = False

    # Iterate through possible steps for the first entity
    for i in range(t):
        first = a - (da * i)

        # Iterate through possible steps for the second entity
        for j in range(t):
            second = b - (db * j)

            # Check if any of the conditions to reach target x are met
            if (second + first == x or second == x or first == x or x == 0):
                ok = True
                break

    # Output result based on whether the target can be reached
    if ok:
        print("YES")
    else:
        print("NO")

# Main method to run the program
def main():
    solve()

if __name__ == "__main__":
    main()

