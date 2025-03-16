
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
	// Get user input and convert it to a list of integers
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	l1 := strings.Split(input, " ")
	var l2 []int
	for _, v := range l1 {
		x, _ := strconv.Atoi(v)
		l2 = append(l2, x)
	}

	// Assign the first two elements of the list to x1, y1 and the last two elements to x2, y2
	x1, y1 := l2[0], l2[1]
	x2, y2 := l2[2], l2[3]

	// Calculate the denominator and numerator of the slope
	denominator := x2 - x1
	numerator := y2 - y1

	// Check if the denominator is zero
	if denominator == 0 {
		// Calculate the distance between the two points and print the result
		d := int(math.Sqrt(float64((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))))
		x4, x3, y3, y4 := x1, x2, y2+d, y1+d
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}

	// If the denominator is not zero, calculate the quotient
	elif denominator!= 0 {
		quotient := numerator / denominator
	}

	// Check if the quotient is equal to 1 or -1
	if quotient == 1 || quotient == -1 {
		// Swap the x and y coordinates of the two points and print the result
		if quotient == 1 {
			x4, x3, y3, y4 := x2, x1, y1, y2
		} else {
			x4, x3, y3, y4 := x1, x2, y2, y1
		}
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}

	// If the quotient is not 1 or -1, print -1
	else {
		fmt.Println(-1)
	}
}
