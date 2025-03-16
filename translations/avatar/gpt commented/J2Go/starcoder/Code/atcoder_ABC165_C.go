package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declare arrays to hold input values and variables for dimensions and result
var a []int
var b []int
var c []int
var d []int
var n int
var m int
var q int
var ans int

func main() {
	// Create a Scanner object for input
	sc := bufio.NewScanner(os.Stdin)

	// Read the values of n, m, and q from input
	fmt.Fscan(sc, &n)
	fmt.Fscan(sc, &m)
	fmt.Fscan(sc, &q)

	// Initialize arrays based on the number of queries (q)
	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)

	// Read the query parameters into the arrays
	for i := 0; i < q; i++ {
		fmt.Fscan(sc, &a[i])
		fmt.Fscan(sc, &b[i])
		fmt.Fscan(sc, &c[i])
		fmt.Fscan(sc, &d[i])
	}

	// Start the depth-first search (DFS) to find the maximum score
	dfs(make([]int, 0))

	// Output the maximum score found
	fmt.Println(ans)
}

// dfs is a depth-first search (DFS) function that finds the maximum score
func dfs(list []int) {
	// Check if the current list has reached the required size (n)
	if len(list) == n {
		score := 0

		// Calculate the score based on the queries
		for i := 0; i < q; i++ {
			// If the condition is met, add the corresponding value to the score
			if list[b[i]-1]-list[a[i]-1] == c[i] {
				score += d[i]
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

