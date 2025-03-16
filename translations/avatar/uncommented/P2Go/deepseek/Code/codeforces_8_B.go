package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	recordOfMovements, _ := reader.ReadString('\n')
	x, y := 0, 0
	dMovement := map[rune][2]int{'L': {0, -1}, 'R': {0, 1}, 'U': {1, 0}, 'D': {-1, 0}}
	d := map[[2]int]string{}
	bug := false

	for _, move := range recordOfMovements {
		if move == '\n' {
			break
		}
		temp := [2]int{x, y}
		x += dMovement[move][0]
		y += dMovement[move][1]
		if _, exists := d[temp]; exists {
			for step := range dMovement {
				if [2]int{x + dMovement[step][0], y + dMovement[step][1]} != temp && _, exists := d[[2]int{x + dMovement[step][0], y + dMovement[step][1]}]; exists {
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

