package main

import (
	"fmt"
)

func main() {
	var x, y, t, n int
	var str string
	var l []rune

	fmt.Scan(&n)
	fmt.Scan(&str)

	l = []rune(str)

	for i := 0; i < n; i++ {
		if l[i] != '4' && l[i] != '7' {
			t = 1
		}
	}

	if t == 1 {
		fmt.Println("NO")
	} else {
		var sumX, sumY int

		for i := 0; i < n/2; i++ {
			sumX += int(l[i] - '0')
		}

		for i := n - 1; i > (n/2)-1; i-- {
			sumY += int(l[i] - '0')
		}

		if sumX == sumY {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

