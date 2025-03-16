
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Read a string of digits from the user
	input, _ := reader.ReadString('\n')

	// Remove the trailing newline character
	input = strings.TrimSuffix(input, "\n")

	// Convert the string of digits to a list of integers
	digits := make([]int, 0)
	for _, char := range input {
		digit, _ := strconv.Atoi(string(char))
		digits = append(digits, digit)
	}

	// Process each digit of the number until there are no digits left
	transformedDigits := make([]int, 0)
	for len(digits) > 0 {
		lastDigit := digits[len(digits)-1]
		digits = digits[:len(digits)-1]

		// Determine whether to keep the digit or replace it with its complement to 9
		if 9-lastDigit < lastDigit {
			// If the digit is the last one and its complement is 0, keep the digit
			if len(digits) == 0 && 9-lastDigit == 0 {
				transformedDigits = append(transformedDigits, lastDigit)
			} else {
				// Otherwise, add the complement to the list
				transformedDigits = append(transformedDigits, 9-lastDigit)
			}
		} else {
			// If the digit is less than or equal to its complement, keep the digit
			transformedDigits = append(transformedDigits, lastDigit)
		}
	}

	// Initialize variables to construct the new number
	newNumber := 0
	power := 0

	// Reconstruct the new number from the transformed digits
	for i := len(transformedDigits) - 1; i >= 0; i-- {
		digit := transformedDigits[i]
		newNumber += digit * int(math.Pow(10, float64(power)))
		power++
	}

	// Output the newly constructed number
	fmt.Println(newNumber)
}
