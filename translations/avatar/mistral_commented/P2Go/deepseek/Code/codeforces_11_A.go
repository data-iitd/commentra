package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)

	var x []int
	input := ""
	fmt.Scan(&input)
	elements := strconv.Split(input, " ")
	for _, element := range elements {
		num, _ := strconv.Atoi(element)
		x = append(x, num)
	}

	m := 0
	q := 0

	for i := 0; i < len(x)-1; i++ {
		if x[i] >= x[i+1] {
			q = (x[i] - x[i+1]) / d + 1
			m += q
			x[i+1] += q * d
		}
	}

	fmt.Println(m)
}
