
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize Scanner object to read user input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first integer input
	fmt.Print("Enter the first integer: ")
	scanner.Scan()
	a, _ := strconv.Atoi(scanner.Text())

	// Read the second integer input
	fmt.Print("Enter the second integer: ")
	scanner.Scan()
	b, _ := strconv.Atoi(scanner.Text())

	// Initialize result variable with the value of a
	res := a

	// Enter a while loop that continues as long as a is greater than or equal to b
	for a >= b {
		res += a / b // Update result by adding the integer division of a by b
		a = a/b + a%b // Update a to be the sum of the integer division and remainder
	}

	fmt.Println(res) // Print the final value of res
}

