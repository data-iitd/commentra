# Importing the sys module for reading input from standard input
import sys

# Function to solve the problem
def solve(n, ls_xyh):
    # Initialize x0 as None
    x0 = None

    # Iterate through the list ls_xyh to find the point with the highest height
    for i in range(n):
        if ls_xyh[i][2] > 0:  # Check if the height is positive
            [x0, y0, h0] = ls_xyh[i]  # Assign x0, y0, and h0
            break

    # Generate a list of candidate points based on the given height and the position of x0, y0
    cands = [(cx, cy, h0 + abs(cx - x0) + abs(cy - y0)) for cx in range(101) for cy in range(101)]

    # Filter out the invalid candidate points based on the given height
    for [x, y, h] in ls_xyh:
        cands = [(cx, cy, ch) for (cx, cy, ch) in cands if max(ch - abs(cx - x) - abs(cy - y), 0) == h]

    # Find the point with the minimum height among the valid candidates
    [xx, yy, hh] = cands[0]

    # Return the solution as a string
    return ' '.join([str(xx), str(yy), str(hh)])

# Function to read the question and return the problem data
def readQuestion():
    # Read the first line to get the number of points
    ws = sys.stdin.readline().strip().split()
    n = int(ws[0])

    # Read the second line to get the list of points
    ls_xyh = [list(map(int, sys.stdin.readline().strip().split())) for j in range(n)]

    # Return the problem data as a tuple (number of points, list of points)
    return (n, ls_xyh)

# Main function to call the solve function and print the result
def main():
    # Call the readQuestion function to get the problem data
    data = readQuestion()

    # Call the solve function to get the solution
    solution = solve(*data)

    # Print the solution
    print(solution)

# Call the main function to start the program
main()
