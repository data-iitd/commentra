

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Start an infinite loop to read input values until EOF is reached
	for scanner.Scan() {
		// Split the input line into individual values
		values := strings.Split(scanner.Text(), " ")

		// Convert the input values from strings to integers
		c := make([]int, 3)
		for i := 0; i < 3; i++ {
			num, _ := strconv.Atoi(values[i])
			c[i] = num
		}

		// Declare and initialize a character array 'card' of size 10 with all elements set to zero
		card := make([]byte, 10)
		count := 0
		sum := c[0] + c[1] // Initialize sum with the sum of the first two input values

		// Loop through the array 'c' to mark the corresponding index in 'card' array
		for i := 0; i < 3; i++ {
			card[c[i]-1] = '1' // Set the index in 'card' array to '1' if the corresponding value in 'c' is read
		}

		// Loop through the array 'card' to check if there are at least 4 distinct numbers in the input
		for i := 0; i < 10; i++ {
			// If the index in 'card' array is not set to '1' and the sum of input values, index and 1 is less than or equal to 20
			if card[i]!= '1' && sum+i+1 <= 20 {
				count++ // Increment the count if the condition is true
			}
		}

		// Check if the count is greater than or equal to 4 and print "YES" if true, otherwise print "NO"
		if count >= 4 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}

	// Check for any errors during input reading
	if err := scanner.Err(); err!= nil {
		fmt.Println("Error reading input:", err)
	}
}

