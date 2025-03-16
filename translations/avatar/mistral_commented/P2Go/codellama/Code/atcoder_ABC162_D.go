package main

import (
	"fmt"
	"math"
	"strings"
)

func calculate(n int, s string) {
	// Create a list arr from the string s
	arr := strings.Split(s, "")

	// Count the number of occurrences of each color in the list arr and store them in variables rNum, gNum, and bNum
	rNum := 0
	gNum := 0
	bNum := 0
	for _, v := range arr {
		if v == "R" {
			rNum++
		} else if v == "G" {
			gNum++
		} else if v == "B" {
			bNum++
		}
	}

	// Initialize a variable sum to 0
	sum := 0

	// Use a for loop to iterate through each step from 1 to the ceiling of N/2
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		// Inside the inner for loop, join three consecutive elements of the list arr to form a string s
		i := 0
		s := ""
		for j := 0; j < 3; j++ {
			s += arr[i]
			i++
		}

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
	var n int
	var s string
	fmt.Scan(&n, &s)

	// Call the calculate function with the input values N and S
	calculate(n, s)
}

