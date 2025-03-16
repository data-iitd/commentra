package main

import (
	"fmt"
)

func main() {
	var recordOfMovements string
	fmt.Scan(&recordOfMovements)

	x, y := 0, 0
	dMovement := map[rune][2]int{
		'L': {0, -1},
		'R': {0, 1},
		'U': {1, 0},
		'D': {-1, 0},
	}
	d := make(map[[2]int]string)
	bug := false

	for _, move := range recordOfMovements {
		temp := [2]int{x, y}
		x += dMovement[move][0]
		y += dMovement[move][1]

		if _, exists := d[[2]int{x, y}]; !exists {
			for step := range dMovement {
				newX := x + dMovement[step][0]
				newY := y + dMovement[step][1]
				if [2]int{newX, newY} != temp && d[[2]int{newX, newY}] != "" {
					bug = true
					break
				}
			}
		} else {
			bug = true
		}

		if bug {
			break
		}
		d[[2]int{x, y}] = ""
	}

	if bug {
		fmt.Println("BUG")
	} else {
		fmt.Println("OK")
	}
}

// <END-OF-CODE>
