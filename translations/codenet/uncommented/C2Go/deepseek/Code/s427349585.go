package main

import (
	"fmt"
)

type card struct {
	s string
	v int
}

func merge(a []card, n, l, m, r int) {
	n1 := m - l
	n2 := r - m
	L := make([]card, n1+1)
	R := make([]card, n2+1)
	for i := 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i := 0; i < n2; i++ {
		R[i] = a[m+i]
	}
	L[n1] = card{"Z", 2000000000}
	R[n2] = card{"Z", 2000000000}
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

func mergeSort(a []card, n, l, r int) {
	if l+1 < r {
		m := (l + r) / 2
		mergeSort(a, n, l, m)
		mergeSort(a, n, m, r)
		merge(a, n, l, m, r)
	}
}

func partition(a []card, n, p, r int) int {
	x := a[r]
	i := p - 1
	for j := p; j < r; j++ {
		if a[j].v <= x.v {
			i++
			a[i], a[j] = a[j], a[i]
		}
	}
	a[i+1], a[r] = a[r], a[i+1]
	return i + 1
}

func quickSort(a []card, n, p, r int) {
	if p < r {
		q := partition(a, n, p, r)
		quickSort(a, n, p, q-1)
		quickSort(a, n, q+1, r)
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]card, n)
	b := make([]card, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].s, &a[i].v)
		b[i] = a[i]
	}
	mergeSort(a, n, 0, n)
	quickSort(b, n, 0, n-1)
	stable := true
	for i := 0; i < n; i++ {
		if a[i].s != b[i].s {
			stable = false
		}
	}
	if stable {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}
	for i := 0; i < n; i++ {
		fmt.Printf("%s %d\n", b[i].s, b[i].v)
	}
}

