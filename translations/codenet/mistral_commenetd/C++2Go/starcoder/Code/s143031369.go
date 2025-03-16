
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Define a constant PI
const PI = math.Pi

// Define a Point structure
type Point struct {
	x, y float64
}

// Define a function to determine the sign of a float64 value
func sig(d float64) int {
	if math.Abs(d) < 1e-8 {
		return 0
	} else if d < 0 {
		return -1
	} else {
		return 1
	}
}

// Define a function to calculate the dot product of three Points
func dot(o, a, b Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

// Define a function to calculate the cross product of a Point and two other Points
func cross(o, a, b Point) float64 {
	return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y)
}

// Define a function to check if a Point is between two other Points on the counterclockwise arc
func btw(x, a, b Point) int {
	return sig(dot(x, a, b))
}

// Define a function to calculate the distance between two Points
func dis(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
}

// Define a function to calculate the cosine of the angle between a line passing through two Points and a given Point
func cos(o, a, b Point) float64 {
	return dot(o, a, b) / dis(o, a) / dis(o, b)
}

// Define a function to find the convex hull of a set of Points using Jarvis March algorithm
func jarvis(p []Point) []Point {
	var (
		d, i, o, s, l, t int
		ch               []Point
	)
	for d = i = 0; i < len(p); i++ {
		if p[i].x < p[d].x {
			d = i
<<<<<<< HEAD
=======
		} else if p[i].x == p[d].x && p[i].y < p[d].y {
			d = i
>>>>>>> 98c87cb78a (data updated)
		}
	}
	l = s = ch[0] = d
	d = 1
	for {
		o = l
		for i = 0; i < len(p); i++ {
			if (t = sig(cross(p[o], p[l], p[i]))) > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0) {
				l = i
			}
		}
<<<<<<< HEAD
		ch[d] = p[l]
=======
		ch[d] = l
>>>>>>> 98c87cb78a (data updated)
		d++
		if l == s {
			break
		}
	}
	return ch[:d]
}

// Define a function to read input and calculate the answers
func main() {
	var (
		n, m int
		xx, yy float64
		p []Point
		ch []Point
		ang []float64
		ans []float64
	)
	// Read the number of Points
	fmt.Scanf("%d", &n)
	// Initialize the Points
	for i := 0; i < n; i++ {
		fmt.Scanf("%d%d", &xx, &yy)
		// Set the x and y coordinates of the Point
		p = append(p, Point{xx, yy})
	}
	// Special case for 2 Points
	if n == 2 {
		// Output the answers
		fmt.Println("0.5")
		fmt.Println("0.5")
	} else {
		// Find the convex hull of the Points
		ch = jarvis(p)
		// Calculate the angles for the Points in the convex hull
		if m = len(ch); m == 2 {
			// Set the answers for the first and second Points
			ans[ch[0]] = 0.5
			ans[ch[1]] = 0.5
		} else {
			// Calculate the angles for all the Points in the convex hull
			for i := 0; i < m; i++ {
				ang[ch[i]] = PI - math.Acos(cos(p[ch[i]], p[ch[(i-1+m)%m]], p[ch[(i+1)%m]]))
			}
			// Calculate the answers for all the Points
			for i := 0; i < n; i++ {
				ans[i] = ang[i] / 2. / PI
			}
		}
		// Output the answers for all the Points
		for i := 0; i < n; i++ {
			fmt.Printf("%.20f\n", ans[i])
		}
	}
}

