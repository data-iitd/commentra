package main

import (
	"fmt"
	"strconv"
)

func main() {
	var x, y int
	var n int
	var str string
	fmt.Scan(&n)
	fmt.Scan(&str)

	l := []rune(str)

	t := 0
	for i := 0; i < n; i++ {
		if l[i] != '4' && l[i] != '7' {
			t = 1
			break
		}
	}

	if t == 1 {
		fmt.Println("NO")
	} else {
		for i := 0; i < n/2; i++ {
			val, _ := strconv.Atoi(string(l[i]))
			x += val
		}
		for i := n - 1; i > (n/2)-1; i-- {
			val, _ := strconv.Atoi(string(l[i]))
			y += val
		}
		if x == y {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

