package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int
	fd := make([]int, 6) // fd: slice to store counts
	var height float64    // height: variable to store each height input

	// Read the number of heights
	fmt.Scan(&n)

	// Loop to read each height and categorize it
	for n > 0 {
		fmt.Scan(&height)
		if height >= 185.0 {
			fd[5]++
		} else if height >= 180.0 {
			fd[4]++
		} else if height >= 175.0 {
			fd[3]++
		} else if height >= 170.0 {
			fd[2]++
		} else if height >= 165.0 {
			fd[1]++
		} else {
			fd[0]++
		}
		n--
	}

	// Loop to print the histogram
	for i := 0; i < 6; i++ {
		fmt.Printf("%d:", i+1)
		for j := 0; j < fd[i]; j++ {
			fmt.Print("*")
		}
		fmt.Println()
	}
}

// <END-OF-CODE>
