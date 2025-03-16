
package main

import (
	"fmt"
	"math"
)

// Define a constant for PI using the arccosine function
const PI = math.Acos(-1.0)

// Function to determine the sign of a double value
func sig(d float64) int {
	return int(math.Abs(d) < 1e-8) - int(d < 0) // Returns 0 if d is close to 0, -1 if d is negative, 1 if d is positive
}

// Structure to represent a point in 2D space
type Point struct {
	x, y float64 // Coordinates of the point
	k    float64 // Additional variable (not used in this code)
}

// Default constructor
func NewPoint() Point {
	return Point{}
}

// Constructor to initialize point with coordinates
func NewPoint2(x, y float64) Point {
	return Point{x, y, 0}
}

// Method to set the coordinates of the point
func (p *Point) Set(x, y float64) {
	p.x = x
	p.y = y
}

// Method to calculate the modulus (length) of the point vector
func (p *Point) Mod() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

// Method to calculate the square of the modulus (length squared)
func (p *Point) Mod_pow() float64 {
	return p.x*p.x + p.y*p.y
}

// Method to output the coordinates of the point
func (p *Point) Output() {
	fmt.Printf("x = %f, y = %f\n", p.x, p.y)
}

// Overloaded operator to compare two points
func (p *Point) Less(q *Point) bool {
	return sig(p.x-q.x) != 0 || sig(p.y-q.y) < 0 // Compare based on x, then y
}

// Function to calculate the dot product of two vectors defined by points
func dot(o, a, b *Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

// Overloaded function to calculate the dot product of two points
func dot2(a, b *Point) float64 {
	return a.x*b.x + a.y*b.y // Standard dot product
}

// Function to calculate the cross product of two vectors defined by points
func cross(o Point, a, b *Point) float64 {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y)
}

// Function to determine if point x is between points a and b
func btw(x, a, b *Point) int {
	return sig(dot(x, a, b)) // Returns the sign of the dot product
}

// Function to calculate the distance between two points
func dis(a, b *Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) // Euclidean distance
}

// Function to calculate the cosine of the angle between two vectors
func cos(o Point, a, b *Point) float64 {
	return dot(o, a, b) / dis(o, a) / dis(o, b) // Cosine formula using dot product and distances
}

// Function to compute the convex hull using the Jarvis march algorithm
func jarvis(p []Point, n int, ch []int) int {
	var d, i, o, s, l, t int
	// Find the leftmost point to start the hull
	for d = i = 0; i < n; i++ {
		if p[i].Less(&p[d]) {
			d = i
		}
	}

	l = s = ch[0] = d // Initialize the starting point
	d = 1             // Index for the convex hull array

	// Loop to find all points in the convex hull
	for {
		o = l
		for i = 0; i < n; i++ {
			// Check if point i is more counter-clockwise than the current point l
			if (t = sig(cross(p[o], &p[l], &p[i]))) > 0 || (t == 0 && btw(&p[l], &p[o], &p[i]) <= 0) {
				l = i
			}
		}
		ch[d] = l
		d++
		if l == s {
			break
		}
	}

	return d - 1 // Return the number of points in the convex hull
}

// Main function
func main() {
	// Initialize angle and answer arrays to zero
	ang := make([]float64, 110)
	ans := make([]float64, 110)
	for i := range ang {
		ang[i] = 0
		ans[i] = 0
	}

	var n, xx, yy int // Number of points and coordinates
	fmt.Scan(&n)      // Read number of points

	// Read the coordinates of the points
	p := make([]Point, 110)
	for i := 0; i < n; i++ {
		fmt.Scan(&xx, &yy)
		p[i].Set(float64(xx), float64(yy)) // Set the coordinates for each point
	}

	// Special case for two points
	if n == 2 {
		fmt.Println("0.5") // Each point contributes equally to the area
		fmt.Println("0.5")
	} else {
		// Compute the convex hull
		m := jarvis(p, n, ch)
		sum := 0.0

		// Special case for two points in the convex hull
		if m == 2 {
			ans[ch[0]] = 0.5 // Assign equal area to both points
			ans[ch[1]] = 0.5
		} else {
			// Calculate angles for each point in the convex hull
			for i := 0; i < m; i++ {
				ang[ch[i]] = PI - math.Acos(cos(p[ch[i]], &p[ch[(i-1+m)%m]], &p[ch[(i+1)%m]]))
			}
			// Calculate the area contribution for each point
			for i := 0; i < n; i++ {
				ans[i] = ang[i] / 2. / PI // Normalize the angle to get area contribution
			}
		}

		// Output the area contributions for each point
		for i := 0; i < n; i++ {
			fmt.Printf("%.20f\n", ans[i]) // Print results with high precision
		}
	}
}

