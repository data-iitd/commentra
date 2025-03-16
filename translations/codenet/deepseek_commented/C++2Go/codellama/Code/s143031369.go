
package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func (p Point) String() string {
	return fmt.Sprintf("x = %f, y = %f\n", p.x, p.y)
}

func (p Point) mod() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p Point) mod_pow() float64 {
	return p.x*p.x + p.y*p.y
}

func (p Point) output() {
	fmt.Printf("x = %f, y = %f\n", p.x, p.y)
}

func (p Point) operator < (p1 Point) bool {
	return sig(p.x-p1.x) != 0 ? p.x < p1.x : sig(p.y-p1.y) < 0
}

func sig(d float64) int {
	return math.Abs(d) < 1e-8 ? 0 : d < 0 ? -1 : 1
}

func dot(o, a, b Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

func dot(a, b Point) float64 {
	return a.x*b.x + a.y*b.y //(a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
}

func cross(o, a, b Point) float64 {
	return (a.x - o.x)*(b.y - o.y) - (b.x - o.x)*(a.y - o.y)
}

func btw(x, a, b Point) int {
	return sig(dot(x, a, b))
}

func dis(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

func cos(o, a, b Point) float64 {
	return dot(o, a, b) / dis(o, a) / dis(o, b)
}

func jarvis(p []Point, n int, ch []int) int {
	var d, i, o, s, l, t int
	for i = 0; i < n; i++ {
		if p[i] < p[d] {
			d = i
		}
	}
	l = s = ch[0] = d
	d = 1
	for {
		o = l
		for i = 0; i < n; i++ {
			if t = sig(cross(p[o], p[l], p[i])); t > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0) {
				l = i
			}
		}
		ch[d] = l
		if l == s {
			break
		}
		d++
	}
	return d
}

func main() {
	var n, xx, yy int
	fmt.Scan(&n)
	p := make([]Point, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xx, &yy)
		p[i].x = float64(xx)
		p[i].y = float64(yy)
	}
	if n == 2 {
		fmt.Println("0.5")
		fmt.Println("0.5")
	} else {
		m := jarvis(p, n, ch)
		sum := 0.0
		if m == 2 {
			ans[ch[0]] = 0.5
			ans[ch[1]] = 0.5
		} else {
			for i := 0; i < m; i++ {
				ang[ch[i]] = math.Pi - math.Acos(cos(p[ch[i]], p[ch[(i-1+m)%m]], p[ch[(i+1)%m]]))
			}
			for i := 0; i < n; i++ {
				ans[i] = ang[i] / 2. / math.Pi
			}
		}
		for i := 0; i < n; i++ {
			fmt.Printf("%.20f\n", ans[i])
		}
	}
}

