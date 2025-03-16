package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new reader to read from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	var n int
	fmt.Fscan(reader, &n)

	// Initialize a slice to count occurrences of each index (up to 1000)
	array := make([]int, 1001)

	// Read n integers and count their occurrences
	for i := 0; i < n; i++ {
		var index int
		fmt.Fscan(reader, &index)
		array[index]++
	}

	// Determine the maximum count of any index
	countMax := -1
	for i := 1; i < len(array); i++ {
		if countMax < array[i] {
			countMax = array[i]
		}
	}

	// Check if the maximum count is within allowed limits based on n being even or odd
	if n%2 == 0 {
		// For even n, check if the maximum count is less than or equal to n/2
		if countMax <= n/2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		// For odd n, check if the maximum count is less than or equal to n/2 + 1
		if countMax <= n/2+1 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// <END-OF-CODE>
