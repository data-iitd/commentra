package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Arrays to store input values
var a []int
var b []int
var c []int
var d []int

// Variables to store input values
var n int
var m int
var q int

// Variable to store the maximum score
var ans int64

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n, &m, &q)

	// Initialize arrays to store the conditions
	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)

	// Read the conditions into the arrays
	for i := 0; i < q; i++ {
		fmt.Fscanln(reader, &a[i], &b[i], &c[i], &d[i])
	}

	// Start the DFS with an empty list
	dfs([]int{})

	// Print the maximum score found
	fmt.Println(ans)
}

// Depth-First Search (DFS) function to generate combinations
func dfs(list []int) {
	// If the list size equals n, calculate the score and update ans
	if len(list) == n {
		score := int64(0)
		for i := 0; i < q; i++ {
			if list[b[i]]-list[a[i]] == c[i] {
				score += d[i]
			}
		}
		ans = max(ans, score)
		return
	}

	// If the list is not empty, continue adding numbers from the last number in the list
	if len(list) > 0 {
		for num := list[len(list)-1]; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	} else {
		// If the list is empty, start with numbers from 1 to m
		for num := 1; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	}
}

// Utility function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

