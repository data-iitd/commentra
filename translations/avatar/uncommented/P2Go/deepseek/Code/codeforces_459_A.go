package main

import (
	"fmt"
	"math"
)

func main() {
	var given string
	fmt.Scanln(&given)
	l1 := strings.Split(given, " ")
	for i := range l1 {
		l1[i] = strings.TrimSpace(l1[i])
	}
	x1, _ := strconv.Atoi(l1[0])
	y1, _ := strconv.Atoi(l1[1])
	x2, _ := strconv.Atoi(l1[2])
	y2, _ := strconv.Atoi(l1[3])

	denominator := x2 - x1
	numerator := y2 - y1
	if denominator != 0 {
		quotient := float64(numerator) / float64(denominator)
		if quotient == 1 {
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
		}
	} else if numerator == 0 {
		d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
		x4 := x1
		x3 := x2
		y3 := y2 + d
		y4 := y1 + d
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
	} else {
		fmt.Println("-1")
	}
}
