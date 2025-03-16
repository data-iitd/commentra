package main

import (
	"fmt"
	"sort"
)

// Define a large prime number for modulo operations
const mod = 1000000007

// Direction vectors for potential grid movements (not used in this code)
var DX = []int{ -1, 0, 1, 0 }
var DY = []int{ 0, -1, 0, 1 }

// Variables to store the number of elements, a threshold value, and the array of long integers
var n int
var k int64
var a []int64

func main() {
	// Initialize scanner for input
	var fs = bufio.NewScanner(os.Stdin)

	// Read the number of elements and the threshold value k
	fs.Scan()
	n, _ = strconv.Atoi(fs.Text())
	fs.Scan()
	k, _ = strconv.ParseInt(fs.Text(), 10, 64)

	// Initialize the array to hold the long integers
	a = make([]int64, n)

	// Read the elements into the array
	for i := 0; i < n; i++ {
		fs.Scan()
		a[i], _ = strconv.ParseInt(fs.Text(), 10, 64)
	}

	// Sort the array to facilitate binary search
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })

	// Define a large value for infinity
	var INF int64 = 1000000000000000000 + 1

	// Set the initial bounds for binary search
	var l int64 = -INF
	var r int64 = INF

	// Perform binary search to find the maximum value satisfying the condition
	for l+1 < r {
		c := (l + r) / 2
		if check(c) {
			l = c
		} else {
			r = c
		}
	}

	// Output the result
	fmt.Println(l)
}

// Function to check if a certain value x can be achieved
func check(x int64) bool {
	var tot int64 = 0 // Total count of valid pairs

	// Iterate through each element in the array
	for i := 0; i < n; i++ {
		now := a[i] // Current element
		l := 0      // Initialize binary search bounds
		r := n

		// If the current element is non-negative
		if now >= 0 {
			// Perform binary search to count valid pairs
			for l < r {
				c := (l + r) / 2
				if now*a[c] < x {
					l = c + 1 // Move right if the product is less than x
				} else {
					r = c // Move left otherwise
				}
			}
			tot += int64(l) // Add the count of valid pairs
		} else {
			// If the current element is negative
			for l < r {
				c := (l + r) / 2
				if now*a[c] >= x {
					l = c + 1 // Move right if the product is greater than or equal to x
				} else {
					r = c // Move left otherwise
				}
			}
			tot += int64(n - l) // Count valid pairs with negative current element
		}

		// Adjust total count if the product of the element with itself is less than x
		if now*now < x {
			tot--
		}
	}

	// Return true if the total count of pairs is less than k
	if tot/2 < k {
		return true
	} else {
		return false
	}
}

