package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	list := strings.Split(input, " ")

	x, _ := strconv.Atoi(list[0])
	a, _ := strconv.Atoi(list[1])
	y, _ := strconv.Atoi(list[2])

	h := "NO"
	if x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7 {
		if x+y+a == 17 {
			h = "YES"
		}
	}
	fmt.Println(h)
}

// <END-OF-CODE>
