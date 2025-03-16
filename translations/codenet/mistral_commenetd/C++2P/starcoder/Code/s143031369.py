# Include necessary libraries
from math import *
# Define a constant value
PI=acos(-1.0)
# Define a function to determine the sign of a double value
def sig(d):
	if(fabs(d)<1e-8):
		return 0
	elif(d<0):
		return -1
	else:
		return 1
# Define a Point structure
class Point:
	def __init__(self,x,y):
		self.x=x
		self.y=y
	# Set x and y coordinates
	def set(self,x,y):
		self.x=x
		self.y=y
	# Calculate the modulus of a Point
	def mod(self):
		return sqrt(self.x*self.x+self.y*self.y)
	# Calculate the modulus squared of a Point
	def mod_pow(self):
		return self.x*self.x + self.y*self.y
	# Output the x and y coordinates of a Point
	def output(self):
		print("x = %f, y = %f"%(self.x,self.y))
	# Compare two Points based on their x and y coordinates
	def __lt__(self,p):
		if(sig(self.x-p.x)!=0):
			return self.x<p.x
		else:
			return sig(self.y-p.y)<0
# Define an array of Points P
P=[Point(0,0) for i in range(110)]
# Define an array ch to store the indices of the points in the convex hull
ch=[0 for i in range(110)]
# Define arrays ang and ans to store the angles and answers respectively
ang=[0 for i in range(110)]
ans=[0 for i in range(110)]
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
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
# Calculate the cosine of the angle between a line passing through two Points and a given Point
def cos(o,a,b):
	return dot(o,a,b)/dis(o,a)/dis(o,b)
# Find the convex hull of a set of Points using Jarvis March algorithm
def jarvis(p,n,ch):
	d,i,o,s,l,t=0,0,0,0,0,0
	for i in range(n):
		if(p[i]<p[d]):
			d=i
	l=s=ch[0]=d
	d=1
	while(l!=s):
		o=l
		for i in range(n):
			if((t=sig(cross(p[o],p[l],p[i])))>0 or (t==0 and btw(p[l],p[o],p[i])<=0)):
				l=i
		ch[d]=l
		d+=1
	return d-1
# Main function to read input and calculate the answers
def main():
	# Read the number of Points
	n=int(input())
	# Initialize the Points
	for i in range(n):
		xx,yy=map(int,input().split())
		# Set the x and y coordinates of the Point
		P[i].set(xx,yy)
	# Special case for 2 Points
	if(n==2):
		# Output the answers
		print("0.5")
		print("0.5")
	else:
		# Find the convex hull of the Points
		m=jarvis(P,n,ch)
		# Calculate the angles for the Points in the convex hull
		if(m==2):
			# Set the answers for the first and second Points
			ans[ch[0]]=0.5
			ans[ch[1]]=0.5
		else:
			# Calculate the angles for all the Points in the convex hull
			for i in range(m):
				ang[ch[i]]=PI-acos(cos(P[ch[i]],P[ch[(i-1+m)%m]],P[ch[(i+1)%m]]))
			# Calculate the answers for all the Points
			for i in range(n):
				ans[i]=ang[i]/2./PI
		# Output the answers for all the Points
		for i in range(n):
			print("%.20f"%ans[i])
# Call the main function
main()

