package main

import (
	"fmt"
)

const MAX = 21

var n, x, y int
var fld [MAX][MAX]int

func initField(i int) {
	var a, b int
	x, y = 10, 10
	for j := 0; j < MAX; j++ {
		for k := 0; k < MAX; k++ {
			fld[j][k] = 0
		}
	}
	for i > 0 {
		fmt.Scanf("%d %d", &a, &b)
		fld[b][a] = 1
		i--
	}
}

func move(i int) {
	var a int
	var direction string
	for i > 0 {
		fmt.Scanf("%1s %d", &direction, &a)
		var d int
		switch direction {
		case "N":
			d = 0
		case "E":
			d = 1
		case "S":
			d = 2
		case "W":
			d = 3
		}
		for a > 0 {
			if d%2 == 1 {
				if d == 1 {
					x++
				} else {
					x--
				}
			} else {
				if d == 0 {
					y++
				} else {
					y--
				}
			}
			if fld[y][x] == 1 {
				fld[y][x] = 0
				n--
			}
			a--
		}
		i--
	}
}

func main() {
	var m int
	for {
		if _, err := fmt.Scanf("%d", &n); err != nil || n == 0 {
			break
		}
		initField(n)
		fmt.Scanf("%d", &m)
		move(m)
		if n > 0 {
			fmt.Println("No")
		} else {
			fmt.Println("Yes")
		}
	}
}

// <END-OF-CODE>
