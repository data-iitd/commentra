package main

import (
	"fmt"
)

func main() {
	var T, S, q int
	fmt.Scan(&T, &S, &q)
	previous := S
	answer := 0
	for previous < T {
		answer++
		previous *= q
	}
	fmt.Println(answer)
}

