package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	recordOfMovements, _ := reader.ReadString('\n')
	recordOfMovements = recordOfMovements[:len(recordOfMovements)-1] // Remove the newline character

	x, y := 0, 0
	dMovement := map[rune][2]int{'L': {0, -1}, 'R': {0, 1}, 'U': {1, 0}, 'D': {-1, 0}}
	d := map[[2]int]bool{}
	bug := false

	for _, move := range recordOfMovements {
		temp := [2]int{x, y}
		x += dMovement[move][0]
		y += dMovement[move][1]

		if _, exists := d[ [2]int{x, y} ]; !exists {
			for step, coords := range dMovement {
				if [2]int{x + coords[0], y + coords[1]} != temp && d[[2]int{x + coords[0], y + coords[1]}] {
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

		d[ [2]int{x, y} ] = true
	}

	if bug {
		fmt.Println("BUG")
	} else {
		fmt.Println("OK")
	}
}
