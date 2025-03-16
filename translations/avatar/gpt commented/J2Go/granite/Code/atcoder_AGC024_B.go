
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner object to read input from the console
	scan := bufio.NewScanner(os.Stdin)

	// Read the number of elements
	scan.Scan()
	N, _ := strconv.Atoi(scan.Text())

	// Initialize an array to store the elements, adjusting for zero-based indexing
	P := make([]int, N)
	for i := 0; i < N; i++ {
		scan.Scan()
		P[i], _ = strconv.Atoi(scan.Text())
		P[i]-- // Store input values after decrementing by 1
	}

	// Create a map to store the index of each element for quick lookup
	map := make(map[int]int)
	for i := 0; i < N; i++ {
		map[P[i]] = i
	}

	// List to store indices where the order is not increasing
	nglist := make([]int, 0)
	for i := 0; i < N-1; i++ {
		// Check if the current index is greater than the next index in the map
		if map[i] > map[i+1] {
			nglist = append(nglist, i) // Add the index to the nglist if the order is violated
		}
	}

	// If there are no indices in nglist, print 0 and exit
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}

	// Calculate the minimum number of moves required to fix the order
	ans := int(^uint(0) >> 1)
	for i := 0; i < len(nglist)-1; i++ {
		// Update ans with the minimum moves needed between consecutive indices in nglist
		ans = int(math.Min(float64(nglist[i]+1+N-nglist[i+1]-1), float64(ans)))
	}

	// Print the result which is the minimum number of moves
	fmt.Println(ans)
}
