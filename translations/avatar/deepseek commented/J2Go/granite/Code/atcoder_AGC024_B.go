
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	N, _ := strconv.Atoi(read(reader))
	P := make([]int, N)
	for i := 0; i < N; i++ {
		P[i], _ = strconv.Atoi(read(reader))
	}

	// Create a HashMap to map each value in P to its index
	map := make(map[int]int)
	for i := 0; i < N; i++ {
		map[P[i]] = i
	}

	// Create a list to store indices of elements that are out of order
	nglist := make([]int, 0)
	for i := 0; i < N-1; i++ {
		if map[i] > map[i+1] {
			nglist = append(nglist, i) // Add the index to nglist if the current element is greater than the next element
		}
	}

	// If nglist is empty, the array P is already sorted
	if len(nglist) == 0 {
		fmt.Println(0) // Print 0 and return as the array is sorted
		return
	}

	// Calculate the minimum number of swaps required to sort the array P
	ans := int(^uint(0) >> 1)
	for i := 0; i < len(nglist)-1; i++ {
		ans = min(ans, nglist[i]+1+N-nglist[i+1]-1)
	}
	ans = min(ans, N-nglist[0]-1)
	ans = min(ans, nglist[len(nglist)-1]+1)

	// Print the minimum number of swaps required
	fmt.Println(ans)
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

