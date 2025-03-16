import math

# Define a constant value
PI = math.acos(-1.0)

# Define a function to determine the sign of a double value
def sig(d):
    return 0 if abs(d) < 1e-8 else -1 if d < 0 else 1

# Define a Point structure
class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
        self.k = 0

    def set(self, x, y):
        self.x = x
        self.y = y

    def mod(self):
        return math.sqrt(self.x**2 + self.y**2)

    def mod_pow(self):
        return self.x**2 + self.y**2

    def output(self):
        print(f"x = {self.x}, y = {self.y}")

    def __lt__(self, other):
        return sig(self.x - other.x) != 0 and self.x < other.x or sig(self.y - other.y) < 0

# Define an array of Points P
P = []
# Define an array ch to store the indices of the points in the convex hull
ch = []
# Define arrays ang and ans to store the angles and answers respectively
ang = []
ans = []

# Calculate the dot product of three Points
def dot(o, a, b):
    return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y)

# Calculate the cross product of a Point and two other Points
def cross(o, a, b):
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y)

# Check if a Point is between two other Points on the counterclockwise arc
def btw(x, a, b):
    return sig(dot(x, a, b))

# Calculate the distance between two Points
def dis(a, b):
    return math.sqrt((a.x - b.x) ** 2 + (a.y - b.y) ** 2)

# Calculate the cosine of the angle between a line passing through two Points and a given Point
def cos(o, a, b):
    return dot(o, a, b) / dis(o, a) / dis(o, b)

# Find the convex hull of a set of Points using Jarvis March algorithm
def jarvis(p, n, ch):
    d = 0
    for i in range(n):
        if p[i] < p[d]:
            d = i
    l = s = ch[0] = d
    d = 1
    while True:
        o = l
        for i in range(n):
            t = sig(cross(p[o], p[l], p[i]))
            if t > 0 or (t == 0 and btw(p[l], p[o], p[i]) <= 0):
                l = i
        ch[d] = l
        d += 1
        if l == s:
            break
    return d

# Main function to read input and calculate the answers
def main():
    global xx, yy
    n = int(input())
    for i in range(n):
        xx, yy = map(int, input().split())
        P.append(Point(xx, yy))

    if n == 2:
        print("0.5")
        print("0.5")
    else:
        m = jarvis(P, n, ch)
        if m == 2:
            ans[ch[0]] = 0.5
            ans[ch[1]] = 0.5
        else:
            for i in range(m):
                ang[ch[i]] = PI - math.acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]))
            for i in range(n):
                ans[i] = ang[i] / 2. / PI
            for i in range(n):
                print("{:.20f}".format(ans[i]))

if __name__ == "__main__":
    main()
