
import sys
from operator import itemgetter

def main():
    N = int(input()) # Read the number of points.
    points = []
    for _ in range(N):
        x, L = map(int, input().split()) # Read the x-coordinate and length L.
        points.append((x, x + L, x - L)) # Store the x-coordinate, right boundary, and left boundary.
    points.sort(key=itemgetter(2)) # Sort the points by their left boundary.
    start = points[0][1] # Initialize the start of the first interval.
    ans = 1 # Initialize the answer (at least one interval is selected).
    for i in range(1, N):
        if points[i][2] < start: # If the current interval overlaps with the previous one, skip it.
            continue
        start = points[i][1] # Move to the next interval.
        ans += 1 # Increment the count of selected intervals.
    print(ans) # Print the number of selected intervals.

if __name__ == "__main__":
    main()

