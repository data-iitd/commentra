package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Reading a line of input from the console
	scanner.Scan()
	line := scanner.Text()

	// Splitting the input line into an array of strings using space as delimiter
	x := strings.Split(line, " ")

	// Parsing the first and second elements of the input array into integers 'a' and 'b' respectively
	a, _ := strconv.Atoi(x[0])
	b, _ := strconv.Atoi(x[1])

	// Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
	c := a - b*2

	// If the value of 'c' is negative, set it to zero
	if c < 0 {
		c = 0
	}

	// Print the value of 'c' to the console
	fmt.Println(c)
}

