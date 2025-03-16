package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a buffered reader to read input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of test cases
	var n int
	fmt.Fscan(reader, &n)

	// Create a map to count occurrences of numbers
	w := make(map[int]int)

	// Read the numbers and count their occurrences
	for i := 0; i < n; i++ {
		var num int
		fmt.Fscan(reader, &num)
		w[num]++
	}

	// Initialize a counter 'c' to store the result
	c := 0

	// Iterate through each number 'i' in the map 'w'
	for i := range w {
		// If the number 'i' is zero, then add its occurrences multiplied by (its occurrences - 1) to the counter 'c'
		if i == 0 {
			c += w[i] * (w[i] - 1)
		} else if _, exists := w[-i]; exists {
			// If the number '-i' is present in the map 'w', then add its occurrences multiplied by the occurrences of 'i' to the counter 'c'
			c += w[i] * w[-i]
		}
	}

	// Print the result divided by 2
	fmt.Println(c / 2)
}

// <END-OF-CODE>
