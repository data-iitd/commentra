package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()
	ch := []rune(s)
	x, y := 0, 0
	co := [2][]int{{}, {}}
	co[0] = append(co[0], x)
	co[1] = append(co[1], y)

	for i := 0; i < len(ch); i++ {
		switch ch[i] {
		case 'L':
			x--
		case 'R':
			x++
		case 'U':
			y++
		case 'D':
			y--
		}
		co[0] = append(co[0], x)
		co[1] = append(co[1], y)
	}

	flag := true
	for i := 0; i < len(co[0])-3; i++ {
		for j := i + 3; j < len(co[0]); j++ {
			dx := co[0][i] - co[0][j]
			dy := co[1][i] - co[1][j]
			if dx < 0 {
				dx = -dx
			}
			if dy < 0 {
				dy = -dy
			}
			if (dx <= 1 && dy == 0) || (dy <= 1 && dx == 0) {
				flag = false
				break
			}
		}
		if !flag {
			break
		}
	}

	if flag {
		fmt.Println("OK")
	} else {
		fmt.Println("BUG")
	}
}
