
// Header Files and Preprocessor Directives
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Input Function
func nextInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

// Global Variables
var n int
var a [1000][999]int
var e1 [1000000]int
var e2 [1000000]int
var d [1000000]int
var b [1000000]bool

// Function Definitions
func p(a, b int) int {
	if a < b {
		return a + b*n
	} else {
		return b + a*n
	}
}

func f(from int) int {
	if b[from] {
		return -1 // If node is already visited, return -1 indicating a cycle
	}
	if d[from]!= 0 {
		return d[from] // If distance is already calculated, return it
	}
	b[from] = true // Mark the node as visited
	to := e1[from]
	max := 0
	if to!= 0 {
		now := f(to) // Recursively find the longest path from 'to'
		if now < 0 {
			return now // If there's a cycle, return -1
		}
		if now > max {
			max = now // Update max if a longer path is found
		}
	}
	to = e2[from]
	if to!= 0 {
		now := f(to) // Recursively find the longest path from 'to'
		if now < 0 {
			return now // If there's a cycle, return -1
		}
		if now > max {
			max = now // Update max if a longer path is found
		}
	}
	b[from] = false // Unmark the node as visited (backtracking)
	return d[from] = max + 1 // Store and return the longest path length
}

// Main Function
func main() {
	n = nextInt() // Read the size of the problem
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			a[i][j] = nextInt() - 1 // Read and adjust indices to be 0-based
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			from := p(i, a[i][j]) // Create a unique node index 'from'
			to := p(i, a[i][j+1]) // Create a unique node index 'to'
			if e1[from] == 0 {
				e1[from] = to // Assign 'to' to e1 of 'from'
			} else if e2[from] == 0 {
				e2[from] = to // Assign 'to' to e2 of 'from'
			} else {
				fmt.Println(-1) // If both e1 and e2 are already assigned, print -1 and exit
				return
			}
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		from := p(i, a[i][0]) // Create a unique starting node index 'from'
		now := f(from) // Find the longest path from 'from'
		if now < 0 {
			ans = -1 // If there's a cycle, set ans to -1
			break
		}
		if now > ans {
			ans = now // Update ans if a longer path is found
		}
	}
	fmt.Println(ans) // Print the result
}

// End of code