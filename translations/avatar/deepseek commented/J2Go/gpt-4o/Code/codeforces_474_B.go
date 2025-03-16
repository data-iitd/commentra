package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the size of the array
	arr := make([]int, n)
	fmt.Scan(&arr[0]) // Initialize the first element of the array

	// Read the rest of the elements and calculate the prefix sum
	for i := 1; i < n; i++ {
		var x int
		fmt.Scan(&x)
		arr[i] = x + arr[i-1]
	}

	var m int
	fmt.Scan(&m) // Read the number of queries
	q := make([]int, m)

	// Read the queries
	for i := 0; i < m; i++ {
		fmt.Scan(&q[i])
	}

	// Perform binary search for each query and print the result adjusted by +1
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n) + 1)
	}
}

// Binary search function to find the position of q in arr
func fun(arr []int, q, n int) int {
	res := 0
	i, j := 0, n-1
	for i <= j {
		md := i + (j-i)/2
		if arr[md] == q {
			return md
		} else if arr[md] > q {
			res = md
			j = md - 1
		} else {
			i = md + 1
		}
	}
	return res
}

// <END-OF-CODE>
