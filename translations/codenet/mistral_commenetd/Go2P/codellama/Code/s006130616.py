// Package main is the entry point of the program
import sys

def main():
    # Initialize variables n, m, x for input
    n, m, x = map(int, sys.stdin.readline().split())

    # Allocate memory for 2D array a and 1D array p
    a = [[0 for _ in range(m)] for _ in range(n)]
    p = [0 for _ in range(n)]

    # Read input for p and initialize a with empty rows
    for i in range(n):
        # Read input for p[i]
        p[i] = int(sys.stdin.readline())

        # Read input for each element of row i of a
        for j in range(m):
            a[i][j] = int(sys.stdin.readline())

    # Initialize variables ans, tot, and ok
    ans = 1200001
    tot = 0
    ok = False

    # Iterate through all possible combinations of bits
    for bits in range(1 << n):
        # Initialize skill array
        skill = [0 for _ in range(m)]

        # Calculate total points and update skill array for the current combination of bits
        tot = 0
        ok = True
        for i in range(n):
            # Check if the current bit is set
            if (bits >> i) & 1 == 1:
                # Add points from p[i] to total
                tot += p[i]

                # Update skill array for each skill
                for j in range(m):
                    skill[j] += a[i][j]

        # Check if the current combination of skills is valid
        for v in skill:
            if v < x:
                ok = False
                break

        # If the current combination is valid, update ans if the total points are less than the current answer
        if ok:
            if ans > tot:
                ans = tot

    # Print the answer
    if ans != 1200001:
        print(ans)
    else:
        print("-1")

if __name__ == "__main__":
    main()

