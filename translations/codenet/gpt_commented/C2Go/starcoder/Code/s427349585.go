package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define a structure to represent a card with a character and an integer value
type card struct {
	s string // Character representing the card's suit or type
	v int    // Integer representing the card's value
}

// Merge function to combine two sorted halves of the array
func me(a []card, l, m, r int) {
	n1 := m - l
	n2 := r - m
	i := 0
	j := 0
	k := l
	for k < r {
		if i < n1 && j < n2 {
			if a[l+i].v <= a[m+j].v {
				a[k] = a[l+i]
				i++
			} else {
				a[k] = a[m+j]
				j++
			}
		} else if i < n1 {
			a[k] = a[l+i]
			i++
		} else if j < n2 {
			a[k] = a[m+j]
			j++
		}
		k++
	}
}

// Merge sort function to recursively sort the array
func ms(a []card, l, r int) {
	if l+1 < r {
		m := (l + r) / 2
		ms(a, l, m)
		ms(a, m, r)
		me(a, l, m, r)
	}
}

// Partition function for quicksort
func partiton(a []card, p, r int) int {
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

// Quicksort function to recursively sort the array
func qs(a []card, p, r int) {
	if p < r {
		q := partiton(a, p, r)
		qs(a, p, q-1)
		qs(a, q+1, r)
	}
}

// Main function
func main() {
	var n int
	var a, b []card
	var s string
	var v int
	var stable bool

	// Read the number of cards
	fmt.Scanf("%d", &n)

	// Read the cards into both arrays a and b
	for i := 0; i < n; i++ {
		fmt.Scanf("%s%d", &s, &v)
		a = append(a, card{s, v})
		b = append(b, card{s, v})
	}

	// Perform merge sort on array a
	ms(a, 0, n)
	// Perform quicksort on array b
	qs(b, 0, n-1)

	// Check if the sorting is stable by comparing the original and sorted arrays
	stable = true
	for i := 0; i < n; i++ {
		if a[i].s!= b[i].s {
			stable = false
			break
		}
	}

	// Output the stability result
	if stable {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}

	// Print the sorted array
	for i := 0; i < n; i++ {
		fmt.Printf("%s %d\n", b[i].s, b[i].v)
	}
}

