package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of pairs of integers to be processed
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of pairs of integers to be processed: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Initialize an array to store the characters representing the actions
	ch := make([]byte, n)

	// Initialize sums for two different actions
	s1, s2 := 0, 0

	// Loop variables
	i, j := 0, 0
	flag, dif := 0, 0

	// Process each pair of integers
	for i = 0; i < n; i++ {
		// Read the next pair of integers
		fmt.Print("Enter the next pair of integers: ")
		input, _ = reader.ReadString('\n')
		x, _ := strconv.Atoi(strings.TrimSpace(input))
		y, _ := strconv.Atoi(strings.TrimSpace(input))

		// Calculate temporary sums for the current iteration
		temp1 := s1 + x
		temp2 := s2 + y

		// Check if adding x to s1 keeps the difference within 500
		if abs(temp1-s2) <= 500 {
			s1 += x // Update s1
			ch[j] = 'A' // Record the action 'A'
			j++
			continue
		}

		// Check if adding y to s2 keeps the difference within 500
		if abs(temp2-s1) <= 500 {
			s2 += y // Update s2
			ch[j] = 'G' // Record the action 'G'
			j++
			continue
		}

		// If neither condition is met, set flag to indicate failure
		flag = 1
		break
	}

	// Check if the loop was exited due to a failure condition
	if flag == 1 {
		fmt.Println("-1") // Output -1 to indicate failure
	} else {
		// Convert the character array to a string and print the result
		ans := string(ch[:j])
		fmt.Println(ans) // Output the recorded actions
	}
}

