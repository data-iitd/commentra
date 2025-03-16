package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	c := 0

	for i := 0; i < n; i++ {
		var input string
		fmt.Scan(&input)
		l1 := strings.Split(input, " ")
		sum := 0

		for _, numStr := range l1 {
			var num int
			fmt.Sscan(numStr, &num)
			sum += num
		}

		if sum > 1 {
			c++
		}
	}

	fmt.Println(c)
}

// <END-OF-CODE>
