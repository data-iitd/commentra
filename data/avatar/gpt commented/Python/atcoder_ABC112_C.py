import sys

def solve(n, ls_xyh):
    # Initialize the coordinates and height of the first building with a positive height
    x0 = None
    for i in range(n):
        if ls_xyh[i][2] > 0:
            [x0, y0, h0] = ls_xyh[i]
            break
            
    # Generate candidate positions (cx, cy) with their corresponding heights based on the first building
    cands = [(cx, cy, h0 + abs(cx - x0) + abs(cy - y0)) for cx in range(101) for cy in range(101)]
    
    # Filter candidates based on the height constraints from the other buildings
    for [x, y, h] in ls_xyh:
        cands = [(cx, cy, ch) for (cx, cy, ch) in cands if max(ch - abs(cx - x) - abs(cy - y), 0) == h]
        
    # Select the first valid candidate position and height
    (xx, yy, hh) = cands[0]
    
    # Return the result as a space-separated string
    return ' '.join([str(xx), str(yy), str(hh)])

def readQuestion():
    # Read input from standard input and parse the number of buildings and their properties
    ws = sys.stdin.readline().strip().split()
    n = int(ws[0])
    ls_xyh = [list(map(int, sys.stdin.readline().strip().split())) for j in range(n)]
    return (n, ls_xyh)

def main():
    # Execute the solve function with the input read from readQuestion and print the result
    print(solve(*readQuestion()))

# Entry point of the program
main()
