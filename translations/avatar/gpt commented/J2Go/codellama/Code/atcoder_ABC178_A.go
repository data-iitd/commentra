package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	scan := bufio.NewScanner(os.Stdin)

	// Reading an integer input from the user
	fmt.Print("Enter an integer: ")
	scan.Scan()
	x, _ := strconv.Atoi(scan.Text())

	// Using a ternary operator to determine the boolean value based on the input
	bool := x == 1

	// Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
	result := 0
	if !bool {
		result = 1
	}

	// Creating a PrintWriter object to output the result to the console
	out := bufio.NewWriter(os.Stdout)

	// Printing the result to the console
	fmt.Fprintln(out, result)

	// Flushing the output stream to ensure all data is written out
	out.Flush()
}

