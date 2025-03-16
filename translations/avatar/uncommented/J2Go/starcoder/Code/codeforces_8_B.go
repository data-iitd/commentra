package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		i, j, x, y, k, dx, dy int
		flag                  bool
		s                     string
		ch                    [100]byte
		co                    [2][101]int
	)

	scan := bufio.NewScanner(os.Stdin)
	scan.Scan()
	s = scan.Text()
	copy(ch[:], s)
	co[0][0] = 0
	co[1][0] = 0
	k = 1
	for i = 0; i < len(s); i++ {
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
		co[0][k] = x
		co[1][k] = y
		k++
	}
	for i = 0; i < k-3; i++ {
		for j = i + 3; j < k; j++ {
			dx = co[0][i] - co[0][j]
			dy = co[1][i] - co[1][j]
			if dx < 0 {
				dx *= -1
			}
			if dy < 0 {
				dy *= -1
			}
			if dx <= 1 && dy == 0 || dy <= 1 && dx == 0 {
				flag = false
				break
			}
		}
		if!flag {
			break
		}
	}
	if flag {
		fmt.Println("OK")
	} else {
		fmt.Println("BUG")
	}
}

