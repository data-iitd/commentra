// Importing necessary packages
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Global variables initialization
var mod = 1000000007
var INF = 1000000007

func main() {
	// Reading input from standard input
	r := bufio.NewReader(os.Stdin)
	// Variables initialization
	var n, m, R int
	fmt.Fscan(r, &n) // Reading number of cities n
	fmt.Fscan(r, &m) // Reading number of roads m
	fmt.Fscan(r, &R) // Reading number of starting points R

	// Initializing rs slice with starting points
	rs := make([]int, R)
	for i := 0; i < R; i++ {
		fmt.Fscan(r, &rs[i]) // Reading starting point i
		rs[i]-- // Decreasing starting point index for matrix indexing
	}

	// Initializing costs matrix with infinite values
	costs := make([][]int, n)
	for i := 0; i < n; i++ {
		costs[i] = make([]int, n)
		for j := 0; j < n; j++ {
			costs[i][j] = INF // Initializing costs[i][j] with infinite value
			costs[i][i] = 0   // Initializing costs[i][i] with zero value
		}
	}

	// Reading roads and filling costs matrix with their costs
	for i := 0; i < m; i++ {
		fmt.Fscan(r, &a) // Reading road starting point a
		fmt.Fscan(r, &b) // Reading road ending point b
		fmt.Fscan(r, &c) // Reading road cost c
		a--                 // Decreasing starting point index for matrix indexing
		b--                 // Decreasing ending point index for matrix indexing
		costs[a][b] = c     // Filling costs[a][b] with cost c
		costs[b][a] = c     // Filling costs[b][a] with cost c
	}

	// Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j]) // Updating costs[i][j] with minimum of current value and costs[i][k] + costs[k][j]
			}
		}
	}

	// Calculating minimum cost of visiting all cities in a single tour
	perms := permutations(rs) // Generating all permutations of starting points
	ans := INF               // Initializing answer with infinite value
	for _, perm := range perms { // Iterating through all permutations
		tmp := 0                 // Initializing temporary variable tmp with zero value
		for j := 1; j < len(perm); j++ { // Iterating through all pairs of consecutive starting points
			from := perm[j-1] // Getting previous starting point
			to := perm[j]     // Getting current starting point
			tmp += costs[from][to] // Adding cost of road from from to to tmp
		}
		ans = min(ans, tmp) // Updating answer with minimum of current answer and tmp
	}
	fmt.Println(ans) // Printing answer
}

// Helper function to generate all permutations of given slice
func permutations(arr []int) [][]int {
	// Helper function initialization
	var helper func([]int, int)
	res := [][]int{}

	helper = func(arr []int, n int) {
		if n == 1 { // Base case: when only one element left in arr
			tmp := make([]int, len(arr))
			copy(tmp, arr) // Copying arr to tmp for returning
			res = append(res, tmp) // Adding tmp to result
			return
		}

		for i := 0; i < n; i++ { // Iterating through all elements of arr
			helper(arr, n-1) // Recursively calling helper function with n-1
			if n%2 == 1 { // Swapping first and last elements when n is odd
				tmp := arr[i]
				arr[i] = arr[n-1]
				arr[n-1] = tmp
			} else { // Swapping first and last elements when n is even
				tmp := arr[0]
				arr[0] = arr[n-1]
				arr[n-1] = tmp
			}
		}
	}
	helper(arr, len(arr)) // Calling helper function with arr and its length
	return res
}