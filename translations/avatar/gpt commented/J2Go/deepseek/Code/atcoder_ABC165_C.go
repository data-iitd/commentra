package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	a, b, c, d []int
	n, m, q    int
	ans        int64 = -100
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the values of n, m, and q from input
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &m)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &q)

	// Initialize arrays based on the number of queries (q)
	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)

	// Read the query parameters into the arrays
	for i := 0; i < q; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &b[i])
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &c[i])
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &d[i])
	}

	// Start the depth-first search (DFS) to find the maximum score
	dfs(make([]int, 0))

	// Output the maximum score found
	fmt.Println(ans)
}

func dfs(list []int) {
	// Check if the current list has reached the required size (n)
	if len(list) == n {
		var score int64 = 0

		// Calculate the score based on the queries
		for i := 0; i < q; i++ {
			// If the condition is met, add the corresponding value to the score
			if list[b[i]]-list[a[i]] == c[i] {
				score += int64(d[i])
			}
		}

		// Update the maximum score if the current score is higher
		if score > ans {
			ans = score
		}
		return
	}

	// If the list is not empty, continue adding numbers from the last added number to m
	if len(list) > 0 {
		for num := list[len(list)-1]; num <= m; num++ {
			list = append(list, num) // Add the current number to the list
			dfs(list)                // Recur with the updated list
			list = list[:len(list)-1] // Backtrack by removing the last number
		}
	} else {
		// If the list is empty, start adding numbers from 1 to m
		for num := 1; num <= m; num++ {
			list = append(list, num) // Add the current number to the list
			dfs(list)                // Recur with the updated list
			list = list[:len(list)-1] // Backtrack by removing the last number
		}
	}
}

