package main

import (
	"fmt"
	"math"
	"sort"
)

// Define a constant value
const PI = math.Pi

// Define a Point structure
type Point struct {
	x, y float64
}

// Calculate the modulus of a Point
func (p Point) mod() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

// Calculate the modulus squared of a Point
func (p Point) modPow() float64 {
	return p.x*p.x + p.y*p.y
}

// Output the x and y coordinates of a Point
func (p Point) output() {
	fmt.Printf("x = %f, y = %f\n", p.x, p.y)
}

// Compare two Points based on their x and y coordinates
func (p Point) lessThan(other Point) bool {
	if math.Abs(p.x-other.x) > 1e-8 {
		return p.x < other.x
	}
	return p.y < other.y
}

// Calculate the dot product of three Points
func dot(o, a, b Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

// Calculate the cross product of a Point and two other Points
func cross(o, a, b Point) float64 {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y)
}

// Check if a Point is between two other Points on the counterclockwise arc
func btw(x, a, b Point) int {
	return sign(dot(x, a, b))
}

// Calculate the distance between two Points
func dis(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

// Calculate the cosine of the angle between a line passing through two Points and a given Point
func cos(o, a, b Point) float64 {
	return dot(o, a, b) / (dis(o, a) * dis(o, b))
}

// Determine the sign of a double value
func sign(d float64) int {
	if math.Abs(d) < 1e-8 {
		return 0
	} else if d < 0 {
		return -1
	}
	return 1
}

// Find the convex hull of a set of Points using Jarvis March algorithm
func jarvis(p []Point, n int) []int {
	var ch []int
	d := 0
	for i := 1; i < n; i++ {
		if p[i].lessThan(p[d]) {
			d = i
		}
	}
	l := d
	ch = append(ch, d)
	d = 1
	for {
		o := l
		for i := 0; i < n; i++ {
			t := sign(cross(p[o], p[l], p[i]))
			if t > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0) {
				l = i
			}
		}
		if l == ch[0] {
			break
		}
		ch = append(ch, l)
		d++
	}
	return ch
}

// Main function to read input and calculate the answers
func main() {
	var n int
	fmt.Scan(&n)

	P := make([]Point, n)
	ang := make([]float64, n)
	ans := make([]float64, n)

	// Initialize the Points
	for i := 0; i < n; i++ {
		var xx, yy float64
		fmt.Scan(&xx, &yy)
		P[i] = Point{xx, yy}
	}

	// Special case for 2 Points
	if n == 2 {
		fmt.Println("0.5")
		fmt.Println("0.5")
		return
	}

	// Find the convex hull of the Points
	ch := jarvis(P, n)
	m := len(ch)

	// Calculate the angles for the Points in the convex hull
	if m == 2 {
		ans[ch[0]] = 0.5
		ans[ch[1]] = 0.5
	} else {
		for i := 0; i < m; i++ {
			ang[ch[i]] = PI - math.Acos(cos(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]]))
		}
		// Calculate the answers for all the Points
		for i := 0; i < n; i++ {
			ans[i] = ang[i] / 2.0 / PI
		}
	}

	// Output the answers for all the Points
	for i := 0; i < n; i++ {
		fmt.Printf("%.20f\n", ans[i])
	}
}

// <END-OF-CODE>
