
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize an empty list to store the results
	li := []int{}
	// Initialize an index variable
	ind := 0

	// Loop through numbers from 1 to 370
	for i := 1; i <= 370; i++ {
		// Initialize a temporary list to hold digits
		temp := []int{}
		// Assign the current number to p and q for processing
		p, q := i, i
		// Initialize a count variable to track the number of digits
		count := 0

		// Count the number of digits in the current number i
		for p!= 0 {
			p /= 10  // Remove the last digit
			count++  // Increment the digit count
		}

		// If the number has 1 digit, add it directly to the list
		if count == 1 {
			li = append(li, i)
		}

		// If the number has 2 digits
		if count == 2 {
			temp = []int{}  // Reset the temporary list
			// Extract digits of the number q
			for q!= 0 {
				x := q % 10  // Get the last digit
				q /= 10  // Remove the last digit
				temp = append(temp, x)  // Append the digit to the temporary list
			}
			// Add the digits in reverse order to the main list
			li = append(li, temp...)
		}

		// If the number has 3 digits
		if count == 3 {
			temp = []int{}  // Reset the temporary list
			// Extract digits of the number q
			for q!= 0 {
				x := q % 10  // Get the last digit
				q /= 10  // Remove the last digit
				temp = append(temp, x)  // Append the digit to the temporary list
			}
			// Add the digits in reverse order to the main list
			li = append(li, temp...)
		}
	}

	// Remove the last two elements from the list (not specified why)
	li = li[:len(li)-2]

	// Take user input for the index
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the index: ")
	n, _ := strconv.Atoi(reader.ReadLine())

	// Print the n-th element from the list (1-based index)
	fmt.Println(li[n-1])
}
