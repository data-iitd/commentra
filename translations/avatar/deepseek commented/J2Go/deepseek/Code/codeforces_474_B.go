package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := parseInt(scanner.Text()) // Read the size of the array
	arr := make([]int, n)
	scanner.Scan()
	arr[0] = parseInt(scanner.Text()) // Initialize the first element of the array

	// Read the rest of the elements and calculate the prefix sum
	for i := 1; i < n; i++ {
		scanner.Scan()
		x := parseInt(scanner.Text())
		arr[i] = x + arr[i-1]
	}

	scanner.Scan()
	m := parseInt(scanner.Text()) // Read the number of queries
	queries := make([]int, m)

	// Read the queries
	for i := 0; i < m; i++ {
		scanner.Scan()
		queries[i] = parseInt(scanner.Text())
	}

	// Perform binary search for each query and print the result adjusted by +1
	for _, q := range queries {
		fmt.Println(binarySearch(arr, q, n) + 1)
	}
}

// Binary search function to find the position of q in arr
func binarySearch(arr []int, q int, n int) int {
	res := 0
	i, j := 0, n
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

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

