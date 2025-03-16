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
		i, j, x, y, k int
		flag          bool
		s             string
		ch            []rune
		co            [][]int
	)

	scan := bufio.NewScanner(os.Stdin)
	scan.Scan()
	s = scan.Text()
	ch = []rune(s)
	co = make([][]int, 2)
	co[0] = make([]int, len(ch))
	co[1] = make([]int, len(ch))
	x = 0
	y = 0
	k = 0
	co[0][k] = x
	co[1][k] = y
	k++

	for i = 0; i < len(ch); i++ {
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

	flag = true
	for i = 0; i < k-3; i++ {
		for j = i + 3; j < k; j++ {
			dx := co[0][i] - co[0][j]
			dy := co[1][i] - co[1][j]
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

