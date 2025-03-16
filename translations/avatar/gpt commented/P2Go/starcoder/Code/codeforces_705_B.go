package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(readLine())

	// Read the list of integers from input
	w := strings.Split(readLine(), " ")

	// Initialize a variable 'c' to track the output state
	c := 2

	// Iterate through each element in the list 'w'
	for i := 0; i < n; i++ {
		// If the current element is 1, print the current value of 'c'
		if w[i] == "1" {
			fmt.Println(c)
		}
		// If the current element is even, toggle 'c' between 2 and 3
		if w[i]%2 == 0 {
			c = 3 - c // This will switch c between 2 and 3
			fmt.Println(c)
		}
		// If the current element is odd (and not 1), print the current value of 'c'
		if w[i]!= "1" {
			fmt.Println(c)
		}
	}
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	return string(line)
}

