package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Create a variable to read input from the user
	var a int64
	var b string

	// Read a long integer value from the user
	fmt.Scan(&a)

	// Read a string value from the user
	fmt.Scan(&b)

	// Remove the '.' from the string
	bStr := strings.ReplaceAll(b, ".", "")

	// Convert the built string (bStr) to an integer
	bInt, err := strconv.Atoi(bStr)
	if err != nil {
		fmt.Println("Error converting string to integer:", err)
		return
	}

	// Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
	result := (a * int64(bInt)) / 100

	// Print the result to the console
	fmt.Println(result)
}

// <END-OF-CODE>
