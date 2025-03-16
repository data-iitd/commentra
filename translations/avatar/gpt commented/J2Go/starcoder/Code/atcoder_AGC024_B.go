package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the number of elements
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	// Initialize an array to store the elements, adjusting for zero-based indexing
	P := make([]int, N)
	for i := 0; i < N; i++ {
		P[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	// Create a map to store the index of each element for quick lookup
	map := make(map[int]int)
	for i := 0; i < N; i++ {
		map[P[i]] = i
	}
	// List to store indices where the order is not increasing
	nglist := make([]int, 0)
	for i := 0; i < N - 1; i++ {
		// Check if the current index is greater than the next index in the map
		if map[i] > map[i + 1] {
			nglist = append(nglist, i)
		}
	}
	// If there are no indices in nglist, print 0 and exit
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}
	// Calculate the minimum number of moves required to fix the order
	ans := min(N-nglist[0]-1, nglist[len(nglist)-1]+1)
	for i := 0; i < len(nglist)-1; i++ {
		// Update ans with the minimum moves needed between consecutive indices in nglist
		ans = min(nglist[i]+1+N-nglist[i+1]-1, ans)
	}
	// Print the result which is the minimum number of moves
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

