package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of test cases from the input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

	// Initialize an empty list to store the given numbers
	w := make([]int, n)

	// Read the given numbers and store them in the list
	for i := 0; i < n; i++ {
		w[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}

	// Initialize a variable 'c' with a value of 2
	c := 2

	// Iterate through each number in the list 'w'
	for _, number := range w {

		// If the number is equal to 1, print the current value of 'c'
		if number == 1 {
			fmt.Println(c)

		// If the number is even, toggle the value of 'c'
		} else if number%2 == 0 {
			c = 3 - c
			fmt.Println(c)

		// If the number is odd, print the current value of 'c'
		} else {
			fmt.Println(c)
		}
	}
}

