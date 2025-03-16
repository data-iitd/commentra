package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Reading an integer input from the user
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

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

