
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables
	var n, m int
	foods := make([]int, m)

	// Read input values
	reader := bufio.NewReader(os.Stdin)
	n, _ = strconv.Atoi(readerReadLine(reader))
	m, _ = strconv.Atoi(readerReadLine(reader))

	// Initialize a vector of size m to store the count of each food item
	foods = make([]int, m)

	// Read n food preferences from the standard input
	for i := 0; i < n; i++ {
		k, _ := strconv.Atoi(readerReadLine(reader))

		// Read the indices of the food items in the current preference
		for j := 0; j < k; j++ {
			temp, _ := strconv.Atoi(readerReadLine(reader))

			// Increment the count of the corresponding food item in the foods vector
			foods[temp-1]++
		}
	}

	// Initialize a variable to store the number of food items that appear in all preferences
	ans := 0

	// Iterate through each element in the foods vector and check if its count is equal to the total number of preferences
	for _, elem := range foods {
		if elem == n {
			ans++
		}
	}

	// Print the value of ans to the standard output
	fmt.Println(ans)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

