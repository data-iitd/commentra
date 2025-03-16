
import sys

def nextInt(sc):
    sc.next()
    return int(sc.next())

def main():
    sc = sys.stdin
    N = nextInt(sc) # Read the number of points.
    points = []
    for i in range(N):
        points.append((nextInt(sc), nextInt(sc))) # Read the x-coordinate and the length L.
    points.sort(key=lambda x: x[1]) # Sort the points by their right boundary.
    # Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
    start = points[0][1] # Initialize the start of the first interval.
    ans = 1 # Initialize the answer (at least one interval is selected).
    for i in range(len(points)):
        if points[i][0] < start: # If the current interval overlaps with the previous one, skip it.
            continue
        start = points[i][1] # Move to the next interval.
        ans += 1 # Increment the count of selected intervals.
    print(ans) # Print the number of selected intervals.

