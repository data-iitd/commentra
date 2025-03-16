import sys

# Constants for general purpose use
MOD = 1000000000 + 7  # Modulus value
ALPHABET_NUM = 26  # Number of letters in the alphabet
INF_INT64 = float('inf')  # Maximum value for int64
INF_INT32 = float('inf')  # Maximum value for int32

def main():
    # Read the input string and target coordinates
    S = list(sys.stdin.readline().strip())
    x, y = map(int, sys.stdin.readline().strip().split())

    F = []  # List to hold the lengths of consecutive 'F's
    cur = 0  # Current count of consecutive 'F's

    # Count consecutive 'F's and store in F
    for char in S:
        if char == 'F':
            cur += 1
        else:
            F.append(cur)
            cur = 0
    F.append(cur)  # Append the last count of 'F's

    evens, odds = [], []  # Lists to separate even and odd indexed counts
    # Separate counts into even and odd indexed lists
    for i in range(len(F)):
        if i % 2 == 0:
            evens.append(F[i])
        else:
            odds.append(F[i])

    # Initialize the dynamic programming tables for x and y
    dpx = [[False] * 20001 for _ in range(8000)]
    dpy = [[False] * 20001 for _ in range(8000)]
    dpx[0][10000] = True
    dpy[0][10000] = True

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
        print("Yes")  # Output "Yes" if reachable
    else:
        print("No")  # Output "No" if not reachable

if __name__ == "__main__":
    main()

# <END-OF-CODE>
