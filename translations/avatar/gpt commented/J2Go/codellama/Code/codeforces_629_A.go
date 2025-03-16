package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of strings to be processed
	num, _ := strconv.Atoi(sc.Text())

	// Initialize counters for occurrences of 'C' and the total fine
	counter := 0
	fine := 0

	// Create an ArrayList to store the input strings
	arr := make([]string, num)

	// Read 'num' strings from input and add them to the ArrayList
	for i := 0; i < num; i++ {
		sc.Scan()
		arr[i] = sc.Text()
	}

	// Calculate fines based on occurrences of 'C' in each column
	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			// Count occurrences of 'C' in the current column
			if arr[k][i] == 'C' {
				counter++
			}
		}
		// Update the fine based on the number of 'C's found in this column
		fine += (counter * (counter - 1)) / 2
		// Reset counter for the next column
		counter = 0
	}

	// Calculate fines based on occurrences of 'C' in each row
	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			// Count occurrences of 'C' in the current row
			if arr[i][k] == 'C' {
				counter++
			}
		}
		// Update the fine based on the number of 'C's found in this row
		fine += (counter * (counter - 1)) / 2
		// Reset counter for the next row
		counter = 0
	}

	// Output the total fine calculated
	fmt.Println(fine)
}

