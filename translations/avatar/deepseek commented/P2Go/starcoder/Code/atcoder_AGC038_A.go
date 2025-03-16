
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the height
	height, _ := strconv.Atoi(readLine(os.Stdin))

	// Read the width
	width, _ := strconv.Atoi(readLine(os.Stdin))

	// Read the number of columns to be filled with "0"
	a, _ := strconv.Atoi(readLine(os.Stdin))

	// Read the number of rows to be filled with "0"
	b, _ := strconv.Atoi(readLine(os.Stdin))

	// Initialize the answer matrix with "0"
	answer := make([][]string, height)
	for i := range answer {
		answer[i] = make([]string, width)
		for j := range answer[i] {
			answer[i][j] = "0"
		}
	}

	// Fill the matrix based on the given conditions
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			if i < b { // Check if the row index is less than B
				if j < a { // Check if the column index is less than A
					answer[i][j] = "0" // Assign "0" if both conditions are met
				} else {
					answer[i][j] = "1" // Assign "1" otherwise
				}
			} else { // If the row index is not less than B
				if j < a {
					answer[i][j] = "1" // Assign "1" if the column index is less than A
				} else {
					answer[i][j] = "0" // Assign "0" otherwise
				}
			}
		}
	}

	// Print each row of the matrix as a string
	for i := 0; i < height; i++ {
		fmt.Println(strings.Join(answer[i], ""))
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

