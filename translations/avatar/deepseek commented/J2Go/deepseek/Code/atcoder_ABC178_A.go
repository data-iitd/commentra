package main

import (
	"fmt"
	"os"
)

func main() {
	var x int
	fmt.Scan(&x) // Read an integer from the input
	bool := x == 1 // Convert the integer x to a boolean value bool
	result := 0
	if !bool {
		result = 1
	}
	
	_, err := fmt.Fprintln(os.Stdout, result) // Print the result
	if err != nil {
		return
	}
}

