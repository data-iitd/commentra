
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize an empty slice 'li' to store the digits
	li := []int{}

	// Initialize an index variable 'ind'
	ind := 0

	// Iterate through the range from 1 to 370
	for i := 1; i <= 370; i++ {
		// Initialize an empty slice 'temp' to store digits
		temp := []int{}

		// Assign current number 'i' to variables p and q
		p, q := i, i

		// Initialize a counter 'count' to keep track of number of digits
		count := 0

		// While p is not zero, divide it by 10 and increment the counter
		for p!= 0 {
			p /= 10
			count++
		}

		// Based on the number of digits, append the number or its digits to 'li'
		if count == 1 {
			// If the number has only one digit, directly append it to 'li'
			li = append(li, i)
		} else if count == 2 {
			// If the number has two digits, extract its digits and reverse the slice
			for q!= 0 {
				x := q % 10  // Get the last digit
				q /= 10    // Move to the previous digit
				temp = append(temp, x)
			}
			li = append(li, temp...)  // Append the reversed slice to 'li'
		} else if count == 3 {
			// If the number has three digits, extract its digits and reverse the slice
			for q!= 0 {
				x := q % 10  // Get the last digit
				q /= 10    // Move to the previous digit
				temp = append(temp, x)
			}
			li = append(li, temp...)  // Append the reversed slice to 'li'
		}
	}

	// Remove the first two elements from 'li' as they are not required
	li = li[2:]

	// Take an input 'n' from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	n, _ := strconv.Atoi(reader.ReadLine())

	// Print the required digit or digits from 'li' based on the user input
	fmt.Println(li[n-1])
}
