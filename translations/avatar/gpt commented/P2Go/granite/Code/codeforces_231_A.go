
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the number of lists to process
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Initialize a counter to keep track of lists with a sum greater than 1
	c := 0

	// Loop through the range of n to process each list
	for i := 0; i < n; i++ {
		// Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
		l1 := make([]int, 0)
		for _, v := range strings.Split(bufio.NewReader(os.Stdin).ReadLine()[0:len(bufio.NewReader(os.Stdin).ReadLine())-1], " ") {
			l1 = append(l1, intMustParse(v))
		}

		// Check if the sum of the current list is greater than 1
		if sum(l1) > 1 {
			// Increment the counter if the condition is met
			c = c + 1
		}
	}

	// Print the final count of lists that had a sum greater than 1
	fmt.Println(c)
}

func sum(l1 []int) int {
	s := 0
	for _, v := range l1 {
		s = s + v
	}
	return s
}

func intMustParse(s string) int {
	i, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return i
}

