
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define a struct to store information about intervals
type Ban struct {
	l, r, val int
}

// A function to initialize the segment tree
func init(a []int) {
	n := len(a)
	// Initialize the first level of the segment tree
	for i := 0; i < n; i++ {
		mn[0][i] = a[i] // Store the value of the element at index i in the first level of the segment tree
	}
	// Build the segment tree recursively
	for i := 0; i+1 < lim; i++ {
		for j := 0; j+1<<i < n; j++ {
			mn[i+1][j] = max(mn[i][j], mn[i][j+1<<i]) // Find the minimum value in the current segment and store it in the next level of the segment tree
		}
	}
	// Calculate the power of 2 up to the maximum depth of the segment tree
	pw[1] = 0
	for i := 2; i < n; i++ {
		pw[i] = pw[i/2] + 1 // Calculate the power of 2 for each index
	}
}

// A function to get the minimum value in a segment of the segment tree
func get(l, r int) int {
	r++ // Adjust the index of the right endpoint of the segment to be one more than the actual index
	p := pw[r-l] // Calculate the depth of the segment tree for the given segment
	return min(mn[p][l], mn[p][r-1<<p]) // Return the minimum value in the given segment
}

// Define some variables
var (
	n, ans int
	a      []int
	dl     []int
	bans   []Ban
	mn     [lim][n]int
	pw     [n]int
)

func main() {
	// Read the number of elements in the array
	fmt.Scan(&n)

	// Read the elements of the array
	a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize some variables
	dl = make([]int, n)
	bans = make([]Ban, 0)

	// Calculate the differences between the indices and the elements in the array
	for i := 0; i < n; i++ {
		if a[i] > i { // Check if the element is out of its position
			fmt.Println(-1) // Output -1 if the element is out of its position
			return
		}
		dl[i] = i - a[i] // Calculate the difference between the index and the element
	}

	// Calculate the answer and store some information about the intervals in a vector
	for i := 0; i < n; i++ {
		r := i
		for r+1 < n && a[r] == a[r+1] { // Check if there is a longer interval with the same value
			r++ // Move to the next index if there is
		}
		ans += a[r] // Add the value of the right endpoint of the current interval to the answer
		i = r // Update the index to be the right endpoint of the current interval
		bans = append(bans, Ban{r - a[r], r, r - a[r]}) // Store some information about the current interval in the vector
	}

	// Initialize the segment tree using the differences between the indices and the elements in the array
	init(dl)

	// Check some conditions and calculate the answer if possible
	for _, t := range bans {
		if get(t.l, t.r) > t.val { // Check if the minimum value in the segment of the segment tree is greater than the value of the interval
			fmt.Println(-1) // Output -1 if the condition is not satisfied
			return
		}
	}

	// Output the answer
	fmt.Println(ans)
}

// Define a function to calculate the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a function to calculate the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Define a function to calculate the power of 2
func pow2(a int) int {
	return 1 << a
}

// Define a function to calculate the power of 10
func pow10(a int) int {
	return 10 << a
}

// Define a function to calculate the power of 100
func pow100(a int) int {
	return 100 << a
}

// Define a function to calculate the power of 1000
func pow1000(a int) int {
	return 1000 << a
}

// Define a function to calculate the power of 10000
func pow10000(a int) int {
	return 10000 << a
}

// Define a function to calculate the power of 100000
func pow100000(a int) int {
	return 100000 << a
}

// Define a function to calculate the power of 1000000
func pow1000000(a int) int {
	return 1000000 << a
}

// Define a function to calculate the power of 10000000
func pow10000000(a int) int {
	return 10000000 << a
}

// Define a function to calculate the power of 100000000
func pow100000000(a int) int {
	return 100000000 << a
}

// Define a function to calculate the power of 1000000000
func pow1000000000(a int) int {
	return 1000000000 << a
}

// Define a function to calculate the power of 10000000000
func pow10000000000(a int) int {
	return 10000000000 << a
}

// Define a function to calculate the power of 100000000000
func pow100000000000(a int) int {
	return 100000000000 << a
}

