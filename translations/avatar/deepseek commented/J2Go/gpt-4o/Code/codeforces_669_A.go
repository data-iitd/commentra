package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	// Reading an integer input from the user
	if len(os.Args) > 1 {
		var err error
		n, err = strconv.Atoi(os.Args[1]) // Convert the first command line argument to an integer
		if err != nil {
			fmt.Println("Invalid input")
			return
		}
	} else {
		fmt.Println("Please provide an integer input")
		return
	}
	solve(n) // Calling the solve function with the input value n
}

func solve(n int) {
	// Calculating the result based on the given logic
	result := (n / 3) * 2
	if n%3 != 0 {
		result += 1
	}
	fmt.Println(result) // Printing the result to the console
}

// <END-OF-CODE>
