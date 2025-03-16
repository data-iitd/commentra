package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Reading an integer input from the user
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Printing the input number
	fmt.Println(n, " ")

	// Initializing a variable m to hold the current divisor, starting with n
	m := n

	// Looping from n-1 down to 1 to find and print all divisors of n
	for i := n - 1; i > 0; i-- {
		// Checking if i is a divisor of m
		if m%i == 0 {
			// Printing the divisor
			fmt.Println(i, " ")
			// Updating m to the current divisor
			m = i
		}
	}
}

