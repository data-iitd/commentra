package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers from input: S (the strength) and W (the weight)
	S, W := readInts()

	// Check if the strength S is less than or equal to the weight W
	// If it is, print "unsafe"; otherwise, print "safe"
	if S <= W {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

func readInts() (int, int) {
	var S, W int
	fmt.Scan(&S, &W)
	return S, W
}

// Entry point of the program
func init() {
	// Set the maximum number of CPU cores to use
	runtime.GOMAXPROCS(runtime.NumCPU())
}

// Entry point of the program
func main() {
	// Call the main function
	main()
}

// 