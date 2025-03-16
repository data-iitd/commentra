package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the list
	var n int
	fmt.Fscan(reader, &n)

	// Create a map to count occurrences of each integer
	counts := make(map[int]int)

	// Read the list of integers and count the occurrences
	for i := 0; i < n; i++ {
		var num int
		fmt.Fscan(reader, &num)
		counts[num]++
	}

	// Initialize a variable to store the count of pairs
	c := 0

	// Iterate over each integer in the map
	for i := range counts {
		if i == 0 {
			// If the integer is 0, calculate the number of ways to choose 2 items from the occurrences of 0
			c += counts[i] * (counts[i] - 1)
		} else {
			// If the integer is not 0, check if its negative counterpart is also in the map
			if counts[-i] > 0 {
				// Calculate the number of ways to choose 2 items from the occurrences of i and -i
				c += counts[i] * counts[-i]
			}
		}
	}

	// Print the result of c / 2, which represents the number of unique pairs
	fmt.Println(c / 2)
}

// <END-OF-CODE>
