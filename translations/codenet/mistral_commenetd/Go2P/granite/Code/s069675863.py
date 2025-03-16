

import sys
import math

# Read a string from the standard input
S = input()

# Parse two integers from the string and assign them to the variables x and y
x, y = map(int, input().split())

# Initialize a 2D boolean array dpx and dpy with the size of 8000 x 20000
dpx = [[False] * 20000 for _ in range(8000)]
dpy = [[False] * 20000 for _ in range(8000)]

# Iterate through the even indices of the F slice and update the dpx array accordingly
for i in range(0, len(evens), 2):
    update_dpx(i, evens[i])

# Iterate through the odd indices of the F slice and update the dpy array accordingly
for i in range(1, len(odds), 2):
    update_dpy(i, odds[i])

# Check if the boolean values at the indices (len(evens) + 1) and (len(odds) + 1) corresponding to x and y are both true
if dpx[len(evens)][x+10000] and dpy[len(odds)][y+10000]:
    print("Yes")
else:
    print("No")

# helper function to update dpx array
def update_dpx(index, val):
    for j in range(2000, 18000):
        if j+val <= 18000:
            dpx[index+1][j+val] = dpx[index+1][j+val] or dpx[index][j]
        if j-val >= 2000 and index!= 0:
            dpx[index+1][j-val] = dpx[index+1][j-val] or dpx[index][j]

# helper function to update dpy array
def update_dpy(index, val):
    for j in range(2000, 18000):
        if j+val <= 18000:
            dpy[index+1][j+val] = dpy[index+1][j+val] or dpy[index][j]
        if j-val >= 2000:
            dpy[index+1][j-val] = dpy[index+1][j-val] or dpy[index][j]

# 