package main

import (
	"fmt"
	"math"
	"strings"
)

func calculate(n int, s string) {
	arr := strings.Split(s, "")

	rNum := 0
	gNum := 0
	bNum := 0

	// Count occurrences of each color
	for _, color := range arr {
		switch color {
		case "R":
			rNum++
		case "G":
			gNum++
		case "B":
			bNum++
		}
	}

	sum := 0

	// Iterate through each step from 1 to the ceiling of N/2
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		// Join three consecutive elements of the list arr to form a string
		if len(arr) >= 3 {
			s := arr[0] + arr[1] + arr[2]

			// Check if the string s is equal to any of the six possible color combinations
			if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
				sum++
			}
		}
	}

	// Print the result of the calculation
	fmt.Println(rNum*gNum*bNum - sum)
}

func main() {
	var N int
	var S string

	// Take an integer input N and a string input S from the user
	fmt.Scan(&N)
	fmt.Scan(&S)

	// Call the calculate function with the input values N and S
	calculate(N, S)
}

// <END-OF-CODE>
