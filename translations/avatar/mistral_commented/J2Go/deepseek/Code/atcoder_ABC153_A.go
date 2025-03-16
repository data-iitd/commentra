package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a new Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Reading a single line of input from the console and storing it as a string slice
	scanner.Scan()
	str := scanner.Text()

	// Splitting the input string by space and converting the first two elements to integers
	parts := strSplit(str, " ")
	h, _ := strconv.Atoi(parts[0])
	a, _ := strconv.Atoi(parts[1])

	// Initializing a variable 'num' to keep track of the number of steps
	num := 0

	// Using a for loop to simulate the given condition
	for h > 0 {
		// Subtracting 'a' from 'h' in each iteration
		h -= a
		// Incrementing the 'num' variable after each successful subtraction
		num++
	}

	// Printing the final result 'num' to the console
	fmt.Println(num)
}

// Helper function to split a string by a given delimiter
func strSplit(str, delimiter string) []string {
	// Implementing a simple split function
	result := []string{}
	for len(str) > 0 {
		index := indexOf(str, delimiter)
		if index == -1 {
			result = append(result, str)
			break
		}
		result = append(result, str[:index])
		str = str[index+len(delimiter):]
	}
	return result
}

// Helper function to find the index of a substring within a string
func indexOf(str, substr string) int {
	for i := 0; i < len(str); i++ {
		if str[i:i+len(substr)] == substr {
			return i
		}
	}
	return -1
}

