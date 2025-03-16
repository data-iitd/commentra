
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the input number from the console and store it in the 'n' variable
	fmt.Print("Enter a number: ")
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Call the 'solve' function to calculate and print the result
	solve(n)
}

// 'solve' function to calculate and print the result
func solve(n int) {
	// Calculate the result and print it to the console
	fmt.Println((n / 3) * 2 + (n % 3 == 0 ? 0 : 1))
}

