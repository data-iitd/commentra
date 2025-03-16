package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	var numberStr string
	fmt.Scan(&numberStr)

	number := make([]int, n)
	for i := 0; i < n; i++ {
		number[i], _ = strconv.Atoi(string(numberStr[i]))
	}

	h1 := 0
	h2 := 0
	x := 0

	for i := 0; i < n; i++ {
		if number[i] != 4 && number[i] != 7 {
			fmt.Println("NO")
			x++
			break
		}
		if i < n/2 {
			h1 += number[i]
		} else {
			h2 += number[i]
		}
	}
	if !x {
		if h1 == h2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

