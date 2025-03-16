
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take input from the user and split it into a list of strings
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	l1 := strings.Split(input, " ")

	// Convert the list of strings into a list of integers
	l1 = convertStringtoListOfInt(l1)

	// Assign the first four integers to coordinates (x1, y1) and (x2, y2)
	x1 := l1[0]
	y1 := l1[1]
	x2 := l1[2]
	y2 := l1[3]

	// Calculate the denominator and numerator for slope calculation
	denominator := x2 - x1
	numerator := y2 - y1

	// Check if the line is not vertical
	if denominator!= 0 {
		quotient := numerator / denominator // Calculate the slope of the line
	}

	// Check if the line is horizontal
	if numerator == 0 {
		// Calculate the distance between the two points
		d := int(math.Sqrt(math.Pow(float64(x2-x1), 2) + math.Pow(float64(y2-y1), 2)))
		// Set new coordinates for the points shifted vertically
		x4 := x1
		x3 := x2
		y3 := y2 + d
		y4 := y1 + d
		// Print the new coordinates
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}

	// Check if the line is vertical
	if denominator == 0 {
		// Set y-coordinates to the original y-values
		y4 := y2
		y3 := y1
		// Calculate the distance between the two points
		d := int(math.Sqrt(math.Pow(float64(x2-x1), 2) + math.Pow(float64(y2-y1), 2)))
		// Set new coordinates for the points shifted horizontally
		x4 := x1 + d
		x3 := x2 + d
		// Print the new coordinates
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}

	// Check if the slope is 1 (45 degrees)
	if quotient == 1 {
		// Set new coordinates for the points
		x4 := x2
		x3 := x1
		y4 := y1
		y3 := y2
		// Print the new coordinates
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}

	// Check if the slope is -1 (-45 degrees)
	if quotient == -1 {
		// Set new coordinates for the points
		x4 := x1
		x3 := x2
		y4 := y2
		y3 := y1
		// Print the new coordinates
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}

	// If none of the conditions are met, print -1
	if denominator == 0 && numerator == 0 {
		fmt.Println(-1)
	}
}

// Function to convert a list of strings to a list of integers
func convertStringtoListOfInt(l1 []string) []int {
	var l2 []int
	for _, v := range l1 {
		i, _ := strconv.Atoi(v)
		l2 = append(l2, i)
	}
	return l2
}

// End of code