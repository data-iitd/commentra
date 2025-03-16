// Package main is the entry point of the program

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// scan function is used to read one line at a time
var sc = bufio.NewScanner(os.Stdin)
var wtr = bufio.NewWriter(os.Stdout)

// Global variables
var N, ss, ans, A, B, C int

// sort function is used to sort an array in ascending order
// type IntSlice []int
// func (a IntSlice) Len() int           { return len(a) }
// func (a IntSlice) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
// func (a IntSlice) Less(i, j int) bool { return a[i] < a[j] }

func main() {
	// Read the first line which contains the number of tests and the number of elements in the array
	X := strings.Split(nextLine(), " ")

	// Initialize the global variables
	N, _ = strconv.Atoi(X[0])
	A, _ = strconv.Atoi(X[1])
	B, _ = strconv.Atoi(X[2])
	C, _ = strconv.Atoi(X[3])
	ss = A + B + C

	// Initialize the array and the dp array
	arr := new int[N]
	dp := new int[N]

	// Initialize the answer variable
	ans = 10000

	// Read the next N lines which contain the elements of the array
	for i := 0; i < N; i++ {
		Y := strings.Split(nextLine(), " ")

		// Read an element of the array
		a, _ := strconv.Atoi(Y[0])
		arr[i] = a
	}

	// Call the dfs function to find the minimum cost
	dfs(dp, 0, arr)

	// Print the answer
	fmt.Fprintln(wtr, ans)

	// Flush the buffer
	_ = wtr.Flush()
}

// dfs function is used for depth-first search
func dfs(dp []int, times int, arr []int) {
	// Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
	if times >= N {
		ans = min(ans, calc(dp, arr))
		return
	}

	// Recursive case: try all possible values for the current element
	for i := 0; i < 4; i++ {
		dp[times] = i
		dfs(dp, times+1, arr)
	}
}

// calc function is used to calculate the cost
func calc(dp, arr []int) int {
	// Initialize the cost and the variables to store the sum of elements with each value in dp
	var cost, AA, BB, CC int

	// Initialize the memo array to store the number of elements with each value in dp
	memo := new int[4]

	// Iterate through the dp array and update the variables
	for i := 0; i < len(dp); i++ {
		// Update the variables based on the current value in dp
		a := dp[i]
		memo[a]++
		if a == 1 {
			AA += arr[i]
		} else if a == 2 {
			BB += arr[i]
		} else if a == 3 {
			CC += arr[i]
		}
	}

	// Calculate the cost based on the variables
	cost += abs(A - AA) + abs(B - BB) + abs(C - CC)

	// Update the cost based on the number of elements with each value in dp
	for i := 1; i < 4; i++ {
		a := memo[i]
		if a < 1 {
			cost += 10000
		} else {
			cost += (a - 1) * 10
		}
	}

	// Return the cost
	return cost
}

// Helper functions
func nextLine() string {
	sc.Scan()
	return sc.Text()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
func com(a, b int) int {
	if a > b {
		return 0
	}
	return 0 //abs(a - b)
}
func abs(a int) int {
	if a < 0 {
		return a * -1
	}
	return a
}
func sum(a []int) (sum int) {
	for _, num := range a {
		sum += num
	}
	return
}

