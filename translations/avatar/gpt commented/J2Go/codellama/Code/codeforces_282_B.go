
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of pairs of integers to be processed
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())

	// Initialize an array to store the characters representing the actions
	ch := make([]byte, n)

	// Initialize sums for two different actions
	var s1, s2 int

	// Loop variables
	var i, j int
	flag := 0
	dif := 0

	// Process each pair of integers
	for i = 0; i < n; i++ {
		// Read the next pair of integers
		var x, y int
		sc.Scan()
		x, _ = strconv.Atoi(sc.Text())
		sc.Scan()
		y, _ = strconv.Atoi(sc.Text())

		// Calculate temporary sums for the current iteration
		temp1 := s1 + x
		temp2 := s2 + y

		// Check if adding x to s1 keeps the difference within 500
		if math.Abs(float64(temp1-s2)) <= 500 {
			s1 += x // Update s1
			ch[j] = 'A' // Record the action 'A'
			j++
			continue // Move to the next iteration
		}

		// Check if adding y to s2 keeps the difference within 500
		if math.Abs(float64(temp2-s1)) <= 500 {
			s2 += y // Update s2
			ch[j] = 'G' // Record the action 'G'
			j++
			continue // Move to the next iteration
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
		ans := string(ch[:j])
		fmt.Println(ans) // Output the recorded actions
	}
}

