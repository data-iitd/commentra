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
	var intList []int
	for _, s := range l1 {
		num, _ := strconv.Atoi(s)
		intList = append(intList, num)
	}

	x1, y1 := intList[0], intList[1]
	x2, y2 := intList[2], intList[3]

	denominator := x2 - x1
	numerator := y2 - y1

	if denominator == 0 {
		d := int(math.Sqrt(float64((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))))
		x4, x3, y3, y4 := x1, x2, y2 + d, y1 + d
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	} else if denominator != 0 {
		quotient := float64(numerator) / float64(denominator)
		if quotient == 1 || quotient == -1 {
			var x4, x3, y3, y4 int
			if quotient == 1 {
				x4, x3, y3, y4 = x2, x1, y1, y2
			} else {
				x4, x3, y3, y4 = x1, x2, y2, y1
			}
			fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
		} else {
			fmt.Println("-1")
		}
	}
}
