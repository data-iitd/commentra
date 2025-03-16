// Include necessary libraries
import java.util.*;
import java.lang.*;
import java.io.*;
// Define a Point class
class Point {
	double x, y;
	double k;
	// Default constructor
	Point(){}
	// Constructor with x and y coordinates
	Point(double x, double y){
		this.x = x;
		this.y = y;
	}
	// Set x and y coordinates
	void set(double x, double y){
		this.x = x;
		this.y = y;
	}
	// Calculate the modulus of a Point
	double mod(){
		return Math.sqrt(x*x+y*y);
	}
	// Calculate the modulus squared of a Point
	double mod_pow(){
		return x*x + y*y;
	}
	// Output the x and y coordinates of a Point
	void output(){
		System.out.println("x = " + x + ", y = " + y);
	}
	// Compare two Points based on their x and y coordinates
	boolean operator < (Point p){
		return sig(x-p.x) != 0 ? x < p.x : sig(y-p.y) < 0;
	}
}
// Define an array of Points P
Point P[] = new Point[110];
// Define an array ch to store the indices of the points in the convex hull
int ch[] = new int[110];
// Define arrays ang and ans to store the angles and answers respectively
double ang[] = new double[110];
double ans[] = new double[110];
// Calculate the dot product of three Points
double dot(Point o, Point a, Point b){
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
}
// Calculate the cross product of a Point and two other Points
double cross(Point o, Point a, Point b){
	return (a.x - o.x)*(b.y - o.y)-(b.x - o.x)*(a.y - o.y);
}
// Check if a Point is between two other Points on the counterclockwise arc
int btw(Point x, Point a, Point b){
	return sig(dot(x, a, b));
}
// Calculate the distance between two Points
double dis(Point a, Point b){
	return Math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
// Calculate the cosine of the angle between a line passing through two Points and a given Point
double cos(Point o, Point a, Point b){
	return dot(o,a,b)/dis(o,a)/dis(o,b);
}
// Find the convex hull of a set of Points using Jarvis March algorithm
int jarvis(Point p[], int n, int ch[]){
	int d, i, o, s, l, t;
	for(d = i = 0; i < n; i ++)
		if(p[i] < p[d])
			d = i;
	l = s = ch[0] = d;
	d = 1;
	do {
		o = l;
		for(i = 0; i < n; i ++)
			if((t=sig(cross(p[o], p[l], p[i])))>0 || (t==0 && btw(p[l], p[o], p[i])<=0))
				l = i;
		ch[d ++] = l;
	} while(l != s); 
	return d-1;
}
// Main function to read input and calculate the answers
public static void main(String[] args) {
	// Initialize the arrays
	for(int i=0;i<110;i++){
		ang[i]=0;
		ans[i]=0;
	}
	// Read the number of Points
	int n;
	Scanner sc = new Scanner(System.in);
	n = sc.nextInt();
	// Initialize the Points
	for(int i=0;i<n;i++){
		int xx = sc.nextInt();
		int yy = sc.nextInt();
		// Set the x and y coordinates of the Point
		P[i] = new Point(xx,yy);
	}
	// Special case for 2 Points
	if(n==2){
		// Output the answers
		System.out.println("0.5");
		System.out.println("0.5");
	}else{
		// Find the convex hull of the Points
		int m=jarvis(P,n,ch);
		// Calculate the angles for the Points in the convex hull
		if(m==2){
			// Set the answers for the first and second Points
			ans[ch[0]]=0.5;
			ans[ch[1]]=0.5;
		}else{
			// Calculate the angles for all the Points in the convex hull
			for(int i=0;i<m;i++){
				ang[ch[i]]=Math.PI-Math.acos(cos(P[ch[i]],P[ch[(i-1+m)%m]],P[ch[(i+1)%m]]));
			}
			// Calculate the answers for all the Points
			for(int i=0;i<n;i++){
				ans[i]=ang[i]/2./Math.PI;
			}
		}
		// Output the answers for all the Points
		for(int i=0;i<n;i++){
			System.out.println(ans[i]);
		}
	}
	// Return 0 to indicate successful execution
	return 0;
}

