
# Python code to calculate the answers
import math

# Define a constant value
PI = math.acos(-1.0)

# Define a function to determine the sign of a double value
def sig(d):
	return abs(d) < 1e-8 and 0 or d < 0 and -1 or 1

# Define a Point structure
class Point:
	def __init__(self, x, y):
		self.x = x
		self.y = y
		self.k = 0

# Define an array of Points P
P = []

# Define an array ch to store the indices of the points in the convex hull
ch = []

# Define arrays ang and ans to store the angles and answers respectively
ang = []
ans = []

# Calculate the dot product of three Points
def dot(o, a, b):
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)

# Calculate the cross product of a Point and two other Points
def cross(o, a, b):
	return (a.x - o.x)*(b.y - o.y)-(b.x - o.x)*(a.y - o.y)

# Check if a Point is between two other Points on the counterclockwise arc
def btw(x, a, b):
	return sig(dot(x, a, b))

# Calculate the distance between two Points
def dis(a, b):
	return math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

# Calculate the cosine of the angle between a line passing through two Points and a given Point
def cos(o, a, b):
	return dot(o,a,b)/dis(o,a)/dis(o,b)

# Find the convex hull of a set of Points using Jarvis March algorithm
def jarvis(p, n, ch):
	d = i = 0
	for i in range(n):
		if p[i] < p[d]:
			d = i
	l = s = ch[0] = d
	d = 1
	while True:
		o = l
		for i in range(n):
			if (t:=sig(cross(p[o], p[l], p[i])))>0 or (t==0 and btw(p[l], p[o], p[i])<=0):
				l = i
		ch[d] = l
		if l == s:
			break
		d += 1
	return d-1

# Main function to read input and calculate the answers
def main():
	ang = [0.0] * 110
	ans = [0.0] * 110
	# Read the number of Points
	n = int(input())
	# Initialize the Points
	for i in range(n):
		x, y = map(int, input().split())
		# Set the x and y coordinates of the Point
		P.append(Point(x, y))
	# Special case for 2 Points
	if n == 2:
		# Output the answers
		print(0.5)
		print(0.5)
	else:
		# Find the convex hull of the Points
		m = jarvis(P, n, ch)
		# Calculate the angles for the Points in the convex hull
		if m == 2:
			# Set the answers for the first and second Points
			ans[ch[0]] = 0.5
			ans[ch[1]] = 0.5
		else:
			# Calculate the angles for all the Points in the convex hull
			for i in range(m):
				ang[ch[i]] = PI - math.acos(cos(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]]))
			# Calculate the answers for all the Points
			for i in range(n):
				ans[i] = ang[i] / (2.0 * PI)
		# Output the answers for all the Points
		for i in range(n):
			print(ans[i])

# Call the main function to execute the code
if __name__ == "__main__":
	main()

Translate the above Python code to C++ and end with comment "