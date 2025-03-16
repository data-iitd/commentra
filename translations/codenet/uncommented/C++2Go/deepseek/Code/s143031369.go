package main

import (
	"fmt"
	"math"
)

const PI = math.Pi

func sig(d float64) int {
	const epsilon = 1e-8
	if math.Abs(d) < epsilon {
		return 0
	} else if d < 0 {
		return -1
	} else {
		return 1
	}
}

type Point struct {
	x, y float64
	k    float64
}

func NewPoint(x, y float64) *Point {
	return &Point{x, y, 0}
}

func (p *Point) Set(x, y float64) {
	p.x = x
	p.y = y
}

func (p *Point) Mod() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p *Point) ModPow() float64 {
	return p.x*p.x + p.y*p.y
}

func (p *Point) Output() {
	fmt.Printf("x = %f, y = %f\n", p.x, p.y)
}

func (p *Point) LessThan(other *Point) bool {
	return sig(p.x-other.x) != 0 && p.x < other.x || sig(p.x-other.x) == 0 && sig(p.y-other.y) < 0
}

func Dot(o, a, b *Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

func Dot2(a, b *Point) float64 {
	return a.x*b.x + a.y*b.y
}

func Cross(o, a, b *Point) float64 {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y)
}

func Btw(x, a, b *Point) int {
	return sig(Dot(x, a, b))
}

func Dis(a, b *Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

func Cos(o, a, b *Point) float64 {
	return Dot(o, a, b) / Dis(o, a) / Dis(o, b)
}

func Jarvis(p []*Point, n int, ch []int) int {
	var d, i, o, s, l, t int
	for d, i = 0, 0; i < n; i++ {
		if p[i].LessThan(p[d]) {
			d = i
		}
	}
	l, s, ch[0] = d, d, d
	d = 1
	for {
		o = l
		for i = 0; i < n; i++ {
			if (t = sig(Cross(p[o], p[l], p[i]))) > 0 || (t == 0 && Btw(p[l], p[o], p[i]) <= 0) {
				l = i
			}
		}
		ch[d] = l
		d++
		if l == s {
			break
		}
	}
	return d
}

func main() {
	var n, xx, yy int
	fmt.Scan(&n)
	p := make([]*Point, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xx, &yy)
		p[i] = NewPoint(float64(xx), float64(yy))
	}
	if n == 2 {
		fmt.Println("0.5")
		fmt.Println("0.5")
	} else {
		ch := make([]int, n)
		m := Jarvis(p, n, ch)
		ang := make([]float64, n)
		ans := make([]float64, n)
		if m == 2 {
			ans[ch[0]] = 0.5
			ans[ch[1]] = 0.5
		} else {
			for i := 0; i < m; i++ {
				ang[ch[i]] = PI - math.Acos(Cos(p[ch[i]], p[ch[(i-1+m)%m]], p[ch[(i+1)%m]]))
			}
			for i := 0; i < n; i++ {
				ans[i] = ang[i] / 2 / PI
			}
		}
		for i := 0; i < n; i++ {
			fmt.Printf("%.20f\n", ans[i])
		}
	}
}

