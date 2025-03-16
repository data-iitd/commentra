

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements in the list
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Read the list of integers and count the occurrences of each integer
	w := make(map[int]int)
	for _, s := range bufio.NewReader(os.Stdin).Scan() {
		i, _ := strconv.Atoi(s)
		w[i]++
	}

	// Initialize a variable to store the count of pairs
	c := 0

	// Iterate over each integer in the map
	for i, v := range w {
		// If the integer is 0, calculate the number of ways to choose 2 items from the occurrences of 0
		if i == 0 {
			c += v * (v - 1)
		}
		// If the integer is not 0, check if its negative counterpart is also in the map
		else {
			if _, ok := w[-i]; ok {
				// Calculate the number of ways to choose 2 items from the occurrences of i and -i
				c += v * w[-i]
			}
		}
	}

	// Print the result of c // 2, which represents the number of unique pairs
	fmt.Println(c / 2)
}
