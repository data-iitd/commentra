

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the user
	scanner := bufio.NewScanner( os.Stdin )

	// Prompt the user to enter an integer input
	fmt.Println( "Enter an integer:" )
	scanner.Scan()

	// Convert the user input to an integer and assign it to the variable x
	x, _ := strconv.Atoi( scanner.Text() )

	// Calculate the greatest common divisor (gcd) of 360 and the user input x
	gcdValue := gcd( 360, x )

	// Print the result of the division of 360 by the gcd
	fmt.Println( 360 / gcdValue )
}

// Function to calculate the greatest common divisor (gcd) of two integers
func gcd( a int, b int ) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

