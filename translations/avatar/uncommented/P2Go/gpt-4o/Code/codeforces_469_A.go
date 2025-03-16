package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var maxLevel int
	fmt.Scan(&maxLevel)

	var xInput string
	fmt.Scan(&xInput)
	xStr := strings.Split(xInput, " ")
	x := make(map[int]struct{})
	for i := 1; i < len(xStr); i++ {
		num, _ := strconv.Atoi(xStr[i])
		x[num] = struct{}{}
	}

	var yInput string
	fmt.Scan(&yInput)
	yStr := strings.Split(yInput, " ")
	y := make(map[int]struct{})
	for i := 1; i < len(yStr); i++ {
		num, _ := strconv.Atoi(yStr[i])
		y[num] = struct{}{}
	}

	delete(x, 0)
	delete(y, 0)

	z := make(map[int]struct{})
	for k := range x {
		z[k] = struct{}{}
	}
	for k := range y {
		z[k] = struct{}{}
	}

	if len(z) != maxLevel {
		fmt.Println("Oh, my keyboard!")
	} else {
		fmt.Println("I become the guy.")
	}
}

// <END-OF-CODE>
