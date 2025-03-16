import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Point class to represent a point with x, l (left boundary), and r (right boundary)
class Point:
    def __init__(self, x, l, r):
        self.x = x
        self.l = l
        self.r = r

# Main function
def main():
    N = next_int()  # Read the number of points
    points = []
    
    for _ in range(N):
        x = next_int()  # Read the x-coordinate of the point
        L = next_int()  # Read the length L
        l = x - L  # Calculate the left boundary
        r = x + L  # Calculate the right boundary
        points.append(Point(x, l, r))
    
    # Sort the points by their right boundary
    points.sort(key=lambda p: p.r)
    
    # Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
    start = points[0].r  # Initialize the start of the first interval
    ans = 1  # Initialize the answer (at least one interval is selected)
    
    for i in range(1, len(points)):
        if points[i].l < start:  # If the current interval overlaps with the previous one, skip it
            continue
        start = points[i].r  # Move to the next interval
        ans += 1  # Increment the count of selected intervals
    
    print(ans)  # Print the number of selected intervals

if __name__ == "__main__":
    main()

# <END-OF-CODE>
