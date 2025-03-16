package main

import (
	"fmt"
	"math"
	"strings"
)

func calculate(n int, s string) {
	// Converting the string s into a slice of runes
	arr := []rune(s)

	// Calculating the counts of 'R', 'G', and 'B'
	rNum, gNum, bNum := 0, 0, 0
	for _, char := range arr {
		switch char {
		case 'R':
			rNum++
		case 'G':
			gNum++
		case 'B':
			bNum++
		}
	}

	// Initializing sum to 0
	sum := 0

	// Iterating over possible step sizes from 1 to math.Ceil(float64(n)/2) + 1
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		// Iterating over possible starting indices for the substring
		for i := 0; i <= n-2*step; i++ {
			// Forming a substring of length 3
			s := string(arr[i]) + string(arr[i+step]) + string(arr[i+step*2])

			// Checking if the substring matches any of the patterns
			if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
				sum++
			}
		}
	}

	// Printing the product of the counts of 'R', 'G', and 'B' minus sum
	fmt.Println(rNum * gNum * bNum - sum)
}

func main() {
	// Taking input for N and S
	var N int
	var S string
	fmt.Scan(&N)
	fmt.Scan(&S)

	// Calling the function calculate with N and S as arguments
	calculate(N, S)
}

// <END-OF-CODE>
