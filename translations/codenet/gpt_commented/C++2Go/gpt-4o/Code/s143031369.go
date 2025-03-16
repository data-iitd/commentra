package main

import (
	"fmt"
	"math"
	"sort"
)

const PI = math.Acos(-1.0)

// Function to determine the sign of a float64 value
func sig(d float64) int {
	if math.Abs(d) < 1e-8 {
		return 0
	} else if d < 0 {
		return -1
	}
	return 1
}

// Structure to represent a point in 2D space
type Point struct {
	x, y float64
}

// Method to calculate the modulus (length) of the point vector
func (p Point) mod() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

// Method to calculate the square of the modulus (length squared)
func (p Point) modPow() float64 {
	return p.x*p.x + p.y*p.y
}

// Method to output the coordinates of the point
func (p Point) output() {
	fmt.Printf("x = %f, y = %f\n", p.x, p.y)
}

// Function to calculate the dot product of two vectors defined by points
func dot(o, a, b Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

// Function to calculate the cross product of two vectors defined by points
func cross(o, a, b Point) float64 {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y)
}

// Function to determine if point x is between points a and b
func btw(x, a, b Point) int {
	return sig(dot(x, a, b))
}

// Function to calculate the distance between two points
func dis(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

// Function to calculate the cosine of the angle between two vectors
func cos(o, a, b Point) float64 {
	return dot(o, a, b) / dis(o, a) / dis(o, b)
}

// Function to compute the convex hull using the Jarvis march algorithm
func jarvis(p []Point, n int) []int {
	ch := make([]int, 0, n)
	d := 0

	// Find the leftmost point to start the hull
	for i := 1; i < n; i++ {
		if p[i].x < p[d].x || (p[i].x == p[d].x && p[i].y < p[d].y) {
			d = i
		}
	}

	l := d
	ch = append(ch, l)

	// Loop to find all points in the convex hull
	for {
		o := l
		for i := 0; i < n; i++ {
			if t := sig(cross(p[o], p[l], p[i])); t > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0) {
				l = i
			}
		}
		if l == d {
			break
		}
		ch = append(ch, l)
	}

	return ch
}

// Main function
func main() {
	var n int
	fmt.Scan(&n) // Read number of points

	P := make([]Point, n)

	// Read the coordinates of the points
	for i := 0; i < n; i++ {
		var xx, yy int
		fmt.Scan(&xx, &yy)
		P[i] = Point{float64(xx), float64(yy)} // Set the coordinates for each point
	}

	// Special case for two points
	if n == 2 {
		fmt.Println("0.5")
		fmt.Println("0.5")
		return
	}

	// Compute the convex hull
	ch := jarvis(P, n)
	m := len(ch)
	ang := make([]float64, n)
	ans := make([]float64, n)

	// Special case for two points in the convex hull
	if m == 2 {
		ans[ch[0]] = 0.5 // Assign equal area to both points
		ans[ch[1]] = 0.5
	} else {
		// Calculate angles for each point in the convex hull
		for i := 0; i < m; i++ {
			ang[ch[i]] = PI - math.Acos(cos(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]]))
		}
		// Calculate the area contribution for each point
		for i := 0; i < n; i++ {
			ans[i] = ang[i] / 2.0 / PI // Normalize the angle to get area contribution
		}
	}

	// Output the area contributions for each point
	for i := 0; i < n; i++ {
		fmt.Printf("%.20f\n", ans[i]) // Print results with high precision
	}
}

// <END-OF-CODE>
