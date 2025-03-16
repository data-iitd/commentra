import math
import sys

# Define a constant for PI using the arccosine function
PI = math.acos(-1.0)

# Function to determine the sign of a double value
def sig(d):
    return 0 if abs(d) < 1e-8 else -1 if d < 0 else 1  # Returns 0 if d is close to 0, -1 if d is negative, 1 if d is positive

# Class to represent a point in 2D space
class Point:
    def __init__(self, x=0, y=0):
        self.x = x  # Coordinates of the point
        self.y = y  # Coordinates of the point

    # Method to calculate the modulus (length) of the point vector
    def mod(self):
        return math.sqrt(self.x * self.x + self.y * self.y)

    # Method to calculate the square of the modulus (length squared)
    def mod_pow(self):
        return self.x * self.x + self.y * self.y

    # Method to output the coordinates of the point
    def output(self):
        print(f"x = {self.x}, y = {self.y}")

    # Overloaded operator to compare two points
    def __lt__(self, other):
        return sig(self.x - other.x) != 0 and self.x < other.x or sig(self.y - other.y) < 0

# Function to calculate the dot product of two vectors defined by points
def dot(o, a, b):
    return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y)

# Function to calculate the cross product of two vectors defined by points
def cross(o, a, b):
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y)

# Function to determine if point x is between points a and b
def btw(x, a, b):
    return sig(dot(x, a, b))

# Function to calculate the distance between two points
def dis(a, b):
    return math.sqrt((a.x - b.x) ** 2 + (a.y - b.y) ** 2)

# Function to calculate the cosine of the angle between two vectors
def cos(o, a, b):
    return dot(o, a, b) / dis(o, a) / dis(o, b)

# Function to compute the convex hull using the Jarvis march algorithm
def jarvis(p, n):
    ch = []
    d = 0
    for i in range(n):
        if p[i] < p[d]:
            d = i

    l = s = d  # Initialize the starting point
    ch.append(d)  # Add the starting point to the convex hull

    while True:
        o = l  # Current point
        for i in range(n):
            t = sig(cross(p[o], p[l], p[i]))
            if t > 0 or (t == 0 and btw(p[l], p[o], p[i]) <= 0):
                l = i  # Update the point in the hull
        if l == s:
            break
        ch.append(l)  # Add the point to the convex hull

    return ch  # Return the list of points in the convex hull

# Main function
def main():
    n = int(input().strip())  # Read number of points
    P = [Point() for _ in range(110)]  # Array to hold up to 110 points
    ans = [0.0] * 110  # Array to hold results

    # Read the coordinates of the points
    for i in range(n):
        xx, yy = map(int, input().strip().split())
        P[i] = Point(xx, yy)  # Set the coordinates for each point

    # Special case for two points
    if n == 2:
        print("0.5")
        print("0.5")
    else:
        # Compute the convex hull
        ch = jarvis(P, n)
        m = len(ch)
        ang = [0.0] * 110  # Array to hold angles

        # Special case for two points in the convex hull
        if m == 2:
            ans[ch[0]] = 0.5  # Assign equal area to both points
            ans[ch[1]] = 0.5
        else:
            # Calculate angles for each point in the convex hull
            for i in range(m):
                ang[ch[i]] = PI - math.acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]))
            # Calculate the area contribution for each point
            for i in range(n):
                ans[i] = ang[i] / 2.0 / PI  # Normalize the angle to get area contribution

        # Output the area contributions for each point
        for i in range(n):
            print(f"{ans[i]:.20f}")  # Print results with high precision

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
