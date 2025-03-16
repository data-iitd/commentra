
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
	fmt.Print("Enter an integer: ")
	scanner.Scan()

	// Convert the input string to an integer
	x, _ := strconv.Atoi(scanner.Text())

	// Calculate and print the number of equal parts in a full circle (360 degrees) 
	// that can be formed with the given angle x using the gcd
	fmt.Println(360 / gcd(360, x))
}

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

