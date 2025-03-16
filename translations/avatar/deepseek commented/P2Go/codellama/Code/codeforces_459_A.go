
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Take input from the user and split it into a list of integers
	given := input("")
	l1 := strings.Split(given, " ")
	l1 = [4]int{l1[0], l1[1], l1[2], l1[3]}

	// Step 2: Assign the values to variables x1, y1, x2, and y2
	x1 := l1[0]
	y1 := l1[1]
	x2 := l1[2]
	y2 := l1[3]

	// Step 3: Check if the denominator is not zero to calculate the quotient
	denominator := x2 - x1
	numerator := y2 - y1
	if denominator != 0 {
		quotient := numerator / denominator

		// Step 4: If the numerator is zero, calculate the distance and print the coordinates of two points
		if numerator == 0 {
			d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
			x4 := x1
			x3 := x2
			y3 := y2 + d
			y4 := y1 + d
			fmt.Printf("%d %d %d %d", x3, y3, x4, y4)

			// Step 5: If the denominator is zero, print the coordinates of two points based on the distance calculated
		} else if denominator == 0 {
			y4 := y2
			y3 := y1
			d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
			x4 := x1 + d
			x3 := x2 + d
			fmt.Printf("%d %d %d %d", x3, y3, x4, y4)

			// Step 6: If the quotient is 1 or -1, swap the coordinates and print them
		} else if quotient == 1 {
			x4 := x2
			x3 := x1
			y4 := y1
			y3 := y2
			fmt.Printf("%d %d %d %d", x3, y3, x4, y4)
		} else if quotient == -1 {
			x4 := x1
			x3 := x2
			y4 := y2
			y3 := y1
			fmt.Printf("%d %d %d %d", x3, y3, x4, y4)

			// Step 7: If none of the above conditions are met, print -1
		} else {
			fmt.Printf("-1")
		}
	}
}

func input(prompt string) string {
	fmt.Printf(prompt)
	var input string
	fmt.Scanln(&input)
	return input
}

func strToInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

func intToStr(i int) string {
	return strconv.Itoa(i)
}

