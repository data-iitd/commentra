

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Prompt the user to enter an integer
	fmt.Println("Enter an integer:")
	scanner.Scan()

	// Convert the input string to an integer
	x, _ := strconv.Atoi(scanner.Text())

	// Calculate the number of distinct cyclic permutations of a string of length x
	result := 360 / gcd(360, x)

	// Print the result
	fmt.Println(result)
}

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

