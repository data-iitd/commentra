
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Take an integer 'n' as input from the user
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Initialize a counter 'c' to 0
	c := 0

	// Iterate through the range of 'n'
	for i := 0; i < n; i++ {
		// Take 'n' lists of integers as input from the user
		l1 := make([]int, 0)
		fmt.Fscan(bufio.NewReader(os.Stdin), &l1)

		// Check if the sum of the elements in the current list is greater than 1
		if sum(l1) > 1 {
			// Increment the counter 'c' by 1 if the condition is true
			c++
		}
	}

	// Print the value of the counter 'c'
	fmt.Println(c)
}

func sum(l1 []int) int {
	s := 0
	for _, v := range l1 {
		s += v
	}
	return s
}

