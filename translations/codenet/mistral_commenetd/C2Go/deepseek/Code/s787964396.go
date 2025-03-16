package main

import (
	"fmt"
	"unsafe"
)

const I = 10000

func main() {
	var a, b []int
	var i, max, n int

	fmt.Print("Enter the number of elements: ")
	fmt.Scan(&n)

	a = make([]int, n+1)
	b = make([]int, n+1)

	fmt.Printf("Enter %d integers:\n", n)
	for i = 0; i < n; i++ {
		fmt.Scan(&a[i+1])
		if a[i+1] > max {
			max = a[i+1]
		}
	}

	CountingSort(a, b, n)

	fmt.Print(b[1])
	for i = 2; i < n+1; i++ {
		fmt.Printf(" %d", b[i])
	}
	fmt.Println()
}

func CountingSort(a, b []int, k int) {
	var c [I]int
	var i, j int

	for i = 0; i <= I; i++ {
		c[i] = 0
	}

	for j = 0; j < k; j++ {
		c[a[j+1]]++
	}

	for i = 1; i < I+1; i++ {
		c[i] += c[i-1]
	}

	for j = k; j > 0; j-- {
		b[c[a[j]]] = a[j]
		c[a[j]]--
	}
}

