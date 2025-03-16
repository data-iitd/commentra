package main

import (
	"fmt"
)

var A [1000000]int
var n int

/*
 * binarySearch function performs a binary search on the array A to find a given key.
 * It returns true if the key is found, otherwise it returns false.
 */
func binarySearch(key int) bool {
	left := 0
	right := n
	var mid int
	for left < right {
		mid = (left + right) / 2
		if key == A[mid] {
			return true // key found
		}
		if key > A[mid] {
			left = mid + 1 // search in the right half
		} else {
			right = mid // search in the left half
		}
	}
	return false
}

/*
 * main function is the entry point of the program.
 * It reads the size of the array and the elements of the array from the user.
 * It then reads the number of queries and performs binary search for each query.
 * Finally, it prints the number of elements found.
 */
func main() {
	var i, q, k, sum int
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	fmt.Scan(&q)
	for i = 0; i < q; i++ {
		fmt.Scan(&k)
		if binarySearch(k) {
			sum++
		}
	}
	fmt.Println(sum)
}

// <END-OF-CODE>
