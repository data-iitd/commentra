
import sys

def main():
    # Read the input string and target coordinates
    S = sys.stdin.readline().rstrip()
    x, y = map(int, sys.stdin.readline().split())

    F = [] # Slice to hold the lengths of consecutive 'F's
    cur = 0 # Current count of consecutive 'F's

    # Count consecutive 'F's and store in F
    for i in range(len(S)):
        if S[i] == 'F':
            cur += 1
        else:
            F.append(cur)
            cur = 0
    F.append(cur) # Append the last count of 'F's
    # Debug output of the lengths of 'F's
    # print(F)

    evens, odds = [], [] # Slices to separate even and odd indexed counts
    # Separate counts into even and odd indexed slices
    for i in range(len(F)):
        if i % 2 == 0:
            evens.append(F[i])
        else:
            odds.append(F[i])

    # Initialize the dynamic programming tables for x and y
    dpx, dpy = [[False] * 18001 for _ in range(8001)], [[False] * 18001 for _ in range(8001)]
    dpx[0][10000], dpy[0][10000] = True, True

    # Fill the dynamic programming table for even indexed counts
    for i in range(len(evens)):
        val = evens[i]
        for j in range(2000, 18001):
            if j + val <= 18000:
                dpx[i + 1][j + val] = dpx[i + 1][j + val] or dpx[i][j]
            if j - val >= 2000 and i != 0:
                dpx[i + 1][j - val] = dpx[i + 1][j - val] or dpx[i][j]

    # Fill the dynamic programming table for odd indexed counts
    for i in range(len(odds)):
        val = odds[i]
        for j in range(2000, 18001):
            if j + val <= 18000:
                dpy[i + 1][j + val] = dpy[i + 1][j + val] or dpy[i][j]
            if j - val >= 2000:
                dpy[i + 1][j - val] = dpy[i + 1][j - val] or dpy[i][j]

    # Check if the target coordinates can be reached
    if dpx[len(evens)][x + 10000] and dpy[len(odds)][y + 10000]:
        print("Yes") # Output "Yes" if reachable
    else:
        print("No") # Output "No" if not reachable

if __name__ == "__main__":
    main()

