
import sys

def solve(n, ls_xyh):
    # Initialize x0 to None
    x0 = None
    
    # Find the point with a positive height
    for i in range(n):
        if ls_xyh[i][2] > 0:
            [x0, y0, h0] = ls_xyh[i]
            break
    
    # Generate candidate points within a 101x101 grid
    cands = [(cx, cy, h0 + abs(cx - x0) + abs(cy - y0)) for cx in range(101) for cy in range(101)]
    
    # Filter candidates to match the height of each point in ls_xyh
    for [x, y, h] in ls_xyh:
        cands = [(cx, cy, ch) for (cx, cy, ch) in cands if max(ch - abs(cx - x) - abs(cy - y), 0) == h]
    
    # Return the coordinates of the center of the tower
    (xx, yy, hh) = cands[0]
    return ' '.join([str(xx), str(yy), str(hh)])

def readQuestion():
    # Read input from stdin and parse the number of points and their coordinates and heights
    ws = sys.stdin.readline().strip().split()
    n = int(ws[0])
    ls_xyh = [list(map(int, sys.stdin.readline().strip().split())) for j in range(n)]
    return (n, ls_xyh)

def main():
    # Read input, solve the problem, and print the result
    print(solve(*readQuestion()))

main()