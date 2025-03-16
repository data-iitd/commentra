package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object for input and a PrintWriter for output
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	
	// Read the number of entries
	scanner.Scan()
	n, _ := fmt.Sscanf(scanner.Text(), "%d", &n)
	
	// Initialize a 2D slice to store the input values
	var vec [][]int
	
	// Read input values into the 2D slice
	for i := 0; i < n; i++ {
		scanner.Scan()
		var values []int
		for _, v := range strings.Split(scanner.Text(), " ") {
			val, _ := strconv.Atoi(v)
			values = append(values, val)
		}
		vec = append(vec, values)
	}
	
	// Initialize variables to track the best option
	ans := 500
	ansprice := 20000
	
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
	fmt.Fprintln(writer, ans)
	writer.Flush() // Close the writer
}
