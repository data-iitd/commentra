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

	// Read the size of the island (n) and the number of 'L' characters (count) from the input
	fmt.Print("Enter the size of the island (n) and the number of 'L' characters (count): ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, count := parseInput(input)

	// Call the method to print the island pattern based on the input values
	printIsland(n, count)
}

func parseInput(input string) (int, int) {
	// Split the input string into a slice of strings
	inputSlice := strings.Split(input, " ")

	// Convert the first and second elements of the slice to integers
	n, _ := strconv.Atoi(inputSlice[0])
	count, _ := strconv.Atoi(inputSlice[1])

	return n, count
}

func printIsland(n, count int) {
	// Calculate the number of 'L' and 'S' characters that can be placed on the island
	a := (n + 1) / 2 // Number of 'L' characters in the first half
	b := n / 2       // Number of 'L' characters in the second half
	max := a * a + b * b // Maximum number of 'L' characters that can fit in the island

	// Check if the provided count exceeds the maximum possible 'L' characters
	if count > max {
		fmt.Println("NO") // Print "NO" if the count is too high
		return // Exit the method
	}

	// If the count is valid, print "YES"
	fmt.Println("YES")

	// Loop through each row of the island
	for i := 0; i < n; i++ {
		var sb strings.Builder // Create a StringBuilder to construct the row

		// Loop through each column of the island
		for j := 0; j < n; j++ {
			// Place 'L' if the sum of indices is even and there are still 'L' characters left
			if (i + j) % 2 == 0 && count > 0 {
				sb.WriteString("L") // Append 'L' to the current row
				count-- // Decrement the count of 'L' characters
			} else {
				sb.WriteString("S") // Append 'S' to the current row
			}
		}

		// Print the constructed row of the island
		fmt.Println(sb.String())
	}
}

