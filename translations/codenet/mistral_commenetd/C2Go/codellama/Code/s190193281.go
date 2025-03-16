
package main

import "fmt"

func binarySearch(key int, S []int, n int) int {
	left := 0
	right := n
	for left < right {
		mid := (left + right) / 2
		if S[mid] == key {
			return 1
		} else if key < S[mid] {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return 0
}

func main() {
	var n, q, c int
	fmt.Print("Enter the size of the array: ")
	fmt.Scan(&n)

	S := make([]int, n)
	fmt.Print("Enter ", n, " integers:\n")
	for i := 0; i < n; i++ {
		fmt.Print("Element ", i+1, ": ")
		fmt.Scan(&S[i])
	}

	fmt.Print("Enter the number of queries: ")
	fmt.Scan(&q)

	T := make([]int, q)
	fmt.Print("Enter ", q, " integers to be searched:\n")
	for i := 0; i < q; i++ {
		fmt.Print("Query ", i+1, ": ")
		fmt.Scan(&T[i])

		if binarySearch(T[i], S, n) == 1 {
			c++
		}
	}

	fmt.Print("Number of queries present in the array: ", c, "\n")
}

