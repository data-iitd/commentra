package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)

	var V []int
	var C []int

	var input string
	fmt.Scan(&input)
	vInput := strings.Split(input, " ")
	for _, v := range vInput {
		vi, _ := strconv.Atoi(v)
		V = append(V, vi)
	}

	fmt.Scan(&input)
	cInput := strings.Split(input, " ")
	for _, c := range cInput {
		ci, _ := strconv.Atoi(c)
		C = append(C, ci)
	}

	list := []int{0}
	ans := 0

	for i := 0; i < N; i++ {
		if V[i] - C[i] > 0 {
			X := V[i]
			Y := C[i]
			list = append(list, X - Y)
		}
	}

	for _, value := range list {
		ans += value
	}

	fmt.Println(ans)
}
