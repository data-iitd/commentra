package main

import (
	"fmt"
	"sort"
)

const mod = 1e9 + 7 // Defining a constant value for modulo arithmetic

var DX = []int{-1, 0, 1, 0} // Defining the four directions for BFS/DFS
var DY = []int{0, -1, 0, 1}

var n int       // Number of elements in the array 'a'
var k int64     // A given value
var a []int64   // The array to be processed

func main() {
	var INF int64 = 1e18 + 1 // Defining a large constant value for the upper bound of the binary search range
	var l, r int64 = -INF, INF // Initializing the binary search range

	fmt.Scan(&n) // Reading the number of elements in the array 'a'
	fmt.Scan(&k) // Reading the given value 'k'
	a = make([]int64, n) // Allocating memory for the array 'a'

	for i := 0; i < n; i++ { // Reading the elements of the array 'a'
		fmt.Scan(&a[i])
	}

	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] }) // Sorting the elements of the array 'a' in ascending order

	for l+1 < r { // Performing binary search to find the answer
		c := (l + r) / 2
		if check(c) {
			l = c // If the condition is satisfied, update the lower bound
		} else {
			r = c // Otherwise, update the upper bound
		}
	}

	fmt.Println(l) // Printing the answer
}

func check(x int64) bool { // A helper function to check if the condition is satisfied
	var tot int64 = 0 // Initializing a variable to store the total number of elements that can be covered

	for i := 0; i < n; i++ { // Iterating through all the elements in the array 'a'
		now := a[i] // Reading the current element
		l, r := 0, n // Initializing the left and right indices for the binary search

		if now >= 0 { // If the current element is non-negative
			for l < r { // Performing binary search to find the index 'c'
				c := (l + r) / 2
				if now*a[c] < x {
					l = c + 1 // Update the left index
				} else {
					r = c // Update the right index
				}
			}
			tot += int64(l) // Adding the index 'l' to the total number of elements that can be covered
		} else { // If the current element is negative
			for l < r { // Performing binary search to find the index 'c'
				c := (l + r) / 2
				if now*a[c] >= x {
					l = c + 1 // Update the left index
				} else {
					r = c // Update the right index
				}
			}
			tot += int64(n - l) // Adding the remaining elements to the total number of elements that can be covered
		}

		if now*now < x {
			tot-- // Decrement the total number of elements that can be covered
		}

		if tot/2 < k {
			return true // If the total number of elements that can be covered is less than 'k', return true
		}
	}

	return false // Otherwise, return false
}

// <END-OF-CODE>
