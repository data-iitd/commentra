package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Reading two integers from user input: n and x
	var n, x int
	fmt.Scan(&n, &x)

	// Calling the print method with the inputs x and n
	print(x, n)
}

func print(x, n int) {
	// Calculating the maximum value based on n
	max := n * 2 - 1

	// Checking if x is equal to 1 or max, if so, print "No" and exit the method
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}

	// If x is valid, print "Yes"
	fmt.Println("Yes")

	// Prepare the line separator for formatting output
	sep := "\n"

	// Generate a sequence of numbers based on the input x and n
	ans := ""
	for i := x + n - 1; i < x + n + max - 1; i++ {
		ans += strconv.Itoa((i%max+1)%max+1) + sep
	}

	// Print the generated sequence
	fmt.Println(ans)
}

