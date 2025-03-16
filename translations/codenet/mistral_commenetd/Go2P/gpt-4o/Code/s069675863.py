import sys

MOD = 1000000007
ALPHABET_NUM = 26
INF_INT64 = float('inf')
INF_INT32 = 2**31 - 1
NIL = -1

def main():
    # Read a string from the standard input
    S = input().strip()

    # Parse two integers from the input
    x, y = map(int, input().split())

    # Initialize a 2D boolean array dpx and dpy with the size of 8000 x 20000
    dpx = [[False] * 20000 for _ in range(8000)]
    dpy = [[False] * 20000 for _ in range(8000)]

    # Prepare the evens and odds lists
    evens = []
    odds = []

    # Fill the evens and odds based on the input string
    for char in S:
        if char == 'F':
            evens.append(1)
        else:
            odds.append(1)

    # Initialize the starting point
    dpx[0][10000] = True
    dpy[0][10000] = True

    # Iterate through the even indices of the evens list and update the dpx array accordingly
    for i in range(len(evens)):
        update_dpx(i, evens[i], dpx)

    # Iterate through the odd indices of the odds list and update the dpy array accordingly
    for i in range(len(odds)):
        update_dpy(i, odds[i], dpy)

    # Check if the boolean values at the indices (len(evens)) and (len(odds)) corresponding to x and y are both true
    if dpx[len(evens)][x + 10000] and dpy[len(odds)][y + 10000]:
        print("Yes")
    else:
        print("No")

def update_dpx(index, val, dpx):
    for j in range(2000, 18001):
        if j + val <= 18000:
            dpx[index + 1][j + val] = dpx[index + 1][j + val] or dpx[index][j]
        if j - val >= 2000 and index != 0:
            dpx[index + 1][j - val] = dpx[index + 1][j - val] or dpx[index][j]

def update_dpy(index, val, dpy):
    for j in range(2000, 18001):
        if j + val <= 18000:
            dpy[index + 1][j + val] = dpy[index + 1][j + val] or dpy[index][j]
        if j - val >= 2000:
            dpy[index + 1][j - val] = dpy[index + 1][j - val] or dpy[index][j]

if __name__ == "__main__":
    main()

# <END-OF-CODE>
