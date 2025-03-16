# Include necessary libraries
import math
# Define a constant value
PI=math.acos(-1.0)
# Define a function to determine the sign of a double value
def sig(d):
	return abs(d) < 1e-8 and 0 or d < 0 and -1 or 1
# Define a Point class
class Point:
	# Default constructor
	def __init__(self):
		self.x=0.0
		self.y=0.0
	# Constructor with x and y coordinates
	def __init__(self,x,y):
		self.x=x
		self.y=y
	# Set x and y coordinates
	def set(self,x,y):
		self.x=x
		self.y=y
	# Calculate the modulus of a Point
	def mod(self):
		return math.sqrt(self.x*self.x+self.y*self.y)
	# Calculate the modulus squared of a Point
	def mod_pow(self):
		return self.x*self.x + self.y*self.y
	# Output the x and y coordinates of a Point
	def output(self):
		print("x = %f, y = %f" % (self.x, self.y))
	# Compare two Points based on their x and y coordinates
	def __lt__(self,p):
		return sig(self.x-p.x) != 0 and self.x < p.x or sig(self.y-p.y) < 0
# Define an array of Points P
P=[]
# Define an array ch to store the indices of the points in the convex hull
ch=[]
# Define arrays ang and ans to store the angles and answers respectively
ang=[]
ans=[]
# Calculate the dot product of three Points
def dot(o,a,b):
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
# Calculate the cross product of a Point and two other Points
def cross(o,a,b):
	return (a.x - o.x)*(b.y - o.y)-(b.x - o.x)*(a.y - o.y)
# Check if a Point is between two other Points on the counterclockwise arc
def btw(x,a,b):
	return sig(dot(x,a,b))
# Calculate the distance between two Points
def dis(a,b):
	return math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
# Calculate the cosine of the angle between a line passing through two Points and a given Point
def cos(o,a,b):
	return dot(o,a,b)/dis(o,a)/dis(o,b)
# Find the convex hull of a set of Points using Jarvis March algorithm
def jarvis(p,n,ch):
	d=i=0
	for i in range(n):
		if p[i] < p[d]:
			d=i
	l=s=ch[d]=d
	d=1
	while l != s:
		o=l
		for i in range(n):
			if (t:=sig(cross(p[o],p[l],p[i])))>0 or (t==0 and btw(p[l],p[o],p[i])<=0):
				l=i
		ch[d]=l
	return d
# Main function to read input and calculate the answers
def main():
	# Read the number of Points
	n=int(input())
	# Initialize the Points
	for i in range(n):
		x,y=map(float,input().split())
		# Set the x and y coordinates of the Point
		P.append(Point(x,y))
	# Special case for 2 Points
	if n==2:
		# Output the answers
		print("0.5")
		print("0.5")
	else:
		# Find the convex hull of the Points
		m=jarvis(P,n,ch)
		# Calculate the angles for the Points in the convex hull
		if m==2:
			# Set the answers for the first and second Points
			ans[ch[0]]=0.5
			ans[ch[1]]=0.5
		else:
			# Calculate the angles for all the Points in the convex hull
			for i in range(m):
				ang[ch[i]]=PI-math.acos(cos(P[ch[i]],P[ch[(i-1+m)%m]],P[ch[(i+1)%m]]))
			# Calculate the answers for all the Points
			for i in range(n):
				ans[i]=ang[i]/2./PI
		# Output the answers for all the Points
		for i in range(n):
			print("%.20f" % ans[i])
# End of code
