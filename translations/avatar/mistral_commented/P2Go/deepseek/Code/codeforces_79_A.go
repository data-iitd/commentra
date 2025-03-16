package main

import (
	"fmt"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y)
	a := 0

	for x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2 {
		if a != 0 {
			if y >= 22 {
				y -= 22
			} else if x >= 1 && y >= 12 {
				x -= 1
				y -= 12
			} else {
				x -= 2
				y -= 2
			}
		} else {
			if x >= 2 && y >= 2 {
				x -= 2
				y -= 2
			} else if x >= 1 && y >= 12 {
				x -= 1
				y -= 12
			} else {
				y -= 22
			}
		}
		a = 1 - a
	}

	if a == 0 {
		fmt.Println("Ciel")
	} else {
		fmt.Println("Hanako")
	}
}

