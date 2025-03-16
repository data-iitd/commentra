from math import atan2, pi

# Step 1: Reading Input
# The code reads the number of points N and the coordinates of the points XY from the standard input.
N, *XY = map(int, open(0).read().split())

# Step 2: Processing Coordinates
# The coordinates are grouped into pairs and stored in the list XY.
XY = list(zip(*[iter(XY)] * 2))

# Step 3: Calculating Angles
# For each point, the code calculates the angles to all other points using atan2.
for i, (x, y) in enumerate(XY):
    # Calculate the angles for each point relative to others
    D = sorted(atan2(X - x, Y - y) for j, (X, Y) in enumerate(XY) if j != i)
    
    # Step 4: Handling Circular Angles
    # The angles are adjusted to handle the circular nature of angles (0 to 2π).
    D.append(D[0] + 2 * pi)
    
    # Step 5: Finding the Maximum Gap
    ans = 0
    for a, b in zip(D, D[1:]):
        if b - a >= pi:
            ans = (b - a) - pi
    
    # Step 6: Calculating the Fraction
    # The fraction of the circle covered by the maximum gap is calculated and printed.
    print(ans / (2 * pi))
