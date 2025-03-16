package main

import (
	"fmt"
	"strings"
)

const (
	MAX = 21
)

var (
	n, x, y int
	fld     [MAX][MAX]int
)

func init(i int) {
	var a, b int
	x, y = 10, 10
	for i--; i >= 0; i-- {
		fmt.Scanf("%d %d", &a, &b)
		fld[b][a] = 1
	}
}

func move(i int) {
	var a, d int
	var buf string
	for i--; i >= 0; i-- {
		fmt.Scanf("%s %d", &buf, &a)
		switch buf {
		case "N":
			d = 0
		case "E":
			d = 1
		case "S":
			d = 2
		case "W":
			d = 3
		}
		for a--; a >= 0; a-- {
			switch d % 2 {
			case 0:
				if d == 0 {
					x--
				} else {
					x++
				}
			case 1:
				if d == 1 {
					y--
				} else {
					y++
				}
			}
			if fld[y][x] == 1 {
				fld[y][x] = 0
				n--
			}
		}
	}
}

func main() {
	var m int
	for {
		fmt.Scanf("%d", &n)
		if n == -1 {
			break
		}
		init(n)
		fmt.Scanf("%d", &m)
		move(m)
		if n == 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

