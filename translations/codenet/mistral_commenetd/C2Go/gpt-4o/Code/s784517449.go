package main

import (
	"fmt"
)

var A [1000000]int // initialize an integer array A of size 1,000,000
var n int          // declare an integer n

// binarySearch performs binary search on the array A for the given key
func binarySearch(key int) int {
	left := 0          // initialize left index to 0
	right := n         // initialize right index to the last index of the array
	var mid int        // initialize middle index

	for left < right { // while left index is less than right index
		mid = (left + right) / 2 // calculate middle index
		if key == A[mid] {       // if key is equal to the middle element
			return 1 // return 1 to indicate key is found
		}
		if key > A[mid] { // if key is greater than the middle element
			left = mid + 1 // update left index to search in the right half
		} else { // if key is less than the middle element
			right = mid // update right index to search in the left half
		}
	}
	return 0 // if key is not found, return 0
}

func main() { // main function
	var i, q, k, sum int // initialize variables i, q, k, and sum

	fmt.Scan(&n) // read the number of elements in the array from the standard input
	for i = 0; i < n; i++ { // for loop to read and store the elements of the array
		fmt.Scan(&A[i])
	}
	fmt.Scan(&q) // read the number of queries from the standard input
	for i = 0; i < q; i++ { // for loop to perform binary search for each query
		fmt.Scan(&k)
		if binarySearch(k) == 1 { // if key is found in the array
			sum++ // increment sum by 1
		}
	}
	fmt.Println(sum) // print the number of queries with a matching element in the array
}

// <END-OF-CODE>
