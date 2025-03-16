// Import necessary libraries
import (
	"fmt"
	"math"
	"sort"
)

// Define lambda functions for input handling
I := func() []int {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return a
}

IS := func() string {
	var s string
	fmt.Scan(&s)
	return s
}

IN := func() int {
	var n int
	fmt.Scan(&n)
	return n
}

IF := func() float64 {
	var n float64
	fmt.Scan(&n)
	return n
}

// Read the number of elements
n := IN()

// Read the list of integers
l := I()

// Initialize a variable to track unique counts
f := 1
sort.Ints(l)

// Initialize a counter for unique elements
c := 0

// Iterate through the sorted list to count unique elements
for i := 0; i < len(l); i++ {
	if l[i] > c {
		c++
	}
}

// Output the total count of unique elements
fmt.Println(c + 1)

