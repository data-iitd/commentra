package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	var number []int
	var temp int
	for i := 0; i < n; i++ {
		fmt.Scan(&temp)
		number = append(number, temp)
	}

	var h1, h2 int
	var x int

	for i := 0; i < n; i++ {
		if number[i] != 4 && number[i] != 7 {
			fmt.Println("NO")
			x = 1
			break
		}

		if i < n/2 {
			h1 += number[i]
		} else {
			h2 += number[i]
		}
	}

	if x == 0 {
		if h1 == h2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

