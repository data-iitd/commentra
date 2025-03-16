import sys

# Function to read the next integer from standard input
def next_int():
    return int(sys.stdin.readline().strip())

# Defining a class 'Point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
class Point:
    def __init__(self, x, l, r):
        self.x = x
        self.l = l
        self.r = r

# Main function starts here
def main():
    # Reading the number of segments N from the input
    N = next_int()
    # Creating a list 'points' to store all segments
    points = []
    # Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' list
    for _ in range(N):
        x = next_int()
        L = next_int()
        # Calculating left and right endpoints of the segment based on x-coordinate and left-endpoint
        l = x - L
        r = x + L
        points.append(Point(x, l, r))
    
    # Sorting 'points' list based on their right-endpoints
    points.sort(key=lambda p: p.r)
    
    # Initializing variables for result calculation
    start = points[0].r
    ans = 1
    
    # Iterating through all segments in sorted order and updating result accordingly
    for i in range(1, len(points)):
        # If the start of current segment is less than the end of previous segment, then skip it
        if points[i].l < start:
            continue
        # Updating start to the end of current segment
        start = points[i].r
        # Incrementing answer by 1
        ans += 1
    
    # Printing the final answer
    print(ans)

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
