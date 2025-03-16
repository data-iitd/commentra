package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Reading two integers from user input: n and x
	fmt.Print("Enter n: ")
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	fmt.Print("Enter x: ")
	scanner.Scan()
	x, _ := strconv.Atoi(scanner.Text())

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
	ans := strings.Builder{}
	for i := x + n - 1; i < x+n+max-1; i++ {
		ans.WriteString(fmt.Sprintf("%d%s", i%max+1, sep))
	}

	// Print the generated sequence
	fmt.Println(ans.String())
}

