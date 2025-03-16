package main

import (
	"fmt"
	"sort"
)

const N = 200010

func read() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}

func writeln(x int64) {
	fmt.Println(x)
}

func main() {
	var n int64
	n = read()

	a := make([]int64, N)
	q := make([]int64, N)
	tot := int64(0)

	// Reading array 'a'
	for i := int64(1); i <= n; i++ {
		a[i] = read()
	}

	// Sorting array 'a' in ascending order
	sort.Slice(a[1:n+1], func(i, j int) bool {
		return a[i+1] < a[j+1]
	})

	// Finding duplicate elements and storing them in 'q'
	for i := int64(1); i <= n; i++ {
		if a[i] == a[i+1] { // Checking if current element is same as next element
			q[tot+1] = a[i] // If yes, storing it in 'q'
			tot++
			i++ // Incrementing index 'i'
		}
	}

	// Outputting the result
	writeln(q[tot] * q[tot-1])
}

// <END-OF-CODE>
