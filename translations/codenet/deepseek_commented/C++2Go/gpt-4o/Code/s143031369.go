package main

import (
	"fmt"
	"math"
	"sort"
)

const PI = math.Pi

type Point struct {
	x, y float64
}

func (p *Point) set(x, y float64) {
	p.x = x
	p.y = y
}

func (p *Point) mod() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p *Point) modPow() float64 {
	return p.x*p.x + p.y*p.y
}

func (p *Point) output() {
	fmt.Printf("x = %f, y = %f\n", p.x, p.y)
}

func sig(d float64) int {
	if math.Abs(d) < 1e-8 {
		return 0
	} else if d < 0 {
		return -1
	}
	return 1
}

func (p Point) lessThan(other Point) bool {
	if sig(p.x-other.x) != 0 {
		return p.x < other.x
	}
	return sig(p.y-other.y) < 0
}

func dot(o, a, b Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

func dotAB(a, b Point) float64 {
	return a.x*b.x + a.y*b.y
}

func cross(o, a, b Point) float64 {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y)
}

func btw(x, a, b Point) int {
	return sig(dot(x, a, b))
}

func dis(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

func cos(o, a, b Point) float64 {
	return dot(o, a, b) / (dis(o, a) * dis(o, b))
}

func jarvis(p []Point, n int) []int {
	ch := make([]int, n)
	d := 0
	for i := 1; i < n; i++ {
		if p[i].lessThan(p[d]) {
			d = i
		}
	}
	l := d
	s := d
	ch[0] = d
	d = 1

	for {
		o := l
		for i := 0; i < n; i++ {
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
	return ch[:d]
}

func main() {
	var n int
	fmt.Scan(&n)

	P := make([]Point, n)
	for i := 0; i < n; i++ {
		var xx, yy int
		fmt.Scan(&xx, &yy)
		P[i].set(float64(xx), float64(yy))
	}

	if n == 2 {
		fmt.Println("0.5")
		fmt.Println("0.5")
	} else {
		ch := jarvis(P, n)
		ang := make([]float64, n)
		ans := make([]float64, n)

		m := len(ch)
		if m == 2 {
			ans[ch[0]] = 0.5
			ans[ch[1]] = 0.5
		} else {
			for i := 0; i < m; i++ {
				ang[ch[i]] = PI - math.Acos(cos(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]]))
			}
			for i := 0; i < n; i++ {
				ans[i] = ang[i] / 2.0 / PI
			}
		}
		for i := 0; i < n; i++ {
			fmt.Printf("%.20f\n", ans[i])
		}
	}
}

// <END-OF-CODE>
