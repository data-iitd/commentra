package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the user
	scan := bufio.NewScanner(os.Stdin)

	// Declare variables
	var n, i, k, p int
	flag := true
	a := make([]int, 1000) // Array to keep track of occurrences

	// Read an integer input from the user
	fmt.Scan(&n)



Translate the above Go code to C++ and end with comment "