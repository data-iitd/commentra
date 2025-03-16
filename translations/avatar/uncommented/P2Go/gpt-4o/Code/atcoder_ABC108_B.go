package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	p := strings.Split(input, " ")

	x1, _ := strconv.Atoi(p[0])
	y1, _ := strconv.Atoi(p[1])
	x2, _ := strconv.Atoi(p[2])
	y2, _ := strconv.Atoi(p[3])

	DIF1 := x2 - x1
	DIF2 := y2 - y1

	x3 := x2 - DIF2
	y3 := y2 + DIF1
	x4 := x1 - DIF2
	y4 := y1 + DIF1

	fmt.Println(strconv.Itoa(x3) + " " + strconv.Itoa(y3) + " " + strconv.Itoa(x4) + " " + strconv.Itoa(y4))
}

// <END-OF-CODE>
