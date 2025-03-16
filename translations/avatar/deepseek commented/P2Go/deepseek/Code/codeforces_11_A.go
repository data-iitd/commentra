package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)

	var x []int
	var m, q int

	var input string
	fmt.Scan(&input)
	elements := strings.Split(input, " ")

	for i := 0; i < len(elements); i++ {
		num, _ := strconv.Atoi(elements[i])
		x = append(x, num)
	}

	for a := 0; a < len(x)-1; a++ {
		if x[a] >= x[a+1] {
			q = int((x[a] - x[a+1]) / d + 1)
			m += q
			x[a+1] += q * d
		}
	}

	fmt.Println(m)
}

