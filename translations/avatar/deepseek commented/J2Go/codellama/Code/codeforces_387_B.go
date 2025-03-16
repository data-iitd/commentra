package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, m int
	var req, pre []int
	var ans int
	var i, j int

	// Read the number of elements n
	n, _ = strconv.Atoi(os.Args[1])

	// Read the number of elements m
	m, _ = strconv.Atoi(os.Args[2])

	// Initialize req
	req = make([]int, n)

	// Initialize pre
	pre = make([]int, m)

	// Read elements into req
	for i = 0; i < n; i++ {
		req[i], _ = strconv.Atoi(os.Args[i+3])
	}

	// Read elements into pre
	for j = 0; j < m; j++ {
		pre[j], _ = strconv.Atoi(os.Args[j+n+3])
	}

	i = n - 1
	j = m - 1
	ans = 0

	// Implement the logic to find the number of elements in req that are greater than the corresponding elements in pre
	for i >= 0 && j >= 0 {
		if req[i] > pre[j] {
			ans++
		} else {
			j--
		}
		i--
	}

	// Print the result which is the sum of ans and the remaining elements in req
	fmt.Println(ans + i + 1)
}

