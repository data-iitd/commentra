

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the console
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the number from the input
	sc.Scan()
	x, _ := strconv.ParseInt(sc.Text(), 10, 64)

	// Create a list to store the digits of the number
	list := make([]int, 0)

	// Loop through each digit of the number from right to left
	for x > 0 {
		// Get the last digit of the number
		r := int(x % 10)

		// Check if the digit is greater than 4 and if 9 - digit is less than digit
		if 9-r < r {
			// If it's the last digit and 9 - r is 0, add the digit as is
			if x/10 == 0 && 9-r == 0 {
				list = append(list, r)
			} else {
				// Otherwise, add 9 - digit to the list
				list = append(list, 9-r)
			}
		} else {
			// Otherwise, add the digit to the list
			list = append(list, r)
		}

		// Remove the last digit from the number
		x = x / 10
	}

	// Initialize variables to construct the new number
	pow := 0
	newNumber := int64(0)

	// Loop through the list of digits to construct the new number
	for i := len(list) - 1; i >= 0; i-- {
		// Add the digit to the new number at the appropriate place value
		newNumber = newNumber + int64(list[i])*(int64(10))^int64(pow)
		pow++
	}

	// Print the new number
	fmt.Println(newNumber)
}

