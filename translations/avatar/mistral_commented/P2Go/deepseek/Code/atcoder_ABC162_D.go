package main

import (
	"fmt"
	"math"
)

func calculate(n int, s string) {
	// Create a slice arr from the string s
	arr := []rune(s)

	// Count the number of occurrences of each color in the slice arr and store them in variables rNum, gNum, and bNum
	rNum := 0
	gNum := 0
	bNum := 0
	for _, char := range arr {
		if char == 'R' {
			rNum++
		} else if char == 'G' {
			gNum++
		} else if char == 'B' {
			bNum++
		}
	}

	// Initialize a variable sum to 0
	sum := 0

	// Use a for loop to iterate through each step from 1 to the ceiling of N/2
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		// Inside the inner for loop, join three consecutive elements of the slice arr to form a string s
		s := string([]rune{arr[step-1], arr[step], arr[step+1]})

		// Check if the string s is equal to any of the six possible color combinations: "RGB", "RBG", "BGR", "BRG", "GBR", or "GRB"
		if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
			sum++
		}
	}

	// After the inner for loop, print the result of the calculation: rNum * gNum * bNum - sum
	fmt.Println(rNum * gNum * bNum - sum)
}

func main() {
	// Take an integer input N and a string input S from the user
	var N int
	var S string
	fmt.Scan(&N)
	fmt.Scan(&S)

	// Call the calculate function with the input values N and S
	calculate(N, S)
}

