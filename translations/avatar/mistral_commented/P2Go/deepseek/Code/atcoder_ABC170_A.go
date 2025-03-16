package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)
	// Scan the next line of input
	scanner.Scan()
	// Split the input line by spaces and convert each string to an integer
	a := []int{}
	for _, s := range strings.Split(scanner.Text(), " ") {
		num, _ := strconv.Atoi(s)
		a = append(a, num)
	}

	// Iterate over the elements of the list a using the enumerate() function
	// which returns a tuple containing the index and the value of each element
	for index, value := range a {
		// Check if the current value is equal to zero
		if value == 0 {
			// Print the index of the first zero to the standard output
			fmt.Println(index + 1)
			// Terminate the loop using the break statement
			break
		}
	}
}

