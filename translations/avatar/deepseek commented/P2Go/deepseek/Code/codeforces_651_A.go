package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	result := int(math.Max(float64(x+y-3+(func(y, x int) int {
		if (y-x)%3 != 0 {
			return 1
		}
		return 0
	}(y, x))), float64(0)))

	fmt.Println(result)

	numInp := func() int {
		var input int
		fmt.Scan(&input)
		return input
	}

	arrInp := func() []int {
		var input []int
		var n int
		fmt.Scan(&n)
		for i := 0; i < n; i++ {
			var num int
			fmt.Scan(&num)
			input = append(input, num)
		}
		return input
	}

	spInp := func() ([]int, []int) {
		var a, b []int
		var n, m int
		fmt.Scan(&n, &m)
		for i := 0; i < n; i++ {
			var num int
			fmt.Scan(&num)
			a = append(a, num)
		}
		for i := 0; i < m; i++ {
			var num int
			fmt.Scan(&num)
			b = append(b, num)
		}
		return a, b
	}

	strInp := func() string {
		var input string
		fmt.Scan(&input)
		return input
	}

	fmt.Println("<END-OF-CODE>")