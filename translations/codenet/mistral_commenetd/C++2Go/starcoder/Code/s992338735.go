<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables to store the input and output
	var N, S int
	// Declare variables to store the minimum and maximum subarray sums
	var M, m int
	// Declare a variable to store the sum of all subarrays
	var addup int
	// Declare a variable to store the loop counter
	var i int

	// Create a new scanner to read the input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input from stdin
	line, err := reader.ReadString('\n')
	// Check if an error occurred
	if err!= nil {
		fmt.Println(err)
	}
	// Convert the input string to an integer
	N, err = strconv.Atoi(strings.TrimSpace(line))
	// Check if an error occurred
	if err!= nil {
		fmt.Println(err)
	}

<<<<<<< HEAD
	// Run the loop as long as the user inputs a positive integer N
=======
	// Run the loop as long as the input is positive
>>>>>>> 98c87cb78a (data updated)
	for N > 0 {
		// Read the next line of input from stdin
		line, err = reader.ReadString('\n')
		// Check if an error occurred
		if err!= nil {
			fmt.Println(err)
		}
		// Convert the input string to an integer
		S, err = strconv.Atoi(strings.TrimSpace(line))
		// Check if an error occurred
		if err!= nil {
			fmt.Println(err)
		}
<<<<<<< HEAD
		// Add the current subarray sum S to the total sum addup
=======
		// Add the current subarray sum to the total sum
>>>>>>> 98c87cb78a (data updated)
		addup += S
		// Update M if the current subarray sum is larger than the current minimum sum
		if S > M {
			M = S
		}
		// Update m if the current subarray sum is smaller than the current maximum sum
		if S < m {
			m = S
		}
<<<<<<< HEAD
		// Decrement N by 1
=======
		// Decrement the input counter
>>>>>>> 98c87cb78a (data updated)
		N--
	}

	// Calculate and print the average of the differences between the maximum and minimum sums of all subarrays
	fmt.Printf("%.1f\n", float64(addup-M-m)/(N-2))
}

