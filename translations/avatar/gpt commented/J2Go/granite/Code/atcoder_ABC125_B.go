
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of items (n) from the input
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	// Read the values (vStr) from the input and convert to a list
	vStr, _ := reader.ReadString('\n')
	vList := str2List(vStr)

	// Read the costs (cStr) from the input and convert to a list
	cStr, _ := reader.ReadString('\n')
	cList := str2List(cStr)

	// Initialize a variable to keep track of the maximum profit
	max := 0

	// Calculate the profit for each item and sum up the positive profits
	for i := 0; i < n; i++ {
		profit := vList[i] - cList[i]
		// Only add to max if the profit is positive
		if profit > 0 {
			max += profit
		}
	}

	// Output the total maximum profit
	fmt.Println(max)
}

// Helper method to convert a space-separated string of integers into a slice
func str2List(str string) []int {
	// Split the input string into an array of strings
	vArrStr := strings.Split(str, " ")

	// Create a slice to hold the integer values
	ret := make([]int, len(vArrStr))

	// Populate the slice with values from the array
	for i, val := range vArrStr {
		v, _ := strconv.Atoi(val)
		ret[i] = v
	}

	// Return the populated slice
	return ret
}

// END-OF-CODE