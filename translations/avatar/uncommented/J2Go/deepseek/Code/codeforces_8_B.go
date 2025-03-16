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
	coords := [][2]int{{x, y}}

	for _, char := range ch {
		switch char {
		case 'L':
			x--
		case 'R':
			x++
		case 'U':
			y++
		case 'D':
			y--
		}
		coords = append(coords, [2]int{x, y})
	}

	flag := true
	for i := 0; i < len(coords)-3; i++ {
		for j := i + 3; j < len(coords); j++ {
			dx := coords[i][0] - coords[j][0]
			dy := coords[i][1] - coords[j][1]
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

