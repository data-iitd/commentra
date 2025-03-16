package main

import (
	"fmt"
)

type card struct {
	s byte
	v int
}

var L, R [100000/2 + 2]card

func me(a []card, l, m, r int) {
	n1 := m - l
	n2 := r - m

	for i := 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i := 0; i < n2; i++ {
		R[i] = a[m+i]
	}
	L[n1].v = 2000000000
	R[n2].v = 2000000000

	i, j := 0, 0
	for k := l; k < r; k++ {
		if L[i].v <= R[j].v {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
		}
	}
}

func ms(a []card, l, r int) {
	if l+1 < r {
		m := (l + r) / 2
		ms(a, l, m)
		ms(a, m, r)
		me(a, l, m, r)
	}
}

func partition(a []card, p, r int) int {
	i := p - 1
	x := a[r]

	for j := p; j < r; j++ {
		if a[j].v <= x.v {
			i++
			a[i], a[j] = a[j], a[i]
		}
	}
	a[i+1], a[r] = a[r], a[i+1]
	return i + 1
}

func qs(a []card, p, r int) {
	if p < r {
		q := partition(a, p, r)
		qs(a, p, q-1)
		qs(a, q+1, r)
	}
}

func main() {
	var n int
	var v int
	var s string
	stable := 1

	fmt.Scan(&n)

	a := make([]card, n)
	b := make([]card, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&s, &v)
		a[i].s = s[0]
		b[i].s = s[0]
		a[i].v = v
		b[i].v = v
	}

	ms(a, 0, n)
	qs(b, 0, n-1)

	for i := 0; i < n; i++ {
		if a[i].s != b[i].s {
			stable = 0
		}
	}
	if stable == 1 {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}
	for i := 0; i < n; i++ {
		fmt.Printf("%c %d\n", b[i].s, b[i].v)
	}
}

// <END-OF-CODE>
