import sys

MAX = 100  # Define a constant MAX for the maximum value

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of points from user input
    x, y, h = [], [], []  # Initialize lists to store coordinates and heights

    # Read the coordinates and heights of each point from user input
    for _ in range(n):
        xi, yi, hi = map(int, sys.stdin.readline().strip().split())
        x.append(xi)
        y.append(yi)
        h.append(hi)

    # Iterate over a range of possible coordinates (i, j) up to MAX
    for i in range(MAX + 1):
        for j in range(MAX + 1):
            ch = check(n, x, y, h, i, j)  # Call the check function to determine if it is a valid center
            if ch > 0:  # If the check function returns a valid height
                print(f"{i} {j} {ch}")  # Print the center coordinates and height

def check(n, x, y, h, cx, cy):
    ch = -1  # Initialize ch to -1
    for i in range(n):  # Loop through each point
        if h[i] > 0:  # If the height of the point is greater than 0
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i]  # Calculate the height difference
            break  # Break the loop as we found a valid height

    # Verify if the calculated height matches the height of all points
    for i in range(n):
        if h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0):
            return -1  # If any point does not match, return -1
    return ch  # Return the calculated height if all points match

if __name__ == "__main__":
    main()

# <END-OF-CODE>
