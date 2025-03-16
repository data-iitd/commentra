from math import atan2, pi

# Read input values: the first value is N (number of points), followed by the coordinates
N, *XY = map(int, open(0).read().split())

# Pair the coordinates into a list of tuples (x, y)
XY = list(zip(*[iter(XY)] * 2))

# Iterate over each point in the list with its index
for i, (x, y) in enumerate(XY):
    # Calculate angles from the current point (x, y) to all other points
    D = sorted(atan2(X - x, Y - y) for j, (X, Y) in enumerate(XY) if j != i)
    
    # Append the angle that wraps around (2*pi) to handle circularity
    D.append(D[0] + 2 * pi)
    
    # Initialize the answer for the current point
    ans = 0
    
    # Calculate the gaps between consecutive angles
    for a, b in zip(D, D[1:]):
        # Check if the gap is greater than or equal to pi
        if b - a >= pi:
            # Update the answer with the size of the gap minus pi
            ans = (b - a) - pi
    
    # Print the normalized answer (as a fraction of 2*pi)
    print(ans / (2 * pi))
