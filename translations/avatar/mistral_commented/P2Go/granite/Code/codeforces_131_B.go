
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of test cases
	n, _ := strconv.Atoi(reader.ReadLine())

	// Initialize a map 'w' to store the occurrences of numbers
	w := make(map[int]int)

	// Read the numbers and update the map 'w'
	for _, s := range reader.ReadLine() {
		i, _ := strconv.Atoi(string(s))
		w[i]++
	}

	// Initialize a counter 'c' to store the result
	c := 0

	// Iterate through each number 'i' in the map 'w'
	for i := range w {
		// If the number 'i' is zero, then add its occurrences multiplied by (its occurrences - 1) to the counter 'c'
		if i == 0 {
			c += w[i] * (w[i] - 1)
		}
		// If the number '-i' is present in the map 'w', then add its occurrences multiplied by the occurrences of 'i' to the counter 'c'
		if _, ok := w[-i]; ok {
			c += w[i] * w[-i]
		}
	}

	// Print the result divided by 2
	fmt.Println(c / 2)
}
