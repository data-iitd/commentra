package main
import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func (p Point) String() string {
	return fmt.Sprintf("(%.2f, %.2f)", p.x, p.y)
}

func (p Point) mod() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p Point) mod_pow() float64 {
	return p.x*p.x + p.y*p.y
}

func (p Point) output() {
	fmt.Printf("x = %.2f, y = %.2f\n", p.x, p.y)
}

func (p Point) angle(o, a, b Point) float64 {
	return math.Acos(dot(o, a, b) / (o.mod()*a.mod()*b.mod()))
}

func dot(o, a, b Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

func cross(o, a, b Point) float64 {
	return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y)
}

func btw(x, a, b Point) int {
	return int(math.Copysign(1, dot(x, a, b)))
}

func dis(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
}

func cos(o, a, b Point) float64 {
	return dot(o, a, b) / dis(o, a) / dis(o, b)
}

func jarvis(p []Point) []int {
	ch := make([]int, len(p))
	d, i, o, s, l, t := 0, 0, 0, 0, 0, 0
	for i = 0; i < len(p); i++ {
		if p[i] < p[d] {
			d = i
		}
	}
	l, s = d, d
	d = 1
	for {
		o = l
		for i = 0; i < len(p); i++ {
			if (t = int(math.Copysign(1, cross(p[o], p[l], p[i])))) > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0) {
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
	var n, xx, yy int
	fmt.Scanf("%d", &n)
	p := make([]Point, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d%d", &xx, &yy)
		p[i] = Point{float64(xx), float64(yy)}
	}
	if n == 2 {
		fmt.Println("0.5")
		fmt.Println("0.5")
	} else {
		ch := jarvis(p)
		var sum float64
		if len(ch) == 2 {
			p[ch[0]].x = 0.5
			p[ch[1]].x = 0.5
		} else {
			for i := 0; i < len(ch); i++ {
				p[ch[i]].k = p[ch[(i-1+len(ch))%len(ch)]].angle(p[ch[i]], p[ch[(i+1)%len(ch)]])
			}
			for i := 0; i < len(ch); i++ {
				sum += p[ch[i]].k
			}
			for i := 0; i < len(ch); i++ {
				p[ch[i]].k /= sum
			}
		}
		for i := 0; i < len(ch); i++ {
			fmt.Printf("%.20f\n", p[ch[i]].k)
		}
	}
}

