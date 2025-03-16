
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of pairs of integers to be processed
	n, _ := strconv.Atoi(reader.ReadLine()[2:])

	// Initialize an array to store the characters representing the actions
	ch := make([]byte, n)

	// Initialize sums for two different actions
	s1, s2 := 0, 0

	// Loop variables
	i, j, flag, dif := 0, 0, 0, 0

	// Process each pair of integers
	for i = 0; i < n; i++ {
		// Read the next pair of integers
		line, _ := reader.ReadString('\n')
		x, _ := strconv.Atoi(line[:len(line)-1])
		y, _ := strconv.Atoi(reader.ReadLine()[2:])

		// Calculate temporary sums for the current iteration
		temp1 := s1 + x
		temp2 := s2 + y

		// Check if adding x to s1 keeps the difference within 500
		if int(math.Abs(float64(temp1-s2))) <= 500 {
			s1 += x // Update s1
			ch[j] = 'A' // Record the action 'A'
			j++ // Move to the next iteration
			continue
		}

		// Check if adding y to s2 keeps the difference within 500
		if int(math.Abs(float64(temp2-s1))) <= 500 {
			s2 += y // Update s2
			ch[j] = 'G' // Record the action 'G'
			j++ // Move to the next iteration
			continue
		}

		// If neither condition is met, set flag to indicate failure
		flag = 1
		break // Exit the loop
	}

	// Check if the loop was exited due to a failure condition
	if flag == 1 {
		fmt.Println(-1) // Output -1 to indicate failure
	} else {
		// Convert the character array to a string and print the result
		fmt.Println(string(ch[:j])) // Output the recorded actions
	}
}
