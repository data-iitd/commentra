
package main

import "fmt"

func main() {
	var a float64 // Declare and initialize a variable of type float64 named 'a'
	var ave float64 = 0 // Declare and initialize a variable of type float64 named 'ave' with an initial value of 0
	var i int // Declare and initialize an integer variable named 'i' with an initial value of 0

	// Start a for loop that iterates 5 times
	for i = 0; i < 5; i++ {
		fmt.Println("Enter a number: ") // Ask the user to enter a number
		fmt.Scanf("%f", &a) // Read a float value from the standard input and assign it to the variable 'a'

		// Check if the value of 'a' is less than or equal to 40
		if a <= 40 {
			ave += 40 // If it is, add 40 to the variable 'ave'
			fmt.Printf("Number %d is less than or equal to 40. Adding 40 to the average.\n", i+1)
		}
		// If the value of 'a' is greater than 40, add it directly to the variable 'ave'
		else {
			ave += a
			fmt.Printf("Number %d is greater than 40. Adding %f to the average.\n", i+1, a)
		}
	}

	// Calculate the average of the 5 numbers by dividing the sum of the numbers (stored in the variable 'ave') by 5
	ave /= 5.0

	// Print the average value to the standard output using the fmt.Println function
	fmt.Printf("The average of the 5 numbers is: %f\n", ave)
}

