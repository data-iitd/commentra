package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Fields(input)

	var l1 []int
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		l1 = append(l1, num)
	}

	x1 := l1[0]
	y1 := l1[1]
	x2 := l1[2]
	y2 := l1[3]

	denominator := x2 - x1
	numerator := y2 - y1

	var quotient float64
	if denominator != 0 {
		quotient = float64(numerator) / float64(denominator)
	}

	if denominator == 0 {
		d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
		x3 := x1
		x4 := x2
		y3 := y2 + d
		y4 := y1 + d
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	} else if numerator == 0 {
		d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
		x3 := x2
		x4 := x1
		y3 := y1
		y4 := y2 + d
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	} else if quotient == 1 {
		x3 := x1
		x4 := x2
		y3 := y1
		y4 := y2
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	} else if quotient == -1 {
		x3 := x2
		x4 := x1
		y3 := y2
		y4 := y1
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	} else {
		fmt.Println("-1")
	}
}
