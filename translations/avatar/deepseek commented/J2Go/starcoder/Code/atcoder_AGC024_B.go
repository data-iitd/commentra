package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array P")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	P := make([]int, N)
	fmt.Println("Enter the elements of the array P")
	for i := 0; i < N; i++ {
		P[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}

	// Create a map to map each value in P to its index
	map := make(map[int]int)
	for i := 0; i < N; i++ {
		map[P[i]] = i
	}

	// Create a list to store indices of elements that are out of order
	nglist := make([]int, 0)
	for i := 0; i < N - 1; i++ {
		if map[P[i]] > map[P[i+1]] {
			nglist = append(nglist, i) // Add the index to nglist if the current element is greater than the next element
		}
	}

	// If nglist is empty, the array P is already sorted
	if len(nglist) == 0 {
		fmt.Println(0) // Print 0 and return as the array is sorted
		return
	}

	// Calculate the minimum number of swaps required to sort the array P
	ans := min(N - nglist[0] - 1, nglist[len(nglist) - 1] + 1)
	for i := 0; i < len(nglist) - 1; i++ {
		ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)
	}

	// Print the minimum number of swaps required
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

