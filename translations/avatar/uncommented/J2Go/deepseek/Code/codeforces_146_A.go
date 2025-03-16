package main

import (
	"fmt"
	"strconv"
)

func main() {
	var x, y, t, n int
	var str string
	fmt.Scan(&n, &str)
	l := []rune(str)
	for i := 0; i < n; i++ {
		if l[i] != '4' && l[i] != '7' {
			t = 1
		}
	}
	if t == 1 {
		fmt.Println("NO")
	} else {
		for i := 0; i < n/2; i++ {
			xi, _ := strconv.Atoi(string(l[i]))
			x += xi
		}
		for i := n - 1; i > (n/2)-1; i-- {
			yi, _ := strconv.Atoi(string(l[i]))
			y += yi
		}
		if x == y {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
