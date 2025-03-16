
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
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of items (n) from the input
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())

	// Read the values (vStr) from the input and convert to a list
	sc.Scan()
	vStr := sc.Text()
	vList := str2List(vStr)

	// Read the costs (cStr) from the input and convert to a list
	sc.Scan()
	cStr := sc.Text()
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

// Helper method to convert a space-separated string of integers into a Map
func str2List(str string) map[int]int {
	// Split the input string into an array of strings
	vArrStr := strings.Split(str, " ")

	// Create a Map to hold the integer values with their corresponding indices
	ret := make(map[int]int)
	key := 0

	// Populate the Map with values from the array
	for _, val := range vArrStr {
		ret[key], _ = strconv.Atoi(val)
		key++
	}

	// Return the populated Map
	return ret
}

// 