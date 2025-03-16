

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a float64 // Declare and initialize a variable of type float64 named 'a'
	var ave float64 = 0 // Declare and initialize a variable of type float64 named 'ave' with an initial value of 0
	var i int = 0 // Declare and initialize an integer variable named 'i' with an initial value of 0

	// Start a for loop that iterates 5 times
	for i = 0; i < 5; i++ {
		fmt.Print("Enter a number: ") // Ask the user to enter a number
		reader := bufio.NewReader(os.Stdin) // Create a new bufio.Reader object to read input from the standard input
		input, _ := reader.ReadString('\n') // Read a string value from the standard input and assign it to the variable 'input'
		input = strings.TrimSpace(input) // Remove any leading or trailing whitespace from the input string
		a, _ = strconv.ParseFloat(input, 64) // Convert the input string to a float64 value and assign it to the variable 'a'

		// Check if the value of 'a' is less than or equal to 40
		if a <= 40 {
			ave += 40 // If it is, add 40 to the variable 'ave'
			fmt.Printf("Number %d is less than or equal to 40. Adding 40 to the average.\n", i+1)
		} else {
			ave += a // If the value of 'a' is greater than 40, add it directly to the variable 'ave'
			fmt.Printf("Number %d is greater than 40. Adding %f to the average.\n", i+1, a)
		}
	}

	// Calculate the average of the 5 numbers by dividing the sum of the numbers (stored in the variable 'ave') by 5
	ave /= 5.0

	// Print the average value to the standard output using the fmt.Printf function
	fmt.Printf("The average of the 5 numbers is: %.0f\n", ave)
}

