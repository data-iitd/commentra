
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := bufio.NewScanner(os.Stdin)

	// Initialize a list to store the digits after transformation
	list := make([]int64, 0)

	// Read a long integer from the user
	x, _ := strconv.ParseInt(sc.Text(), 10, 64)

	// Process each digit of the number until there are no digits left
	for x > 0 {
		// Extract the last digit of the number
		r := x % 10

		// Determine whether to keep the digit or replace it with its complement to 9
		if 9-r < r {
			// If the digit is the last one and its complement is 0, keep the digit
			if x/10 == 0 && 9-r == 0 {
				list = append(list, r)
			} else {
				// Otherwise, add the complement to the list
				list = append(list, 9-r)
			}
		} else {
			// If the digit is less than or equal to its complement, keep the digit
			list = append(list, r)
		}

		// Remove the last digit from the number
		x = x / 10
	}

	// Initialize variables to construct the new number
	pow := 0
	newNumber := int64(0)

	// Reconstruct the new number from the transformed digits
	for i := 0; i < len(list); i++ {
		newNumber = newNumber + list[i]*int64(math.Pow(10, float64(pow)))
		pow++
	}

	// Output the newly constructed number
	fmt.Println(newNumber)
}

