
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Read the number of entries
	n, _ := strconv.Atoi(reader.ReadLine())

	// Initialize a 2D array to store the input values
	vec := make([][]int, n)
	for i := 0; i < n; i++ {
		line := reader.ReadLine()
		values := make([]int, 4)
		for j, value := range strings.Split(string(line), " ") {
			values[j], _ = strconv.Atoi(value)
		}
		vec[i] = values
	}

	// Initialize variables to track the best option
	ans := 500 // Default answer if no valid option is found
	ansprice := 20000 // Set a high initial price

	// Iterate through each entry to find the best option
	for i := 0; i < n; i++ {
		fl := 1 // Flag to check if the current entry is not dominated

		// Check if the current entry is dominated by any other entry
		for j := 0; j < n; j++ {
			if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
				fl = 0 // Set flag to 0 if dominated
			}
		}

		// If the current entry is not dominated, check its price
		if fl == 1 {
			if vec[i][3] < ansprice {
				ansprice = vec[i][3] // Update the best price found
				ans = i + 1 // Update the answer with the current index (1-based)
			}
		}
	}

	// Output the result
	fmt.Println(ans)
}

