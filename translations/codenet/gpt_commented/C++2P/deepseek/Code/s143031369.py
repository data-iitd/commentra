import math

# Define a constant for PI using the arccosine function
PI = math.acos(-1.0)

# Function to determine the sign of a double value
def sig(d):
    return 0 if abs(d) < 1e-8 else -1 if d < 0 else 1

# Class to represent a point in 2D space
class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
        self.k = 0  # Additional variable (not used in this code)

    def set(self, x, y):
        self.x = x
        self.y = y

    def mod(self):
        return math.sqrt(self.x * self.x + self.y * self.y)

    def mod_pow(self):
        return self.x * self.x + self.y * self.y

    def output(self):
        print(f"x = {self.x}, y = {self.y}")

    def __lt__(self, other):
        return sig(self.x - other.x) != 0 and self.x < other.x or sig(self.y - other.y) < 0

# Function to calculate the dot product of two vectors defined by points
def dot(o, a, b):
    return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y)

# Overloaded function to calculate the dot product of two points
def dot(a, b):
    return a.x * b.x + a.y * b.y

# Function to calculate the cross product of two vectors defined by points
def cross(o, a, b):
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y)

# Function to determine if point x is between points a and b
def btw(x, a, b):
    return sig(dot(x, a, b))

# Function to calculate the distance between two points
def dis(a, b):
    return math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))

# Function to calculate the cosine of the angle between two vectors
def cos(o, a, b):
    return dot(o, a, b) / dis(o, a) / dis(o, b)

# Function to compute the convex hull using the Jarvis march algorithm
def jarvis(p, n, ch):
    d, i, o, s, l, t = 0, 0, 0, 0, 0, 0
    # Find the leftmost point to start the hull
    for i in range(n):
        if p[i] < p[d]:
            d = i

    l = s = ch[0] = d
    d = 1

    # Loop to find all points in the convex hull
    while True:
        o = l
        for i in range(n):
            if (t := sig(cross(p[o], p[l], p[i]))) > 0 or (t == 0 and btw(p[l], p[o], p[i]) <= 0):
                l = i
        ch[d] = l
        d += 1
        if l == s:
            break

    return d

# Main function
if __name__ == "__main__":
    # Initialize angle and answer arrays to zero
    ang = [0] * 110
    ans = [0] * 110

    n = int(input())  # Read number of points

    # Read the coordinates of the points
    P = [Point() for _ in range(n)]
    for i in range(n):
        x, y = map(int, input().split())
        P[i].set(x, y)

    # Special case for two points
    if n == 2:
        print("0.5")
        print("0.5")
    else:
        # Compute the convex hull
        m = jarvis(P, n, ch)

        # Special case for two points in the convex hull
        if m == 2:
            ans[ch[0]] = 0.5
            ans[ch[1]] = 0.5
        else:
            # Calculate angles for each point in the convex hull
            for i in range(m):
                ang[ch[i]] = PI - math.acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]))

            # Calculate the area contribution for each point
            for i in range(n):
                ans[i] = ang[i] / (2. * PI)

        # Output the area contributions for each point
        for i in range(n):
            print("{:.20f}".format(ans[i]))
