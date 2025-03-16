import sys

# Read the next word from the input, convert it to an integer, and return it.
def next_int():
    return int(sys.stdin.readline().strip())

# Point represents a point with x, l (left boundary), and r (right boundary).
class Point:
    def __init__(self, x, l):
        self.x = x
        self.l = x - l
        self.r = x + l

# Sort the points by their right boundary.
def sort_key(point):
    return point.r

# Main function is the entry point of the program.
def main():
    N = next_int()  # Read the number of points.
    points = []
    for _ in range(N):
        x = next_int()  # Read the x-coordinate of the point.
        l = next_int()  # Read the length L.
        points.append(Point(x, l))
    
    # Sort the points by their right boundary.
    points.sort(key=sort_key)
    
    # Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
    start = points[0].r  # Initialize the start of the first interval.
    ans = 1  # Initialize the answer (at least one interval is selected).
    for i in range(1, N):
        if points[i].l < start:  # If the current interval overlaps with the previous one, skip it.
            continue
        start = points[i].r  # Move to the next interval.
        ans += 1  # Increment the count of selected intervals.
    
    print(ans)  # Print the number of selected intervals.

# Call the main function.
main()
