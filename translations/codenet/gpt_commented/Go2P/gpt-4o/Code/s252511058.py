import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Point class represents a point with its position and its left and right bounds
class Point:
    def __init__(self, x, l, r):
        self.x = x  # Position
        self.l = l  # Left bound
        self.r = r  # Right bound

# Main function
def main():
    N = next_int()  # Read the number of points
    points = []  # Create a list to hold the points

    # Read each point's position and calculate its left and right bounds
    for _ in range(N):
        x = next_int()  # Read the position of the point
        L = next_int()  # Read the length to calculate bounds
        l = x - L  # Calculate the left bound
        r = x + L  # Calculate the right bound
        points.append(Point(x, l, r))  # Append the point to the list

    # Sort the points based on their right bounds
    points.sort(key=lambda p: p.r)

    # Initialize the scheduling process for the interval scheduling problem
    start = points[0].r  # Start with the right bound of the first point
    ans = 1  # Initialize the count of non-overlapping intervals

    # Iterate through the sorted points to count non-overlapping intervals
    for i in range(1, len(points)):
        if points[i].l < start:  # If the left bound overlaps with the current start
            continue  # Skip to the next point
        start = points[i].r  # Update the start to the right bound of the current point
        ans += 1  # Increment the count of non-overlapping intervals

    # Output the total number of non-overlapping intervals
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
