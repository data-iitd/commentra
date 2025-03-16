package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of strings to be processed
	num, _ := strconv.Atoi(readLine(reader))

	// Initialize counters for occurrences of 'C' and the total fine
	counter := 0
	fine := 0

	// Create an array to store the input strings
	arr := make([]string, num)

	// Read 'num' strings from input and add them to the array
	for i := 0; i < num; i++ {
		arr[i] = readLine(reader)
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

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

