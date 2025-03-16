package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var given string
	fmt.Scanln(&given)
	l1 := strings.Fields(given)
	var coordinates []int

	for _, x := range l1 {
		num, _ := strconv.Atoi(x)
		coordinates = append(coordinates, num)
	}

	x1 := coordinates[0]
	y1 := coordinates[1]
	x2 := coordinates[2]
	y2 := coordinates[3]

	denominator := x2 - x1
	numerator := y2 - y1

	if denominator != 0 {
		quotient := float64(numerator) / float64(denominator)
		if numerator == 0 {
			d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
			x4 := x1
			x3 := x2
			y3 := y2 + d
			y4 := y1 + d
			fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
		} else if denominator == 0 {
			y4 := y2
			y3 := y1
			d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
			x4 := x1 + d
			x3 := x2 + d
			fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
		} else if quotient == 1 {
			x4 := x2
			x3 := x1
			y4 := y1
			y3 := y2
			fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
		} else if quotient == -1 {
			x4 := x1
			x3 := x2
			y4 := y2
			y3 := y1
			fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
		} else {
			fmt.Println("-1")
		}
	} else {
		fmt.Println("-1")
	}
}

// <END-OF-CODE>