// Define a function to calculate the power of 1000000000000
func pow1000000000000(a int) int {
	return 1000000000000 << a
}

// Define a function to calculate the power of 10000000000000
func pow10000000000000(a int) int {
	return 10000000000000 << a
}

// Define a function to calculate the power of 100000000000000
func pow100000000000000(a int) int {
	return 100000000000000 << a
}

// Define a function to calculate the power of 1000000000000000
func pow1000000000000000(a int) int {
	return 1000000000000000 << a
}

// Define a function to calculate the power of 10000000000000000
func pow10000000000000000(a int) int {
	return 10000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000
func pow100000000000000000(a int) int {
	return 100000000000000000 << a
}

// Define a function to calculate the power of 1000000000000000000
func pow1000000000000000000(a int) int {
	return 1000000000000000000 << a
}

// Define a function to calculate the power of 10000000000000000000
func pow10000000000000000000(a int) int {
	return 10000000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000000
func pow100000000000000000000(a int) int {
	return 100000000000000000000 << a
}

// Define a function to calculate the power of 1000000000000000000000
func pow1000000000000000000000(a int) int {
	return 1000000000000000000000 << a
}

// Define a function to calculate the power of 10000000000000000000000
func pow10000000000000000000000(a int) int {
	return 10000000000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000000000
func pow100000000000000000000000(a int) int {
	return 100000000000000000000000 << a
}

// Define a function to calculate the power of 1000000000000000000000000
func pow1000000000000000000000000(a int) int {
	return 1000000000000000000000000 << a
}

// Define a function to calculate the power of 10000000000000000000000000
func pow10000000000000000000000000(a int) int {
	return 10000000000000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000000000000
func pow100000000000000000000000000(a int) int {
	return 100000000000000000000000000 << a
}

// Define a function to calculate the power of 1000000000000000000000000000
func pow1000000000000000000000000000(a int) int {
	return 1000000000000000000000000000 << a
}

// Define a function to calculate the power of 10000000000000000000000000000
func pow10000000000000000000000000000(a int) int {
	return 10000000000000000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000000000000000
func pow100000000000000000000000000000(a int) int {
	return 100000000000000000000000000000 << a
}

// Define a function to calculate the power of 1000000000000000000000000000000
func pow1000000000000000000000000000000(a int) int {
	return 1000000000000000000000000000000 << a
}

// Define a function to calculate the power of 10000000000000000000000000000000
func pow10000000000000000000000000000000(a int) int {
	return 10000000000000000000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000000000000000000
func pow100000000000000000000000000000000(a int) int {
	return 100000000000000000000000000000000 << a
}

// Define a function to calculate the power of 1000000000000000000000000000000000
func pow1000000000000000000000000000000000(a int) int {
	return 1000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 10000000000000000000000000000000000
func pow10000000000000000000000000000000000(a int) int {
	return 10000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000000000000000000000
func pow100000000000000000000000000000000000(a int) int {
	return 100000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 1000000000000000000000000000000000000
func pow1000000000000000000000000000000000000(a int) int {
	return 1000000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 10000000000000000000000000000000000000
func pow10000000000000000000000000000000000000(a int) int {
	return 10000000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000000000000000000000000
func pow100000000000000000000000000000000000000(a int) int {
	return 100000000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 1000000000000000000000000000000000000000
func pow1000000000000000000000000000000000000000(a int) int {
	return 1000000000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 10000000000000000000000000000000000000000
func pow10000000000000000000000000000000000000000(a int) int {
	return 10000000000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000000000000000000000000000
func pow100000000000000000000000000000000000000000(a int) int {
	return 100000000000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 100000000000000000000000000000000000000000
func pow1000000000000000000000000000000000000000000(a int) int {
	return 1000000000000000000000000000000000000000000 << a
}

// Define a function to calculate the power of 1000000000000000000000000000000000000000000
func pow10000000000000000000000000000000000000000000(a int) int {
	return 10000000000000000000000000000000000000000000 << a
}

// Define a function t