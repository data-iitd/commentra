package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of elements in the list
	var n int
	fmt.Fscan(reader, &n)

	// Read the list of integers and count the occurrences of each integer
	w := make(map[int]int)
	for i := 0; i < n; i++ {
		var num int
		fmt.Fscan(reader, &num)
		w[num]++
	}

	// Initialize a variable to store the count of pairs
	c := 0

	// Iterate over each integer in the map
	for i := range w {
		// If the integer is 0, calculate the number of ways to choose 2 items from the occurrences of 0
		if i == 0 {
			c += w[i] * (w[i] - 1)
		} else {
			// If the integer is not 0, check if its negative counterpart is also in the map
			if _, exists := w[-i]; exists {
				// Calculate the number of ways to choose 2 items from the occurrences of i and -i
				c += w[i] * w[-i]
			}
		}
	}

	// Print the result of c // 2, which represents the number of unique pairs
	fmt.Fprintln(writer, c/2)
}

