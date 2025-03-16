

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
	// Step 1: Take input from the user and split it into a list of integers
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	l1 := strings.Split(input, " ")
	var l2 []int
	for _, v := range l1 {
		val, _ := strconv.Atoi(v)
		l2 = append(l2, val)
	}

	// Step 2: Assign the values to variables x1, y1, x2, and y2
	x1 := l2[0]
	y1 := l2[1]
	x2 := l2[2]
	y2 := l2[3]

	// Step 3: Check if the denominator is not zero to calculate the quotient
	denominator := x2 - x1
	numerator := y2 - y1
	var quotient float64
	if denominator!= 0 {
		quotient = float64(numerator) / float64(denominator)
	}

	// Step 4: If the numerator is zero, calculate the distance and print the coordinates of two points
	if numerator == 0 {
		d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
		x4 := x1
		x3 := x2
		y3 := y2 + d
		y4 := y1 + d
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}

	// Step 5: If the denominator is zero, print the coordinates of two points based on the distance calculated
	if denominator == 0 {
		y4 := y2
		y3 := y1
		d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
		x4 := x1 + d
		x3 := x2 + d
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}

	// Step 6: If the quotient is 1 or -1, swap the coordinates and print them
	if quotient == 1 {
		x4 := x2
		x3 := x1
		y4 := y1
		y3 := y2
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}
	if quotient == -1 {
		x4 := x1
		x3 := x2
		y4 := y2
		y3 := y1
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	}

	// Step 7: If none of the above conditions are met, print -1
	if denominator!= 0 && numerator!= 0 && quotient!= 1 && quotient!= -1 {
		fmt.Println(-1)
	}
}

