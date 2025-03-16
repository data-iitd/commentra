
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a main function
func main() {
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input from stdin.
	input, err := reader.ReadString('\n')
	if err!= nil {
		fmt.Println(err)
	}

	// Convert the input to a slice of integers.
	inputSlice := strings.Split(input, " ")
	inputInts := make([]int, len(inputSlice))
	for i := 0; i < len(inputSlice); i++ {
		inputInts[i], err = strconv.Atoi(inputSlice[i])
		if err!= nil {
			fmt.Println(err)
		}
	}

	// Set up variables for the four input integers.
	a := inputInts[0]
	b := inputInts[1]
	c := inputInts[2]
	d := inputInts[3]

	// Check the values of a, b, c, and d and print the result based on the conditions.
	if c > b {
		fmt.Println(0)
	} else if a > d {
		fmt.Println(0)
	} else if a < c {
		fmt.Println(min(b, d) - c)
	} else {
		l := []int{a, b, c, d}
		sort.Ints(l)
		fmt.Println(l[2] - l[1])
	}
}

// Define a min function
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 