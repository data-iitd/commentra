
package main

import (
	"fmt"
	"math"
	"strings"
)

func calculate(n int, s string) {
	// Converting the string s into a list of characters
	arr := strings.Split(s, "")

	// Calculating the counts of 'R', 'G', and 'B'
	rNum := strings.Count(s, "R")
	gNum := strings.Count(s, "G")
	bNum := strings.Count(s, "B")

	// Initializing sum to 0
	sum := 0

	// Iterating over possible step sizes from 1 to math.ceil(n / 2) + 1
	for step := 1; step <= int(math.Ceil(float64(n)/2))+1; step++ {
		// Iterating over possible starting indices for the substring
		for i := 0; i < n-2*step; i++ {
			// Forming a substring of length 3
			s := arr[i] + arr[i+step] + arr[i+step*2]

			// Checking if the substring matches any of the patterns
			if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
				sum = sum + 1
			}
		}
	}

	// Printing the product of the counts of 'R', 'G', and 'B' minus sum
	fmt.Println(rNum * gNum * bNum - sum)
}

func main() {
	// Taking input for N and S
	var n int
	var s string
	fmt.Scan(&n)
	fmt.Scan(&s)

	// Calling the function calculate with N and S as arguments
	calculate(n, s)
}

