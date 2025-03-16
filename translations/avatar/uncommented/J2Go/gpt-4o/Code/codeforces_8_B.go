package main

import (
	"fmt"
	"math"
)

func main() {
	var s string
	var x, y, k int
	var flag = true
	var co [2][101]int

	fmt.Scan(&s)
	x, y = 0, 0
	co[0][k] = x
	co[1][k] = y
	k++

	for i := 0; i < len(s); i++ {
		switch s[i] {
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

	for i := 0; i < k-3; i++ {
		for j := i + 3; j < k; j++ {
			dx := int(math.Abs(float64(co[0][i] - co[0][j])))
			dy := int(math.Abs(float64(co[1][i] - co[1][j])))
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

// <END-OF-CODE>
