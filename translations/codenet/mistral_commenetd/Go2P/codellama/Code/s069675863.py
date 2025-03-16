
import sys

def main():
    # Read a string from the standard input
    S = sys.stdin.readline().rstrip()

    # Parse two integers from the string and assign them to the variables x and y
    x, y = map(int, sys.stdin.readline().split())

    # Initialize a 2D boolean array dpx and dpy with the size of 8000 x 20000
    dpx = [[False] * 20000 for _ in range(8000)]
    dpy = [[False] * 20000 for _ in range(8000)]

    # Iterate through the even indices of the F slice and update the dpx array accordingly
    for i in range(len(S)):
        if i % 2 == 0:
            for j in range(2000, 18001):
                if j + int(S[i]) <= 18000:
                    dpx[i + 1][j + int(S[i])] = dpx[i + 1][j + int(S[i])] or dpx[i][j]
                if j - int(S[i]) >= 2000 and i != 0:
                    dpx[i + 1][j - int(S[i])] = dpx[i + 1][j - int(S[i])] or dpx[i][j]

    # Iterate through the odd indices of the F slice and update the dpy array accordingly
    for i in range(len(S)):
        if i % 2 == 1:
            for j in range(2000, 18001):
                if j + int(S[i]) <= 18000:
                    dpy[i + 1][j + int(S[i])] = dpy[i + 1][j + int(S[i])] or dpy[i][j]
                if j - int(S[i]) >= 2000:
                    dpy[i + 1][j - int(S[i])] = dpy[i + 1][j - int(S[i])] or dpy[i][j]

    # Check if the boolean values at the indices (len(evens) + 1) and (len(odds) + 1) corresponding to x and y are both true
    if dpx[len(S)][x + 10000] and dpy[len(S)][y + 10000]:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

