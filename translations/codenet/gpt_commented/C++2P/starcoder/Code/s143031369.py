# Define a constant for PI using the arccosine function
PI=acos(-1.0)

# Function to determine the sign of a double value
def sig(d):
    if(fabs(d) < 1e-8):
        return 0
    elif(d < 0):
        return -1
    else:
        return 1

# Structure to represent a point in 2D space
class Point:
    def __init__(self):
        self.x = 0.0
        self.y = 0.0
        self.k = 0.0

    # Constructor to initialize point with coordinates
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Method to set the coordinates of the point
    def set(self, x, y):
        self.x = x
        self.y = y

    # Method to calculate the modulus (length) of the point vector
    def mod(self):
        return sqrt(self.x*self.x + self.y*self.y)

    # Method to calculate the square of the modulus (length squared)
    def mod_pow(self):
        return self.x*self.x + self.y*self.y

    # Method to output the coordinates of the point
    def output(self):
        print("x = %f, y = %f" % (self.x, self.y))

    # Overloaded operator to compare two points
    def __lt__(self, p):
        if(sig(self.x - p.x)!= 0):
            return self.x < p.x
        else:
            return sig(self.y - p.y) < 0

# Array to hold up to 110 points
P=[Point() for i in range(110)]

# Array to hold the indices of the convex hull points
ch=[0 for i in range(110)]

# Arrays to hold angles and results
ang=[0.0 for i in range(110)]
ans=[0.0 for i in range(110)]

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
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))

# Function to calculate the cosine of the angle between two vectors
def cos(o, a, b):
    return dot(o, a, b) / dis(o, a) / dis(o, b)

# Function to compute the convex hull using the Jarvis march algorithm
def jarvis(p, n, ch):
    d=0
    i=0
    o=0
    s=0
    l=0
    t=0
    # Find the leftmost point to start the hull
    for i in range(n):
        if(p[i] < p[d]):
            d = i
    l = s = ch[0] = d
    d = 1
    # Loop to find all points in the convex hull
    while(l!= s):
        o = l
        for i in range(n):
            # Check if point i is more counter-clockwise than the current point l
            if((t = sig(cross(p[o], p[l], p[i]))) > 0 or (t == 0 and btw(p[l], p[o], p[i]) <= 0)):
                l = i
        ch[d] = l
        d += 1
    return d - 1

# Main function
def main():
    # Initialize angle and answer arrays to zero
    ang=[0.0 for i in range(110)]
    ans=[0.0 for i in range(110)]
    memset(ang, 0, sizeof(ang))
    memset(ans, 0, sizeof(ans))

    n=0
    xx=0
    yy=0
    # Read number of points
    n=int(input())
    # Read the coordinates of the points
    for i in range(n):
        xx, yy=map(int, input().split())
        P[i].set(xx, yy)
    # Special case for two points
    if(n == 2):
        print("0.5") # Each point contributes equally to the area
        print("0.5")
    else:
        # Compute the convex hull
        m=jarvis(P, n, ch)
        sum=0
        # Special case for two points in the convex hull
        if(m == 2):
            ans[ch[0]] = 0.5 # Assign equal area to both points
            ans[ch[1]] = 0.5
        else:
            # Calculate angles for each point in the convex hull
            for i in range(m):
                ang[ch[i]] = PI - acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]))
            # Calculate the area contribution for each point
            for i in range(n):
                ans[i] = ang[i] / 2. / PI # Normalize the angle to get area contribution
        # Output the area contributions for each point
        for i in range(n):
            print("%.20f" % ans[i]) # Print results with high precision
    return 0

# 