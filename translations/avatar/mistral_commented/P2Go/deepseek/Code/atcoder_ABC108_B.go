package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take input from the user and split it using a space as the delimiter
	var input string
	fmt.Scanln(&input)
	p := strings.Split(input, " ")

	// Extract the first four elements of the list p and convert them to integers
	x1, _ := strconv.Atoi(p[0])
	y1, _ := strconv.Atoi(p[1])
	x2, _ := strconv.Atoi(p[2])
	y2, _ := strconv.Atoi(p[3])

	// Calculate the differences between the coordinates
	DIF1 := x2 - x1
	DIF2 := y2 - y1

	// Calculate the coordinates of the other two points based on the given coordinates and the differences
	x3 := x2 - DIF2
	y3 := y2 + DIF1
	x4 := x1 - DIF2
	y4 := y1 + DIF1

	// Print the calculated coordinates in the format x3 x4 y3 y4
	fmt.Println(strconv.Itoa(x3) + " " + strconv.Itoa(y3) + " " + strconv.Itoa(x4) + " " + strconv.Itoa(y4))
}

