<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define the card structure
type card struct {
	s string
	v int
}

// Merge function to merge two subarrays
func me(a []card, l, m, r int) {
	n1 := m - l
	n2 := r - m
	L := make([]card, n1)
	R := make([]card, n2)
	for i := 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i := 0; i < n2; i++ {
		R[i] = a[m+i]
	}
	L[n1].v = R[n2].v = 2000000000
	i := 0
	j := 0
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

// Merge sort function to sort the array
func ms(a []card, l, r int) {
	if l+1 < r {
		m := (l + r) / 2
		ms(a, l, m)
		ms(a, m, r)
		me(a, l, m, r)
	}
}

// Partition function to partition the array around a pivot
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

// Quick sort function to sort the array
func qs(a []card, p, r int) {
	if p < r {
		q := partition(a, p, r)
		qs(a, p, q-1)
		qs(a, q+1, r)
	}
}

// Main function to read input, sort the arrays, check for stability, and print the result
func main() {
	var n int
	var a, b []card
	var s string
	var v int
	var stable bool
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s%d", &s, &v)
		a = append(a, card{s, v})
		b = append(b, card{s, v})
	}
	ms(a, 0, n)
	qs(b, 0, n-1)
	stable = true
	for i := 0; i < n; i++ {
		if a[i].s!= b[i].s {
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

