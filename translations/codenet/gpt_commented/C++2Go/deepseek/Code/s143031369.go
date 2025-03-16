package main

import (
	"fmt"
	"math"
)

const PI = math.Pi

// Function to determine the sign of a double value
func sig(d float64) int {
	if math.Abs(d) < 1e-8 {
		return 0
	} else if d < 0 {
		return -1
	} else {
		return 1
	}
}

// Structure to represent a point in 2D space
type Point struct {
	x, y float64
	k    float64
}

// Method to set the coordinates of the point
func (p *Point) set(x, y float64) {
	p.x = x
	p.y = y
}

// Method to calculate the modulus (length) of the point vector
func (p Point) mod() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

// Method to calculate the square of the modulus (length squared)
func (p Point) mod_pow() float64 {
	return p.x*p.x + p.y*p.y
}

// Method to output the coordinates of the point
func (p Point) output() {
	fmt.Printf("x = %f, y = %f\n", p.x, p.y)
}

// Overloaded operator to compare two points
func (p Point) lessThan(other Point) bool {
	if sig(p.x - other.x) != 0 {
		return p.x < other.x
	}
	return sig(p.y - other.y) < 0
}

// Function to calculate the dot product of two vectors defined by points
func dot(o, a, b Point) float64 {
	return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y)
}

// Overloaded function to calculate the dot product of two points
func dot(a, b Point) float64 {
	return a.x * b.x + a.y * b.y
}

// Function to calculate the cross product of two vectors defined by points
func cross(o, a, b Point) float64 {
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y)
}

// Function to determine if point x is between points a and b
func btw(x, a, b Point) int {
	return sig(dot(x, a, b))
}

// Function to calculate the distance between two points
func dis(a, b Point) float64 {
	return math.Sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))
}

// Function to calculate the cosine of the angle between two vectors
func cos(o, a, b Point) float64 {
	return dot(o, a, b) / dis(o, a) / dis(o, b)
}

// Function to compute the convex hull using the Jarvis march algorithm
func jarvis(p []Point, n int, ch []int) int {
	d, i, o, s, l, t := 0, 0, 0, 0, 0, 0
	// Find the leftmost point to start the hull
	for i = 0; i < n; i++ {
		if p[i].lessThan(p[d]) {
			d = i
		}
	}
	l, s, ch[0] = d, d, d
	d = 1

	// Loop to find all points in the convex hull
	for {
		o = l
		for i = 0; i < n; i++ {
			if t = sig(cross(p[o], p[l], p[i])); t > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0) {
				l = i
			}
		}
		ch[d] = l
		d++
		if l == s {
			break
		}
	}
	return d - 1
}

func main() {
	var n, xx, yy int
	var P [110]Point
	var ch [110]int
	var ang, ans [110]float64

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xx, &yy)
		P[i].set(float64(xx), float64(yy))
	}

	if n == 2 {
		fmt.Println("0.5")
		fmt.Println("0.5")
	} else {
		m := jarvis(P[:], n, ch[:])
		if m == 2 {
			ans[ch[0]] = 0.5
			ans[ch[1]] = 0.5
		} else {
			for i := 0; i < m; i++ {
				ang[ch[i]] = PI - math.Acos(float64(cos(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]])))
			}
			for i := 0; i < n; i++ {
				ans[i] = ang[i] / 2. / PI
			}
		}
		for i := 0; i < n; i++ {
			fmt.Printf("%.20f\n", ans[i])
		}
	}
}

