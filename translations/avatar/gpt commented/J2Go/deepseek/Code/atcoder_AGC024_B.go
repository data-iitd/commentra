package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	
	// Initialize an array to store the elements, adjusting for zero-based indexing
	P := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		P[i], _ = strconv.Atoi(scanner.Text())
		P[i]-- // Store input values after decrementing by 1
	}
	
	// Create a map to store the index of each element for quick lookup
	mp := make(map[int]int)
	for i := 0; i < N; i++ {
		mp[P[i]] = i
	}
	
	// List to store indices where the order is not increasing
	var nglist []int
	for i := 0; i < N - 1; i++ {
		// Check if the current index is greater than the next index in the map
		if mp[i] > mp[i + 1] {
			nglist = append(nglist, i)
		}
	}
	
	// If there are no indices in nglist, print 0 and exit
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}
	
	// Calculate the minimum number of moves required to fix the order
	ans := min(N - nglist[0] - 1, nglist[len(nglist) - 1] + 1)
	for i := 0; i < len(nglist) - 1; i++ {
		// Update ans with the minimum moves needed between consecutive indices in nglist
		ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)
	}
	
	// Print the result which is the minimum number of moves
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

