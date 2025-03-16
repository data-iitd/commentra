package main

import (
	"fmt"
	"math"
)

// Define a constant value
const PI = math.Pi

// Define a function to determine the sign of a double value
func sig(d float64) int {
	if math.Abs(d) < 1e-8 {
		return 0
	} else if d < 0 {
		return -1
	} else {
		return 1
	}
}

// Define a Point structure
type Point struct {
	x, y float64
	k    float64
}

// Default constructor
func NewPoint(x, y float64) *Point {
	return &Point{x, y, 0}
}

// Set x and y coordinates
func (p *Point) set(x, y float64) {
	p.x = x
	p.y = y
}

// Calculate the modulus of a Point
func (p *Point) mod() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

// Calculate the modulus squared of a Point
func (p *Point) mod_pow() float64 {
	return p.x*p.x + p.y*p.y
}

// Output the x and y coordinates of a Point
func (p *Point) output() {
	fmt.Printf("x = %f, y = %f\n", p.x, p.y)
}

// Compare two Points based on their x and y coordinates
func (p *Point) lessThan(other *Point) bool {
	if sig(p.x-other.x) != 0 {
		return p.x < other.x
	}
	return sig(p.y-other.y) < 0
}

// Calculate the dot product of three Points
func dot(o, a, b *Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

// Calculate the cross product of a Point and two other Points
func cross(o, a, b *Point) float64 {
	return (a.x - o.x)*(b.y - o.y) - (b.x - o.x)*(a.y - o.y)
}

// Check if a Point is between two other Points on the counterclockwise arc
func btw(x, a, b *Point) int {
	return sig(dot(x, a, b))
}

// Calculate the distance between two Points
func dis(a, b *Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

// Calculate the cosine of the angle between a line passing through two Points and a given Point
func cos(o, a, b *Point) float64 {
	return dot(o, a, b) / dis(o, a) / dis(o, b)
}

// Find the convex hull of a set of Points using Jarvis March algorithm
func jarvis(p []*Point, n int, ch []int) int {
	d, i, o, s, l := 0, 0, 0, 0, 0
	for i = 0; i < n; i++ {
		if p[i].lessThan(p[d]) {
			d = i
		}
	}
	l = s = ch[0] = d
	d = 1
	for {
		o = l
		for i = 0; i < n; i++ {
			t := sig(cross(p[o], p[l], p[i]))
			if t > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0) {
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
	var n int
	var xx, yy float64
	fmt.Scan(&n)
	p := make([]*Point, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xx, &yy)
		p[i] = NewPoint(xx, yy)
	}
	if n == 2 {
		fmt.Println("0.5")
		fmt.Println("0.5")
	} else {
		ch := make([]int, n)
		m := jarvis(p, n, ch)
		if m == 2 {
			fmt.Println("0.5")
			fmt.Println("0.5")
		} else {
			ang := make([]float64, n)
			ans := make([]float64, n)
			for i := 0; i < m; i++ {
				ang[ch[i]] = PI - math.Acos(cos(p[ch[i]], p[ch[(i-1+m)%m]], p[ch[(i+1)%m]]))
			}
			for i := 0; i < n; i++ {
				ans[i] = ang[i] / 2. / PI
				fmt.Printf("%.20f\n", ans[i])
			}
		}
	}
}

